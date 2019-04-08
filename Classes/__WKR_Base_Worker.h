//
//  __WKR_Base_Worker.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

@import DNCore;

#import "__PTCLBase_Protocol.h"

#define WKR_Base_Option_NoCache @"noCache"

@interface WKR_Base_Worker : NSObject<PTCLBase_Protocol>

- (BOOL)isOptionEnabled:(nonnull NSString*)option;

- (void)workerSemaphoreClose:(GGMutableDictionary*)semaphores
                      forKey:(id)semaphoreKey;
- (void)workerSemaphoreOpen:(GGMutableDictionary*)semaphores
                     forKey:(id)semaphoreKey
                  withBlock:(DNCUtilitiesBlock)block;

@end
