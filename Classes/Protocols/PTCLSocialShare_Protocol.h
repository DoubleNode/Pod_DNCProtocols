//
//  PTCLSocialShare_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

typedef void(^PTCLSocialShareBlockVoidNSError)(NSError* _Nullable error);

@protocol PTCLSocialShare_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLSocialShare_Protocol> _Nullable  nextSocialShareWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLSocialShare_Protocol>)nextSocialShareWorker;

- (void)doShareReview:(nonnull NSString*)text
            withImage:(nullable UIImage*)image
  usingViewController:(nonnull UIViewController*)viewController
            withBlock:(nullable PTCLSocialShareBlockVoidNSError)block;

@end
