//
//  PTCLCollectionViewDataSource_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLCollectionViewDataSource_Protocol_h
#define PTCLCollectionViewDataSource_Protocol_h

#import <UIKit/UIKit.h>

@protocol PTCLCollectionViewDataSource_Protocol <UICollectionViewDataSource>

@property (strong, nonatomic)   id _Nullable        delegate;
@property (strong, nonatomic)   id _Nullable        dataObject;
@property (strong, nonatomic)   NSArray* _Nullable  data;

@property (strong, nonatomic)   UICollectionView* _Nullable collectionView;

+ (nonnull instancetype)dataSource;
+ (nonnull instancetype)dataSourceWithCollectionView:(nullable UICollectionView*)collectionView;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithCollectionView:(nullable UICollectionView*)collectionView;

- (BOOL)resignFirstResponder;

@end

#endif /* PTCLCollectionViewDataSource_Protocol_h */
