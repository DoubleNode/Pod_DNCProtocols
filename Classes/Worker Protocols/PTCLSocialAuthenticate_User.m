//
//  PTCLSocialAuthenticate_User.m
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#import "PTCLSocialAuthenticate_User.h"

@implementation PTCLSocialAuthenticate_User

@synthesize name;
@synthesize handle;
@synthesize email;
@synthesize phone;
@synthesize photoUrl;

+ (nonnull instancetype)user    {   return [[self.class alloc] init];   }

@end
