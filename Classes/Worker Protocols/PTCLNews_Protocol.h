//
//  PTCLNews_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLNews_Protocol_h
#define PTCLNews_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAONews;

typedef void(^PTCLNewsContinueBlock)();

typedef void(^PTCLNewsBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLNewsBlockVoidBOOLNSError)(BOOL, NSError* _Nullable error);

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

- (void)doFlagObject:(nonnull DAONews*)news
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
            andBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAONews*)news
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
              andBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAONews*)news
               withAction:(nonnull NSString*)action
                 andBlock:(nullable PTCLNewsBlockVoidBOOLNSError)block;

@end

#endif /* PTCLNews_Protocol_h */
