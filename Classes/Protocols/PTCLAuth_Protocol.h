//
//  PTCLAuth_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

@class DAOAuth;
@class DAOUser;

typedef void(^PTCLAuthContinueBlock)();

typedef void(^PTCLAuthBlockVoidDAOAuthNSError)(DAOAuth* _Nullable auth, NSError* _Nullable error);

typedef void(^PTCLAuthBlockVoidDAOAuthNSErrorContinue)(DAOAuth* _Nullable auth, NSError* _Nullable error, PTCLAuthContinueBlock _Nullable continueBlock);

@protocol PTCLAuth_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLAuth_Protocol> _Nullable    nextAuthWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLAuth_Protocol>)nextAuthWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForUser:(nonnull DAOUser*)user
                  withBlock:(nullable PTCLAuthBlockVoidDAOAuthNSErrorContinue)block
             andUpdateBlock:(nullable PTCLAuthBlockVoidDAOAuthNSError)updateBlock;

@end
