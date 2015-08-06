//
//  VMUrlService.h
//  VEVO
//
//  Created by Harry Xu on 3/11/13.
//  Copyright (c) 2013 VEVO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMConstants.h"

@interface VMUrlService : NSObject

// Authentication
+ (NSString *)oauthToken;


+(NSURL *) carouselURL;
+(NSURL *) userPlaylistURL;
+(NSURL *) playlistsForFriendURL:(NSString *)friendVevoId;
+(NSURL *) videosForPlaylistURL:(NSString *)playlistId;
+(NSURL *) playlistURLForId:(NSString *)playlistId;

//+(NSURL *) musicMapURL:(MapBounds)bounds;
+(NSURL *) facebookFriendsURL;
+(NSURL *) sendFacebookInviteURL;

//Search
+(NSURL *) lookaheadSearchURLWithTerm:(NSString *)term;
+(NSURL *) artistSearchURLWithTerm:(NSString *)term offset:(int)offset limit:(int)limit;
+(NSURL *) videoSearchURLWithTerm:(NSString *)term offset:(int)offset limit:(int)limit;
+(NSURL *) isrcSearchURLWithIsrc:(NSString *)isrc;

//Top videos
+(NSURL *) topVideosURLWithOrder:(NSString *)orderString genre:(NSString *)genre offset:(int)offset limit:(int)limit;

//Movie player
+(NSURL *) isrcAllRecommendationsURL:(NSString *)isrc;
+(NSURL *) videoDetailURL:(NSString *)isrc;
+(NSURL *) videoRenditionsURL:(NSString *)isrc;
+(NSURL *) googlecastRenditionsURL:(NSString *)isrc;
+(NSURL *) videosURLForShowId:(int)showId episode:(NSString *)episodeId;


#pragma mark - API v2

// Top Videos
+ (NSString *)topVideosWithOrder:(NSString *)orderString
                           genre:(NSString *)genre
                            page:(int)page
                            size:(int)size
                          isLive:(BOOL)live
                      isPremiere:(BOOL)premiere
                      isExplicit:(VMVideoExplicitFilterType)explicitFilter;

// Top Videos request without live and premiere parameters.
+ (NSString *)topVideosWithOrder:(NSString *)orderString genre:(NSString *)genre page:(int)page size:(int)size minYear:(NSString *)minYear maxYear:(NSString *)maxYear;

// Top Videos
+ (NSString *)topVideosWithOrder:(NSString *)orderString
                           genre:(NSString *)genre
                            page:(int)page
                            size:(int)size
                          isLive:(BOOL)live
                      isPremiere:(BOOL)premiere
                      isExplicit:(VMVideoExplicitFilterType)explicitFilter
                         minYear:(NSString *)minYear
                         maxYear:(NSString *)maxYear;

// Get a single Video
+ (NSString *)videoWithISRC:(NSString *)isrc;

+ (NSString *)renditionsWithIsrc:(NSString *)isrc streamType:(NSString *)type;

// Related videos
+ (NSString *)relatedVideo:(NSString *)isrc;

// Artist videos
+ (NSString *)videosOfArtist:(NSString *)safename page:(int)page size:(int)size;

// Artists videos
+ (NSString *)videosOfArtists:(NSArray *)artists page:(int)page size:(int)size;

// Vevo Now
+ (NSString *)vevoNowOnPage:(int)page size:(int)size;

// Vevo Now all posts
+ (NSString *)vevoNowAllOnPage:(int)page size:(int)size;

+ (NSString *)genres;

+ (NSString *)artistsWithOrder:(NSString *)orderString genre:(NSString *)genre page:(int)page size:(int)size;

+ (NSString *)artistsWithOrder:(NSString *)orderString genres:(NSArray *)genres page:(int)page size:(int)size;

+ (NSString *)suggestedArtistsWithGenres:(NSArray *)genres page:(int)page size:(int)size;

+ (NSString *)artistsByIsrc:(NSString *)isrc;

+ (NSString *)relatedArtists:(NSArray *)artists;

+ (NSString *)artist:(NSString *)artist;

+ (NSString *)artistBio:(NSString *)artist;

+ (NSString *)artistBuyLinks:(NSString *)artist;

+ (NSString *)artistEvents:(NSString *)artist;

+ (NSString *)artistVideos:(NSString *)artist;

+ (NSString *)similarArtists:(NSString *)artist;

+ (NSString *)vevoTVChannels:(BOOL)withShows hoursAhead:(int)hoursAhead;

+ (NSString *)vevoTVShows:(int)hoursAhead;

+ (NSString *)vevoTVShowsForChannel:(NSString *)channelIsrc hoursAhead:(int)hoursAhead;

+ (NSString *)vevoTVVideosForChannel:(NSString *)channelIsrc;

+ (NSString *)createUser;

+ (NSString *)currentUser;

+ (NSString *)verifyUserEmail;

+ (NSString *)changeUserPassword;

+ (NSString *)registerDeviceWithPushToken:(NSString *)token;

+ (NSString *)userNotifications;

+ (NSString *)userIdentities;

+ (NSString *)linkFacebook:(NSString *)fbToken;

+ (NSString *)deleteUserIdentity:(NSInteger)identity;

+ (NSString *)getUser:(NSInteger)userId;

+ (NSString *)getMyFriends;

+ (NSString *)getMyArtistsForPage:(int)page size:(int)size;

+ (NSString *)addArtists;

+ (NSString *)getUserFriends:(NSInteger)userId;

+ (NSString *)getUserArtists:(NSInteger)userId;

+ (NSString *)resetPassword;

+ (NSString *)verifyEmailByToken;

+ (NSString *)mePlaylists;

+ (NSString *)userPlaylists:(NSInteger)userId;

+ (NSString *)getPlaylist:(NSString *)playlistId;

+ (NSString *)getPlaylist:(NSString *)playlistId page:(int)page size:(int)size;

+ (NSString *)createPlaylist;

+ (NSString *)updatePlaylist:(NSString *)playlistId;

+ (NSString *)deleteUser:(NSInteger)userId;

+ (NSString *)checkIdentityAvailabilityWithType:(NSString *)type identifier:(NSString *)identifier;

+ (NSString *)searchWithTerm:(NSString *)q videoLimit:(int)videoLimit skippedVideos:(int)skippedVideos;

// Get shows
+ (NSString *)getShowsWithEpisodes:(BOOL)withEpisodes;

// Get a single show
+ (NSString *)getShowWithSlug:(NSString *)slug;

// Settings
+ (NSString *)getSettingsWithCurrentVersion:(NSString *)version;

// New Premiere API
+ (NSString *)premieresWithOrder:(NSString *)orderString genre:(NSString *)genre page:(int)page size:(int)size minYear:(NSString *)minYear maxYear:(NSString *)maxYear;

+ (NSString *)premieresFeedWithOrder:(NSString *)orderString genre:(NSArray *)genres page:(int)page size:(int)size minYear:(NSString *)minYear maxYear:(NSString *)maxYear;


+ (NSString *)myGenres;

+ (NSString *)getPremiereArtistsForPage:(int)page size:(int)size;

+ (NSString *)premiereArtists;

@end
