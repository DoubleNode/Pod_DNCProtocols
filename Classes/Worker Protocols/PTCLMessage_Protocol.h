//
//  PTCLMessage_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAOMessage;
@class DAOPhoto;

typedef void(^PTCLMessageContinueBlock)(void);

typedef void(^PTCLMessageBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLMessageBlockVoidDAOMessageNSError)(DAOMessage* _Nullable message, NSError* _Nullable error);
typedef void(^PTCLMessageBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLMessageBlockVoidDAOMessageNSErrorContinue)(DAOMessage* _Nullable message, NSError* _Nullable error, PTCLMessageContinueBlock _Nullable continueBlock);
typedef void(^PTCLMessageBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOPhoto* >* _Nullable photos, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLMessageContinueBlock _Nullable continueBlock);

@protocol PTCLMessage_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLMessage_Protocol> _Nullable    nextMessageWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLMessage_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)messageId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLMessageBlockVoidDAOMessageNSErrorContinue)block
           andUpdateBlock:(nullable PTCLMessageBlockVoidDAOMessageNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOMessage*)message
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLMessageBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOMessage*)message
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLMessageBlockVoidDAOMessageNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadPhotosForObject:(nonnull DAOMessage*)message
                 withProgress:(nullable PTCLProgressBlock)progressBlock
                     andBlock:(nullable PTCLMessageBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSErrorContinue)block
               andUpdateBlock:(nullable PTCLMessageBlockVoidNSArrayDAOPhotoNSUIntegerNSUIntegerNSError)updateBlock;

@end
