//
//  PTCLCheckin_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLCheckin_Protocol_h
#define PTCLCheckin_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOCheckin;
@class DAOLocation;
@class DAOPhoto;
@class DAOUser;

typedef void(^PTCLCheckinContinueBlock)(void);

typedef void(^PTCLCheckinBlockVoidNSError)(NSError* _Nullable error);

typedef void(^PTCLCheckinBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);

typedef void(^PTCLCheckinBlockVoidDAOLocationNSError)(DAOLocation* _Nullable location, NSError* _Nullable error);
typedef void(^PTCLCheckinBlockVoidDAOCheckinNSError)(DAOCheckin* _Nullable checkin, NSError* _Nullable error);
typedef void(^PTCLCheckinBlockVoidDAOPhotoNSError)(DAOPhoto* _Nullable photo, NSError* _Nullable error);
typedef void(^PTCLCheckinBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);

typedef void(^PTCLCheckinBlockVoidDAOLocationNSErrorContinue)(DAOLocation* _Nullable location, NSError* _Nullable error, PTCLCheckinContinueBlock _Nullable continueBlock);
typedef void(^PTCLCheckinBlockVoidDAOCheckinNSErrorContinue)(DAOCheckin* _Nullable checkin, NSError* _Nullable error, PTCLCheckinContinueBlock _Nullable continueBlock);
typedef void(^PTCLCheckinBlockVoidDAOPhotoNSErrorContinue)(DAOPhoto* _Nullable photo, NSError* _Nullable error, PTCLCheckinContinueBlock _Nullable continueBlock);
typedef void(^PTCLCheckinBlockVoidDAOUserNSErrorContinue)(DAOUser* _Nullable user, NSError* _Nullable error, PTCLCheckinContinueBlock _Nullable continueBlock);

@protocol PTCLCheckin_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLCheckin_Protocol> _Nullable    nextCheckinWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLCheckin_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)checkinId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLCheckinBlockVoidDAOCheckinNSErrorContinue)block
           andUpdateBlock:(nullable PTCLCheckinBlockVoidDAOCheckinNSError)updateBlock;

- (void)doDeleteObject:(nonnull DAOCheckin*)checkin
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLCheckinBlockVoidBOOLNSError)block;

- (void)doDeleteObjectForId:(nonnull NSString*)checkinId
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLCheckinBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOCheckin*)checkin
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLCheckinBlockVoidDAOCheckinNSError)block;

- (void)doFavoriteObject:(nonnull DAOCheckin*)checkin
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLCheckinBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAOCheckin*)checkin
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLCheckinBlockVoidNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadLocationForObject:(nonnull DAOCheckin*)checkin
                   withProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLCheckinBlockVoidDAOLocationNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLCheckinBlockVoidDAOLocationNSError)updateBlock;

- (void)doLoadPhotoForObject:(nonnull DAOCheckin*)checkin
                withProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLCheckinBlockVoidDAOPhotoNSErrorContinue)block
              andUpdateBlock:(nullable PTCLCheckinBlockVoidDAOPhotoNSError)updateBlock;

- (void)doLoadUserForObject:(nonnull DAOCheckin*)checkin
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLCheckinBlockVoidDAOUserNSErrorContinue)block
             andUpdateBlock:(nullable PTCLCheckinBlockVoidDAOUserNSError)updateBlock;

@end

#endif /* PTCLCheckin_Protocol_h */
