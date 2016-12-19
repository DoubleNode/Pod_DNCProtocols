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

@protocol PTCLValidation_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLValidation_Protocol> _Nullable    nextValidationWorker;

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

@end

#endif /* PTCLValidation_Protocol_h */
