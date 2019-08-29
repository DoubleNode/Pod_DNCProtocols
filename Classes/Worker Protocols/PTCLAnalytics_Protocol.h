//
//  PTCLAnalytics_Protocol.h
//  DoubleNode Protocols
//
//  Created by Darren Ehlers on 2016/10/16.
//  Copyright © 2016 Darren Ehlers and DoubleNode, LLC.
//
//  DNCProtocols is released under the MIT license. See LICENSE for details.
//

#ifndef PTCLAnalytics_Protocol_h
#define PTCLAnalytics_Protocol_h

#import "__PTCLBase_Protocol.h"

#define NS_PRETTY_FUNCTION  [NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__]

@protocol PTCLAnalytics_Protocol <PTCLBase_Protocol>

@property (strong, nonatomic)   id<PTCLAnalytics_Protocol> _Nullable    nextAnalyticsWorker;

+ (nonnull instancetype)worker;
+ (nonnull instancetype)worker:(nullable id<PTCLAnalytics_Protocol>)nextAnalyticsWorker;

#pragma mark - Business Logic / Single Item CRUD

#pragma mark - Identify

- (void)doIdentify:(NSString* _Nonnull)userId;
- (void)doIdentify:(NSString* _Nonnull)userId traits:(NSDictionary* _Nonnull)traits;
- (void)doIdentify:(NSString* _Nonnull)userId traits:(NSDictionary* _Nonnull)traits options:(NSDictionary* _Nonnull)options;

#pragma mark - Track

- (void)doTrack:(NSString* _Nonnull)event;
- (void)doTrack:(NSString* _Nonnull)event properties:(NSDictionary* _Nonnull)properties;
- (void)doTrack:(NSString* _Nonnull)event properties:(NSDictionary* _Nonnull)properties options:(NSDictionary* _Nonnull)options;

#pragma mark - Screen

- (void)doScreen:(NSString* _Nonnull)screenTitle;
- (void)doScreen:(NSString* _Nonnull)screenTitle properties:(NSDictionary* _Nonnull)properties;
- (void)doScreen:(NSString* _Nonnull)screenTitle properties:(NSDictionary* _Nonnull)properties options:(NSDictionary* _Nonnull)options;

#pragma mark - Group

- (void)doGroup:(NSString* _Nonnull)groupId;
- (void)doGroup:(NSString* _Nonnull)groupId traits:(NSDictionary* _Nonnull)traits;
- (void)doGroup:(NSString* _Nonnull)groupId traits:(NSDictionary* _Nonnull)traits options:(NSDictionary* _Nonnull)options;

@end

#endif /* PTCLAnalytics_Protocol_h */
