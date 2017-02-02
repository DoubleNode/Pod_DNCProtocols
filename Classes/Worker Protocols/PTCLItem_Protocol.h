//
//  PTCLItem_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLItem_Protocol_h
#define PTCLItem_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOItem;
@class DAOLocation;

typedef void(^PTCLItemContinueBlock)();

typedef void(^PTCLItemBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSString* _Nonnull searchId, NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLItemBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSString* _Nonnull searchId, NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);

@protocol PTCLItem_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLItem_Protocol> _Nullable    nextItemWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLItem_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)itemId
                withBlock:(nullable PTCLItemBlockVoidDAOItemNSErrorContinue)block
           andUpdateBlock:(nullable PTCLItemBlockVoidDAOItemNSError)updateBlock;

- (void)doSaveObject:(nonnull DAOItem*)item
           withBlock:(nullable PTCLItemBlockVoidDAOItemNSError)block;

- (void)doSaveObject:(nonnull DAOItem*)item
          inLocation:(nonnull DAOLocation*)location
           withBlock:(nullable PTCLItemBlockVoidDAOItemNSError)block;

- (void)doSaveObjectOptions:(nonnull DAOItem*)item
                  withBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doSaveOption:(nonnull NSString*)optionId
              andKey:(nonnull NSString*)optionKey
            andValue:(nullable id)optionValue
             forItem:(nonnull DAOItem*)daoItem
           withBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doFavoriteObject:(nonnull DAOItem*)item
               withBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAOItem*)item
                 withBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doWishlistObject:(nonnull DAOItem*)item
               withBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doUnwishlistObject:(nonnull DAOItem*)item
                 withBlock:(nullable PTCLItemBlockVoidNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadLocationsForObject:(nonnull DAOItem*)item
                       withBlock:(nullable PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjects:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
       withParameters:(nullable NSDictionary*)parameters
             andBlock:(nullable PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
       andUpdateBlock:(nullable PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLItem_Protocol_h */
