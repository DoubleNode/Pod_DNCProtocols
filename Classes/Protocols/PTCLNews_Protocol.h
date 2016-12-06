//
//  PTCLNews_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#import "__PTCLBase_Protocol.h"

@class DAONews;

typedef void(^PTCLNewsContinueBlock)();

typedef void(^PTCLNewsBlockVoidNSError)(NSError* _Nullable error);

typedef void(^PTCLNewsBlockVoidDAONewsNSError)(DAONews* _Nullable news, NSError* _Nullable error);

typedef void(^PTCLNewsBlockVoidDAONewsNSErrorContinue)(DAONews* _Nullable news, NSError* _Nullable error, PTCLNewsContinueBlock _Nullable continueBlock);

@protocol PTCLNews_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLNews_Protocol> _Nullable    nextNewsWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLNews_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)newsId
                withBlock:(nullable PTCLNewsBlockVoidDAONewsNSErrorContinue)block
           andUpdateBlock:(nullable PTCLNewsBlockVoidDAONewsNSError)updateBlock;

- (void)doFavoriteObject:(nonnull DAONews*)news
               withBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAONews*)news
                 withBlock:(nullable PTCLNewsBlockVoidNSError)block;

@end
