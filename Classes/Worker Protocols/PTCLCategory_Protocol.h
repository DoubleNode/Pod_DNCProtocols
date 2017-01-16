//
//  PTCLCategory_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLCategory_Protocol_h
#define PTCLCategory_Protocol_h

#import "__PTCLBase_Protocol.h"

@class DAOCategory;

typedef void(^PTCLCategoryContinueBlock)();

typedef void(^PTCLCategoryBlockVoidNSArrayNSUIntegerNSUIntegerNSError)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error);

typedef void(^PTCLCategoryBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)(NSArray<DAOCategory* >* _Nullable categories, NSUInteger currentPage, NSUInteger numberOfPages, NSError* _Nullable error, PTCLCategoryContinueBlock _Nullable continueBlock);

@protocol PTCLCategory_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLCategory_Protocol> _Nullable nextCategoryWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLCategory_Protocol>)nextCategoryWorker;

#pragma mark - Business Logic / Collection Items CRUD

- (void)doLoadItemsWithParameters:(nullable NSDictionary*)parameters
                         andBlock:(nullable PTCLCategoryBlockVoidNSArrayNSUIntegerNSUIntegerNSErrorContinue)block
                   andUpdateBlock:(nullable PTCLCategoryBlockVoidNSArrayNSUIntegerNSUIntegerNSError)updateBlock;

@end

#endif /* PTCLCategory_Protocol_h */
