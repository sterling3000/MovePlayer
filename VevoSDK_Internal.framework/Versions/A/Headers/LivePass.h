//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//
//  LivePass version 2.83.0.19914
//

#import "ConvivaContentInfo.h"
#import "ConvivaLightSession.h"
#import <Foundation/Foundation.h>

#define OPTION_EXTERNAL_BITRATE_REPORTING @"externalBitrateReporting"

/// @mainpage
/// @author Saiguang Che
///
/// The top level class for customer interaction is LivePass. Additional api
/// is available in ConvivaLightSession.

@interface LivePass : NSObject

/// @brief Initialize the LivePass module
///
/// See Conviva integration guide for details of how to use this method.
/// \param customerKey a key assigned by Conviva to uniquely identify a
///   Conviva customer
+ (void)initWithCustomerKey:(NSString *)customerKey;

/// @brief Initialize LivePass with advanced settings parameters
///
/// \param customerKey a key assigned by Conviva to uniquely identify a
///   Conviva customer
/// \param settings a dictionary with string keys and object values
+ (void)initWithCustomerKey:(NSString *)customerKey
                andSettings:(NSDictionary *)settings;

/// @brief Cleanup all the sessions owned by LivePass
+ (void)cleanup;

/// @brief Create a session for LivePass
///
/// \param streamer can be a subclass of ConvivaStreamerProxy, AVPlayer,
///   MPMoviePlayerController, ConvivaMPMoviePlayerController or a null
///   object
/// \param contentInfo Info related to the content (url, etc)
+ (ConvivaLightSession *)createSessionWithStreamer:(id)streamer
                             andConvivaContentInfo:(ConvivaContentInfo *)contentInfo;

/// @brief Create a session for LivePass
///
/// \param streamer can be a subclass of ConvivaStreamerProxy, AVPlayer,
///   MPMoviePlayerController, ConvivaMPMoviePlayerController or a null
///   object
/// \param contentInfo Info related to the content (url, etc)
/// \param options Options that modify session behavior
+ (ConvivaLightSession *)createSessionWithStreamer:(id)streamer
                             andConvivaContentInfo:(ConvivaContentInfo *)contentInfo
                                        andOptions:(NSDictionary*) options;

/// @brief Cleanup session. Should be called when a video session is over.
///
/// \param session The session to be cleaned
+ (void)cleanupSession:(ConvivaLightSession *)session;

/// @brief Toggle on/off console traces.
///
/// \param on pass true to enable console trace, false otherwise
+ (void)toggleTraces:(BOOL)on;

/// @brief This function is used to send Conviva Player Insights Event,
/// not associated with a video session. Events have a name and a list of
/// key value pairs as event attributes
///
/// \param name A name for the event
/// \param attributes A dictionary of key value pair associated with the
///   event
+ (void)sendEvent:(NSString *)name withAttributes:(NSDictionary *)attributes;

/// Notify that ad has started
+ (void)adStart:(ConvivaLightSession *)session;
/// Notify that ad has ended
+ (void)adEnd:(ConvivaLightSession *)session;

/// @brief Set the current bitrate
///
/// \param session The session
/// \param bitrateKbps The new bitrate. The bitrate is ignored if -1
/// \note To use this method, session should be created with the
///   sessionOptions parameter OPTION_EXTERNAL_BITRATE_REPORTING
///   set to true.
+ (void)setBitrate:(ConvivaLightSession*)session :(int)bitrateKbps;

/// @brief Set
/// @brief True if library has been initialized
///
/// \deprecated Not used and to be phased out
+ (BOOL)ready;

@end

@interface LivePass (Precision)


/// @brief Generate VRL with array of URLs and ConvivaContentInfo.
///
/// \param URLs an array of NSURL instances
/// \param info an instance of ConvivaContentInfo
///
/// \return an URL that follows Conviva VRL specification
+ (NSURL*)generateVRL:(NSArray*)URLs withContentInfo:(ConvivaContentInfo*)info;

/// @brief Start monitoring for fallback.
///
/// \param object   an object to which the selector message will be sent on failure
/// \param selector a message that will be sent when fallback needed
/// \param session  ConvivaLightSession instance that is monitored for fallback
+ (void)startFallbackMonitoring:(id)object selector:(SEL)selector forSession:(ConvivaLightSession*)session;

/// @brief Stop monitoring for fallback.
///
/// \param session ConvivaLightSession instance that is monitored for fallback
+ (void)stopFallbackMonitoringForSession:(ConvivaLightSession*)session;

/// @brief Determine whether fallback is needed when an error occurs.
///
/// \param session ConvivaLightSession instance that is monitored for fallback
+ (BOOL)needFallbackOnError:(ConvivaLightSession*)session;

@end
