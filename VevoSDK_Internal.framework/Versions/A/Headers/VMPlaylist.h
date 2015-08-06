//
//  VMPlaylist.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/15/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMVideo.h"

/**
    Type of playlist.
 */
typedef NS_ENUM(NSInteger, VMPlaylistType) {
    
    /** User's custom playlist. Created by an end user. */
	VM_PLAYLIST_TYPE_USER,
    
    /** VEVO official playlist. End user cannot overwrite it. */
	VM_PLAYLIST_TYPE_VEVO
};


/**
    Playlist data class.
 */
@interface VMPlaylist : VMEntityBase

/**
    A string value representing the playlist ID. This is a system-generated random string.
 */
@property (nonatomic, strong, readonly) NSString          *playlistId;

/**
    Playlist name.
 */
@property (nonatomic, strong, readonly) NSString          *title;

/**
    The description of the playlist.
 */
@property (nonatomic, strong, readonly) NSString          *playlistDescription;


/**
    Type of this playlist.
 */
@property (nonatomic, readonly) VMPlaylistType            playlistType;

/**
    Video count.
 */
@property (nonatomic, readonly) NSInteger                 videoCount;

/**
    Videos array.
 */
@property (nonatomic, strong, readonly) NSMutableArray    *videos;

/**
    A short vevo.ly URL that points to the playlist watch page on vevo.com.
 */
@property (nonatomic, strong, readonly) NSURL             *shortUrl;

/**
    The full URL that points to the playlist watch plage on vevo.com.
 */
@property (nonatomic, strong, readonly) NSURL             *webUrl;

/**
    The URL of the image file that represents this playlist.
 */
@property (nonatomic, strong, readonly) NSURL             *imageUrl;

/**
    The last modified date of this playlist.
 */
@property (nonatomic, strong, readonly) NSDate            *lastModifiedDate;

/**
    Class method to create a empty custom playlist.
 */
+ (VMPlaylist*)newPlaylist;

/**
    Class method to create a empty custom playlist with a given title.
 @param title Title of the playlist, cannot be empty.
 @return This class method creates a playlist object with a title information. A UUID is generated and used as the playlist's unique ID.
 */
+ (VMPlaylist*)newPlaylistWithTitle:(NSString*)title;

/**
    Class method to create a empty custom playlist wiht a given title and description.
 @param title Title of the playlist, cannot be empty.
 @param description Description of the playlist, can be empty string.
 @return This class method creates a playlist object with a title information. A UUID is generated and used as the playlist's unique ID.
 */
+ (VMPlaylist*)playlistWithTitle:(NSString*)title description:(NSString*)description;

/**
    Initialize a playlist with a dictionary of playlist info, with a given playlist type.
 
 @param dictionary A dictionary containing the playlist information.
 @param type Playlist type info.
 
 @return A newly instantiated VMPlaylist object.
 */
- (id)initFromDictionary:(NSDictionary *)dictionary type:(VMPlaylistType)type;

/** 
    @name Video Handling Methods
*/

/**
    Append a video object to the current video list.
 @param video Video object to be appended.
 */
- (void)appendVideo:(VMVideo *)video;

/**
    Remove a video from the video list.
 @param video Video object to be removed from the playlist.
 */
- (void)removeVideo:(VMVideo *)video;

/**
    Remove a video from the video list
 @param video Video Object to be removed from the playist.
 @param index Index of the video object in the playlist.
 */
- (void)removeVideo:(VMVideo *)video atIndex:(NSUInteger)index;

/**
 Move video from index to index
 */
- (void)moveVideoFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

/**
 Shuffle the videos of this playlist.
 @return An array of shuffled indexes of the videos in the original videos array. e.g. [2, 1, 4, 3, 5].
 */
- (NSArray *)shuffle;


/**
 Get the comma separated ISRCs of the videos in the playlist.
 */
- (NSString *)vectorizedIsrcs;

- (NSArray *)isrcArray;

- (void)updateTitle:(NSString *)newTitle;

/**
 Change the last modifiedDate to now
 */
- (void)updateLastModifiedDate;

/**
 Update with dictionary
 */
- (void)updateFromDictionary:(NSDictionary *)dictionary;

@end
