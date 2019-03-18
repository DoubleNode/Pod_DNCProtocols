//
//  PTCLFavorite_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLFavorite_Protocol_h
#define PTCLFavorite_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOItem;
@class DAOFavorite;
@class DAOUser;

typedef void(^PTCLFavoriteContinueBlock)(void);

typedef void(^PTCLFavoriteBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLFavoriteBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLFavoriteBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLFavoriteBlockVoidDAOFavoriteNSError)(DAOFavorite* _Nullable favorite, NSError* _Nullable error);
typedef void(^PTCLFavoriteBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOFavorite* >* _Nullable favorites, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLFavoriteBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLFavoriteContinueBlock _Nullable continueBlock);
typedef void(^PTCLFavoriteBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLFavoriteContinueBlock _Nullable continueBlock);
typedef void(^PTCLFavoriteBlockVoidDAOFavoriteNSErrorContinue)(DAOFavorite* _Nullable favorite, NSError* _Nullable error, PTCLFavoriteContinueBlock _Nullable continueBlock);
typedef void(^PTCLFavoriteBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFavorite* >* _Nullable favorites, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLFavoriteContinueBlock _Nullable continueBlock);

@protocol PTCLFavorite_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLFavorite_Protocol> _Nullable    nextFavoriteWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLFavorite_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)favoriteId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLFavoriteBlockVoidDAOFavoriteNSErrorContinue)block
           andUpdateBlock:(nullable PTCLFavoriteBlockVoidDAOFavoriteNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOFavorite*)favorite
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLFavoriteBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)favoriteId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLFavoriteBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForItem:(nonnull DAOItem*)item
                 withProgress:(nullable PTCLProgressBlock)progressBlock
                     andBlock:(nullable PTCLFavoriteBlockVoidBOOLNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemForObject:(nonnull DAOFavorite*)favorite
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLFavoriteBlockVoidDAOItemNSErrorContinue)block
             andUpdateBlock:(nullable PTCLFavoriteBlockVoidDAOItemNSError)updateBlock;

- (void)doLoadUserForObject:(nonnull DAOFavorite*)favorite
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLFavoriteBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLFavoriteBlockVoidDAOUserNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLFavoriteBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLFavoriteBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLFavorite_Protocol_h */
