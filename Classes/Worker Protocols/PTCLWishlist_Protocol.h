//
//  PTCLWishlist_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLWishlist_Protocol_h
#define PTCLWishlist_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOItem;
@class DAOWishlist;
@class DAOUser;

typedef void(^PTCLWishlistContinueBlock)(void);

typedef void(^PTCLWishlistBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLWishlistBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLWishlistBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLWishlistBlockVoidDAOWishlistNSError)(DAOWishlist* _Nullable wishlist, NSError* _Nullable error);
typedef void(^PTCLWishlistBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOWishlist* >* _Nullable wishlists, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLWishlistBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLWishlistContinueBlock _Nullable continueBlock);
typedef void(^PTCLWishlistBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLWishlistContinueBlock _Nullable continueBlock);
typedef void(^PTCLWishlistBlockVoidDAOWishlistNSErrorContinue)(DAOWishlist* _Nullable wishlist, NSError* _Nullable error, PTCLWishlistContinueBlock _Nullable continueBlock);
typedef void(^PTCLWishlistBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOWishlist* >* _Nullable wishlists, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLWishlistContinueBlock _Nullable continueBlock);

@protocol PTCLWishlist_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLWishlist_Protocol> _Nullable    nextWishlistWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLWishlist_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)wishlistId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLWishlistBlockVoidDAOWishlistNSErrorContinue)block
           andUpdateBlock:(nullable PTCLWishlistBlockVoidDAOWishlistNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOWishlist*)wishlist
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLWishlistBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)wishlistId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLWishlistBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForItem:(nonnull DAOItem*)item
                 withProgress:(nullable PTCLProgressBlock)progressBlock
                     andBlock:(nullable PTCLWishlistBlockVoidBOOLNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemForObject:(nonnull DAOWishlist*)wishlist
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLWishlistBlockVoidDAOItemNSErrorContinue)block
             andUpdateBlock:(nullable PTCLWishlistBlockVoidDAOItemNSError)updateBlock;

- (void)doLoadUserForObject:(nonnull DAOWishlist*)wishlist
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLWishlistBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLWishlistBlockVoidDAOUserNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLWishlistBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLWishlistBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLWishlist_Protocol_h */
