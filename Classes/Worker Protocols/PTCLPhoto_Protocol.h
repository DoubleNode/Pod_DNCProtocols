//
//  PTCLPhoto_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLPhoto_Protocol_h
#define PTCLPhoto_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOFlag;
@class DAOItem;
@class DAOLocation;
@class DAOPhoto;
@class DAOReview;
@class DAOUser;

typedef void(^PTCLPhotoContinueBlock)(void);

typedef void(^PTCLPhotoBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLPhotoBlockVoidDAOItemNSError)(DAOItem* _Nullable beer, NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidDAOLocationNSError)(DAOLocation* _Nullable brewery, NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidDAOPhotoNSError)(DAOPhoto* _Nullable photo, NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidDAOReviewNSError)(DAOReview* _Nullable review, NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLPhotoBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLPhotoBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable beer, NSError* _Nullable error, PTCLPhotoContinueBlock _Nullable continueBlock);
typedef void(^PTCLPhotoBlockVoidDAOLocationNSErrorContinue)(DAOLocation* _Nullable brewery, NSError* _Nullable error, PTCLPhotoContinueBlock _Nullable continueBlock);
typedef void(^PTCLPhotoBlockVoidDAOPhotoNSErrorContinue)(DAOPhoto* _Nullable photo, NSError* _Nullable error, PTCLPhotoContinueBlock _Nullable continueBlock);
typedef void(^PTCLPhotoBlockVoidDAOReviewNSErrorContinue)(DAOReview* _Nullable review, NSError* _Nullable error, PTCLPhotoContinueBlock _Nullable continueBlock);
typedef void(^PTCLPhotoBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLPhotoContinueBlock _Nullable continueBlock);
typedef void(^PTCLPhotoBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLPhotoContinueBlock _Nullable continueBlock);

@protocol PTCLPhoto_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLPhoto_Protocol> _Nullable    nextPhotoWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLPhoto_Protocol>)nextPhotoWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)photoId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLPhotoBlockVoidDAOPhotoNSErrorContinue)block
           andUpdateBlock:(nullable PTCLPhotoBlockVoidDAOPhotoNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOPhoto*)photo
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLPhotoBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)photoId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLPhotoBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOPhoto*)photo
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLPhotoBlockVoidDAOPhotoNSError)block;

- (void)doFavoriteObject:(nonnull DAOPhoto*)photo
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLPhotoBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAOPhoto*)photo
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLPhotoBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOPhoto*)photo
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLPhotoBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOPhoto*)photo
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
           andProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLPhotoBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOPhoto*)photo
               withAction:(nonnull NSString*)action
              andProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLPhotoBlockVoidNSUIntegerNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemForObject:(nonnull DAOPhoto*)photo
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLPhotoBlockVoidDAOItemNSErrorContinue)block
             andUpdateBlock:(nullable PTCLPhotoBlockVoidDAOItemNSError)updateBlock;

- (void)doLoadLocationForObject:(nonnull DAOPhoto*)photo
                   withProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLPhotoBlockVoidDAOLocationNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLPhotoBlockVoidDAOLocationNSError)updateBlock;

- (void)doLoadReviewForObject:(nonnull DAOPhoto*)photo
                 withProgress:(nullable PTCLProgressBlock)progressBlock
                     andBlock:(nullable PTCLPhotoBlockVoidDAOReviewNSErrorContinue)block
               andUpdateBlock:(nullable PTCLPhotoBlockVoidDAOReviewNSError)updateBlock;

- (void)doLoadUserForObject:(nonnull DAOPhoto*)photo
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLPhotoBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLPhotoBlockVoidDAOUserNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadFlagsForObject:(nonnull DAOPhoto*)photo
                 withActions:(nonnull NSArray<NSString*>*)actions
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLPhotoBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLPhotoBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAOPhoto*)photo
                   withActions:(nonnull NSArray<NSString*>*)actions
                   andProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLPhotoBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLPhotoBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLPhoto_Protocol_h */
