//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//


#import "ConvivaContentInfo.h"
#import <MediaPlayer/MediaPlayer.h>

extern NSString *const ConvivaMPMoviePlayerPlaybackDidFinishNotification;

@interface ConvivaMPMoviePlayerController : MPMoviePlayerController

- (id)initWithConvivaContentInfo:(ConvivaContentInfo *)info;

- (id)initWithContentURLs:(NSArray *)contentURLs andConvivaContentInfo:(ConvivaContentInfo *)info;

- (void)setContentURLs:(NSArray *)contentURLs;

- (void)setContentURLs:(NSArray *)contentURLs andConvivaContentInfo:(ConvivaContentInfo *)info;

- (void)cleanup;

@end
