//
//  PTCLUserNotificationSetting_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLUserNotificationSetting_Protocol_h
#define PTCLUserNotificationSetting_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOUser;
@class DAOUserNotificationSetting;

typedef void(^PTCLUserNotificationSettingContinueBlock)(void);

typedef void(^PTCLUserNotificationSettingBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLUserNotificationSettingBlockVoidDAOUserNotificationSettingNSError)(DAOUserNotificationSetting* _Nullable user, NSError* _Nullable error);
typedef void(^PTCLUserNotificationSettingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOUserNotificationSetting* >* _Nullable userDevices, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLUserNotificationSettingBlockVoidDAOUserNotificationSettingNSErrorContinue)(DAOUserNotificationSetting* _Nullable user, NSError* _Nullable error, PTCLUserNotificationSettingContinueBlock _Nullable continueBlock);
typedef void(^PTCLUserNotificationSettingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOUserNotificationSetting* >* _Nullable userDevices, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLUserNotificationSettingContinueBlock _Nullable continueBlock);

@protocol PTCLUserNotificationSetting_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLUserNotificationSetting_Protocol> _Nullable    nextUserNotificationSettingWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLUserNotificationSetting_Protocol>)nextUserNotificationSettingWorker;

// Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)userNotificationSettingId
                andUserId:(nonnull NSString*)userId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLUserNotificationSettingBlockVoidDAOUserNotificationSettingNSErrorContinue)block
           andUpdateBlock:(nullable PTCLUserNotificationSettingBlockVoidDAOUserNotificationSettingNSError)updateBlock;

- (void)doSaveObject:(nonnull DAOUserNotificationSetting*)userNotificationSetting
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserNotificationSettingBlockVoidBOOLNSError)block;

// Collection Items CRUD

- (void)doLoadObjectsForUser:(nonnull DAOUser*)user
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLUserNotificationSettingBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserNotificationSettingBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLUserNotificationSetting_Protocol_h */
