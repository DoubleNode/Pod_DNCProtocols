//
//  PTCLCollectionViewDataSource_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLCollectionViewDataSource_Protocol_h
#define PTCLCollectionViewDataSource_Protocol_h

#import <UIKit/UIKit.h>

@protocol PTCLCollectionViewDataSource_Protocol <UICollectionViewDataSource>

@property (strong, nonatomic)   NSArray* _Nullable  data;

+ (nonnull instancetype)dataSourceWithCollectionView:(nullable UICollectionView*)collectionView;

- (nonnull instancetype)initWithCollectionView:(nullable UICollectionView*)collectionView;

@end

#endif /* PTCLCollectionViewDataSource_Protocol_h */
