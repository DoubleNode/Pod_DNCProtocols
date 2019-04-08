//
//  PTCLState_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#pragma once

#import <UIKit/UIKit.h>

@protocol PTCLState_Protocol

- (NSDictionary*)saveObjectState;
- (void)restoreObjectState:(NSDictionary*)state;

@end
