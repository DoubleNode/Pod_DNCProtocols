//
//  PTCLEncryption_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLEncryption_Protocol_h
#define PTCLEncryption_Protocol_h

#import "__PTCLBase_Protocol.h"

typedef void(^PTCLEncryptionBlockVoidIDNSError)(id _Nullable object, NSError* _Nullable error);

@protocol PTCLEncryption_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLEncryption_Protocol> _Nullable  nextEncryptionWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLEncryption_Protocol>)nextEncryptionWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doEncryptObject:(nonnull id)object
                withKey:(nonnull id)key
               andBlock:(nullable PTCLEncryptionBlockVoidIDNSError)block;

- (void)doDecryptObject:(nonnull id)object
                withKey:(nonnull id)key
               andBlock:(nullable PTCLEncryptionBlockVoidIDNSError)block;

@end

#endif /* PTCLEncryption_Protocol_h */
