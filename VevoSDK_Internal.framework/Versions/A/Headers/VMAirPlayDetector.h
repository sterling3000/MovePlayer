//
//  VMAirPlayDetector.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/15/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MPMoviePlayerController.h>
#import <MediaPlayer/MediaPlayer.h>


/*
 * Does the job of detecting whether this device can connect to an Apple TV or whatever using AirPlay.  It uses a hack with MPVolumeButton to overcome the fact that the framework has no properties or events for this information, which seems pretty silly to me.
 
 To use it, simply put the following code in your app, typically in appdelegate during applicationDidFinishLaunchingWithOptions:
 [[AirPlayDetector defaultDetector] startMonitoring:window];
 
 A notification will be posted when availability changes: AirPlayAvailabilityChanged
 
 Or you can query availability by: [AirPlayDetector defaultDetector].isAirPlayAvailable
 
 */
@interface VMAirPlayDetector : NSObject

/*
 * When true, there are available airplay devices to play to.
 */
@property (readonly, nonatomic) BOOL isAirPlayAvailable;

/*
 * A convenient static instance of the detector, since apps will almost always use a single shared instance.
 */
+ (VMAirPlayDetector*)defaultDetector;

/*
 * Begins the process of monitoring for changes in airplay availability.
 */
- (void)startMonitoring:(UIWindow*)window;


@end
