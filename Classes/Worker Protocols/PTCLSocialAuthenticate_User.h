//
//  PTCLSocialAuthenticate_User.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLSocialAuthenticate_User_h
#define PTCLSocialAuthenticate_User_h

#import <UIKit/UIKit.h>

@interface PTCLSocialAuthenticate_User : NSObject

+ (nonnull instancetype)user;

@property (copy, nonatomic)   NSString* _Nullable   name;
@property (copy, nonatomic)   NSString* _Nullable   handle;
@property (copy, nonatomic)   NSString* _Nullable   email;
@property (copy, nonatomic)   NSString* _Nullable   phone;
@property (copy, nonatomic)   NSString* _Nullable   photoUrl;

@end

#endif /* PTCLSocialAuthenticate_User_h */
