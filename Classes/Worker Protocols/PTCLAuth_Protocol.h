//
//  PTCLAuth_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLAuth_Protocol_h
#define PTCLAuth_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOAuth;
@class DAOUser;

typedef void(^PTCLAuthContinueBlock)(void);

typedef void(^PTCLAuthBlockVoidDAOAuthNSError)(DAOAuth* _Nullable auth, NSError* _Nullable error);

typedef void(^PTCLAuthBlockVoidDAOAuthNSErrorContinue)(DAOAuth* _Nullable auth, NSError* _Nullable error, PTCLAuthContinueBlock _Nullable continueBlock);

@protocol PTCLAuth_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLAuth_Protocol> _Nullable    nextAuthWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLAuth_Protocol>)nextAuthWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForUser:(nonnull DAOUser*)user
               withProgress:(nullable PTCLProgressBlock)progressBlock
                   andBlock:(nullable PTCLAuthBlockVoidDAOAuthNSErrorContinue)block
             andUpdateBlock:(nullable PTCLAuthBlockVoidDAOAuthNSError)updateBlock;

@end

#endif /* PTCLAuth_Protocol_h */
