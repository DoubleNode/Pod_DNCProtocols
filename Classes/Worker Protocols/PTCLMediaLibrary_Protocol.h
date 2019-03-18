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
typedef void(^PTCLMediaLibraryBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLMediaLibraryBlockVoidNSArrayNSError)(NSArray* _Nullable assets, NSError* _Nullable error);
typedef void(^PTCLMediaLibraryBlockVoidNSURLNSDictionary)(NSURL* _Nullable url, NSDictionary* _Nullable info);
typedef void(^PTCLMediaLibraryBlockVoidUIImageNSDictionary)(UIImage* _Nullable image, NSDictionary* _Nullable info);

@protocol PTCLMediaLibrary_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLMediaLibrary_Protocol> _Nullable    nextMediaLibraryWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLMediaLibrary_Protocol>)nextMediaLibraryWorker;

+ (CGSize)PTCLMediaLibraryMaximumSize;

- (BOOL)doCheckAuthorization;
- (void)doRequestAuthorizationWithProgress:(nullable PTCLProgressBlock)progressBlock
                                  andBlock:(nullable PTCLMediaLibraryBlockVoidNSError)completionBlock;

- (void)doLoadCollectionsWithProgress:(nullable PTCLProgressBlock)progressBlock
                             andBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;
- (void)doLoadAssetsOfMediaTypes:(nullable NSArray*)mediaTypes
                    withProgress:(nullable PTCLProgressBlock)progressBlock
                        andBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;
- (void)doLoadAssetsForCollection:(nonnull id)assetCollection
                     ofMediaTypes:(nullable NSArray*)mediaTypes
                     withProgress:(nullable PTCLProgressBlock)progressBlock
                         andBlock:(nullable PTCLMediaLibraryBlockVoidNSArrayNSError)completionBlock;

- (void)doLoadAudio:(nonnull id)asset
           withSize:(CGSize)size
        andProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLMediaLibraryBlockVoidNSURLNSDictionary)completionBlock;
- (void)doLoadImage:(nonnull id)asset
           withSize:(CGSize)size
        andProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLMediaLibraryBlockVoidUIImageNSDictionary)completionBlock;
- (void)doLoadVideo:(nonnull id)asset
           withSize:(CGSize)size
        andProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLMediaLibraryBlockVoidNSURLNSDictionary)completionBlock;

- (void)doSaveImage:(UIImage* _Nullable)image
       withProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;
- (void)doSaveImage:(UIImage* _Nullable)image
       toCollection:(nonnull id)assetCollection
       withProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;

- (void)doSaveAudioFromUrl:(NSURL* _Nullable)videoUrl
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;
- (void)doSaveAudioFromUrl:(NSURL* _Nullable)videoUrl
              toCollection:(nonnull id)assetCollection
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;

- (void)doSaveImageFromUrl:(NSURL* _Nullable)imageUrl
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;
- (void)doSaveImageFromUrl:(NSURL* _Nullable)imageUrl
              toCollection:(nonnull id)assetCollection
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;

- (void)doSaveVideoFromUrl:(NSURL* _Nullable)videoUrl
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;
- (void)doSaveVideoFromUrl:(NSURL* _Nullable)videoUrl
              toCollection:(nonnull id)assetCollection
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLMediaLibraryBlockVoidBOOLNSError)completionBlock;

@end

#endif /* PTCLMediaLibrary_Protocol_h */
