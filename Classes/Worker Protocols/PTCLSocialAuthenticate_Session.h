//
//  PTCLSocialAuthenticate_Session.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLSocialAuthenticate_Session_h
#define PTCLSocialAuthenticate_Session_h

#import <UIKit/UIKit.h>

#import "PTCLSocialAuthenticate_User.h"

@interface PTCLSocialAuthenticate_Session : NSObject

+ (nonnull instancetype)session;

@property (copy, nonatomic)   NSString* _Nullable       userId;
@property (copy, nonatomic)   NSString* _Nullable       username;
@property (copy, nonatomic)   NSString* _Nullable       password;
@property (copy, nonatomic)   NSDictionary* _Nullable   authData;

@property (copy, nonatomic)   PTCLSocialAuthenticate_User* _Nullable    user;

@end

#endif /* PTCLSocialAuthenticate_Session_h */
