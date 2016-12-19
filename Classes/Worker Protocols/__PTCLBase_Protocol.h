//
//  __PTCLBase_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef __PTCLBase_Protocol_h
#define __PTCLBase_Protocol_h

#import <UIKit/UIKit.h>

@protocol PTCLBase_Protocol <NSObject>

@property (strong, nonatomic)   id<PTCLBase_Protocol> _Nullable nextBaseWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLBase_Protocol>)nextBaseWorker;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithWorker:(nullable id<PTCLBase_Protocol>)nextBaseWorker;

- (void)configure;

- (void)enableOption:(nonnull NSString*)option;
- (void)disableOption:(nonnull NSString*)option;

@end

#endif /* __PTCLBase_Protocol_h */
