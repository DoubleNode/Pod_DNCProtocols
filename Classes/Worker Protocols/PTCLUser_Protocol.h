//
//  PTCLUser_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLUser_Protocol_h
#define PTCLUser_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOFlag;
@class DAOLocation;
@class DAOPhoto;
@class DAOUser;

typedef void(^PTCLUserContinueBlock)(void);

typedef void(^PTCLUserBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLUserBlockVoidDAOPhotoNSError)(DAOPhoto* _Nullable photo, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidDAOUser)(DAOUser* _Nullable user);
typedef void(^PTCLUserBlockVoidDAOUserBOOLNSError)(DAOUser* _Nullable user, BOOL success, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidDAOUserNSString)(DAOUser* _Nullable user, NSString* _Nullable accessToken);
typedef void(^PTCLUserBlockVoidDAOUserNSError)(DAOUser* _Nullable user, NSError* _Nullable error);

typedef void(^PTCLUserSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSString* _Nonnull searchId, NSArray<DAOUser* >* _Nullable users, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOUser* >* _Nullable users, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSError)(NSArray<DAOUser* >* _Nullable users, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLUserBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)(NSArray<NSString* >* _Nullable tags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLUserContinueBlock _Nullable continueBlock);
typedef void(^PTCLUserBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOLocation* >* _Nullable locations, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLUserContinueBlock _Nullable continueBlock);
typedef void(^PTCLUserBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOUser* >* _Nullable users, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLUserContinueBlock _Nullable continueBlock);
typedef void(^PTCLUserBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)(NSArray<NSString* >* _Nullable tags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLUserContinueBlock _Nullable continueBlock);

@protocol PTCLUser_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLUser_Protocol> _Nullable    nextUserWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLUser_Protocol>)nextUserWorker;

#pragma mark - Business Logic / Single Item CRUD

- (BOOL)doCheckForAccessTokenError:(nullable NSData*)errorData;
- (void)doCurrentAccessTokenWithProgress:(nullable PTCLProgressBlock)progressBlock
                                andBlock:(nullable PTCLUserBlockVoidDAOUserNSString)block;
- (void)doCurrentUserWithProgress:(nullable PTCLProgressBlock)progressBlock
                         andBlock:(nullable PTCLUserBlockVoidDAOUser)block;

- (void)doDeleteCurrentUserWithProgress:(nullable PTCLProgressBlock)progressBlock
                               andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;
- (void)doLogOut;

- (void)doValidateCurrentSessionWithProgress:(nullable PTCLProgressBlock)progressBlock
                                    andBlock:(nullable PTCLUserBlockVoidDAOUserBOOLNSError)block;

- (void)doLoginWithAuthType:(nonnull NSString*)authType
                andUsername:(nonnull NSString*)username
                andPassword:(nonnull NSString*)password
                andProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLUserBlockVoidDAOUserBOOLNSError)block;

- (void)doFlagObject:(nonnull DAOUser*)user
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOUser*)user
             forUser:(nullable DAOUser*)flaggingUser
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doDeleteFlag:(nonnull DAOFlag*)flag
           forObject:(nonnull DAOUser*)user
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOUser*)user
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
           andProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOUser*)user
               withAction:(nonnull NSString*)action
              andProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLUserBlockVoidNSUIntegerNSError)block;

- (void)doFollowUser:(nonnull DAOUser*)user
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doUnfollowUser:(nonnull DAOUser*)user
          withProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doTagObject:(nonnull DAOUser*)user
            withTag:(nonnull NSString*)tag
        andProgress:(nullable PTCLProgressBlock)progressBlock
           andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doUntagObject:(nonnull DAOUser*)user
              withTag:(nonnull NSString*)tag
          andProgress:(nullable PTCLProgressBlock)progressBlock
             andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doLoad:(nonnull NSString*)userId
  withProgress:(nullable PTCLProgressBlock)progressBlock
      andBlock:(nullable PTCLUserBlockVoidDAOUserNSError)block;

- (void)doVerify:(nonnull DAOUser*)user
    withProgress:(nullable PTCLProgressBlock)progressBlock
        andBlock:(nullable PTCLUserBlockVoidDAOUserNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadAvatarForUser:(nonnull DAOUser*)user
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLUserBlockVoidDAOPhotoNSError)block;

- (void)doLoadLocationsForObject:(nonnull DAOUser*)user
                    withProgress:(nullable PTCLProgressBlock)progressBlock
                        andBlock:(nullable PTCLUserBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doResetPasswordForEmail:(nonnull NSString*)email
                   withProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doSaveObject:(nonnull DAOUser*)user
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doSaveOptions:(nonnull DAOUser*)daoUser
         withProgress:(nullable PTCLProgressBlock)progressBlock
             andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doSignUp:(nonnull DAOUser*)user
    withProgress:(nullable PTCLProgressBlock)progressBlock
        andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doSearchUsers:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
       withParameters:(nullable NSDictionary*)parameters
          andProgress:(nullable PTCLProgressBlock)progressBlock
             andBlock:(nullable PTCLUserSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)block;

- (void)doSaveOption:(nonnull NSString*)optionId
              andKey:(nonnull NSString*)optionKey
            andValue:(nullable id)optionValue
             forUser:(nonnull DAOUser*)daoUser
        withProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadAllFlagsForObject:(nonnull DAOUser*)user
                    withActions:(nonnull NSArray<NSString*>*)actions
                    andProgress:(nullable PTCLProgressBlock)progressBlock
                       andBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadFlagsForObject:(nonnull DAOUser*)user
                 withActions:(nonnull NSArray<NSString*>*)actions
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAOUser*)user
                   withActions:(nonnull NSArray<NSString*>*)actions
                   andProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadTagsForObject:(nonnull DAOUser*)user
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLUserBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)block
             andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsWithTag:(nonnull NSString*)tag
              withParameters:(nullable NSDictionary*)parameters
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLUserBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLUser_Protocol_h */
