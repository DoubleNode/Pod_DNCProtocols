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

@interface WKR_Base_Worker : DNCDataTranslation<PTCLBase_Protocol>

- (BOOL)isOptionEnabled:(nonnull NSString*)option;

- (void)workerSemaphoreClose:(nonnull GGMutableDictionary*)semaphores
                      forKey:(nonnull id)semaphoreKey;
- (void)workerSemaphoreOpen:(nonnull GGMutableDictionary*)semaphores
                     forKey:(nonnull id)semaphoreKey
                  withBlock:(nullable DNCUtilitiesBlock)block;

@end
