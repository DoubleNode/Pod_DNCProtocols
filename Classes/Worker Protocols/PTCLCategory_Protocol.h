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
@class DAOItem;
@class DAOPhoto;

typedef void(^PTCLCategoryContinueBlock)();

typedef void(^PTCLCategoryBlockVoidNSError)(NSError* _Nullable error);

typedef void(^PTCLCategoryBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidDAOCategoryNSError)(DAOCategory* _Nullable category, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSString* _Nonnull searchId, NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLCategoryBlockVoidDAOCategoryNSErrorContinue)(DAOCategory* _Nullable category, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
typedef void(^PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);
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

- (void)doFollowObject:(nonnull DAOCategory*)category
             withBlock:(nullable PTCLCategoryBlockVoidNSError)block;

- (void)doUnfollowObject:(nonnull DAOCategory*)category
               withBlock:(nullable PTCLCategoryBlockVoidNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadItemsForObject:(nonnull DAOCategory*)category
                   withBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadPhotosForObject:(nonnull DAOCategory*)category
                    withBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)block
               andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjects:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
        withLongitude:(nullable NSNumber*)longitude
         withLatitude:(nullable NSNumber*)latitude
       withParameters:(nullable NSDictionary*)parameters
             andBlock:(nullable PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
       andUpdateBlock:(nullable PTCLCategorySearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLCategory_Protocol_h */
