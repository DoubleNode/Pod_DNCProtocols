//
//  PTCLSocialAuthenticate_Session.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

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
