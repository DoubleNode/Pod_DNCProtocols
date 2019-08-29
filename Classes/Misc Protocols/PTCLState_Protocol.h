//
//  PTCLState_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#pragma once

#import <UIKit/UIKit.h>

@protocol PTCLState_Protocol

- (NSDictionary*)saveObjectState;
- (void)restoreObjectState:(NSDictionary*)state;

@end
