//
//  WKRNET_Header_Processor.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef WKRNET_Header_Processor_h
#define WKRNET_Header_Processor_h

@protocol WKRNET_Header_Processor<NSObject>

+ (nonnull instancetype)processor;

- (nullable NSString*)authenticationCookieValue;

- (void)processorAddHeaders:(NSMutableURLRequest*_Nonnull)request;
- (void)processorGrabHeaders:(NSURLResponse*_Nonnull)response;

@end

#endif /* WKRNET_Header_Processor_h */
