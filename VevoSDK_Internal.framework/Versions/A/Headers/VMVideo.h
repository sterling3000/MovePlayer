//
//  VMVideo.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

/**
    An anonymous enumeration type VMVideoStreamingType to provide three different types of video streaming.
 */
typedef NS_ENUM(NSInteger, VMVideoStreamingType) {
    
    /** Video On Demand. This is the regular streaming type and video is streamed VOD when user picks to play any video from the app. */
    VMVideoStreamingTypeOnDemand,
    
    /** Live stream with single live stream. Apply to most of the live on letterman videos. */
    VMVideoStreamingTypeLive,
    
    /** Live Stream with multiple camera angles. Each camera angle provides a different view of this live event. */
    VMVideoStreamingTypeLiveWithMultipleCameras,
    
    /** Live Stream with multiple stages. For example, front stage, back stange, red carpet ,... */
    VMVideoStreamingTypeLiveWithMultipleStages
};



/**
    Video object data class.
 */
@interface VMVideo : VMEntityBase


/**
    The ISRC of this video. 
 */
@property (nonatomic, strong, readonly) NSString      *isrc;

/**
    Title of this video.
 */
@property (nonatomic, strong, readonly) NSString      *title;

/**
    The URL safe name of this video. A url safe name is a string composed with letters, numbers, dashes, and underscroes only that represents this video. We use this value when we make API calls regarding this video.
 */
@property (nonatomic, strong, readonly) NSString      *urlSafeTitle;

/**
    An array of VMRendition objects. Each rendition contains the information of the actual HLS streams. This array should contain at least one item but usually more than one items. 
 */
@property (nonatomic, strong) NSArray       *renditions;


/**
 An array of VMRendition objects for google chromecast, we should use renditions when google support HLS.
 */
@property (nonatomic, copy) NSArray       *googlecastRenditions;



/**
    An integer value that represents the streaming type of this video. There are 3 streaming types. Please refer to <VMVideoStreamType>.
 */
@property (nonatomic, readonly) VMVideoStreamingType      streamingType;


/**
    A string value indicating the name of the genre of this video.
 */
@property (nonatomic, readonly) NSString      *genre;


/**
    A boolean value indicating whether this video is premiere or not.
 */
@property (nonatomic, readonly) BOOL        isPremiere;

/**
    A boolean value that indicates whether this video is a explicit video.
 */
@property (nonatomic, readonly) BOOL        isExplicit;

/**
    A boolean value that indicates whether the current video object contains the extended information such as the rendition info. (v1)
 */
@property (nonatomic, readonly) BOOL        isExtended;

/**
    Whether this video is a live stream.
 */
@property (nonatomic, readonly) BOOL        isLiveStream;


/**
 Whether this video is active.
 */
@property (nonatomic, readonly) BOOL        isActive;

/**
    An arry containing the credits information of the video. Each element of the array is a VMVideoCredit object.
 */
@property (nonatomic, strong, readonly) NSArray             *credits;


/**
    During of this video represented in number of seconds. 
 */
@property (nonatomic, readonly) NSInteger                   duration;

/**
    Current view count in total of this video.
 */
@property (nonatomic, readonly) NSInteger                   viewcount;

/**
    A string value of the view count that is localizedly formatteed in the format of "100,000 views".
 */
@property (nonatomic, strong, readonly) NSString      *formattedViewcount;

/**
    Returns an array of raw artist dictionaries associated with the video
 */
@property (nonatomic, strong, readonly) NSArray       *artists;

/**
    The artist(s) of this video represented in the way of "main artist ft. featured artist"
 */
@property (nonatomic, strong, readonly) NSString      *artist;


/**
    Name of the main artist of this video.
 */
@property (nonatomic, strong, readonly) NSString      *mainArtist;


/**
    The URL safe name of the main artist. Refer to class <VMArtist>.
 */
@property (nonatomic, strong, readonly) NSString      *mainArtistUrlSafename;


/**
    The URLs of the buy links of this video.
 */
@property (nonatomic, strong, readonly) NSArray     *buyLinks;

/**
 Name of the director of this video.
 */
@property (nonatomic, strong, readonly) NSString    *director;

/**
 Name of the composer of this video.
 */
@property (nonatomic, strong, readonly) NSString    *composer;

/**
 Name of the producer of the video.
 */
@property (nonatomic, strong, readonly) NSString    *producer;

/**
 Name of the record label.
 */
@property (nonatomic, strong, readonly) NSString    *recordLabel;

/**
    URL of the image of this video.
 */
@property (nonatomic, strong, readonly) NSURL       *imageUrl;

/**
 Copyright
 */
@property (nonatomic, weak, readonly) NSString      *copyright;

/**
 Year in string.
 */
@property (nonatomic, weak, readonly) NSString      *year;

/**
 A vevo.ly short url tha that points to the video on vevo.com.
 */
@property (nonatomic, strong, readonly) NSURL       *shortUrl;

/**
 Stream URLs. Extracted from the rendition info of this video.
 */
@property (nonatomic, weak, readonly) NSArray       *streamUrls;

/**
 Stream URL for conviva fallback.
 */
@property (nonatomic, weak, readonly) NSURL       *fallbackStreamUrl;

/**
 Release date of this video.
 */
@property (nonatomic, weak, readonly) NSDate        *releaseDate;

/**
 When NO, we should not play any ad.
 */
@property (nonatomic, readonly) BOOL                monetizable;

/**
 genres for this video
 */
@property (nonatomic, strong) NSArray               *genres;

/**
 categories for this video (MusicVideo, LivePerformance, etc)
 */
@property (nonatomic, strong) NSArray               *categories;

/**
 Whether this video is MusicVideo.
 */
@property (nonatomic, readonly) BOOL        isMusicVideo;

/**
    Update the current video object with more information.
 
    Call this method to update the video data once we get a new dictionary of video info from our API call.
 
    @param dictionary A NSDictionary object that contains video data.
 
 */
- (void)updateVideoWithDictionary:(NSDictionary *)dictionary;

- (NSArray *)subVideosForMultipleCameraLiveStream;

- (void)updateVideoRenditions:(NSArray *)renditions;

- (NSString*)titleWithDashes;

@end
