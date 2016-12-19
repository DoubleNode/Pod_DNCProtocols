//
//  PTCLSocialAuthenticate_User.m
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLSocialAuthenticate_User_h
#define PTCLSocialAuthenticate_User_h

#import "PTCLSocialAuthenticate_User.h"

@implementation PTCLSocialAuthenticate_User

@synthesize name;
@synthesize handle;
@synthesize email;
@synthesize phone;
@synthesize photoUrl;

+ (nonnull instancetype)user    {   return [[self.class alloc] init];   }

@end

#endif /* PTCLSocialAuthenticate_User_h */
