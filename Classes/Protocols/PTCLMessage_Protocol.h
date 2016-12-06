//
//  PTCLMessage_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

@class DAOMessage;

typedef void(^PTCLMessageBlockVoidDAOMessageNSError)(DAOMessage* _Nullable message, NSError* _Nullable error);

@protocol PTCLMessage_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLMessage_Protocol> _Nullable    nextWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLMessage_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doSaveObject:(nonnull DAOMessage*)message
           withBlock:(nullable PTCLMessageBlockVoidDAOMessageNSError)block;

@end
