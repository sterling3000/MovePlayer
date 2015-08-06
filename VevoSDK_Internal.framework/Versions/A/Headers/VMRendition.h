//
//  VMRendition.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//



#import "VMEntityBase.h"
#import "VMVideo.h"

@interface VMRendition : VMEntityBase

@property (nonatomic, readonly) NSInteger           version;

/**
    The URL of the stream presented in this rendition.
 */
@property (strong, nonatomic, readonly) NSURL       *streamUrl;


/**
 Boolean value indicating whether this rendition is a LIVE stream.
 */
@property (nonatomic, readonly) BOOL                isLiveStream;

@property (nonatomic, readonly) BOOL                isMultipleCameras;

@property (nonatomic, strong, readonly) NSString    *cameraName;

/**
 Streaming type of this rendition. Refer to VMVideoSteamingType.
 */
@property (nonatomic, readonly) VMVideoStreamingType  streamingType;

@property (nonatomic, readonly) NSString            *streamingTypeName;

/**
 Rendition type. Similar to streamingType. This is the actual value returned from the API v2.
 */
@property (nonatomic, strong, readonly) NSString    *renditionType;

/**
 Audio bitrate
 */
@property (nonatomic, readonly) NSUInteger          audioBitRate;

/**
 Audio Sample rate.
 */
@property (nonatomic, readonly) NSUInteger          audioSampleRate;

/**
 Video bitrate.
 */
@property (nonatomic, readonly) NSUInteger          videoBitRate;

/**
 Total bitrate
 */
@property (nonatomic, readonly) NSUInteger          totalBitRate;

/**
 Frame height.
 */
@property (nonatomic, readonly) int                 frameHeight;

/**
 Frame width.
 */
@property (nonatomic, readonly) int                 frameWidth;

/**
 Thumbnail image of the rendition. Could be the thumbnail of the camera angle or stage.
 */
@property (nonatomic, strong, readonly) NSURL       *thumbnailUrl;


@end
