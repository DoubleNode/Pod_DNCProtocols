//
//  PTCLReview_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLReview_Protocol_h
#define PTCLReview_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOItem;
@class DAOLocation;
@class DAORating;
@class DAOReview;
@class DAOUser;

typedef void(^PTCLReviewContinueBlock)(void);

typedef void(^PTCLReviewBlockVoidDAOReview)(DAOReview* _Nullable review);
typedef void(^PTCLReviewBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLReviewBlockVoidDAOReviewNSError)(DAOReview* _Nullable updatedReview, NSError* _Nullable error);

typedef void(^PTCLReviewBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLReviewBlockVoidDAOLocationNSError)(DAOLocation* _Nullable location, NSError* _Nullable error);
typedef void(^PTCLReviewBlockVoidDAOPhotoNSError)(DAOPhoto* _Nullable photo, NSError* _Nullable error);
typedef void(^PTCLReviewBlockVoidDAOReviewNSError)(DAOReview* _Nullable review, NSError* _Nullable error);
typedef void(^PTCLReviewBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOReview* >* _Nullable reviews, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLReviewBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLReviewContinueBlock _Nullable continueBlock);
typedef void(^PTCLReviewBlockVoidDAOLocationNSErrorContinue)(DAOLocation* _Nullable location, NSError* _Nullable error, PTCLReviewContinueBlock _Nullable continueBlock);
typedef void(^PTCLReviewBlockVoidDAOPhotoNSErrorContinue)(DAOPhoto* _Nullable photo, NSError* _Nullable error, PTCLReviewContinueBlock _Nullable continueBlock);
typedef void(^PTCLReviewBlockVoidDAOReviewNSErrorContinue)(DAOReview* _Nullable review, NSError* _Nullable error, PTCLReviewContinueBlock _Nullable continueBlock);
typedef void(^PTCLReviewBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLReviewContinueBlock _Nullable continueBlock);
typedef void(^PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOReview* >* _Nullable reviews, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLReviewContinueBlock _Nullable continueBlock);

@protocol PTCLReview_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLReview_Protocol> _Nullable    nextReviewWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLReview_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)reviewId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLReviewBlockVoidDAOReviewNSErrorContinue)block
           andUpdateBlock:(nullable PTCLReviewBlockVoidDAOReviewNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOReview*)review
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLReviewBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)reviewId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLReviewBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOReview*)review
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLReviewBlockVoidDAOReviewNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadCreatorForObject:(nonnull DAOReview*)review
                  withProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLReviewBlockVoidDAOUserNSErrorContinue)block
                andUpdateBlock:(nullable PTCLReviewBlockVoidDAOUserNSError)updateBlock;

- (void)doLoadItemForObject:(nonnull DAOReview*)review
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLReviewBlockVoidDAOItemNSErrorContinue)block
             andUpdateBlock:(nullable PTCLReviewBlockVoidDAOItemNSError)updateBlock;

- (void)doLoadLocationForObject:(nonnull DAOReview*)review
                   withProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLReviewBlockVoidDAOLocationNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLReviewBlockVoidDAOLocationNSError)updateBlock;

- (void)doLoadPhotoForObject:(nonnull DAOReview*)review
                withProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLReviewBlockVoidDAOPhotoNSErrorContinue)block
              andUpdateBlock:(nullable PTCLReviewBlockVoidDAOPhotoNSError)updateBlock;

- (void)doLoadUserForObject:(nonnull DAOReview*)review
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLReviewBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLReviewBlockVoidDAOUserNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForItem:(nonnull DAOItem*)item
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForLocation:(nonnull DAOLocation*)location
                  withParameters:(nullable NSDictionary*)parameters
                     andProgress:(nullable PTCLProgressBlock)progressBlock
                        andBlock:(nullable PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLReviewBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLReview_Protocol_h */
