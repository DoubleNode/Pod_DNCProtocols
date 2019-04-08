//
//  PTCLSocialShare_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLSocialShare_Protocol_h
#define PTCLSocialShare_Protocol_h

#import "__PTCLBase_Protocol.h"

typedef void(^PTCLSocialShareBlockVoidNSError)(NSError* _Nullable error);

@protocol PTCLSocialShare_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLSocialShare_Protocol> _Nullable  nextSocialShareWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLSocialShare_Protocol>)nextSocialShareWorker;

- (void)doShareReview:(nonnull NSString*)text
            withImage:(nullable UIImage*)image
  usingViewController:(nonnull UIViewController*)viewController
          andProgress:(nullable PTCLProgressBlock)progressBlock
             andBlock:(nullable PTCLSocialShareBlockVoidNSError)block;

@end

#endif /* PTCLSocialShare_Protocol_h */
