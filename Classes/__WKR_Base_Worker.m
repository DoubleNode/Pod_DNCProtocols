//
//  __WKR_Base_Worker.m
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__WKR_Base_Worker.h"

@interface WKR_Base_Worker ()
{
    NSMutableArray<NSString*> * _options;
}

@end

@implementation WKR_Base_Worker

@synthesize nextBaseWorker;

#define ERROR_DOMAIN_CLASS      [NSString stringWithFormat:@"com.doublenode.dncprotocols.%@", NSStringFromClass([self class])]
#define ERROR_UNKNOWN           1001
#define ERROR_NOT_FOUND         1002
#define ERROR_BAD_PARAMETER     1003
#define ERROR_BAD_RESPONSE      1004
#define ERROR_SERVER_ERROR      1005

+ (instancetype _Nonnull)worker   {   return [self worker:nil]; }

+ (instancetype _Nonnull)worker:(nullable id<PTCLBase_Protocol>)nextBaseWorker
{
    id<PTCLBase_Protocol>   worker  = [[self.class alloc] init];
    worker.nextBaseWorker   = nextBaseWorker;
    return worker;
}

- (id)init
{
    self = [super init];
    if (self)
    {
        _options    = [@[ ] mutableCopy];
    }
    
    return self;
}

#pragma mark - Common Methods

- (BOOL)isOptionEnabled:(nonnull NSString*)option
{
    @synchronized (_options)
    {
        return [_options containsObject:option];
    }
}

- (void)enableOption:(nonnull NSString*)option
{
    @synchronized (_options)
    {
        if (![self isOptionEnabled:option])
        {
            [_options addObject:option];
        }
    }
    
    if (self.nextBaseWorker)
    {
        [self.nextBaseWorker enableOption:option];
    }
}

- (void)disableOption:(nonnull NSString*)option
{
    @synchronized (_options)
    {
        if ([self isOptionEnabled:option])
        {
            [_options removeObject:option];
        }
    }
    
    if (self.nextBaseWorker)
    {
        [self.nextBaseWorker disableOption:option];
    }
}

@end
