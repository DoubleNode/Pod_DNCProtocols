//
//  PTCLSocialAuthenticate_Session.m
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
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
