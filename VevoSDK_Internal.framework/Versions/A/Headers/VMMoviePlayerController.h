//
//  VMMoviePlayerController.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 7/2/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import "VMVideo.h"
#import "VMError.h"
#import "VMPlaylist.h"
#import "VMConstants.h"
#import "VMMoviePlayerControllerDelegate.h"
#import "VMShowEpisode.h"

/** Define Movie Player Control Styles */
typedef NS_ENUM(NSInteger, VMMovieControlStyle)
{
    /** Fullscreen style */
    VMMovieControlStyleFullscreen = 0,
    
    /** Set the default style to be fullscreen style */
    VMMovieControlStyleDefault = VMMovieControlStyleFullscreen,
    
    /** Embedded style */
    VMMovieControlStyleEmbedded,
    
    /** If control stype is none, the control bar will be hidden. */
    VMMovieControlStyleNone,
};

@interface VMMoviePlayerController : NSObject <UIGestureRecognizerDelegate>

/**
    The base view that the movie player is placed on. In order to play a video, a baseView must be provided to the VMMoviePlayerController object. However the controller itself does not hold the reference of the base view.
 */
@property (nonatomic, weak) UIView                                      *baseView;


/**
    A delegate object that conforms the <VMMoviePlayerContainerDelegate> protocal.
 */
@property (nonatomic, strong, readonly) VMVideo                         *currentVideo;


/**
    Delegate object that conforms the VMMoviePlayerControllerDelegate protocol.
 */
@property (nonatomic, assign) id<VMMoviePlayerControllerDelegate>         delegate;

 
/**
    THe control style of the movie player. The default value is VMMovieControlStyleFullscreen.
 */
@property (nonatomic) VMMovieControlStyle                               controlStyle;
 

/**
    The duration of the movie, or 0.0 if not known.
 */
@property(nonatomic, readonly) NSTimeInterval                           duration;

/**
    The amount of currently playable content, reflects the amount of content that can be played now.
 */
@property(nonatomic, readonly) NSTimeInterval                           playableDuration;

/**
 @property The amount of currently playable content, reflects the amount of content that can be played now.
 */
@property(nonatomic) NSTimeInterval                                     controlViewFadeoutDuration;


/**
 A Boolean value that determines whether continue play recommendation videos. 
 
 Setting the value of this property to YES will continue play recommendation videos after the current video finishes playing. The default value is NO.
 */
@property (nonatomic) BOOL                                              enableContinuousPlay;


/**
 A Boolean value that indicating whether AirPlay available.
 */
@property (nonatomic, readonly) BOOL   isAirPlayAvailable;

 
/**
 Indicates whether the player should show the Play Next button on the control panel. Default NO. When the Play Next button is present, clicking it during a video is playing will stop the current video and jumps to the next one on the recommended videos list, if enableContinuousPlay is set to YES.
 */
@property (nonatomic) BOOL showPlayNextButton;


/**
 Hide or show the full screen button on the bottom right corner of the player.
 */
@property (nonatomic) BOOL showFullscreenButton;


/**
 Enable/disable the feature of getting related videos. When YES, the player will call the server to get a list of related videos of the current video. Default NO.
 */
@property (nonatomic) BOOL disableRelatedVideos;


/**
 Enable/disable the feature of getting artist videos. When YES, the player will call the server to get a list of videos from the same artist of the current video. Default NO.
 */
@property (nonatomic) BOOL disableArtistVideos;


/**
 Volume of the player. 0.0 to 1.0.
 */
@property (nonatomic) float playerVolume;

/**
 Flag indicating whether there is an ad playling currently
 */
@property (nonatomic, readonly) BOOL adPlaying;


/**
 Flag indicating if we are current live streaming.
 */
@property (nonatomic, readonly) BOOL  isLiveStreaming;

/**
 Flag that will be set by the player itself when it's mirroring (NOT airplaying) on an external device either thru a cable or apple tv.
 */
@property (nonatomic, readonly) BOOL  isMirroring;

/**
 Boolean indicating whether we are in full screen mode.
 */
@property (nonatomic, readonly) BOOL  isFullscreen;


/**
    Initialize the movie player controller with a given base view.
 
    @param baseView A UIView object that will be the holder view of the movie player.
 
 */
- (id)initWithBaseView:(UIView *)baseView;



/**
    Call this method to stop the playback.
 */
- (void)stopPlayer;



/**
    Call this method to resume the player after pausing it.
 */
- (void)resume;


/**
    Call this method to pause the player. After successfully pause the player, the current playback state will become VMMoviePlaybackStatePaused.
*/
- (void)pause;


/**
    @return A boolean value indicating whether the movie player is current playing a video.
 */
- (BOOL)isPlaying;

/**
    @return A boolean value indicating whether the airplay is currently active.
 */
- (BOOL)isAirPlayVideoActive;


/**
    @return The current playback time from the player.
 */
- (NSTimeInterval)currentTime;


/**
    Move the playback cursor to a given time.
    
    Calling this method will cause the movie player seeks to the expected time position and start playing from there.
 
    @param time The time position of the video that we are seeking to.
 */
- (void)seekToTime:(NSTimeInterval)time;

/**
    Play a video.
    @param video A VMVideo object. If video is NULL, this method will not do anything.
 */
- (void)playVideo:(VMVideo *)video;


/**
    Play a video by its ISRC.
    @param isrc The ISRC of the video.
 */
- (void)playVideoByISRC:(NSString *)isrc;


/**
 Play a stream URL.
 @param streamURL The stream url.
 */
- (void)playStreamURL:(NSURL *)streamURL;


/**
    Play a playlist from a given index.
 
    @param sourcePlaylist A VMPlaylist.
    @param index Index of the video where the player will start. 
 */
- (void)playPlaylist:(VMPlaylist *)sourcePlaylist startingIndex:(NSInteger)index;

/**
    Play the recommended videos from a given index.
    @param index Index of the recommended videos where the player will start playing.
 */
- (void)playRecommendationAtIndex:(NSInteger)index;

/**
 Play the artist videos from a given index.
 @param index Index of the artist videos where the player will start playing.
 */
- (void)playArtistVideoAtIndex:(NSInteger)index;

/**
    Play the next video on the list. If the current video is on the end of the playlist, then we start over and play the first video.
 */
- (void)playNextVideo;

/**
    Play the previous video on the list.
 */
- (void)playPreviousVideo;


/**
    Register a time elapse observer of the player.
 
    This method is paired with the -(void)unregisterPlayerTimeObserver: method. A registered time observer must be unregistered at the end of the lifecycle.
 
    @param interval Time interval in seconds.
    @param cb Callback block that will be called in every interval seconds.
    @return A registered time observer object. 
 */
- (id)registerPlayerTimeObserverWithInterval:(double)interval callbackBlock:(void(^)(CMTime time))cb;


/**
    Unregister the given time observer.
 
    @param timeObserver A already registered time observer to the movie player.
 */
- (void)unregisterPlayerTimeObserver:(id)timeObserver;



@end
