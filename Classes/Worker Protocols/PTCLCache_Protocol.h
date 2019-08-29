//
//  PTCLCache_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLCache_Protocol_h
#define PTCLCache_Protocol_h

#import "__PTCLBase_Protocol.h"

typedef void(^PTCLCacheBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLCacheBlockVoidIDNSError)(id _Nullable object, NSError* _Nullable error);
typedef void(^PTCLCacheBlockVoid)(id _Nullable object, NSError* _Nullable error);

@protocol PTCLCache_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLCache_Protocol> _Nullable  nextCacheWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLCache_Protocol>)nextCacheWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)cacheId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLCacheBlockVoidIDNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)cacheId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLCacheBlockVoidNSError)block;

- (void)doSaveObject:(nonnull id)object
               forId:(nonnull NSString*)cacheId
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLCacheBlockVoidNSError)block;

- (void)doLoadImageForUrl:(nonnull NSURL*)url
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLCacheBlockVoidIDNSError)block;

@end

#endif /* PTCLCache_Protocol_h */
