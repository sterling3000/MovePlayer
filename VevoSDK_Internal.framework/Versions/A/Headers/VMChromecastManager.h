//
//  VMChromecastManager.h
//  vevo-ios-sdk
//
//  Created by Hxu on 2/12/14.
//  Copyright (c) 2014 Vevo. All rights reserved.
//

#import "VMInternalConstants.h"

#ifndef disable_chromecast

#import <Foundation/Foundation.h>
#import "VMVideo.h"
#import <UIKit/UIKit.h>
#import <GoogleCast/GoogleCast.h>

#define kVevoGCKPlayerStateChangeNotificationName @"kVevoGCKPlayerStateChangeNotification"

#define kVevoGCKPlayerLoadStatusChangeNotificationName @"kVevoGCKPlayerLoadStatusChangeNotification"

#define kVevoGCKDeviceAvailibilityChangeNotificationName @"kVevoGCKDeviceAvailibilityChangeNotification"

#define kVevoGCKEnableStateChangeNotificationName @"kVevoGCKEnableStateChangeNotification"

#define kVevoGCKStartConnectingNotificationName @"kVevoGCKStartConnectingNotification"

#define kVevoGCKResumeVideoNotificationName @"kVevoGCKResumeVideoNotificationName"

#define kReturnToGooglecastHasShownUpKey  @"kReturnToGooglecastHasShownUpKey"

@interface VMChromecastManager : NSObject

/*
 A Boolean value indicating whether Google chrome cast device available. (read-only)
 */
@property (nonatomic, readonly) BOOL isGooglecastDeviceAvailable;

/*
 A Boolean value indicating whether there is a Google chrome cast device selected. (read-only)
 */
@property (nonatomic, readonly) BOOL enableGooglecast;

/*
 A Boolean value indicating whether Google chrome cast session started. (read-only)
 */
@property (nonatomic) BOOL sessionHasStarted;

/*
 A Boolean value indicating whether video stream loaded. (read-only)
 */
@property (nonatomic) BOOL streamLoaded;

/*
 A Boolean value indicating whether casting Ad. (read-only)
 */
@property (nonatomic, readonly) BOOL isCastingAd;

/*
 A Boolean value indicating whether Google chrome cast failed to load media. (read-only)
 */
@property (nonatomic) BOOL mediaFailedToLoad;


/** The current media stream position. */
@property(nonatomic, readonly) NSTimeInterval currentStreamPosition;

/** The current media player stream duration. */
@property(nonatomic, readonly) NSTimeInterval currentStreamDuration;

/** The current playing video. */
@property(nonatomic, strong) VMVideo* currentVideo;

/** The current selected device. */
@property (nonatomic, strong) GCKDevice *selectedDevice;

/** The current media player state. */
@property(nonatomic, readonly) GCKMediaPlayerState playerState;

/**
 Class object. A convenient static instance of the manager, since apps will almost always use a single shared instance
 
 @return A static instance of the class.
 */
+ (VMChromecastManager*)sharedInstance;

/** Returns true if connected to a Chromecast device. */
- (BOOL)isConnected;

/** Returns true if media is loaded on the device. */
- (BOOL)isPlayingMedia;

/**
 Get number of available devices.
 
 @return The number of available chrome cast devices.
 */
- (int) numberOfDevices;

/**
 Start scan chrome cast devices.
 */
- (void)startScan;

/**
 Stop scan chrome cast devices.
 */
- (void)stopScan;

/**
 Request media channel status update if channel exist.
 */
- (void)requestStatusUpdateIfPossible;

/**
 Select specified chrome cast device from device list.
 
 @param index The index of selected chrome cast device.
 */
- (void)selectDeviceAtIndex:(int)index;

/**
 Displays a selection list of available chromecast devices.
 
 @param view The view from which the device list action sheet originates.
 @param delegate The receiver’s delegate object. The delegate is used to respond to taps in the action sheet and should usually be provided.
 */
-(void)showDevicesInView:(UIView*)view;

/**
 Displays a disconnect menu for selected chromecast device.
 
 If display disconnect menu not from player, and video is still playing, there will be Return to Video option in disconnect menu.
 
 @param view The view from which the disconnect action sheet originates.
 @param isFromPlayer A boolean value indicates whether displayed inside player.
 @param delegate The receiver’s delegate object, the delegate is used to respond to taps in the action sheet and should usually be provided.
 */
-(void)showDisconnectInView:(UIView*)view fromPlayer:(BOOL)isFromPlayer;

/**
 Play a video on selected chromecast device.
 
 @param video The video to play.
 @param position The start playback position.
 */
- (BOOL)playVideoOnSelectedDevice:(VMVideo*)video fromPosition:(NSTimeInterval)position;

/**
 Play FreeWheel ad on selected chromecast device.
 
 @param adURL The stream URL of FreeWheel ad.
 */
- (void)playFWAdOnSelectedDevice:(NSString*)adURL;

/**
 Pauses playback of selected chromecast device.
 */
- (void)pauseVideo;

/**
 Resumes playback of selected chromecast device.
 */
- (void)resumeVideo;

/**
 Moves the playback cursor to a given time.
 
 @param playbackPosition The time to which to move the playback cursor.
 */
- (void)playStreamFrom:(NSTimeInterval) playbackPosition;


/**
 Change the audio volume of the player.
 
 @param volume The volume to set.
 */
- (void)changeVolume:(double)volume;

/**
 Disconnect Chrome cast application session.
 */
- (void)disconnectSession;

- (GCKMediaPlayerIdleReason) playerIdleReason;

@end

#endif

//@protocol VMChromecastMenuDelegate <NSObject>
//
//- (void)chromecastMenuDidSelectResume;
//
//@optional
//- (void)chromecastMenuDidSelectDisconnect;
//
//- (void)chromecastMenuDidSelectCancel;
//
//@end

