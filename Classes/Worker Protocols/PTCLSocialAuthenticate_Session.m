//
//  PTCLSocialAuthenticate_Session.m
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLSocialAuthenticate_Session_h
#define PTCLSocialAuthenticate_Session_h

#import "PTCLSocialAuthenticate_Session.h"

@implementation PTCLSocialAuthenticate_Session

@synthesize userId;
@synthesize username;
@synthesize password;
@synthesize authData;
@synthesize user;

+ (nonnull instancetype)session {   return [[self.class alloc] init];   }

@end

#endif /* PTCLSocialAuthenticate_Session_h */
