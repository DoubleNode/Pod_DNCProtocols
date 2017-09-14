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

- (BOOL)doCheckForAccessTokenError:(nullable NSData*)errorData;
- (void)doCurrentAccessTokenWithBlock:(nullable PTCLUserBlockVoidDAOUserNSString)block;
- (void)doCurrentUserWithBlock:(nullable PTCLUserBlockVoidDAOUser)block;

- (void)doDeleteCurrentUserWithBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;
- (void)doLogOut;

- (void)validateCurrentSessionInBackgroundWithBlock:(nullable PTCLUserBlockVoidDAOUserBOOLNSError)block;

- (void)logInWithUsernameInBackground:(nonnull NSString*)authType
                             username:(nonnull NSString*)username
                             password:(nonnull NSString*)password
                            withBlock:(nullable PTCLUserBlockVoidDAOUserBOOLNSError)block;

- (void)doFlagObject:(nonnull DAOUser*)user
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAOUser*)user
             forUser:(nullable DAOUser*)flaggingUser
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doDeleteFlag:(nonnull DAOFlag*)flag
           forObject:(nonnull DAOUser*)user
           withBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAOUser*)user
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
              andBlock:(nullable PTCLUserBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAOUser*)user
               withAction:(nonnull NSString*)action
                 andBlock:(nullable PTCLUserBlockVoidNSUIntegerNSError)block;

- (void)doFollowUser:(nonnull DAOUser*)user
           withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doUnfollowUser:(nonnull DAOUser*)user
             withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doTagObject:(nonnull DAOUser*)user
            withTag:(nonnull NSString*)tag
           andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doUntagObject:(nonnull DAOUser*)user
              withTag:(nonnull NSString*)tag
             andBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doLoad:(nonnull NSString*)userId
     withBlock:(nullable PTCLUserBlockVoidDAOUserNSError)block;

- (void)doVerify:(nonnull DAOUser*)user
       withBlock:(nullable PTCLUserBlockVoidDAOUserNSError)block;

#pragma mark - Business Logic / Single Item Relationship CRUD

- (void)doLoadAvatarForUser:(nonnull DAOUser*)user
                  withBlock:(nullable PTCLUserBlockVoidDAOPhotoNSError)block;

- (void)doLoadLocationsForObject:(nonnull DAOUser*)user
                       withBlock:(nullable PTCLUserBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSErrorContinue)block
                  andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOLocationNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doResetPasswordForEmail:(nonnull NSString*)email
                      withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)saveInBackground:(nonnull DAOUser*)user
               withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)saveOptionsInBackground:(nonnull DAOUser*)daoUser
                      withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)signUpInBackground:(nonnull DAOUser*)user
                 withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

- (void)doSearchUsers:(nonnull NSString*)searchId
             withText:(nonnull NSString*)search
       withParameters:(nullable NSDictionary*)parameters
             andBlock:(nullable PTCLUserSearchBlockVoidNSArrayNSUIntegerNSUIntegerNSError)block;

- (void)doSaveOption:(nonnull NSString*)optionId
              andKey:(nonnull NSString*)optionKey
            andValue:(nullable id)optionValue
             forUser:(nonnull DAOUser*)daoUser
           withBlock:(nullable PTCLUserBlockVoidBOOLNSError)block;

#pragma mark - Business Logic / Collection Items CRUD
 
- (void)doLoadAllFlagsForObject:(nonnull DAOUser*)user
                    withActions:(nonnull NSArray<NSString*>*)actions
                       andBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                 andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadFlagsForObject:(nonnull DAOUser*)user
                 withActions:(nonnull NSArray<NSString*>*)actions
                    andBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAOUser*)user
                   withActions:(nonnull NSArray<NSString*>*)actions
                      andBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadTagsForObject:(nonnull DAOUser*)user
                   andBlock:(nullable PTCLUserBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSErrorContinue)block
             andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayNSStringNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadObjectsWithTag:(nonnull NSString*)tag
              withParameters:(nullable NSDictionary*)parameters
                    andBlock:(nullable PTCLUserBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLUserBlockVoidNSArrayDAOUserNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLUser_Protocol_h */
