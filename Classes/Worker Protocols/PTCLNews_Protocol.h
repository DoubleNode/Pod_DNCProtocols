//
//  PTCLNews_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLNews_Protocol_h
#define PTCLNews_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOFlag;
@class DAONews;

typedef void(^PTCLNewsContinueBlock)(void);

typedef void(^PTCLNewsBlockVoidNSError)(NSError* _Nullable error);
typedef void(^PTCLNewsBlockVoidBOOLNSError)(BOOL success, NSError* _Nullable error);
typedef void(^PTCLNewsBlockVoidNSUIntegerNSError)(NSUInteger count, NSError* _Nullable error);

typedef void(^PTCLNewsBlockVoidDAONewsNSError)(DAONews* _Nullable news, NSError* _Nullable error);

typedef void(^PTCLNewsBlockVoidDAONewsNSErrorContinue)(DAONews* _Nullable news, NSError* _Nullable error, PTCLNewsContinueBlock _Nullable continueBlock);

typedef void(^PTCLNewsBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);
typedef void(^PTCLNewsBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOFlag* >* _Nullable flags, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLNewsContinueBlock _Nullable continueBlock);

@protocol PTCLNews_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLNews_Protocol> _Nullable    nextNewsWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLNews_Protocol>)nextWorker;

#pragma mark - Business Logic / Single Item CRUD

- (void)doLoadObjectForId:(nonnull NSString*)newsId
             withProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLNewsBlockVoidDAONewsNSErrorContinue)block
           andUpdateBlock:(nullable PTCLNewsBlockVoidDAONewsNSError)updateBlock;

- (void)doFavoriteObject:(nonnull DAONews*)news
            withProgress:(nullable PTCLProgressBlock)progressBlock
                andBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doUnfavoriteObject:(nonnull DAONews*)news
              withProgress:(nullable PTCLProgressBlock)progressBlock
                  andBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doFlagObject:(nonnull DAONews*)news
          withAction:(nonnull NSString*)action
             andText:(nonnull NSString*)text
         andProgress:(nullable PTCLProgressBlock)progressBlock
            andBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doUnflagObject:(nonnull DAONews*)news
            withAction:(nonnull NSString*)action
               andText:(nonnull NSString*)text
           andProgress:(nullable PTCLProgressBlock)progressBlock
              andBlock:(nullable PTCLNewsBlockVoidNSError)block;

- (void)doCheckFlagObject:(nonnull DAONews*)news
               withAction:(nonnull NSString*)action
              andProgress:(nullable PTCLProgressBlock)progressBlock
                 andBlock:(nullable PTCLNewsBlockVoidNSUIntegerNSError)block;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadFlagsForObject:(nonnull DAONews*)news
                 withActions:(nonnull NSArray<NSString*>*)actions
                 andProgress:(nullable PTCLProgressBlock)progressBlock
                    andBlock:(nullable PTCLNewsBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
              andUpdateBlock:(nullable PTCLNewsBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

- (void)doLoadMyFlagsForObject:(nonnull DAONews*)news
                   withActions:(nonnull NSArray<NSString*>*)actions
                   andProgress:(nullable PTCLProgressBlock)progressBlock
                      andBlock:(nullable PTCLNewsBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSErrorContinue)block
                andUpdateBlock:(nullable PTCLNewsBlockVoidNSArrayDAOFlagNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLNews_Protocol_h */
