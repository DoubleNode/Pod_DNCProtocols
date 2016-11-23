//
//  PTCLFile_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

@class DAOUser;

typedef void(^PTCLFileBlockVoidNSStringIDBOOLNSError)(NSString* _Nullable url, id _Nullable file, BOOL success, NSError* _Nullable error);

@protocol PTCLFile_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLFile_Protocol> _Nullable    nextFileWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLFile_Protocol>)nextFileWorker;

- (void)saveFileInBackgroundForUser:(nonnull DAOUser*)user
                           withName:(nonnull NSString*)fileName
                               data:(nonnull NSData*)data
                              block:(nullable PTCLFileBlockVoidNSStringIDBOOLNSError)block;

@end
