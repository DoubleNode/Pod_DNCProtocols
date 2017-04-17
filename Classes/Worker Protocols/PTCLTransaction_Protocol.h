//
//  PTCLTransaction_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOTransaction;
@class DAOUser;

typedef void(^PTCLTransactionContinueBlock)();

typedef void(^PTCLTransactionBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLTransactionBlockVoidDAOTransactionNSError)(DAOTransaction* _Nullable transaction, NSError* _Nullable error);
typedef void(^PTCLTransactionBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSError)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLTransactionBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSError)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLTransactionBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSError)(NSArray<DAOTransaction* >* _Nullable transmissions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLTransactionBlockVoidDAOTransactionNSErrorContinue)(DAOTransaction* _Nullable transaction, NSError* _Nullable error, PTCLTransactionContinueBlock _Nullable continueBlock);
typedef void(^PTCLTransactionBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLTransactionContinueBlock _Nullable continueBlock);
typedef void(^PTCLTransactionBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLTransactionContinueBlock _Nullable continueBlock);
typedef void(^PTCLTransactionBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLTransactionContinueBlock _Nullable continueBlock);

@protocol PTCLTransaction_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLTransaction_Protocol> _Nullable    nextTransactionWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLTransaction_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)transactionId
                withBlock:(nullable PTCLTransactionBlockVoidDAOTransactionNSErrorContinue)block
           andUpdateBlock:(nullable PTCLTransactionBlockVoidDAOTransactionNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOTransaction*)transaction
             withBlock:(nullable PTCLTransactionBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOTransaction*)transaction
           withBlock:(nullable PTCLTransactionBlockVoidDAOTransactionNSError)block;

@end
