//
//  PTCLUserDevice_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

@class DAOUser;
@class DAOUserDevice;

typedef void(^PTCLUserDeviceContinueBlock)();

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
                withBlock:(nullable PTCLUserDeviceBlockVoidDAOUserDeviceNSErrorContinue)block
           andUpdateBlock:(nullable PTCLUserDeviceBlockVoidDAOUserDeviceNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOUserDevice*)userDevice
             withBlock:(nullable PTCLUserDeviceBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)userDeviceId
                  andUserId:(nonnull NSString*)userId
                  withBlock:(nullable PTCLUserDeviceBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOUserDevice*)userDevice
           withBlock:(nullable PTCLUserDeviceBlockVoidBOOLNSError)block;

// Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLUserDeviceBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserDeviceBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end
