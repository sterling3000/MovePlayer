//
//  VMSDKAnalyticsManager.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/16/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMVideo.h"
#import "VMPlaylist.h"
#import "VMComScoreManager.h"


@class MPMoviePlayerViewController;
@class MPMoviePlayerController;
@class VMMoviePlayerController;

typedef NS_ENUM(NSInteger, kVMSDKAnalyticsManagerUserStatus){
    
    kVMSDKAnalyticsManagerUserStatusLoggedIn,
    kVMSDKAnalyticsManagerUserStatusEmailLoggedIn,
    kVMSDKAnalyticsManagerUserStatusFBLoggedIn,
    kVMSDKAnalyticsManagerUserStatusGooglePlusLoggedIn,
    kVMSDKAnalyticsManagerUserStatusLoggedOut
    
};

typedef NS_ENUM(NSInteger, kVMSDKAnalyticsManagerVideoType) {
    
    kVMSDKAnalyticsManagerVideoTypeVOD,         /*Video On Demand */
    kVMSDKAnalyticsManagerVideoTypeVEVOTV,      /*Vevo tv */
    kVMSDKAnalyticsManagerVideoTypeAOD,         /*Audio On Demand */
    kVMSDKAnalyticsManagerVideoTypePreRollAd,   /*Pre-roll for advertisement clips */
    kVMSDKAnalyticsManagerVideoTypePostRollAd,  /*Post-roll for advertisement clips */
    
};

typedef NS_ENUM(NSInteger, kVMSDKAnalyticsManagerShareType) {
    
    kVMSDKAnalyticsManagerShareTypeFacebook,
    kVMSDKAnalyticsManagerShareTypeFacebookMessenger,
    kVMSDKAnalyticsManagerShareTypeTwitter,
    kVMSDKAnalyticsManagerShareTypeGooglePlus,
    kVMSDKAnalyticsManagerShareTypeEmail,
    kVMSDKAnalyticsManagerShareTypeTextMessage,
    kVMSDKAnalyticsManagerShareTypePinterest
    
};

typedef NS_ENUM(NSInteger, kVMSDKAnalyticsManagerAdType) {
    
    kVMSDKAnalyticsManagerAdTypePreRoll
    
};

typedef NS_ENUM(NSInteger, kVMSDKAnalyticsManagerSearchType) {
    
    kVMSDKAnalyticsManagerSearchTypeLookahead,
    kVMSDKAnalyticsManagerSearchTypeSearchResults
    
};

@interface VMSDKAnalyticsManager : NSObject

+ (VMSDKAnalyticsManager*)defaultManager;

@property (nonatomic, strong) VMComScoreManager *comScoreManager;
@property (nonatomic, getter = isDebugMode) BOOL debugMode;

- (void)logError:(NSError *)error withName:(NSString *)name message:(NSString *)message;

- (void)logErrorWithName:(NSString *)name parameters:(NSDictionary*)parameters;

#pragma mark - set user info
/*
 set user info
 userId
 userStatus
 */
- (void)setUserInfoWithUserId:(NSString *)userId userStatus:(kVMSDKAnalyticsManagerUserStatus)userStatus;

#pragma mark - set outside video data
/*
 set playlist title, clip number(position in playlist), and total clips
 */
- (void)setPlaylistInfoWithPlaylistName:(NSString *)playlistName clipNumber:(NSInteger)clipNumber totalClips:(NSInteger)totalClips;

/*
 set part number and total number of parts
 used for videos w/ multple parts(i.e. long concerts)
 */
- (void)setPartInfoWithPartNumber:(NSInteger)partNumber totalParts:(NSInteger)totalParts;

/*
 set stream type
 */
- (void)setStreamType:(kVMSDKAnalyticsManagerVideoType)streamType;

/*
 set show title, season number, episode number
 */
- (void)setShowDataWithShowTitle:(NSString *)showTitle seasonNumber:(NSInteger)seasonNumber episodeNumber:(NSInteger)episodeNumber;

/*
 reset outside video data
 */
- (void)resetVideoData;

#pragma mark stream sense
/*
 video starts playing
 */
- (void)logPlayWithVideo:(VMVideo *)video
          width:(NSNumber *)width
         height:(NSNumber *)height
       position:(long)position
       duration:(float)duration
         adLoad:(BOOL)adLoad
           adId:(NSUInteger)adId
         adType:(kVMSDKAnalyticsManagerAdType)adType;

/*
 video pauses
 */
- (void)logPauseWithVideo:(VMVideo *)video
           width:(NSNumber *)width
          height:(NSNumber *)height
        position:(long)position
        duration:(float)duration
          adLoad:(BOOL)adLoad
            adId:(NSUInteger)adId
          adType:(kVMSDKAnalyticsManagerAdType)adType;

/*
 video ends playing
 */
- (void)logEndWithVideo:(VMVideo *)video
         width:(NSNumber *)width
        height:(NSNumber *)height
      position:(long)position
      duration:(float)duration
        adLoad:(BOOL)adLoad
          adId:(NSUInteger)adId
        adType:(kVMSDKAnalyticsManagerAdType)adType;

#pragma mark - app events
#pragma mark - artist screen events
/*
 register artist tickets link tap
 
 event_type=artist
 event_action=tickets
 event_data=artist name_city_date
 */
- (void)registerArtistTicketsLinkTapWithArtistName:(NSString *)artistName city:(NSString *)city date:(NSDate *)date;

/*
 register artist video play
 
 event_type=artist
 event_action=play_video
 event_data=video ID
 */
- (void)registerArtistVideoPlayWithVideoId:(NSString *)videoId;

#pragma mark - share
/*
 register video share
 
 event_type=video
 event_action=share
 event_data=video id_share type (text message|email|Facebook|Twitter|Google+)
 */
- (void)registerVideoShareWithVideoId:(NSString *)videoId shareType:(kVMSDKAnalyticsManagerShareType)shareType;

/*
 register artist share
 
 event_type=aritst
 event_action=share
 event_data=artist name_share type (text message|email|Facebook|Twitter|Google+)
 */
- (void)registerArtistShareWithArtistName:(NSString *)artistName shareType:(kVMSDKAnalyticsManagerShareType)shareType;

/*
 register playlist share
 
 event_type=playlist
 event_action=share
 event_data=playlist id_share type (text message|email|Facebook|Twitter|Google+)
 */
- (void)registerPlaylistShareWithPlaylistId:(NSString *)playlistId shareType:(kVMSDKAnalyticsManagerShareType)shareType;

/*
 register video and playlist share
 
 event_type=playlist_video
 event_action=share
 event_data=playlist id_video id_share type (text message|email|Facebook|Twitter|Google+)
 */
- (void)registerPlaylistAndVideoShareWithPlaylistId:(NSString *)playlistId
                                            videoId:(NSString *)videoId
                                          shareType:(kVMSDKAnalyticsManagerShareType)shareType;

/*
 register vevo TV share
 
 event_type=vevo_tv
 event_action=share
 event_data=video ID_share type (text message|email|Twitter|Facebook|Google+)
 
 Each time a visitor shares a video from Vevo TV, fire this event.
 It should be fired, however, when a visitor taps an individual share icon (Facebook, email, Twitter, etc.).
 */
- (void)registerVevoTVShareWithVideoId:(NSString *)videoId shareType:(kVMSDKAnalyticsManagerShareType)shareType;

#pragma mark - playlist events
/*
 register playlist deletion
 
 event_type=playlist
 event_action=delete_playlist
 event_data=user ID
 
 Occurs whenever a visitor answers “YES” when asked if he or she wants to delete a playlist.
 */
- (void)registerDeletePlaylist;

/*
 register playlist creation
 
 event_type=playlist
 event_action=delete_playlist
 event_data=user ID
 
 Occurs whenever a visitor creates a playlist
 */
- (void)registerCreatePlaylist;

#pragma mark - registration events
/*
 register create account
 
 event_type=registration
 event_action=create_account
 event_data=create_account_start
 
 This event is fired on the primary registration screen.
 */
- (void)registerCreateAccount;

/*
 register email signup form error
 
 event_type=registration
 event_action=create_account
 event_data=error
 error_field=field name
 error_message=error message text
 
 When a visitor fails to fill in the email signup form correctly, capture the field on which the error occurs and the error message in the error_field and error_message labels.
 */
- (void)registerEmailSignupFormErrorWithFieldName:(NSString *)fieldName errorMessageText:(NSString *)errorMessageText;

/*
 register login form error
 
 event_type=registration
 event_action=create_account
 event_data=error
 error_field=field name
 error_message=error message text
 
 When a visitor fails to fill in the login form correctly, capture the field on which the error occurs and the error message in the error_field and error_message labels.
 */
- (void)registerLoginFormErrorWithFieldName:(NSString *)fieldName errorMessageText:(NSString *)errorMessageText;

/*
 register forgot password form error
 
 event_type=registration
 event_action=create_account
 event_data=error
 error_field=field name
 error_message=error message text
 
 When a visitor fails to fill in the forgot password form correctly, capture the field on which the error occurs and the error message in the error_field and error_message labels.
 */
- (void)registerForgotPasswordFormErrorWithFieldName:(NSString *)fieldName errorMessageText:(NSString *)errorMessageText;

/*
 register initiate email signup
 
 event_type=registration
 event_action=create_account
 event_data=initiate_email_signup
 */
- (void)registerInitiateEmailSignup;

/*
 register email signup success
 
 event_type=registration
 event_action=create_account
 event_data=email_signup_success
 */
- (void)registerEmailSignupSuccess;

/*
 register email login success
 
 event_type=registration
 event_action=log_in
 event_data=email_log_in
 */
- (void)registerEmailLogin;

/*
 register initiate facebook login
 
 event_type=registration
 event_action=facebook_connect
 event_data=facebook_connect_start
 */
- (void)registerInitiateFacebookLogin;

/*
 register initiate Google Plus login
 
 event_type=registration
 event_action=google_connect
 event_data=google_connect_start
 */
- (void)registerInitiateGooglePlusLogin;

/*
 register facebook login success
 
 event_type=registration
 event_action=facebook_connect
 event_data=facebook_connect_success
 */
- (void)registerFacebookLoginSuccess;

/*
 register Google Plus login success
 
 event_type=registration
 event_action=google_connect
 event_data=google_connect_success
 */
- (void)registerGooglePlusLoginSuccess;


/*
 register initiate forgot password
 
 event_type=registration
 event_action=forgot_password
 event_data=forgot_password_start
 
 When someone starts the Forgot Password process, fire an event.
 */
- (void)registerInitiateForgotPassword;

/*
 register forgot password complete
 
 event_type=registration
 event_action=forgot_password
 event_data=forgot_password_start
 
 If a visitor successfully completes the two-step Forgot Password flow, indicate success by firing an event.
 */
- (void)registerForgotPasswordComplete;

/*
 register user logout
 
 event_type=registration
 event_action=log_out
 event_data=log_out
 
 This event should be fired when someone taps “YES” when asked if he or she wants to log out.
 */
- (void)registerLogout;

#pragma mark - search events
/*
 register search event
 
 event_type=search
 event_action=search_term
 event_data=search term
 search_type=search type(lookahead|search_results)
 
 Note: Make sure all search terms captured are transformed to lowercase characters, so that “Wrecking Ball” and “wrecking ball” are not recorded as two separate search terms.
 */
- (void)registerSearchWithSearchTerm:(NSString *)searchTerm
                          searchType:(kVMSDKAnalyticsManagerSearchType)searchType;


#pragma mark - Player events

- (void)registerLearnMoreButtonTapped;

- (void)registerPlayButtonTappedOnVideo:(VMVideo *)video;

- (void)registerPauseButtonTappedOnVideo:(VMVideo *)video;

- (void)logPlayerStartBufferingOnVideo:(VMVideo *)video;

- (void)logPlayerStopBufferingOnVideo:(VMVideo *)video;

- (void)logAdViewedOnPlayer:(VMVideo *)video;

- (void)logPlayerStartLoadingVideo:(VMVideo *)video;

- (void)logPlayerStopLoadingVideo:(VMVideo *)video;

#pragma mark - vevo tv
/*
 register Vevo TV channel change
 
 event_type=vevo_tv
 event_action=channel_select
 event_data=channel name(i.e. hits, flow, nashville)
 
 When a user taps a channel link to change a channel, capture the channel name. 
 The channel links are indicated by the red rectangle in the screenshot below.
 */
- (void)registerVevoTVChannelChangeWithChannelName:(NSString *)channelName;

#pragma mark - video events
/*
 register video add to playlist
 
 event_type=video
 event_action=add_to_playlist
 event_data=playlist ID
 
 Users can add videos to their playlists from any video shown on the site.
 
 Note: The playlist add event should not be fired until either the user taps the name of an existing playlist or completes the playlist creation process, thus adding the video to the new playlist.
 */
- (void)registerVideoAddToPlaylistWithPlaylistId:(NSString *)playlistId;

/*
 register video info
 
 event_type=video
 event_action=info
 event_data=video ID
 
 If a visitor taps the info icon on a video, an info event should be fired, capturing the video ID.
 */
- (void)registerVideoInfoWithVideoId:(NSString *)videoId;

#pragma mark - chromecast
/*
 register chromecast connect
 
 event_type=chromecast
 event_action=connect
 
 */
- (void)registerChromcastConnect;

/*
 register chromecast disconnect
 
 event_type chromcast
 event_action=disconnect
 
 */
- (void)registerChromcastDisconnect;

/*
 register chromecast video play
 
 event_type=chromecast
 event_action=video_play
 event_data=video_id
 */
- (void)registerChromcastPlayVideoVideoId:(NSString *)videoId;

#pragma mark - airplay
/*
 register airplay connect
 
 event_type=airplay
 event_action=connect
 event_data=video_id
 
 */
- (void)registerAirplayConnectWithVideoId:(NSString *)videoId;

/*
 register airplay disconnect
 
 event_type=airplay
 event_action=disconnect
 */
- (void)registerAirplayDisconnect;


@end
