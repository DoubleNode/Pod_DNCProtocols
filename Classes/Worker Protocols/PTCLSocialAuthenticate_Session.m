//
//  PTCLSocialAuthenticate_Session.m
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "PTCLSocialAuthenticate_Session.h"

@implementation PTCLSocialAuthenticate_Session

@synthesize userId;
@synthesize username;
@synthesize password;
@synthesize authData;
@synthesize user;

+ (nonnull instancetype)session {   return [[self.class alloc] init];   }

@end
