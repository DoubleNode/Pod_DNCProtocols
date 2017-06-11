//
//  PTCLLocation_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLLocation_Protocol_h
#define PTCLLocation_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOCategory;
@class DAOFlag;
@class DAOItem;
@class DAOLocation;
@class DAOPhoto;
@class DAOUser;

typedef void(^PTCLLocationContinueBlock)(void);

typedef void(^PTCLLocationBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLLocationBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLLocationBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLLocationBlockVoidDAOLocationNSError)(DAOLocation* _Nullable location, NSError* _Nullable error);
typedef void(^PTCLLocationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLLocationBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLLocationSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSString* _Nonnull searchId, NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLLocationBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLLocationBlockVoidDAOLocationNSErrorContinue)(DAOLocation* _Nullable location, NSError* _Nullable error, PTCLLocationContinueBlock _Nullable continueBlock);
typedef void(^PTCLLocationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLocationContinueBlock _Nullable continueBlock);
typedef void(^PTCLLocationBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLocationContinueBlock _Nullable continueBlock);
typedef void(^PTCLLocationSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSString* _Nonnull searchId, NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLocationContinueBlock _Nullable continueBlock);
typedef void(^PTCLLocationBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLocationContinueBlock _Nullable continueBlock);

typedef void(^PTCLLocationBlockVoidDAOLocation)(DAOLocation* _Nullable location);

@protocol PTCLLocation_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLLocation_Protocol> _Nullable    nextLocationWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLLocation_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)locationId
                withBlock:(nullable PTCLLocationBlockVoidDAOLocationNSErrorContinue)block
           andUpdateBlock:(nullable PTCLLocationBlockVoidDAOLocationNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOLocation*)location
             withBlock:(nullable PTCLLocationBlockVoidBOOLNSError)block;

- (void)doDeleteObject:(nonnull DAOLocation*)location
          fromCategory:(nonnull DAOCategory*)category
             withBlock:(nullable PTCLLocationBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOLocation*)location
           withBlock:(nullable PTCLLocationBlockVoidDAOLocationNSError)block;

- (void)doSaveObject:(nonnull DAOLocation*)location
          inCategory:(nonnull DAOCategory*)category
           withBlock:(nullable PTCLLocationBlockVoidDAOLocationNSError)block;

- (void)doSaveObjectOptions:(nonnull DAOLocation*)location
                  withBlock:(nullable PTCLLocationBlockVoidBOOLNSError)block;

- (void)doSaveOption:(nonnull NSString*)optionId
              andKey:(nonnull NSString*)optionKey
            andValue:(nullable id)optionValue
         forLocation:(nonnull DAOLocation*)daoLocation
           withBlock:(nullable PTCLLocationBlockVoidBOOLNSError)block;

- (void)doFlagObject:(nonnull DAOLocation*)location
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLLocationBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOLocation*)location
             forUser:(nullable DAOUser*)flaggingUser
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLLocationBlockVoidNSError)block;

- (void)doDeleteFlag:(nonnull DAOFlag*)flag
           forObject:(nonnull DAOLocation*)location
           withBlock:(nullable PTCLLocationBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOLocation*)location
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
              andBlock:(nullable PTCLLocationBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOLocation*)location
               withAction:(nonnull NSString*)action
                 andBlock:(nullable PTCLLocationBlockVoidNSUIntegerNSError)block;

- (void)doFollowObject:(nonnull DAOLocation*)location
             withBlock:(nullable PTCLLocationBlockVoidNSError)block;

- (void)doUnfollowObject:(nonnull DAOLocation*)location
               withBlock:(nullable PTCLLocationBlockVoidNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadFlagsForObject:(nonnull DAOLocation*)location
                 withActions:(nonnull NSArray<NSString*>*)actions
                    andBlock:(nullable PTCLLocationBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLLocationBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAOLocation*)location
                   withActions:(nonnull NSArray<NSString*>*)actions
                      andBlock:(nullable PTCLLocationBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLLocationBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadItemsForObject:(nonnull DAOLocation*)location
                   withBlock:(nullable PTCLLocationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLLocationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadPhotosForObject:(nonnull DAOLocation*)location
                   withBlock:(nullable PTCLLocationBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLLocationBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjects:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
        withLongitude:(nullable NSNumber*)longitude
         withLatitude:(nullable NSNumber*)latitude
       withParameters:(nullable NSDictionary*)parameters
             andBlock:(nullable PTCLLocationSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
       andUpdateBlock:(nullable PTCLLocationSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLLocation_Protocol_h */
