//
//  PTCLItem_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLItem_Protocol_h
#define PTCLItem_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOCategory;
@class DAOFlag;
@class DAOItem;
@class DAOLocation;
@class DAOPhoto;
@class DAOUser;

typedef void(^PTCLItemContinueBlock)(void);

typedef void(^PTCLItemBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLItemBlockVoidDAOItemNSError)(DAOItem* _Nullable item, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)(NSArray<NSString* >* _Nullable tags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSString* _Nonnull searchId, NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLItemBlockVoidDAOItemNSErrorContinue)(DAOItem* _Nullable item, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOPhoto* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)(NSArray<NSString* >* _Nullable tags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);
typedef void(^PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSString* _Nonnull searchId, NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLItemContinueBlock _Nullable continueBlock);

@protocol PTCLItem_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLItem_Protocol> _Nullable    nextItemWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLItem_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)itemId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLItemBlockVoidDAOItemNSErrorContinue)block
           andUpdateBlock:(nullable PTCLItemBlockVoidDAOItemNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOItem*)item
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doDeleteObject:(nonnull DAOItem*)item
          fromCategory:(nonnull DAOCategory*)category
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doDeleteObject:(nonnull DAOItem*)item
          fromLocation:(nonnull DAOLocation*)location
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOItem*)item
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidDAOItemNSError)block;

- (void)doSaveObject:(nonnull DAOItem*)item
          inCategory:(nonnull DAOCategory*)category
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidDAOItemNSError)block;

- (void)doSaveObject:(nonnull DAOItem*)item
          inLocation:(nonnull DAOLocation*)location
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidDAOItemNSError)block;

- (void)doSaveObjectOptions:(nonnull DAOItem*)item
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doSaveOption:(nonnull NSString*)optionId
              andKey:(nonnull NSString*)optionKey
            andValue:(nullable id)optionValue
             forItem:(nonnull DAOItem*)daoItem
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidBOOLNSError)block;

- (void)doFavoriteObject:(nonnull DAOItem*)item
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAOItem*)item
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOItem*)item
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOItem*)item
             forUser:(nullable DAOUser*)flaggingUser
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doDeleteFlag:(nonnull DAOFlag*)flag
           forObject:(nonnull DAOItem*)item
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOItem*)item
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
           andProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOItem*)item
               withAction:(nonnull NSString*)action
              andProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLItemBlockVoidNSUIntegerNSError)block;

- (void)doSaveFlag:(nonnull DAOFlag*)flag
      withProgress:(nullable PTCLProgressBlock)progressBlock
          andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doTagObject:(nonnull DAOItem*)item
            withTag:(nonnull NSString*)tag
        andProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doUntagObject:(nonnull DAOItem*)item
              withTag:(nonnull NSString*)tag
          andProgress:(nullable PTCLProgressBlock)progressBlock
             andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doWishlistObject:(nonnull DAOItem*)item
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLItemBlockVoidNSError)block;

- (void)doUnwishlistObject:(nonnull DAOItem*)item
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLItemBlockVoidNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadFlagsForObject:(nonnull DAOItem*)item
                 withActions:(nonnull NSArray<NSString*>*)actions
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLItemBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAOItem*)item
                   withActions:(nonnull NSArray<NSString*>*)actions
                   andProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLItemBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadLocationsForObject:(nonnull DAOItem*)item
                    withProgress:(nullable PTCLProgressBlock)progressBlock
                        andBlock:(nullable PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadPhotosForObject:(nonnull DAOItem*)item
                 withProgress:(nullable PTCLProgressBlock)progressBlock
                     andBlock:(nullable PTCLItemBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)block
               andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadTagsForObject:(nonnull DAOItem*)item
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLItemBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)block
             andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjects:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
       withParameters:(nullable NSDictionary*)parameters
          andProgress:(nullable PTCLProgressBlock)progressBlock
             andBlock:(nullable PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
       andUpdateBlock:(nullable PTCLItemBlockVoidNSStringNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsWithTag:(nonnull NSString*)tag
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLItemBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLItemBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLItem_Protocol_h */
