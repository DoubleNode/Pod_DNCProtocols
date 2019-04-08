//
//  PTCLContact_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOContact;
@class DAOUser;

typedef void(^PTCLContactContinueBlock)(void);

typedef void(^PTCLContactBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLContactBlockVoidDAOContactNSError)(DAOContact* _Nullable contact, NSError* _Nullable error);
typedef void(^PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSError)(NSArray<DAOContact* >* _Nullable contacts, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLContactBlockVoidDAOContactNSErrorContinue)(DAOContact* _Nullable contact, NSError* _Nullable error, PTCLContactContinueBlock _Nullable continueBlock);
typedef void(^PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOContact* >* _Nullable contacts, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLContactContinueBlock _Nullable continueBlock);

@protocol PTCLContact_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLContact_Protocol> _Nullable    nextContactWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLContact_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)contactId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLContactBlockVoidDAOContactNSErrorContinue)block
           andUpdateBlock:(nullable PTCLContactBlockVoidDAOContactNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOContact*)contact
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLContactBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOContact*)contact
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLContactBlockVoidDAOContactNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSError)updateBlock;

@end
