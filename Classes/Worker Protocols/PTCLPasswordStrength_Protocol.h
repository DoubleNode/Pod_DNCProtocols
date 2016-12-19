//
//  PTCLPasswordStrength_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLPasswordStrength_Protocol_h
#define PTCLPasswordStrength_Protocol_h

#import "__PTCLBase_Protocol.h"

typedef NS_ENUM(NSUInteger, WKRPasswordStrengthType)
{
    WKRPasswordStrengthTypeWeak,
    WKRPasswordStrengthTypeModerate,
    WKRPasswordStrengthTypeStrong
};

@protocol PTCLPasswordStrength_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLPasswordStrength_Protocol> _Nullable nextPasswordStrengthWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLPasswordStrength_Protocol>)nextWorker;

#pragma mark - Business Logic

- (WKRPasswordStrengthType)doCheckPasswordStrength:(nonnull NSString*)password;

@end

#endif /* PTCLPasswordStrength_Protocol_h */
