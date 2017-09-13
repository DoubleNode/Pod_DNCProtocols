//
//  PTCLCategory_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLCategory_Protocol_h
#define PTCLCategory_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOCategory;
@class DAOFlag;
@class DAOItem;
@class DAOPhoto;
@class DAOUser;

typedef void(^PTCLCategoryContinueBlock)(void);

typedef void(^PTCLCategoryBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLCategoryBlockVoidDAOCategoryNSError)(DAOCategory* _Nullable category, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSError)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)(NSArray<NSString* >* _Nullable tags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSString* _Nonnull searchId, NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
 
typedef void(^PTCLCategoryBlockVoidDAOCategoryNSErrorContinue)(DAOCategory* _Nullable category, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)(NSArray<NSString* >* _Nullable tags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSString* _Nonnull searchId, NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);

typedef void(^PTCLCategoryBlockVoidDAOLocation)(DAOCategory* _Nullable category);
typedef void(^PTCLCategoryBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

@protocol PTCLCategory_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLCategory_Protocol> _Nullable nextCategoryWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLCategory_Protocol>)nextCategoryWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)categoryId
                withBlock:(nullable PTCLCategoryBlockVoidDAOCategoryNSErrorContinue)block
           andUpdateBlock:(nullable PTCLCategoryBlockVoidDAOCategoryNSError)updateBlock;

- (void)doSaveObject:(nonnull DAOCategory*)category
           withBlock:(nullable PTCLCategoryBlockVoidDAOCategoryNSError)block;

- (void)doSaveObjectOptions:(nonnull DAOCategory*)category
                  withBlock:(nullable PTCLCategoryBlockVoidBOOLNSError)block;

- (void)doSaveOption:(nonnull NSString*)optionId
              andKey:(nonnull NSString*)optionKey
            andValue:(nullable id)optionValue
         forCategory:(nonnull DAOCategory*)daoCategory
           withBlock:(nullable PTCLCategoryBlockVoidBOOLNSError)block;

- (void)doFlagObject:(nonnull DAOCategory*)category
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOCategory*)category
             forUser:(nullable DAOUser*)flaggingUser
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doDeleteFlag:(nonnull DAOFlag*)flag
           forObject:(nonnull DAOCategory*)category
           withBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOCategory*)category
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
              andBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOCategory*)category
               withAction:(nonnull NSString*)action
                 andBlock:(nullable PTCLCategoryBlockVoidNSUIntegerNSError)block;

- (void)doFollowObject:(nonnull DAOCategory*)category
             withBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doUnfollowObject:(nonnull DAOCategory*)category
               withBlock:(nullable PTCLCategoryBlockVoidNSError)block;
  
- (void)doTagObject:(nonnull DAOCategory*)category
            withTag:(nonnull NSString*)tag
           andBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doUntagObject:(nonnull DAOCategory*)category
              withTag:(nonnull NSString*)tag
             andBlock:(nullable PTCLCategoryBlockVoidNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemsForObject:(nonnull DAOCategory*)category
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadPhotosForObject:(nonnull DAOCategory*)category
                    withBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)block
               andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadFlagsForObject:(nonnull DAOCategory*)category
                 withActions:(nonnull NSArray<NSString*>*)actions
                    andBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAOCategory*)category
                   withActions:(nonnull NSArray<NSString*>*)actions
                      andBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadTagsForObject:(nonnull DAOCategory*)category
                   andBlock:(nullable PTCLCategoryBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)block
             andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjects:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
        withLongitude:(nullable NSNumber*)longitude
         withLatitude:(nullable NSNumber*)latitude
       withParameters:(nullable NSDictionary*)parameters
             andBlock:(nullable PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
       andUpdateBlock:(nullable PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsWithTag:(nonnull NSString*)tag
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLCategory_Protocol_h */
