//
//  PTCLNotification_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#pragma once

#import "__PTCLBase_Protocol.h"

@class DAONotification;
@class DAOTransmission;
@class DAOUser;

typedef void(^PTCLNotificationContinueBlock)(void);

typedef void(^PTCLNotificationBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLNotificationBlockVoidDAONotificationNSError)(DAONotification* _Nullable notification, NSError* _Nullable error);
typedef void(^PTCLNotificationBlockVoidNSArrayDAONotificationNSUIntegerNSUIntegerNSError)(NSArray<DAONotification* >* _Nullable notifications, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLNotificationBlockVoidNSArrayDAOTransmissionNSUIntegerNSUIntegerNSError)(NSArray<DAOTransmission* >* _Nullable transmissions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLNotificationBlockVoidDAONotificationNSErrorContinue)(DAONotification* _Nullable notification, NSError* _Nullable error, PTCLNotificationContinueBlock _Nullable continueBlock);
typedef void(^PTCLNotificationBlockVoidNSArrayDAONotificationNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAONotification* >* _Nullable notifications, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLNotificationContinueBlock _Nullable continueBlock);
typedef void(^PTCLNotificationBlockVoidNSArrayDAOTransmissionNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOTransmission* >* _Nullable transmissions, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLNotificationContinueBlock _Nullable continueBlock);

@protocol PTCLNotification_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLNotification_Protocol> _Nullable    nextNotificationWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLNotification_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)notificationId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLNotificationBlockVoidDAONotificationNSErrorContinue)block
           andUpdateBlock:(nullable PTCLNotificationBlockVoidDAONotificationNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAONotification*)notification
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLNotificationBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAONotification*)notification
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLNotificationBlockVoidDAONotificationNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadTransmissionsForObject:(nonnull DAONotification*)notification
                        withProgress:(nullable PTCLProgressBlock)progressBlock
                            andBlock:(nullable PTCLNotificationBlockVoidNSArrayDAOTransmissionNSUIntegerNSUIntegerNSErrorContinue)block
                      andUpdateBlock:(nullable PTCLNotificationBlockVoidNSArrayDAOTransmissionNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLNotificationBlockVoidNSArrayDAONotificationNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLNotificationBlockVoidNSArrayDAONotificationNSUIntegerNSUIntegerNSError)updateBlock;

@end
