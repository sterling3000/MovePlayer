//
//  VMInternalConstants.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/10/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "VMUtilities.h"

#define VM_SDK_VERSION     @"0.9.7"

#define VEVO_BACKEND_API_VERSION   @"v2"

@interface VMInternalConstants : NSObject

extern NSString *kVMClientAppName;

/* ComScoreClientID */
extern NSString *kComScoreClientID;
extern NSString *kComScoreSecret;
extern NSString *kAppStoreReviewLink;

/* ComScore 2.0 */
extern NSString *kComScore20CustomerC2;
extern NSString *kComScore20PublisherSecret;
extern NSString *kComScore20PixelURL;

//URLs
extern NSString *kVevoApiBaseUrlProduction;
extern NSString *kVevoSecureApiBaseUrlProduction;

//Movie player
extern NSString *kVMMoviePlayerShouldPauseNotification;
extern NSString *kVMMoviePlayerShouldResumeNotification;

extern NSString *kVMWillRotateToInterfaceOrientation;
extern NSString *kVMDidRotateToInterfaceOrientation;
extern NSString *kVMMoviePlayerWillEnterFullscreen;
extern NSString *kVMMoviePlayerWillExitFullscreen;
extern NSString *kVMMoviePlayerDidEnterFullscreen;
extern NSString *kVMMoviePlayerDidExitFullscreen;

extern int const kVMBeaconingInterval;

//TV Out
extern NSString *kVEVOTVOUTDIDSTARTNOTIFICATION;
extern NSString *kVEVOTVOUTDIDSTOPNOTIFICATION;

extern NSString *kVMResourceDownloadFailedNotificationName;
extern NSString *kVMAPIFailedNotificationName;




/* Colors */
#define VMRGB(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define VMRGBwithAlpha(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

//Conviva
#define kVMConvivaServiceUrl @"https://cws.conviva.com/0/wsg"
#define kVMConvivaCustomerId @"c2e8a3a626bd820962a3eadffb15e468ab55327b"
#define kVMConvivaCustomerIdTest @"97dba4ef2732fe8b13b36e088da70c5bc8351d30"
#define kVMConvivaPlayerName @"VEVO iPhone %@"


#define isDevice_retina ([[UIScreen mainScreen] scale] >= 2.0f)

#define isDevice_iPad ([[[UIDevice currentDevice] model] rangeOfString:@"iPad"].location != NSNotFound)
#define isDevice_HighResolutionDevice (([[UIScreen mainScreen] scale] >= 2.0f) || (isDevice_iPad))
#define kImageQuality kHighResImageQuality

#define VMALERT(title,msg) {UIAlertView* alert = [[UIAlertView alloc] initWithTitle:title message:msg delegate:nil cancelButtonTitle:VMLocalizedString(@"Shared_CloseButton", @"Dismiss") otherButtonTitles:nil];[alert show];}

#define VMLocalizedString(msg, defaultMsg) [VMUtilities localizedStringForKey:msg withDefault:defaultMsg]

#define kVevoMediaApiKeyLowRes      @"-M6LM-Wk3-m90h0Vp_mE"
#define kVevoMediaApiKeyHighRes     @"G05bmz9x--_6-J-qpR4_"
#define kVevoMediaApiKey isDevice_HighResolutionDevice ? kVevoMediaApiKeyHighRes : kVevoMediaApiKeyLowRes

//Current Google Chromecast device doesn't support HLS streams, we need get android rendition for Google Chromecast.
#define kVevoMediaApiKeyGooglecast     @"Cwuqh7ltPj0jq7eF_WGCQKg"


#define kIconWidth								122
#define kIconHeight								70

#define kThumbWidth								68
#define kThumbHeight							38

#define kChartImageWidth						125
#define kChartImageHeight						70

#define kArtistProfileWidth						320
#define kArtistProfileHeight					200

#define kInfoViewImageWidth						147
#define kInfoViewImageHeight					87

#define kHighResImageQuality					70
#define kLowResImageQuality						80
#define kiPadResImageQuality					90

//#define kUseConvivaTest

// ComScore
//#define disable_comScore

// GoogleCast
//#define disable_chromecast

//partner comscore settings
#define NS_SITE                             @"vevo"
#define SYN_ID                              @"bb8a16ab-1279-4f17-969b-1dba5eb60eda"
#define DEFAULT_APP_NAME                    @"VEVO"
#define C2                                  @"3005647"


@end
