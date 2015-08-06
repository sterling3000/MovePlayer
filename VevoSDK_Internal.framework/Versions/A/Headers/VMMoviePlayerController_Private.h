//
//  VMMoviePlayerController_Private.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 9/23/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VevoSDK.h"
#import "VMPlayerOverlayObject.h"
#import "VMFreeWheelAdManager.h"
#import "VMTVChannel.h"


typedef NS_ENUM(NSInteger, VMMoviePlaybackState)
{
    
    VMMoviePlaybackStateStopped = 0,
    VMMoviePlaybackStatePlaying,
    VMMoviePlaybackStatePaused,
    VMMoviePlaybackStateInterrupted,
    VMMoviePlaybackStateSeekingForward,
    VMMoviePlaybackStateSeekingBackward
};

@interface VMMoviePlayerController()<VMFreeWheelAdManagerDelegate>

@property (nonatomic) BOOL          hideDefaultCloseButton;
@property (nonatomic) BOOL          hideDefaultVevoLogo;
/**
 @property A Boolean value that determines whether resume previous Google Chromecast video.
 */
@property (nonatomic) BOOL                              resumeGooglecastVideo;
/**
 When set to YES, the top tool bar will be disable and invisible. Default NO.
 */
@property (nonatomic, readwrite) BOOL                   disableTopBar;

/**
 *  Current playlist title.
 */
@property (nonatomic, strong) NSString                  *playlistTitle;


/**
 Current playback state.
 */
@property (nonatomic, readonly) VMMoviePlaybackState    playerbackState;

@property (nonatomic, strong) id<FWContext>             fwContext;

@property (nonatomic) BOOL                              isMiniPlayer;

@property (nonatomic, strong) UIView                    *adCounterDownView;

@property (nonatomic, weak) UIView                      *adBaseView;

@property (nonatomic) BOOL                              disableChromecast;

@property (nonatomic) BOOL userControlFullscreenButton;

@property (nonatomic) BOOL isFullScreenButtonExpand;

// ViewId is only for player statistics (Conviva)
@property (nonatomic, strong) NSString                  *viewerId;


//@property (nonatomic) BOOL                              disableAdInFirstPlay;


/**
 Ad instance currently playling
 */
@property (nonatomic, retain) id adInstance;

/**
 A boolean value that determines whether the player should monitor and receive the timed metadata. Default is NO. When set to YES,
 */
@property (nonatomic) BOOL                                              observeTimedMetaData;


- (void)onTouchPlayer;

- (void)userBeganScrubbing;

- (void)userEndedScrubbing;

- (BOOL)isShowingControlView;

/**
 Show a given player overlay view.
 
 @param overlayView An view object that conforms the <VMPlayerOverlayOvject> protocol.
 */
//- (void)showOverlay:(id<VMPlayerOverlayObject>)overlayView;

- (void)onLearnMorePressed:(id)sender;

- (void)adFadeInOutView:(UIView *)fadeInView;

- (void)fadeOutControlView;

- (void)fadeInControlView;

- (void)playVevoTVChannel:(VMTVChannel *)channel;

- (void)stopInternalPlayer;

@end
