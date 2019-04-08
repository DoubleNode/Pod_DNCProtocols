//
//  __WKRNET_Base_Worker.m
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

@import DNCore;

#import "__WKRNET_Base_Worker.h"

@interface WKRNET_Base_Worker ()
{
    NSMutableDictionary<NSString*, NSNumber*>*  _retryCounts;
}

@end

@implementation WKRNET_Base_Worker

#define ERROR_DOMAIN_CLASS      [NSString stringWithFormat:@"com.doublenode.dncprotocols.%@", NSStringFromClass([self class])]
#define ERROR_UNKNOWN           1001
#define ERROR_NOT_FOUND         1002
#define ERROR_BAD_PARAMETER     1003
#define ERROR_BAD_RESPONSE      1004
#define ERROR_SERVER_ERROR      1005

+ (DNCUrlSessionManager*)createManager
{
    return DNCUrlSessionManager.manager;
}

#pragma mark - Property Access Methods

- (NSNumber*)retryCountForKey:(NSString*)key
{
    NSNumber*   retryCount;
    
    @synchronized (self->_retryCounts)
    {
        retryCount = self->_retryCounts[key];
    }
    
    return retryCount;
}

- (void)setRetryCount:(NSNumber*)retryCount
               forKey:(NSString*)key
{
    @synchronized (self->_retryCounts)
    {
        self->_retryCounts[key] = retryCount;
    }
}

- (void)clearRetryCountForKey:(NSString*)key
{
    @synchronized (self->_retryCounts)
    {
        [self->_retryCounts removeObjectForKey:key];
    }
}

#pragma mark - Configuration

- (void)configure
{
    [super configure];
    
    _retryCounts = NSMutableDictionary.dictionary;
}

#pragma mark - Utility Methods

- (BOOL)utilityCheckForAccessTokenError:(NSData*_Nullable)errorData
{
    return NO;
}

- (void)utilityAddHeaders:(NSMutableURLRequest*_Nonnull)request
{
    if ([self.headerProcessor respondsToSelector:@selector(processorAddHeaders:)])
    {
        [self.headerProcessor processorAddHeaders:request];
    }
}

- (void)utilityGrabHeaders:(NSURLResponse*_Nonnull)response
{
    if ([self.headerProcessor respondsToSelector:@selector(processorGrabHeaders:)])
    {
        [self.headerProcessor processorGrabHeaders:response];
    }
}

- (void)utilityAddHeaders:(NSMutableURLRequest*_Nonnull)request
         usingAccessToken:(NSString* _Nullable)accessToken
{
    [self utilityAddHeaders:request];
    
    if (accessToken.length > 0)
    {
        [request setValue:accessToken forHTTPHeaderField:@"Authentication"];
    }
}

- (void)utilitySendRequest:(NSMutableURLRequest*_Nonnull)request
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler
{
    [self utilitySendRequest:request
      withResponseSerializer:nil
                retryHandler:retryHandler
                errorHandler:errorHandler
           completionHandler:completionHandler];
}

- (void)utilitySendRequest:(NSMutableURLRequest*_Nonnull)request
    withResponseSerializer:(id<AFURLResponseSerialization>_Nullable)responseSerializer
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler
{
    DNCLog(DNCLL_Info, DNCLD_Networking, @"START - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
    
    [self utilityAddHeaders:request];
    
    DNCUrlSessionManager*   manager = self.class.createManager;
    if (responseSerializer)
    {
        manager.responseSerializer  = responseSerializer;
    }
    
    NSURLSessionDataTask*   dataTask =
    [manager sendTaskWithRequest:request
              serverErrorHandler:
     ^(NSHTTPURLResponse* _Nullable httpResponse, id _Nullable responseObject)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         [self utilityGrabHeaders:httpResponse];
         
         NSString*  jsonErrorMessage    = @"";
         
         if (responseObject)
         {
             id jsonData;
             if ([responseObject isKindOfClass:NSData.class])
             {
                 jsonData = [NSJSONSerialization JSONObjectWithData:responseObject
                                                            options:0
                                                              error:nil];
             }
             else if ([responseObject isKindOfClass:NSDictionary.class])
             {
                 DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY DATA - [%@] %@ responseObject=%@", request.HTTPMethod, request.URL.absoluteString, responseObject);
             }
             else
             {
                 DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY DATA - [%@] %@ responseObject=%@", request.HTTPMethod, request.URL.absoluteString, responseObject);
             }
             if (jsonData)
             {
                 DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY DATA - [%@] %@ DATA=%@", request.HTTPMethod, request.URL.absoluteString, jsonData);
                 
                 jsonErrorMessage = [self stringFromString:jsonData[@"error"]];
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"data"][@"error"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"data"][@"message"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"message"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"Message"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"Message"]];
                 }
             }
         }
         
         NSString*  retryErrorMessage   = jsonErrorMessage;
         if (!retryErrorMessage.length)
         {
             retryErrorMessage  = [NSHTTPURLResponse localizedStringForStatusCode:httpResponse.statusCode];
         }
         if (!retryErrorMessage.length)
         {
             retryErrorMessage  = NSLocalizedString(@"Unknown error", @"");
         }
         
         NSNumber* retryCount = [self retryCountForKey:request.URL.absoluteString];
         if (!retryCount)
         {
             retryCount = @(0);
         }
         retryCount = @(retryCount.intValue + 1);
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   retryError  = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                      code:httpResponse.statusCode
                                                  userInfo:@{
                                                             NSLocalizedDescriptionKey: retryErrorMessage,
                                                             }];
         
         [self setRetryCount:retryCount
                      forKey:request.URL.absoluteString];
         
         if (retryCount.intValue >= 5)
         {
             [self clearRetryCountForKey:request.URL.absoluteString];
             
             DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY LIMIT - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             
             errorHandler ? errorHandler(retryError) : nil;
             
             DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             return;
         }
         
         retryHandler ? retryHandler(retryError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
                dataErrorHandler:
     ^(NSData* _Nullable errorData, NSString* _Nullable errorMessage)
     {
         NSError*   responseError   = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                          code:ERROR_SERVER_ERROR
                                                      userInfo:@{
                                                                 NSLocalizedDescriptionKey: NSLocalizedString(@"Unknown error", @""),
                                                                 }];
         if (errorMessage.length)
         {
             DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             
             responseError = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                 code:ERROR_SERVER_ERROR
                                             userInfo:@{
                                                        NSLocalizedDescriptionKey: errorMessage
                                                        }];
         }
         
         if ([self utilityCheckForAccessTokenError:errorData])
         {
             DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             
             retryHandler ? retryHandler(responseError) : nil;
             return;
         }
         
         errorHandler ? errorHandler(responseError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
             unknownErrorHandler:
     ^(NSError* _Nullable dataError)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   responseError = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                        code:ERROR_BAD_RESPONSE
                                                    userInfo:dataError.userInfo];
         
         errorHandler ? errorHandler(responseError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
           noResponseBodyHandler:
     ^()
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   responseError = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                        code:ERROR_BAD_RESPONSE
                                                    userInfo:@{ NSLocalizedDescriptionKey: NSLocalizedString(@"The server response was invalid.", nil),
                                                                NSLocalizedFailureReasonErrorKey: NSLocalizedString(@"Unable to load object.", nil)
                                                                }];
         
         errorHandler ? errorHandler(responseError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
               completionHandler:
     ^(NSURLResponse* response, id responseObject)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         [self utilityGrabHeaders:response];
         
         completionHandler ? completionHandler(response, responseObject) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }];
    
    [dataTask resume];
}

- (void)utilityDataRequest:(NSMutableURLRequest*_Nonnull)request
                  withData:(NSData*)data
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler
{
    [self utilityDataRequest:request
                    withData:data
       andResponseSerializer:nil
                retryHandler:retryHandler
                errorHandler:errorHandler
           completionHandler:completionHandler];
}

- (void)utilityDataRequest:(NSMutableURLRequest*_Nonnull)request
                  withData:(NSData*)data
     andResponseSerializer:(id<AFURLResponseSerialization>_Nullable)responseSerializer
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler
{
    DNCLog(DNCLL_Info, DNCLD_Networking, @"START - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
    
    [self utilityAddHeaders:request];
    
    DNCUrlSessionManager*   manager = self.class.createManager;
    if (responseSerializer)
    {
        manager.responseSerializer  = responseSerializer;
    }
    
    NSURLSessionDataTask*   dataTask =
    [manager dataTaskWithRequest:request
                        withData:data
              serverErrorHandler:
     ^(NSHTTPURLResponse* _Nullable httpResponse, id _Nullable responseObject)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         [self utilityGrabHeaders:httpResponse];
         
         NSString*  jsonErrorMessage    = @"";
         
         if (responseObject)
         {
             id jsonData;
             if ([responseObject isKindOfClass:NSData.class])
             {
                 jsonData = [NSJSONSerialization JSONObjectWithData:responseObject
                                                            options:0
                                                              error:nil];
             }
             else if ([responseObject isKindOfClass:NSDictionary.class])
             {
                 DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY DATA - [%@] %@ responseObject=%@", request.HTTPMethod, request.URL.absoluteString, responseObject);
             }
             else
             {
                 DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY DATA - [%@] %@ responseObject=%@", request.HTTPMethod, request.URL.absoluteString, responseObject);
             }
             if (jsonData)
             {
                 DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY DATA - [%@] %@ DATA=%@", request.HTTPMethod, request.URL.absoluteString, jsonData);
                 
                 jsonErrorMessage = [self stringFromString:jsonData[@"error"]];
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"data"][@"error"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"data"][@"message"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"message"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"Message"]];
                 }
                 if (!jsonErrorMessage.length)
                 {
                     jsonErrorMessage    = [self stringFromString:jsonData[@"Message"]];
                 }
             }
         }
         
         NSString*  retryErrorMessage   = jsonErrorMessage;
         if (!retryErrorMessage.length)
         {
             retryErrorMessage  = [NSHTTPURLResponse localizedStringForStatusCode:httpResponse.statusCode];
         }
         if (!retryErrorMessage.length)
         {
             retryErrorMessage  = NSLocalizedString(@"Unknown error", @"");
         }
         
         NSNumber* retryCount = [self retryCountForKey:request.URL.absoluteString];
         if (!retryCount)
         {
             retryCount = @(0);
         }
         retryCount = @(retryCount.intValue + 1);
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   retryError  = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                      code:httpResponse.statusCode
                                                  userInfo:@{
                                                             NSLocalizedDescriptionKey: retryErrorMessage,
                                                             }];
         
         [self setRetryCount:retryCount
                      forKey:request.URL.absoluteString];
         
         if (retryCount.intValue >= 5)
         {
             [self clearRetryCountForKey:request.URL.absoluteString];
             
             DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY LIMIT - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             
             errorHandler ? errorHandler(retryError) : nil;
             
             DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             return;
         }
         
         retryHandler ? retryHandler(retryError) : nil;
     }
                dataErrorHandler:
     ^(NSData* _Nullable errorData, NSString* _Nullable errorMessage)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   responseError   = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                          code:ERROR_SERVER_ERROR
                                                      userInfo:@{
                                                                 NSLocalizedDescriptionKey: NSLocalizedString(@"Unknown error", @""),
                                                                 }];
         if (errorMessage.length)
         {
             DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             
             responseError = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                 code:ERROR_SERVER_ERROR
                                             userInfo:@{
                                                        NSLocalizedDescriptionKey: errorMessage
                                                        }];
         }
         
         if ([self utilityCheckForAccessTokenError:errorData])
         {
             DNCLog(DNCLL_Info, DNCLD_Networking, @"RETRY - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
             
             retryHandler ? retryHandler(responseError) : nil;
             return;
         }
         
         errorHandler ? errorHandler(responseError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
             unknownErrorHandler:
     ^(NSError* _Nullable dataError)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   responseError = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                        code:ERROR_BAD_RESPONSE
                                                    userInfo:dataError.userInfo];
         
         errorHandler ? errorHandler(responseError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
           noResponseBodyHandler:
     ^()
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE ERROR - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         NSError*   responseError = [NSError errorWithDomain:ERROR_DOMAIN_CLASS
                                                        code:ERROR_BAD_RESPONSE
                                                    userInfo:@{ NSLocalizedDescriptionKey: NSLocalizedString(@"The server response was invalid.", nil),
                                                                NSLocalizedFailureReasonErrorKey: NSLocalizedString(@"Unable to load object.", nil)
                                                                }];
         
         errorHandler ? errorHandler(responseError) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }
               completionHandler:
     ^(NSURLResponse* response, id responseObject)
     {
         DNCLog(DNCLL_Info, DNCLD_Networking, @"RESPONSE - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
         
         [self utilityGrabHeaders:response];
         
         completionHandler ? completionHandler(response, responseObject) : nil;
         
         DNCLog(DNCLL_Info, DNCLD_Networking, @"END - [%@] %@", request.HTTPMethod, request.URL.absoluteString);
     }];
    
    [dataTask resume];
}

#pragma mark - Utility methods

- (NSString*)stringFromString:(NSString*)string
{
    if ([string isKindOfClass:NSDictionary.class])
    {
        NSData* jsonData    = [NSJSONSerialization dataWithJSONObject:string
                                                              options:0
                                                                error:nil];
        
        string = [NSString.alloc initWithData:jsonData
                                     encoding:NSUTF8StringEncoding];
    }
    
    if ([string isKindOfClass:NSString.class])
    {
        return string;
    }
    
    if (!string ||
        ![string isKindOfClass:NSString.class] ||
        [string isEqualToString:@"<null>"])
    {
        return @"";
    }
    
    return [NSString stringWithFormat:@"%@", string];
}

@end
