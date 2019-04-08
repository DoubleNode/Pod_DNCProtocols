//
//  __WKR_Base_Worker.m
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
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
    return [[self.class alloc] initWithWorker:nextBaseWorker];
}

- (nonnull instancetype)init
{
    self = [super init];
    if (self)
    {
        _options    = [@[ ] mutableCopy];
        
        self.nextBaseWorker = nil;
        
        [self configure];
    }
    
    return self;
}

- (nonnull instancetype)initWithWorker:(nullable id<PTCLBase_Protocol>)nextBaseWorker_
{
    self = [super init];
    if (self)
    {
        _options    = [@[ ] mutableCopy];
        
        self.nextBaseWorker = nextBaseWorker_;
        
        [self configure];
    }
    
    return self;
}

#pragma mark - Configuration

- (void)configure
{
    // Worker Dependency Injection
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

- (void)workerSemaphoreClose:(GGMutableDictionary*)semaphores
                      forKey:(id)semaphoreKey
{
    @synchronized (semaphores)
    {
        DNCSemaphore*   mySemaphore = [semaphores objectForKey:semaphoreKey];
        
        [semaphores removeObjectForKey:semaphoreKey];
        
        if (mySemaphore)
        {
            [mySemaphore done];
        }
    };
}

- (void)workerSemaphoreOpen:(GGMutableDictionary*)semaphores
                     forKey:(id)semaphoreKey
                  withBlock:(DNCUtilitiesBlock)block
{
    [DNCLowThread run:
     ^()
     {
         __block DNCSemaphore*  semaphore;
         
         @synchronized (semaphores)
         {
             semaphore = [semaphores objectForKey:semaphoreKey];
         };
         
         if (semaphore)
         {
             [semaphore wait];
         }
         
         @synchronized (semaphores)
         {
             if (!semaphore)
             {
                 semaphore = DNCSemaphoreGate.semaphore;
             }
             semaphores[semaphoreKey]   = semaphore;
         };
         
         block ? block() : (void)nil;
     }];
}

@end
