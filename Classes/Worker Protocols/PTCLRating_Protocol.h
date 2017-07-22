//
//  PTCLRating_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLRating_Protocol_h
#define PTCLRating_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOItem;
@class DAOLocation;
@class DAORating;
@class DAOReview;
@class DAOUser;

typedef void(^PTCLRatingContinueBlock)(void);

typedef void(^PTCLRatingBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLRatingBlockVoidDAORatingNSError)(DAORating* _Nullable updatedRating, NSError* _Nullable error);

typedef void(^PTCLRatingBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLRatingBlockVoidDAOLocationNSError)(DAOLocation* _Nullable location, NSError* _Nullable error);
typedef void(^PTCLRatingBlockVoidDAORatingNSError)(DAORating* _Nullable rating, NSError* _Nullable error);
typedef void(^PTCLRatingBlockVoidDAOReviewNSError)(DAOReview* _Nullable review, NSError* _Nullable error);
typedef void(^PTCLRatingBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAORating* >* _Nullable ratings, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLRatingBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLRatingContinueBlock _Nullable continueBlock);
typedef void(^PTCLRatingBlockVoidDAOLocationNSErrorContinue)(DAOLocation* _Nullable location, NSError* _Nullable error, PTCLRatingContinueBlock _Nullable continueBlock);
typedef void(^PTCLRatingBlockVoidDAORatingNSErrorContinue)(DAORating* _Nullable rating, NSError* _Nullable error, PTCLRatingContinueBlock _Nullable continueBlock);
typedef void(^PTCLRatingBlockVoidDAOReviewNSErrorContinue)(DAOReview* _Nullable review, NSError* _Nullable error, PTCLRatingContinueBlock _Nullable continueBlock);
typedef void(^PTCLRatingBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLRatingContinueBlock _Nullable continueBlock);
typedef void(^PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAORating* >* _Nullable ratings, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLRatingContinueBlock _Nullable continueBlock);

@protocol PTCLRating_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLRating_Protocol> _Nullable    nextRatingWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLRating_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)ratingId
                withBlock:(nullable PTCLRatingBlockVoidDAORatingNSErrorContinue)block
           andUpdateBlock:(nullable PTCLRatingBlockVoidDAORatingNSError)updateBlock;

- (void)doLoadObjectForReview:(nonnull DAOReview*)review
                    withBlock:(nullable PTCLRatingBlockVoidDAORatingNSErrorContinue)block
               andUpdateBlock:(nullable PTCLRatingBlockVoidDAORatingNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAORating*)rating
             withBlock:(nullable PTCLRatingBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)ratingId
                  withBlock:(nullable PTCLRatingBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForItem:(nonnull DAOItem*)item
                    withBlock:(nullable PTCLRatingBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAORating*)rating
           withBlock:(nullable PTCLRatingBlockVoidDAORatingNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemForObject:(nonnull DAORating*)rating
                  withBlock:(nullable PTCLRatingBlockVoidDAOItemNSErrorContinue)block
             andUpdateBlock:(nullable PTCLRatingBlockVoidDAOItemNSError)updateBlock;

- (void)doLoadLocationForObject:(nonnull DAORating*)rating
                      withBlock:(nullable PTCLRatingBlockVoidDAOLocationNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLRatingBlockVoidDAOLocationNSError)updateBlock;

- (void)doLoadReviewForObject:(nonnull DAORating*)rating
                    withBlock:(nullable PTCLRatingBlockVoidDAOReviewNSErrorContinue)block
               andUpdateBlock:(nullable PTCLRatingBlockVoidDAOReviewNSError)updateBlock;

- (void)doLoadUserForObject:(nonnull DAORating*)rating
                  withBlock:(nullable PTCLRatingBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLRatingBlockVoidDAOUserNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForItem:(nonnull DAOItem*)item
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForLocation:(nonnull DAOLocation*)location
                  withParameters:(nullable NSDictionary*)parameters
                        andBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForReview:(nonnull DAOReview*)review
                withParameters:(nullable NSDictionary*)parameters
                      andBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLRatingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLRating_Protocol_h */
