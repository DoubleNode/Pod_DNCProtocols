//
//  __WKRNET_Base_Worker.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__WKR_Base_Worker.h"

#import "__WKRNET_Header_Processor.h"

@class DNCUrlSessionManager;

@protocol AFURLResponseSerialization;

@interface WKRNET_Base_Worker : WKR_Base_Worker

@property (strong, nonatomic)   id<WKRNET_Header_Processor> _Nullable   headerProcessor;

+ (nonnull DNCUrlSessionManager*)createManager;

- (BOOL)utilityCheckForAccessTokenError:(NSData*_Nullable)errorData;

- (void)utilityAddHeaders:(NSMutableURLRequest*_Nonnull)request
      withHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor;
- (void)utilityAddHeaders:(NSMutableURLRequest*_Nonnull)request
      withHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor
         usingAccessToken:(NSString* _Nullable)accessToken;

- (void)utilityGrabHeaders:(NSURLResponse*_Nonnull)response
       withHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor;

- (void)utilitySendRequest:(NSMutableURLRequest*_Nonnull)request
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilitySendRequest:(NSMutableURLRequest*_Nonnull)request
    withResponseSerializer:(id<AFURLResponseSerialization>_Nullable)responseSerializer
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilitySendRequest:(NSMutableURLRequest*_Nonnull)request
       withHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilitySendRequest:(NSMutableURLRequest*_Nonnull)request
       withHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor
     andResponseSerializer:(id<AFURLResponseSerialization>_Nullable)responseSerializer
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilityDataRequest:(NSMutableURLRequest*_Nonnull)request
                  withData:(NSData* _Nonnull)data
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilityDataRequest:(NSMutableURLRequest*_Nonnull)request
                  withData:(NSData* _Nonnull)data
     andResponseSerializer:(id<AFURLResponseSerialization>_Nullable)responseSerializer
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilityDataRequest:(NSMutableURLRequest*_Nonnull)request
                  withData:(NSData* _Nonnull)data
        andHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

- (void)utilityDataRequest:(NSMutableURLRequest*_Nonnull)request
                  withData:(NSData* _Nonnull)data
        andHeaderProcessor:(id<WKRNET_Header_Processor>_Nullable)headerProcessor
     andResponseSerializer:(id<AFURLResponseSerialization>_Nullable)responseSerializer
              retryHandler:(void(^ _Nullable)(NSError* _Nullable retryError))retryHandler
              errorHandler:(void(^ _Nullable)(NSError* _Nullable responseError))errorHandler
         completionHandler:(void(^ _Nullable)(NSURLResponse* _Nonnull response, id _Nullable responseObject))completionHandler;

@end
