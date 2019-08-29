//
//  PTCLLineitem_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOLineitem;
@class DAOTransaction;
@class DAOUser;

typedef void(^PTCLLineitemContinueBlock)(void);

typedef void(^PTCLLineitemBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLLineitemBlockVoidDAOLineitemNSError)(DAOLineitem* _Nullable lineitem, NSError* _Nullable error);
typedef void(^PTCLLineitemBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSError)(NSArray<DAOLineitem* >* _Nullable lineitems, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLLineitemBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSError)(NSArray<DAOLineitem* >* _Nullable lineitems, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLLineitemBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSError)(NSArray<DAOTransaction* >* _Nullable transmissions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLLineitemBlockVoidDAOLineitemNSErrorContinue)(DAOLineitem* _Nullable lineitem, NSError* _Nullable error, PTCLLineitemContinueBlock _Nullable continueBlock);
typedef void(^PTCLLineitemBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLineitem* >* _Nullable lineitems, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLineitemContinueBlock _Nullable continueBlock);
typedef void(^PTCLLineitemBlockVoidNSArrayDAOLineitemNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLineitem* >* _Nullable lineitems, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLineitemContinueBlock _Nullable continueBlock);
typedef void(^PTCLLineitemBlockVoidNSArrayDAOTransactionNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOTransaction* >* _Nullable transactions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLLineitemContinueBlock _Nullable continueBlock);

@protocol PTCLLineitem_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLLineitem_Protocol> _Nullable    nextLineitemWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLLineitem_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForOrderId:(nonnull NSString*)orderId
                         andId:(nonnull NSString*)lineitemId
                  withProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLLineitemBlockVoidDAOLineitemNSErrorContinue)block
                andUpdateBlock:(nullable PTCLLineitemBlockVoidDAOLineitemNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOLineitem*)lineitem
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLLineitemBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOLineitem*)lineitem
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLLineitemBlockVoidDAOLineitemNSError)block;

@end
