//
//  PTCLUserDevice_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLUserDevice_Protocol_h
#define PTCLUserDevice_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOUser;
@class DAOUserDevice;

typedef void(^PTCLUserDeviceContinueBlock)(void);

typedef void(^PTCLUserDeviceBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLUserDeviceBlockVoidDAOUserDeviceNSError)(DAOUserDevice* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLUserDeviceBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOUserDevice* >* _Nullable userDevices, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLUserDeviceBlockVoidDAOUserDeviceNSErrorContinue)(DAOUserDevice* _Nullable user, NSError* _Nullable error, PTCLUserDeviceContinueBlock _Nullable continueBlock);
typedef void(^PTCLUserDeviceBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOUserDevice* >* _Nullable userDevices, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLUserDeviceContinueBlock _Nullable continueBlock);

@protocol PTCLUserDevice_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLUserDevice_Protocol> _Nullable    nextUserDeviceWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLUserDevice_Protocol>)nextUserDeviceWorker;

// Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)userDeviceId
                andUserId:(nonnull NSString*)userId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLUserDeviceBlockVoidDAOUserDeviceNSErrorContinue)block
           andUpdateBlock:(nullable PTCLUserDeviceBlockVoidDAOUserDeviceNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOUserDevice*)userDevice
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLUserDeviceBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)userDeviceId
                  andUserId:(nonnull NSString*)userId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLUserDeviceBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOUserDevice*)userDevice
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserDeviceBlockVoidBOOLNSError)block;

// Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLUserDeviceBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserDeviceBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLUserDevice_Protocol_h */
