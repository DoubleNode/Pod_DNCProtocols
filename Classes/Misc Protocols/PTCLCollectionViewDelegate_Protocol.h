//
//  PTCLCollectionViewDelegate_Protocol.h
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

#ifndef PTCLCollectionViewDelegate_Protocol_h
#define PTCLCollectionViewDelegate_Protocol_h

#import <UIKit/UIKit.h>

@protocol PTCLCollectionViewDelegate_Protocol <UICollectionViewDelegate>

@property (strong, nonatomic)   id _Nullable                delegate;
@property (strong, nonatomic)   UICollectionView* _Nullable collectionView;

+ (nonnull instancetype)delegate;
+ (nonnull instancetype)delegateWithCollectionView:(nullable UICollectionView*)collectionView;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithCollectionView:(nullable UICollectionView*)collectionView;

#pragma mark - VisibleRow methods

- (NSInteger)numberOfVisibleColumns;
- (NSInteger)numberOfVisibleItemsInSection:(NSInteger)section;
- (NSInteger)numberOfVisibleRowsInSection:(NSInteger)section;

- (CGFloat)visibleColumnWidth;
- (CGSize)visibleSize;

- (BOOL)lastVisibleRowForItemAtIndexPath:(nullable NSIndexPath*)indexPath;

@end

#endif /* PTCLCollectionViewDelegate_Protocol_h */
