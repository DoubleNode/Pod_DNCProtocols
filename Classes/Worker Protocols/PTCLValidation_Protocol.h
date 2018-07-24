//
//  PTCLValidation_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLValidation_Protocol_h
#define PTCLValidation_Protocol_h

#import "__PTCLBase_Protocol.h"

#import "PTCLPasswordStrength_Protocol.h"

@protocol PTCLValidation_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLValidation_Protocol> _Nullable    nextValidationWorker;

@property (assign, nonatomic)   NSInteger   minimumBirthdayAge;     // -1 = no minimum
@property (assign, nonatomic)   NSInteger   maximumBirthdayAge;     // -1 = no minimum

@property (assign, nonatomic)   NSInteger   minimumHandleLength;    // -1 = no minimum
@property (assign, nonatomic)   NSInteger   maximumHandleLength;    // -1 = no maximum

@property (assign, nonatomic)   NSInteger   minimumNameLength;      // -1 = no minimum
@property (assign, nonatomic)   NSInteger   maximumNameLength;      // -1 = no maximum

@property (assign, nonatomic)   NSInteger   minimumNumberValue;
@property (assign, nonatomic)   NSInteger   maximumNumberValue;

@property (assign, nonatomic)   NSInteger   minimumPercentageValue;
@property (assign, nonatomic)   NSInteger   maximumPercentageValue;

@property (assign, nonatomic)   NSInteger   minimumUnsignedNumberValue;
@property (assign, nonatomic)   NSInteger   maximumUnsignedNumberValue;

@property (assign, nonatomic)   WKRPasswordStrengthType requiredPasswordStrength;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLValidation_Protocol>)nextValidationWorker;

- (BOOL)doValidateBirthday:(nonnull NSDate*)birthday error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateEmail:(nonnull NSString*)email error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateHandle:(nonnull NSString*)handle error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateName:(nonnull NSString*)name error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateNumber:(nonnull NSString*)number error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidatePassword:(nonnull NSString*)password error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidatePercentage:(nonnull NSString*)percentage error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateSearch:(nonnull NSString*)search error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateState:(nonnull NSString*)state error:(NSError*_Nullable*_Nullable)error;
- (BOOL)doValidateUnsignedNumber:(nonnull NSString*)number error:(NSError*_Nullable*_Nullable)error;

@end

#endif /* PTCLValidation_Protocol_h */
