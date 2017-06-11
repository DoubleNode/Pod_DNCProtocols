//
//  PTCLConversation_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOCategory;
@class DAOConversation;
@class DAOItem;
@class DAOLocation;
@class DAOMessage;
@class DAOUser;

typedef void(^PTCLConversationContinueBlock)(void);

typedef void(^PTCLConversationBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidDAOConversationNSError)(DAOConversation* _Nullable conversation, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidDAOConversationNSErrorContinue)(DAOConversation* _Nullable conversation, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);

typedef void(^PTCLConversationBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSError)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidNSArrayDAOMessageNSUIntegerNSUIntegerNSError)(NSArray<DAOMessage* >* _Nullable messages, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSError)(NSArray<DAOUser* >* _Nullable users, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLConversationBlockVoidNSArrayDAOConversationNSUIntegerNSUIntegerNSError)(NSArray<DAOConversation* >* _Nullable conversations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLConversationBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);
typedef void(^PTCLConversationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOItem* >* _Nullable items, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);
typedef void(^PTCLConversationBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);
typedef void(^PTCLConversationBlockVoidNSArrayDAOMessageNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOMessage* >* _Nullable messages, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);
typedef void(^PTCLConversationBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOUser* >* _Nullable users, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);
typedef void(^PTCLConversationBlockVoidNSArrayDAOConversationNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOConversation* >* _Nullable conversations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLConversationContinueBlock _Nullable continueBlock);

@protocol PTCLConversation_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLConversation_Protocol> _Nullable    nextConversationWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLConversation_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)conversationId
                withBlock:(nullable PTCLConversationBlockVoidDAOConversationNSErrorContinue)block
           andUpdateBlock:(nullable PTCLConversationBlockVoidDAOConversationNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOConversation*)conversation
             withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOConversation*)conversation
           withBlock:(nullable PTCLConversationBlockVoidDAOConversationNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doAddCategory:(nonnull DAOCategory*)category
             toObject:(nonnull DAOConversation*)conversation
            withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doAddItem:(nonnull DAOItem*)item
         toObject:(nonnull DAOConversation*)conversation
        withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doAddLocation:(nonnull DAOLocation*)location
             toObject:(nonnull DAOConversation*)conversation
            withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doAddUser:(nonnull DAOUser*)user
         toObject:(nonnull DAOConversation*)conversation
        withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doRemoveCategory:(nonnull DAOCategory*)category
              fromObject:(nonnull DAOConversation*)conversation
               withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doRemoveItem:(nonnull DAOItem*)item
          fromObject:(nonnull DAOConversation*)conversation
           withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doRemoveLocation:(nonnull DAOLocation*)location
              fromObject:(nonnull DAOConversation*)conversation
               withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

- (void)doRemoveUser:(nonnull DAOUser*)user
          fromObject:(nonnull DAOConversation*)conversation
           withBlock:(nullable PTCLConversationBlockVoidBOOLNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadCategoriesForObject:(nonnull DAOConversation*)conversation
                        withBlock:(nullable PTCLConversationBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSErrorContinue)block
                   andUpdateBlock:(nullable PTCLConversationBlockVoidNSArrayDAOCategoryNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadItemsForObject:(nonnull DAOConversation*)conversation
                   withBlock:(nullable PTCLConversationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLConversationBlockVoidNSArrayDAOItemNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadLocationsForObject:(nonnull DAOConversation*)conversation
                       withBlock:(nullable PTCLConversationBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLConversationBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMessagesForObject:(nonnull DAOConversation*)conversation
                      withBlock:(nullable PTCLConversationBlockVoidNSArrayDAOMessageNSUIntegerNSUIntegerNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLConversationBlockVoidNSArrayDAOMessageNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadUsersForObject:(nonnull DAOConversation*)conversation
                   withBlock:(nullable PTCLConversationBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLConversationBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsWithBlock:(nullable PTCLConversationBlockVoidNSArrayDAOConversationNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLConversationBlockVoidNSArrayDAOConversationNSUIntegerNSUIntegerNSError)updateBlock;

@end
