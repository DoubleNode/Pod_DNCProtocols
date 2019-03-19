//
//  PTCLOrder_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOLineitem;
@class DAOOrder;
@class DAOTransaction;
@class DAOUser;

typedef void(^PTCLOrderContinueBlock)(void);

typedef void(^PTCLOrderBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLOrderBlockVoidDAOOrderNSError)(DAOOrder* _Nullable order, NSError* _Nullable error);
typedef void(^PTCLOrderBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSError)(NSArray<DAOLineitem* >* _Nullable lineitems, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLOrderBlockVoidNSArrayDAOOrderNSUIntegerNSUIntegerNSError)(NSArray<DAOOrder* >* _Nullable orders, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLOrderBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSError)(NSArray<DAOTransaction* >* _Nullable transmissions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLOrderBlockVoidDAOOrderNSErrorContinue)(DAOOrder* _Nullable order, NSError* _Nullable error, PTCLOrderContinueBlock _Nullable continueBlock);
typedef void(^PTCLOrderBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLineitem* >* _Nullable lineitems, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLOrderContinueBlock _Nullable continueBlock);
typedef void(^PTCLOrderBlockVoidNSArrayDAOOrderNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOOrder* >* _Nullable orders, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLOrderContinueBlock _Nullable continueBlock);
typedef void(^PTCLOrderBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLOrderContinueBlock _Nullable continueBlock);

@protocol PTCLOrder_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLOrder_Protocol> _Nullable    nextOrderWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLOrder_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)orderId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLOrderBlockVoidDAOOrderNSErrorContinue)block
           andUpdateBlock:(nullable PTCLOrderBlockVoidDAOOrderNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOOrder*)order
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLOrderBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOOrder*)order
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLOrderBlockVoidDAOOrderNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadLineitemsForObject:(nonnull DAOOrder*)order
                    withProgress:(nullable PTCLProgressBlock)progressBlock
                        andBlock:(nullable PTCLOrderBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLOrderBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadTransactionsForObject:(nonnull DAOOrder*)order
                       withProgress:(nullable PTCLProgressBlock)progressBlock
                           andBlock:(nullable PTCLOrderBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSErrorContinue)block
                     andUpdateBlock:(nullable PTCLOrderBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSError)updateBlock;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForLocation:(nonnull DAOLocation*)location
                  withParameters:(nullable NSDictionary*)parameters
                     andProgress:(nullable PTCLProgressBlock)progressBlock
                        andBlock:(nullable PTCLOrderBlockVoidNSArrayDAOOrderNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLOrderBlockVoidNSArrayDAOOrderNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLOrderBlockVoidNSArrayDAOOrderNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLOrderBlockVoidNSArrayDAOOrderNSUIntegerNSUIntegerNSError)updateBlock;

@end
