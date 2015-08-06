//
//  VMMoviePlayerControllerDelegate.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 8/22/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//


@class VMMoviePlayerController;

@protocol VMMoviePlayerControllerDelegate <NSObject>

@optional

/** ------------------------------------------
 *   @name Player Event Callbacks.
 *  ------------------------------------------
 */

/**
 This method is called when the movie player is stopped by the user, or finished playing.
 
 When user clicks the Close button to stop the player, the player gets closed. And then this event will be triggered.
 
 @param player The movie player controller object.
 */
- (void)moviePlayerDidStop:(VMMoviePlayerController *)player;

/**
 This method is called when the movie player  finished playing current video.
 @param player The movie player controller object.
 */
- (void)moviePlayerDidFinishPlayingCurrentVideo:(VMMoviePlayerController *)player;


/**
 Called when the movie player fails to play a video.
 @param player The failing player controller.
 @param error VMError object that contains the error information.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player didFailWithError:(VMError *)error;


/**
 Called right after a preroll ad starts playing.
 @param player The player controller object.
 */
- (void)moviePlayerDidStartPlayingPreroll:(VMMoviePlayerController *)player;


/**
 Called right after a preroll ad finishes playing.
 @param player The player controller object.
 */
- (void)moviePlayerDidFinishPlayingPreroll:(VMMoviePlayerController *)player;

/**
 
 */
- (void)moviePlayer:(VMMoviePlayerController *)player didReceiveVideoNonTemporalAdSlot:(id)slot;

/**
 Called when the player successfully gets the list of related videos of the current playing video.
 @param player The player controller object.
 @param relatedVideos The list of related videos returned from the server.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player didGetRelatedVideos:(NSArray*)relatedVideos;


/**
 Called when the player successfully gets the list of artist videos of the current playing video.
 @param player The player controller object.
 @param artistVideos The list of videos from same artist returned from the server.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player didGetArtistVideos:(NSArray*)artistVideos;


/**
 Called right after the player plays the video that positions at index in the recommendations array.
 @param player The player controller object.
 @param index The index of the video that is played in the related video list.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player didStartPlayRelatedVidoesAtIndex:(NSUInteger)index;

/**
 Called right after the player plays the video that positions at index in the artist videos array.
 @param player The player controller object.
 @param index The index of the video that is played in the artist video list.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player didStartPlayArtistVidoesAtIndex:(NSUInteger)index;


/**
 Called right before the movie player is about start playing a video.
 @param player The player controller object.
 */
- (void)movieplayerWillStartPlaying:(VMMoviePlayerController *)player;


/** ------------------------------------------
 *   @name Touch Event Callbacks.
 *  ------------------------------------------
 */

/**
 Called when user is dragging the movie controller thumb to scrub through the movie.
 @param player The player controller object.
 */
- (void)userBeganScrubbing:(VMMoviePlayerController *)player;

/**
 Called when user has released the movie thumb control to stop scrubbing through the movie.
 @param player The player controller object.
 */
- (void)userEndedScrubbing:(VMMoviePlayerController *)player;


/**
 Callback of the forward button on the control view.
 @param player The player controller object.
 @param sender Button object that sends the event.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player onForwardButtonTapped:(id)sender;

/**
 Callback of the full screen button on the control view.
 @param player The player controller object.
 @param sender fullscreen buttton object that sends the event.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player onFullScreenButtonTapped:(id)sender;

/**
 Callback of the full screen button on the control view.
 @param player The player controller object.
 @param sender close buttton object that sends the event.
 */
- (void)moviePlayer:(VMMoviePlayerController *)player onCloseButtonTapped:(id)sender;

/**
 Callback of touch of player control view.
 @param player The player controller object.
 @param sender close buttton object that sends the event.
 */
- (void)moviePlayerGetTouchOnControlView:(VMMoviePlayerController *)player ;

@end
