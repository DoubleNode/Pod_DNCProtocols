//
//  PTCLUserIdentification_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLUserIdentification_Protocol_h
#define PTCLUserIdentification_Protocol_h

#import "__PTCLBase_Protocol.h"

@protocol PTCLUserIdentification_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLUserIdentification_Protocol> _Nullable    nextUserIdentificationWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLUserIdentification_Protocol>)nextUserIdentificationWorker;

- (void)doIdentifyUserWithIdentifier:(nonnull NSString*)identifier
                         andUsername:(nonnull NSString*)username
                            andEmail:(nonnull NSString*)email;

@end

#endif /* PTCLUserIdentification_Protocol_h */
