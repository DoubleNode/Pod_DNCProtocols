//
//  PTCLMediaLibrary_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLMediaLibrary_Protocol_h
#define PTCLMediaLibrary_Protocol_h

#import "__PTCLBase_Protocol.h"

typedef void(^PTCLMediaLibraryBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLMediaLibraryBlockVoidNSArrayNSError)(NSArray* _Nullable assets, NSError* _Nullable error);
typedef void(^PTCLMediaLibraryBlockVoidUIImageNSDictionary)(UIImage* _Nullable image, NSDictionary* _Nullable info);

@protocol PTCLMediaLibrary_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLMediaLibrary_Protocol> _Nullable    nextMediaLibraryWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLMediaLibrary_Protocol>)nextMediaLibraryWorker;

+ (CGSize)PTCLMediaLibraryMaximumSize;

- (BOOL)doCheckAuthorization;
- (void)doRequestAuthorizationWithCompletionBlock:(nullable PTCLMediaLibraryBlockVoidNSError)completionBlock;

- (void)doLoadCollectionsWithCompletionBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;
- (void)doLoadImagesWithCompletionBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;
- (void)doLoadImagesForCollection:(nonnull id)assetCollection
              withCompletionBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;

- (void)doLoadImage:(nonnull id)asset
               size:(CGSize)size
    completionBlock:(nullable PTCLMediaLibraryBlockVoidUIImageNSDictionary)completionBlock;

@end

#endif /* PTCLMediaLibrary_Protocol_h */
