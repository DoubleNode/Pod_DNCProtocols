//
//  PTCLActivity_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLActivity_Protocol_h
#define PTCLActivity_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOActivity;
@class DAOFlag;
@class DAOItem;
@class DAOLocation;
@class DAOPhoto;
@class DAORating;
@class DAOUser;

typedef void(^PTCLActivityContinueBlock)(void);

typedef void(^PTCLActivityBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidBOOLNSError)(BOOL, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLActivityBlockVoidDAOActivityNSError)(DAOActivity* _Nullable activity, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidDAOLocationNSError)(DAOLocation* _Nullable location, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidDAOPhotoNSError)(DAOPhoto* _Nullable photo, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOActivity* >* _Nullable activities, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLActivityBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLActivityBlockVoidDAOActivityNSErrorContinue)(DAOActivity* _Nullable activity, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);
typedef void(^PTCLActivityBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);
typedef void(^PTCLActivityBlockVoidDAOLocationNSErrorContinue)(DAOLocation* _Nullable location, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);
typedef void(^PTCLActivityBlockVoidDAOPhotoNSErrorContinue)(DAOPhoto* _Nullable photo, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);
typedef void(^PTCLActivityBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);
typedef void(^PTCLActivityBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOActivity* >* _Nullable activities, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);
typedef void(^PTCLActivityBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLActivityContinueBlock _Nullable continueBlock);

@protocol PTCLActivity_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLActivity_Protocol> _Nullable    nextActivityWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLActivity_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)activityId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLActivityBlockVoidDAOActivityNSErrorContinue)block
           andUpdateBlock:(nullable PTCLActivityBlockVoidDAOActivityNSError)updateBlock;

- (void)doFavoriteObject:(nonnull DAOActivity*)activity
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLActivityBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAOActivity*)activity
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLActivityBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOActivity*)activity
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLActivityBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOActivity*)activity
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
           andProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLActivityBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOActivity*)activity
               withAction:(nonnull NSString*)action
              andProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLActivityBlockVoidNSUIntegerNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemForObject:(nullable DAOActivity*)activity
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLActivityBlockVoidDAOItemNSErrorContinue)block
             andUpdateBlock:(nullable PTCLActivityBlockVoidDAOItemNSError)updateBlock;

- (void)doLoadLocationForObject:(nullable DAOActivity*)activity
                   withProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLActivityBlockVoidDAOLocationNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLActivityBlockVoidDAOLocationNSError)updateBlock;

- (void)doLoadPhotoForObject:(nullable DAOActivity*)activity
                withProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLActivityBlockVoidDAOPhotoNSErrorContinue)block
              andUpdateBlock:(nullable PTCLActivityBlockVoidDAOPhotoNSError)updateBlock;

- (void)doLoadUserForObject:(nullable DAOActivity*)activity
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLActivityBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLActivityBlockVoidDAOUserNSError)updateBlock;

- (void)doLoadUserAvatarForObject:(nullable DAOActivity*)activity
                     withProgress:(nullable PTCLProgressBlock)progressBlock
                         andBlock:(nullable PTCLActivityBlockVoidDAOPhotoNSErrorContinue)block
                   andUpdateBlock:(nullable PTCLActivityBlockVoidDAOPhotoNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadFlagsForObject:(nullable DAOActivity*)activity
                 withActions:(nonnull NSArray<NSString*>*)actions
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLActivityBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLActivityBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nullable DAOActivity*)activity
                   withActions:(nonnull NSArray<NSString*>*)actions
                   andProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLActivityBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLActivityBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsWithParameters:(nullable NSDictionary*)parameters
                        andProgress:(nullable PTCLProgressBlock)progressBlock
                           andBlock:(nullable PTCLActivityBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
                     andUpdateBlock:(nullable PTCLActivityBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLActivityBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLActivityBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLActivity_Protocol_h */
