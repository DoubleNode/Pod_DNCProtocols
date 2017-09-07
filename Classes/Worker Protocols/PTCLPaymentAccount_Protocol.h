//
//  PTCLPaymentAccount_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOContact;
@class DAOPaymentAccount;
@class DAOUser;

typedef void(^PTCLPaymentAccountContinueBlock)(void);

typedef void(^PTCLPaymentAccountBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLPaymentAccountBlockVoidDAOContactNSError)(DAOContact* _Nullable contact, NSError* _Nullable error);
typedef void(^PTCLPaymentAccountBlockVoidDAOPaymentAccountNSError)(DAOPaymentAccount* _Nullable paymentAccount, NSError* _Nullable error);
typedef void(^PTCLPaymentAccountBlockVoidNSArrayDAOPaymentAccountNSUIntegerNSUIntegerNSError)(NSArray<DAOPaymentAccount* >* _Nullable paymentAccounts, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLPaymentAccountBlockVoidDAOContactNSErrorContinue)(DAOContact* _Nullable contact, NSError* _Nullable error, PTCLPaymentAccountContinueBlock _Nullable continueBlock);
typedef void(^PTCLPaymentAccountBlockVoidDAOPaymentAccountNSErrorContinue)(DAOPaymentAccount* _Nullable paymentAccount, NSError* _Nullable error, PTCLPaymentAccountContinueBlock _Nullable continueBlock);
typedef void(^PTCLPaymentAccountBlockVoidNSArrayDAOPaymentAccountNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOPaymentAccount* >* _Nullable paymentaccounts, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLPaymentAccountContinueBlock _Nullable continueBlock);

@protocol PTCLPaymentAccount_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLPaymentAccount_Protocol> _Nullable    nextPaymentAccountWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLPaymentAccount_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)paymentAccountId
                withBlock:(nullable PTCLPaymentAccountBlockVoidDAOPaymentAccountNSErrorContinue)block
           andUpdateBlock:(nullable PTCLPaymentAccountBlockVoidDAOPaymentAccountNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOPaymentAccount*)paymentAccount
             withBlock:(nullable PTCLPaymentAccountBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOPaymentAccount*)paymentAccount
           withBlock:(nullable PTCLPaymentAccountBlockVoidDAOPaymentAccountNSError)block;

- (void)doVerifyObject:(nonnull DAOPaymentAccount*)paymentAccount
          withDeposit1:(NSUInteger)deposit1
           andDeposit2:(NSUInteger)deposit2
              andBlock:(nullable PTCLPaymentAccountBlockVoidBOOLNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadContactForObject:(nonnull DAOPaymentAccount*)paymentAccount
                     withBlock:(nullable PTCLPaymentAccountBlockVoidDAOContactNSErrorContinue)block
                andUpdateBlock:(nullable PTCLPaymentAccountBlockVoidDAOContactNSError)updateBlock;

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLPaymentAccountBlockVoidNSArrayDAOPaymentAccountNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLPaymentAccountBlockVoidNSArrayDAOPaymentAccountNSUIntegerNSUIntegerNSError)updateBlock;

@end
