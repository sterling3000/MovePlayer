//
//  VMFreeWheelAdManager.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/12/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <AdManager/FWSDK.h>
#import "FWConstants.h"
#import "FWProtocols.h"
#import "FWSDK.h"
#import "FWVer.h"
#import <UIKit/UIKit.h>
#import "VMVideo.h"
#import "VMTVChannel.h"

// Shared Constants
extern int const kFreeWheelNetworkId;
extern NSString *kFreeWheelApplicationProfile;
extern NSString *kFreeWheelAdServerUrl;

//Freewheel test
extern int const kFreeWheelTestNetworkId;
extern NSString *kFreeWheelTestApplicationProfile;
extern NSString *kFreeWheelTestAdServerUrl;

// iPad Specific
extern NSString *kFreeWheelSSID_watchpage_ipad;
extern NSString *kFreeWheelSSID_watchingnow_ipad;
extern NSString *kFreeWheelSSID_playlistbrowse_ipad;
extern NSString *kFreeWheelSSID_artistbrowse_ipad;
extern NSString *kFreeWheelSSID_videobrowse_ipad;
extern NSString *kFreeWheelSSID_matchbrowse_ipad;
extern NSString *kFreeWheelSSID_main_ipad;
extern NSString *kFreeWheelSSID_searchresults_ipad;
extern NSString *kFreeWheelSSID_history_ipad;
extern NSString *kFreeWheelSSID_entry_ipad;
extern NSString *kFreeWheelSSID_trivia_ipad;
extern NSString *kFreeWheelSSID_vevotv_ipad;
extern NSString *kFreeWheelSSID_canvas_ad_ipad;

// iPhone specific
extern NSString *kFreeWheelSSID_watchpage_iphone;
extern NSString *kFreeWheelSSID_watchingnow_iphone;
extern NSString *kFreeWheelSSID_playlistbrowse_iphone;
extern NSString *kFreeWheelSSID_artistbrowse_iphone;
extern NSString *kFreeWheelSSID_videobrowse_iphone;
extern NSString *kFreeWheelSSID_matchbrowse_iphone;
extern NSString *kFreeWheelSSID_main_iphone;
extern NSString *kFreeWheelSSID_searchresults_iphone;
extern NSString *kFreeWheelSSID_history_iphone;
extern NSString *kFreeWheelSSID_entry_iphone;
extern NSString *kFreeWheelSSID_trivia_iphone;
extern NSString *kFreeWheelSSID_vevotv_iphone;
extern NSString *kFreeWheelSSID_canvas_ad_iphone;

extern NSString *kFreeWheel_Canvas_Ad_Width_Key_iPhone;
extern NSString *kFreeWheel_Canvas_Ad_Height_Key_iPhone;
extern NSString *kFreeWheel_Canvas_Ad_Width_Key_iPad_Portrait;
extern NSString *kFreeWheel_Canvas_Ad_Height_Key_iPad_Portrait;
extern NSString *kFreeWheel_Canvas_Ad_Width_Key_iPad_Landscape;
extern NSString *kFreeWheel_Canvas_Ad_Height_Key_iPad_Landscape;



@protocol VMFreeWheelAdManagerDelegate;

@interface VMFreeWheelAdManager : NSObject

@property (nonatomic, assign) id <VMFreeWheelAdManagerDelegate, NSObject> delegate;
//@property (nonatomic, retain) id <FWContext>freewheelAdContext;

@property (nonatomic) BOOL clickDetetionEnable;
@property (nonatomic, strong) NSMutableDictionary    *extraParams;
@property (nonatomic) BOOL requestCanvasAd;
@property (nonatomic, strong) NSDictionary *canvasAdSize;

+ (VMFreeWheelAdManager *)sharedInstance;

+ (id<FWAdManager>)getAdManager;
+ (BOOL)isAdEnabled;

/**
 Make a request to get a banner ad.
 @param SSID Tag name for the request.
 */
- (id<FWContext>)submitAdRequestForBannerWithSSID:(NSString *)SSID controller:(id)controller;

/**
 Make a request to get a banner ad in a specific size.
 @param SSID Tag name for the request.
 @param size Size of the banner.
 */
- (id<FWContext>)submitAdRequestForBannerWithSSID:(NSString *)SSID forSize:(CGSize)size adUnit:(NSString *)adUnit controller:(id)controller;

/**
 @method - (void)submitBackgroundAdRequestForBannersWithSSID:(NSString *)SSID Make a request to get a background banner ad.
 @discussion We use this request for the iPad app's tile views. The returned ad will be displayed as the background image on the tile views.
 */

- (id<FWContext>)submitBackgroundAdRequestForBannersWithSSID:(NSString *)SSID controller:(id)controller;

/**
 Make a request to get an ad for Vevo TV
 
 This request is a Freewheel Live Mode request.
 
 @param program A string value providing the name of the current program. Freewheel needs this name in order to do the ad targeting. If nil, then ad targeting will be disabled.
 */

- (id<FWContext>)submitAdRequestForVevoTVWithCurrentProgramName:(NSString *)program controller:(id)controller baseView:(UIView *)baseView;

- (id<FWContext>)submitAdRequestForVevoTVWithCurrentChannel:(VMTVChannel *)channel controller:(id)controller baseView:(UIView *)baseView;


/**
 Make a request to get a video preroll ad for a specific video.
 @discussion This request is triggered before a video is played.
 */

- (id<FWContext>)submitAdRequestForVideo:(VMVideo *)video controller:(id)controller baseView:(UIView *)baseView;

/**
 Make a request to get a video preroll ad for a video in a specific playlist
 @discussion This request is triggered before a video is played.
 */

- (id<FWContext>)submitAdRequestForVideo:(VMVideo *)video inPlaylist:(NSString *)playlistId controller:(id)controller baseView:(UIView *)baseView;


@end

@protocol VMFreeWheelAdManagerDelegate
//
//- (void)adRequestFailed;
//- (void)playAds:(id<FWContext>)fwContext;

@optional
- (void)onReqComplete:(id<FWContext>)fwContext;

- (double)desiredBitrate;

@end
