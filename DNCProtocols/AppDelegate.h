//
//  AppDelegate.h
//  DNCProtocols
//
//  Created by Darren Ehlers on 10/22/16.
//  Copyright © 2019 - 2016 DoubleNode.com. All rights reserved.
//

#import "PTCLCollectionViewDataSource_Protocol.h"
#import "PTCLCollectionViewDelegate_Protocol.h"
#import "PTCLState_Protocol.h"

#import "PTCLActivity_Protocol.h"
#import "PTCLAnalytics_Protocol.h"
#import "PTCLAuth_Protocol.h"
#import "PTCLCache_Protocol.h"
#import "PTCLCategory_Protocol.h"
#import "PTCLCheckin_Protocol.h"
#import "PTCLContact_Protocol.h"
#import "PTCLConversation_Protocol.h"
#import "PTCLFavorite_Protocol.h"
#import "PTCLFile_Protocol.h"
#import "PTCLItem_Protocol.h"
#import "PTCLLineitem_Protocol.h"
#import "PTCLLocation_Protocol.h"
#import "PTCLMediaLibrary_Protocol.h"
#import "PTCLMessage_Protocol.h"
#import "PTCLNews_Protocol.h"
#import "PTCLNotification_Protocol.h"
#import "PTCLOrder_Protocol.h"
#import "PTCLPasswordStrength_Protocol.h"
#import "PTCLPaymentAccount_Protocol.h"
#import "PTCLPhoto_Protocol.h"
#import "PTCLRating_Protocol.h"
#import "PTCLReview_Protocol.h"
#import "PTCLSocialAuthenticate_Protocol.h"
#import "PTCLSocialShare_Protocol.h"
#import "PTCLTransaction_Protocol.h"
#import "PTCLUser_Protocol.h"
#import "PTCLUserDevice_Protocol.h"
#import "PTCLUserNotificationSetting_Protocol.h"
#import "PTCLUserIdentification_Protocol.h"
#import "PTCLValidation_Protocol.h"
#import "PTCLWishlist_Protocol.h"

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@end

