//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//

#import "ConvivaContentInfo.h"
#import <Foundation/Foundation.h>

@interface ConvivaLightSession : NSObject

/*! \cond PRIVATE */
/// @brief Create a session and start monitoring with it.
///
/// Do NOT call directly. Use [LivePass createSessionWithStreamer:andStreamer:]
/// API instead.
+ (ConvivaLightSession *)startMonitoringStreamer:(id)streamer
                                 withContentInfo:(ConvivaContentInfo *)contentInfo
                                     withOptions:(NSDictionary*)options
                                  forSessionType:(bool)isGlobal;
/*! \endcond */

/// @brief Cleanup session. Should be called when a video session is over.
///
/// Releases the reference to montiored streamer. Session can be safely released
/// after this call
- (void) cleanup;

/// Send an custom event pertaining to the session
- (void)sendEvent:(NSString *)name withAttributes:(NSDictionary *)attributes;

/// Set content length in second for the monitored video
/// @deprecated
- (void)setContentLength:(NSInteger)contentLength;

/// Notify that ad has started
- (void)adStart;

/// Notify that ad has ended
- (void)adEnd;

/// Set the resource for the session
- (void)setCdnNameOrResource:(NSString*) cdnNameOrResource;

/// Report a fatal error and use specified error message
- (void)reportError: (NSString *)errorMsg;

/// Attach streamer to specified streamer */
- (void)attachStreamer: (id)streamer;

/// @brief Pause session monitoring such that it can be resumed later
/// @note The existing streamer is detached from the session.
/// @see attachStreamer()
- (void)pauseMonitor;

/// @brief Set the current bitrate
- (void)setBitrate: (int)bitrateKbps;

@end
