//
//  PTCLSocialAuthenticate_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

#import "PTCLSocialAuthenticate_Session.h"
#import "PTCLSocialAuthenticate_User.h"

#define NS_PRETTY_FUNCTION  [NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__]

typedef void(^PTCLSocialAuthenticateBlockVoidSessionNSError)(PTCLSocialAuthenticate_Session* _Nullable session, NSError* _Nullable error);
typedef void(^PTCLSocialAuthenticateBlockVoidUserNSError)(PTCLSocialAuthenticate_User* _Nullable user, NSError* _Nullable error);

@protocol PTCLSocialAuthenticate_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLSocialAuthenticate_Protocol> _Nullable   nextSocialAuthenticateWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLSocialAuthenticate_Protocol>)nextSocialAuthenticateWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doAuthenticateWithCompletion:(PTCLSocialAuthenticateBlockVoidSessionNSError _Nullable)completion;

- (void)doRetrieveUser:(nullable NSString*)userId
           withSession:(nullable PTCLSocialAuthenticate_Session*)session
        withCompletion:(nullable PTCLSocialAuthenticateBlockVoidUserNSError)completion;

@end
