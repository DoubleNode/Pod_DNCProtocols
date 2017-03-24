//
//  PTCLMessage_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOMessage;

typedef void(^PTCLMessageContinueBlock)();

typedef void(^PTCLMessageBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLMessageBlockVoidDAOMessageNSError)(DAOMessage* _Nullable message, NSError* _Nullable error);

typedef void(^PTCLMessageBlockVoidDAOMessageNSErrorContinue)(DAOMessage* _Nullable message, NSError* _Nullable error, PTCLMessageContinueBlock _Nullable continueBlock);

@protocol PTCLMessage_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLMessage_Protocol> _Nullable    nextMessageWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLMessage_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)messageId
                withBlock:(nullable PTCLMessageBlockVoidDAOMessageNSErrorContinue)block
           andUpdateBlock:(nullable PTCLMessageBlockVoidDAOMessageNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOMessage*)message
             withBlock:(nullable PTCLMessageBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOMessage*)message
           withBlock:(nullable PTCLMessageBlockVoidDAOMessageNSError)block;

@end
