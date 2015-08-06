//
//  VMApiFacade.h
//  VEVO
//
//  Created by Harry Xu on 3/12/13.
//  Copyright (c) 2013 VEVO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMConstants.h"



@class VMVideo, VMError, VMArtist, VMUser, VMPlaylist, VMUserIdentity, VMShow, VMPaging;


@interface VMApiFacade : NSObject

/**
 Class object.
 
 @return A static instance of the class.
 */
+ (VMApiFacade *)sharedInstance;

#pragma mark - API v2 --- Videos ---
/**---------------------------------------------------------------------------------------
 * @name Video APIs
 *  ---------------------------------------------------------------------------------------
 */


/**
 Get a chunk of videos with given filter type and genre.
 
 @param type Filter type, e.g. MostViewedLastDay, ...
 @param genre String representation of a genre. 
 @param page A integer number indicating the page number of the videos that we are requesting.
 @param size A integer number indicating the number of videos we are requesting on each page.
 @param live Boolean value indicating whether we only request LIVE videos.
 @param premiere Boolean value indicating whether we only request for Premiere videos.
 @param isExplicit An VMIsExplicitFilterType enum. See VMIsExplicitFilterType for options.
 @param completion A callback block. success indicates whether the request is good. videos is an NSArray object that contains all the top videos requested, if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getVideosForOrder:(VMVideoFilterType *)type
                    genre:(NSString *)genre
                     page:(int)page
                     size:(int)size
                   isLive:(BOOL)live
               isPremiere:(BOOL)premiere
               isExplicit:(VMVideoExplicitFilterType)explicitFilter
               completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;


/**
 Get a chunk of videos with given filter type and genre.
 
 @param type Filter type, e.g. MostViewedLastDay, ...
 @param genre String representation of a genre.
 @param page A integer number indicating the page number of the videos that we are requesting.
 @param size A integer number indicating the number of videos we are requesting on each page.
 @param live Boolean value indicating whether we only request LIVE videos.
 @param premiere Boolean value indicating whether we only request for Premiere videos.
 @param isExplicit An VMIsExplicitFilterType enum. See VMIsExplicitFilterType for options.
 @param minYear A string value indicating the minimum year of the expected videos.
 @param maxYear A string value indicating the maximum year of the expected videos.
 @param completion A callback block. success indicates whether the request is good. videos is an NSArray object that contains all the top videos requested, if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getVideosForOrder:(VMVideoFilterType *)type
                    genre:(NSString *)genre
                     page:(int)page
                     size:(int)size
                   isLive:(BOOL)live
               isPremiere:(BOOL)premiere
               isExplicit:(VMVideoExplicitFilterType)explicitFilter
                  minYear:(NSString *)minYear
                  maxYear:(NSString *)maxYear
               completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;

/**
 Get a chunk of videos with given filter type and genre.
 
 @param type Filter type, e.g. MostViewedLastDay, ...
 @param genre String representation of a genre.
 @param page A integer number indicating the page number of the videos that we are requesting.
 @param size A integer number indicating the number of videos we are requesting on each page.
 @param minYear A string value indicating the minimum year of the expected videos.
 @param maxYear A string value indicating the maximum year of the expected videos.
 @param completion A callback block. success indicates whether the request is good. videos is an NSArray object that contains all the top videos requested, if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getVideosForOrder:(VMVideoFilterType *)type genre:(NSString *)genre page:(int)page size:(int)size minYear:(NSString *)minYear maxYear:(NSString *)maxYear completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;


/**
 Get a specific video with the given ISRC value.
 
 @param isrc ISRC value. 
 @param completion Callback block. success indicates whether the request is good. Video is an VMVideo object that contains all the video metadata as long as the rendition information, if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getVideoWithIsrc:(NSString *)isrc completion:(void(^)(BOOL success, VMVideo *video, VMError *error))completion;

/**
 Get the renditions array for a video
 
 @param isrc ISRC value of a video.
 @param type A string value representing the type fo the stream. Possible values include:"hls", "mp4"
 @param completion Callback block. success indicates whether the request is good. Renditions is an NSArray object that contains all the rendition data, if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getVideoRenditionsWithIsrc:(NSString *)isrc streamType:(NSString *)type completion:(void(^)(BOOL success, NSArray *renditions, VMError *error))completion;

/**
 Get videos of a specific artist on a page.
 
The way we get penetrated vidoes of an artist is based on page by page. However, we cannot jump page forward. i.e. if we have not requested videos on page 2, we cannot request videos on page 3.
 
 @param artistSafeName Artist's url safe name, a.k.a artist's id.
 @param page Page number of the requested videos. Page starts with 1, passing 0 will return errors. If the total number of pages is 5, page can only be a number from 1 thru 5.
 @param size Number of videos on a page.
 @param completion Callback block.success indicates whether the request is good. videos is an NSArray object that contains all the videos of this artist requested, if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getVideosOfArtist:(NSString *)artistSafeName page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;


/**
 Get related videos of a specific video.
 @param isrc ISRC of a input video.
 @param completion Callback block.
 */
- (void)getRelatedVideos:(NSString *)isrc completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;

/**
 Get a list of VEVO Staff-picked videos in the trend.
 @param completion Callback block. Each element inside array videos is a VMVideo object representing a staff-picked video.
 */
- (void)getStaffPickedVideosWithCompletion:(void(^)(BOOL success, NSArray *vidoes, VMError *error))completion;

/**
 Get a list of VEVO Featured videos in the trend.
 @param completion Callback block. Each element inside array videos is a VMVideo object representing a Featured video.
 */
- (void)getFeaturedVideosWithCompletion:(void(^)(BOOL success, NSArray *vidoes, VMError *error))completion;

/**
 Get a list of premieres vidoes.
 @param type Filter type, e.g. MostViewedLastDay, ...
 @param genre String representation of a genre.
 @param page A integer number indicating the page number of the videos that we are requesting.
 @param size A integer number indicating the number of videos we are requesting on each page.
 @param completion Callback block. Each element inside array videos is a VMVideo object representing a Featured video.
 */
- (void)getPremiereVideosForOrder:(VMVideoFilterType *)type genre:(NSString *)genre page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *posts, VMError *error))completion;

#pragma mark - API v2 --- Artists ---
/**---------------------------------------------------------------------------------------
 * @name Artist
 *  ---------------------------------------------------------------------------------------
 */

/**
 Get artists.
 @param type            A string value that defines a filter type. Refer to VMArtistsFilterType for possible values.
 @param genre           A genre's url safe name.
 @param page            Page number of the artists.
 @param size            Size of requested artists on page page.
 @param completion      Completion callback block. Each element in the artists array is a VMArtist instance object.
 */
- (void)getArtistsForOrder:(VMArtistFilterType *)type genre:(NSString *)genre page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;


/**
 Get top artists for selected genres.
 @param type            A string value that defines a filter type. Refer to VMArtistsFilterType for possible values.
 @param genres          list of genres.
 @param page            Page number of the artists.
 @param size            Size of requested artists on page page.
 @param completion      Completion callback block. Each element in the artists array is a VMArtist instance object.
 */
- (void)getArtistsForOrder:(VMArtistFilterType *)type genres:(NSArray *)genres page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;


/**
 Get artists that are related to a given vide.
 @param isrc            A video ISRC
 @param completion      Completion callback block. Each element in the artists array is a VMArtist instance object.
 */
- (void)getArtistsByIsrc:(NSString *)isrc completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;


/**
 Get a list of similar artists to a given group of artists.
 @param artists         Array of given artists.
 @param completion      Completion callback block. Each element in the artists array is a VMArtist instance object.
 */
- (void)getRelatedArtistsWithArtists:(NSArray *)artists completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;


/**
 Get an artist by a specific artist.
 @param artist          artist's URL safe name.
 @param completion      Completion callback block.
 */
- (void)getArtistBySafeName:(NSString *)artist completion:(void(^)(BOOL success, VMArtist *artist, VMError *error))completion;


/**
 Get artist bio.
 @param artist          The URL safe name of a given artist.
 @param completion      Completion callback block.
 */
- (void)getArtistBio:(NSString *)artist completion:(void(^)(BOOL success, NSString *bio, VMError *error))completion;


/**
 Get artists buylinks.
 @param artist          The URL safe name of a given artist.
 @param completion      Completion callback block.
 */
- (void)getArtistBuylinks:(NSString *)artist completion:(void(^)(BOOL success, NSArray *buylinks, VMError *error))completion;


/**
 Get artist events.
 @param artist          The URL safe name of a given artist.
 @param completion      Completion callback block.
 */
- (void)getArtistEvents:(NSString *)artist completion:(void(^)(BOOL success, NSArray *events, VMError *error))completion;


/**
 Get similars artists to a given artist.
 @param artist          The URL safe name of a given artist.
 @param completion      Completion callback block.
 */
- (void)getSimilarArtists:(NSString *)artist completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;


/**
 Get videos by a given artist
 @param artist          The URL safe name of a given artist.
 @param page            Page of content.
 @param size            number of videos we are requesting on this page.
 @param completion      Completion callback block.
 */
- (void)getArtistVideos:(NSString *)artist page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;


#pragma mark - API v2 --- Shows ---
/**---------------------------------------------------------------------------------------
 * @name Shows
 *  ---------------------------------------------------------------------------------------
 */

/**
 Get a list of VEVO Shows.
 @param completion      Completion callback block. Each element in the shows array is a VMShow object that contains the show data. Refer to VMShow for detailed information of the show object.
 */
- (void)getShowsWithCompletion:(void(^)(BOOL success, NSArray *shows, VMError *error))completion;

/**
 Get a list of VEVO Shows without the detailed episodes info from each show.
 @param completion      Completion callback block. Each element in the shows array is a VMShow object that contains the show data. Refer to VMShow for detailed information of the show object.
 */
- (void)getShowsWithoutEpisodesWithCompletion:(void(^)(BOOL success, NSArray *shows, VMError *error))completion;

/**
 Get a single show.
 @param slug            Name of the show
 @param completion      Completion callback block. Refer to VMShow for detailed information of the show object.
 */
- (void)getShowBySlug:(NSString *)slug withCompletion:(void(^)(BOOL success, VMShow *show, VMError *error))completion;

/**
 Get a list of the emerging (a.k.a. LIFT) artists from server. 
  @param completion      Completion callback block. Each element in the shows array is a VMShowArtist object that contains the show artist data. Refer to VMShowArtist for detailed information of this object.
 */
- (void)getEmergingArtistsWithCompletion:(void(^)(BOOL success, NSArray *showArtists, VMError *error))completion;

/**
 Get a list of the certified artists from server.
 @param completion      Completion callback block. Each element in the shows array is a VMShowArtist object that contains the show artist data. Refer to VMShowArtist for detailed information of this object.
 */
- (void)getCertifiedArtistsWithcompletion:(void(^)(BOOL success, NSArray *showArtists, VMError *error))completion;

#pragma mark - API v2 --- Resouces ---
/**---------------------------------------------------------------------------------------
 * @name Resouces
 *  ---------------------------------------------------------------------------------------
 */

/**
 Get localized all genres information.
 @param completion      Completion callback bock. genres array consists of all the returned VMGenre object.
 */
- (void)getAllGenres:(void(^)(BOOL success, NSArray *genres, VMError *error))completion;


#pragma mark - API v2 --- Search ---
/**---------------------------------------------------------------------------------------
 * @name Search
 *  ---------------------------------------------------------------------------------------
 */

/**
 Search
 
 In API v2 we only use this method to handle search.
 
 @param q               Search term. Cannot be empty.
 @param artistsLimit    limit of artists in the return payload.
 @param videosLimit     limit of videos in the return payload.
 @param skippedArtists  Number of skipped artists.
 @param skippedVideos   Number of skipped videos.
 @param completion      Completion callback block. artists contains all the returned artists that matches the search term. videos contains all the returned videos that matches the search term. The number of the items in these 2 arrays is less than or equal to the limit of the requested artists or videos. Each item of the artist array is an instance of the VMSearchResultArtist class. Each item of the video array is an instance of the VMSearchResultVideo class.
 */
- (void)searchWithTerm:(NSString *)q videosLimit:(int)videosLimit skippedVideos:(int)skippedVideos completion:(void(^)(BOOL success, NSArray *artists, NSArray *videos, VMError *error))completion;

#pragma mark - API v2 --- VEVO TV ---
/**---------------------------------------------------------------------------------------
 * @name VEVO TV
 *  ---------------------------------------------------------------------------------------
 */


/**
 Get vevo tv channels information with their tv shows within the next given hours.
 @param withShows       Boolean value indicating whether we are reqeusting the show information too. If YES, the information the shows of each channel will also be included in the returned channels data.
 @param hoursAhead      Number of hours ahead.
 @param completion      Completion callback block. Each element inside array channels is a VMTVChannel instance object.
 */
- (void)getVevoTVChannelsWithShows:(BOOL)withShows hoursAhead:(int)hoursAhead completion:(void(^)(BOOL success, NSArray *channels, VMError *error))completion;


/**
 Get vevo tv shows information of all the channels, within the next given hours.
 @param hoursAhead      Number of hours ahead.
 @param completion      Completion callback block. Each element inside array channels is a VMTVShow instance object.
 */
- (void)getVevoTVShows:(int)hoursAhead completion:(void(^)(BOOL success, NSArray *shows, VMError *error))completion;


/**
 Get vevo tv shows information for a specific channel.
 @param channelIsrc     An ISRC that uniquely represents a vevo tv channel.
 @param hoursAhead      Number of hours ahead.
 @param completion      Completion callback block. Each element inside array channels is a VMTVShow instance object.
 */
- (void)getVevoTVShowsForChannel:(NSString *)channelIsrc hoursAhead:(int)hoursAhead completion:(void(^)(BOOL success, NSArray *shows, VMError *error))completion;


/**
 Get vevo tv videos information for a specific channel.
 @param channelIsrc     An ISRC that uniquely represents a vevo tv channel.
 @param completion      Completion callback block. Each element inside array channels is a VMTVVideo instance object.
 */
- (void)getVevoTVVideosForChannel:(NSString *)channelIsrc completion:(void(^)(BOOL success, NSArray *videos, VMError *error))completion;


#pragma mark - API v2 --- Playlists ---
/**---------------------------------------------------------------------------------------
 * @name Playlists
 *  ---------------------------------------------------------------------------------------
 */

/**
 Get playlist of current session user
 @param completion  Completion callback block. playlists contains all the cloud playlists data.
 */
- (void)getMePlaylistsWithCompletion:(void(^)(BOOL success, NSArray *playlists, VMError *error))completion;

/**
 Get user's clound playlists.
 @param userId      User ID
 @param completion  Completion callback block. playlists contains all the could playlists data.
 */
- (void)getUserPlaylists:(NSInteger)userId completion:(void(^)(BOOL success, NSArray *playlists, VMError *error))completion;


/**
 Get a playlist with the given specific playlist ID.
 @param playlistId      An unique id of this playlist generated by server.
 @param completion      Completion callback block.
 */
- (void)getPlaylist:(NSString *)playlistId completion:(void(^)(BOOL success, VMPlaylist *playlist, VMError *error))completion;
 
/**
 Create a playlist.
 @param name            Name of the playlist
 @param description     Description of the playlist
 @param isrcArray       An array whose elements are ISRCs of the video that belong to the playlist.
 @param completion      Completion callback block. Upon sucessful request, a server generated playlist ID will be returned and carried by playlsitId.
 */
- (void)createPlaylistWithName:(NSString *)name description:(NSString *)description containVideos:(NSArray *)isrcArray completion:(void(^)(BOOL success, NSString *playlistId, VMError *error))completion;


/**
 Update a existing playlist.
 @param playlist        The locally updated playlist object.
 @param Completion      Completion callback block.
 */
- (void)updatePlaylist:(VMPlaylist *)playlist completion:(void(^)(BOOL success, VMError *error))completion;


/**
 Delete a existing playlist.
 @param playlistId      The id of the playlist to be delted.
 @Param completion      Completion callback block.
 */
- (void)deletePlaylist:(NSString *)playlistId completion:(void(^)(BOOL success, VMError *error))completion;

/**
 SYNCHRONOUS
 Create a playlist.
 @param name            Name of the playlist
 @param description     Description of the playlist
 @param isrcArray       An array whose elements are ISRCs of the video that belong to the playlist.
 @param completion      Completion callback block. Upon sucessful request, a server generated playlist ID will be returned and carried by playlsitId.
 */
- (void)createPlaylistSynchronouslyWithName:(NSString *)name
                                description:(NSString *)description
                              containVideos:(NSArray *)isrcArray
                                 completion:(void(^)(BOOL success, NSString *playlistId))completion;

/**
 SYNCHRONOUS
 Update a existing playlist.
 @param playlist        The locally updated playlist object.
 @param Completion      Completion callback block.
 */
- (void)updatePlaylistSynchronously:(VMPlaylist *)playlist completion:(void(^)(BOOL success))completion;




@end
