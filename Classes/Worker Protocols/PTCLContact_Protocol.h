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
typedef void(^PTCLContactBlockVoidNSStringNSError)(NSString* _Nullable security, NSError* _Nullable error);
typedef void(^PTCLContactBlockVoidNSDictionaryNSError)(NSDictionary* _Nullable response, NSError* _Nullable error);

typedef void(^PTCLContactBlockVoidDAOContactNSError)(DAOContact* _Nullable contact, NSError* _Nullable error);
typedef void(^PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSError)(NSArray<DAOContact* >* _Nullable contacts, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLContactBlockVoidDAOContactNSErrorContinue)(DAOContact* _Nullable contact, NSError* _Nullable error, PTCLContactContinueBlock _Nullable continueBlock);
typedef void(^PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOContact* >* _Nullable contacts, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLContactContinueBlock _Nullable continueBlock);

@protocol PTCLContact_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLContact_Protocol> _Nullable    nextContactWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLContact_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item Security CRUD

- (void)doLoadSecurityForObject:(nonnull DAOContact*)contact
                   withProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLContactBlockVoidNSStringNSError)block;

- (void)doDeleteSecurityForObject:(nonnull DAOContact*)contact
                     withProgress:(nullable PTCLProgressBlock)progressBlock
                         andBlock:(nullable PTCLContactBlockVoidBOOLNSError)block;

- (void)doSaveSecurity:(nonnull NSString*)security
             forObject:(nonnull DAOContact*)contact
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLContactBlockVoidBOOLNSError)block;

- (void)doVerifySecurity:(nonnull NSString*)security
               forObject:(nonnull DAOContact*)contact
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLContactBlockVoidBOOLNSError)block;

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

- (void)doSendVerificationType:(nonnull NSString*)type
                     forObject:(nonnull DAOContact*)contact
                  withProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLContactBlockVoidNSDictionaryNSError)block;

- (void)doVerifyType:(nonnull NSString*)type
           forObject:(nonnull DAOContact*)contact
      withParameters:(nullable NSDictionary*)parameters
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLContactBlockVoidNSDictionaryNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLContactBlockVoidNSArrayDAOContactNSUIntegerNSUIntegerNSError)updateBlock;

@end
