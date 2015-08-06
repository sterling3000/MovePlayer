//
//  VMApiFacade_Private.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 12/16/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMApiFacade.h"

@interface VMApiFacade ()



/**---------------------------------------------------------------------------------------
 * @name VEVO Now
 *  ---------------------------------------------------------------------------------------
 */

/**
 Get vevo now posts by pagination.
 @param page Page number of requested data.
 @param size Number of reqeust posts on this page.
 @param completion Callback block.
 */
- (void)getVevoNowPostsOnPage:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *posts, VMError *error))completion;

/**
 Get all of the vevo now posts including the past posts that are not shown any mroe on the browse page, in a penetrated fashion.
 @param page Page number of requested data.
 @param size Number of reqeust posts on this page.
 @param completion Callback block.
 */
- (void)getVevoNowAllPostsOnPage:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *posts, VMError *error))completion;


/**---------------------------------------------------------------------------------------
 * @name Users
 *  ---------------------------------------------------------------------------------------
 */

/**
 Create a new account.
 @param firstname   User's first name.
 @param lastname    User's last name.
 @param dob         Date of birth. Can be either a NSDate object or NSString object. If passing dob in NSString the format has to be MM/dd/yyyy.
 @param email       User's email.
 @param password    User's password. At least 6 characters.
 @param gender      "male" or "female"
 @param completion  completion callback block.
 */
- (void)createUserWithFirstName:(NSString *)firstname lastName:(NSString *)lastname dob:(id)dob email:(NSString *)email password:(NSString *)password gender:(NSString *)gender completion:(void(^)(BOOL success, VMUser *user, VMError *error))completion;

/**
 Create a new account.
 @param firstname   User's first name.
 @param lastname    User's last name.
 @param dob         Date of birth. Can be either a NSDate object or NSString object. If passing dob in NSString the format has to be MM/dd/yyyy.
 @param email       User's email.
 @param password    User's password. At least 6 characters.
 @param gender      "male" or "female"
 @param genres      array of user preferred genres 
 @param artists     array of user selected artists
 @param completion  completion callback block.
 */
- (void)createUserWithFirstName:(NSString *)firstname lastName:(NSString *)lastname dob:(id)dob email:(NSString *)email password:(NSString *)password gender:(NSString *)gender genres:(NSArray*)genres artists:(NSArray*)artists completion:(void(^)(BOOL success, VMUser *user, VMError *error))completion;


/**
 Create a new account thru Facebook.
 @param email       User's email.
 @param password    User's password. At least 6 characters.
 @param fbToken     Facebook access token.
 @param completion  completion callback block.
 */
- (void)createUserWithEmail:(NSString *)email password:(NSString *)password providerType:(NSString *)providerType providerToken:(NSString *)token completion:(void(^)(BOOL success, VMUser *user, VMError *error))completion;


/**
 Get my (current user's) user info.
 @param completion  Completion block.
 */
- (void)getMeWithCompletion:(void(^)(BOOL success, VMUser *user, VMError *error))completion;

/**
 Update my (current user's) profile information.
 @param firstName   New first name.
 @param lastName    New last name.
 @param dob         New date of birth. Can be either a NSDate object or NSString object. If passing dob in NSString the format has to be MM/dd/yyyy.
 @param email       New email.
 @param gender      New gender.
 @param completion  Completion callback block.
 */
- (void)updateMeWithFirstName:(NSString *)firstName lastName:(NSString *)lastName dob:(id)dob email:(NSString *)email gender:(NSString *)gender completion:(void(^)(BOOL success, VMError *error))completion;

/**
 Verify registration. Calling this API will result in an email sent to the user's registered email address.
 @param completion  Completion callback block.
 */
- (void)verifyMyEmailWithCompletion:(void(^)(BOOL success, VMError *error))completion;

/**
 Verify registration. Calling this API will result in an email sent to the user's registered email address.
 
 This request does not need logged in user's access token. But it is still required to use the anonymous token.
 
 @param email       User email.
 @param completion  Completion callback block.
 */
- (void)verifyEmail:(NSString *)email completion:(void(^)(BOOL success, VMError *error))completion;

/**
 Change account's password to a new password.
 @param completion  Completion callback block.
 */
- (void)changeMyPassword:(NSString *)newPassword completion:(void(^)(BOOL success, VMError *error))completion;


/**
 Register current device and associate it with the current user's account.
 @param token           The push token of the device.
 @param completion      Completion callback block.
 */
- (void)registerDeviceWithPushToken:(NSString *)token completion:(void(^)(BOOL success, VMError *error))completion;


/**
 Get user notification settings.
 @param completion  Completion callback block. Each element in the return array settings is a NSString object representing a notification setting.
 */
- (void)getNotificationSettingsWithCompletion:(void(^)(BOOL success, NSArray *settings, VMError *error))completion;


/**
 Update user's notification settings.
 @param settings        An NSArray object that consists of notification settings that is going to be updated to. Each element is an NSString object that represents a setting.
 @param completion      Completion callback block.
 */
- (void)updateNotificationSettings:(NSArray *)settings completion:(void(^)(BOOL success, VMError *error))completion;

/**
 Get the identities of the current logged in user.
 @param completion      Completion callback block. Each element in the return array identities is a VMUserIdentity object.
 */
- (void)get3rdPartyIdentitiesWithCompletion:(void(^)(BOOL success, NSArray *identities, VMError *error))completion;

/**
 link user's vevo account with his/her 3rd account( facebook or googleplus).
 @param providerType         User's 3rd party provider type(facebook or google).
 @param providerToken         User's 3rd party access token.
 @param completion      Completion callback block. fbIdentity is a VMUserIdentity object that contains the linked facebook identity information.
 */
- (void)linkUserTo3rdPartyProvider:(NSString *)providerType providerToken:(NSString*)providerToken completion:(void (^)(BOOL, VMUserIdentity *, VMError *))completion;


/**
 Delete(unlink) a specific 3rd party identity from user's profile.
 @param identity        A integer number representing the ID of this identity.
 @param completion      Completion callback block.
 */
- (void)delete3rdPartyIdentity:(NSInteger)identity completion:(void(^)(BOOL success, VMError *error))completion;

/**
 Get a specific user's information.
 @param userId          User's id
 @param completion      Completion callback block.
 */
- (void)getUser:(NSInteger)userId completion:(void(^)(BOOL success, VMUser *user, VMError *error))completion;


/**
 Get user friends.
 @param userId          User's id.
 @param completion      Completion callback block. Each element in the array friends is a VMFriend object.
 */
- (void)getUserFriends:(NSInteger)userId completion:(void(^)(BOOL success, NSArray *friends, VMError *error))completion;

/**
 Get user's favored artists.
 @param userId          User's id
 @param completion      Completion callback block. Each element of array artists is a VMArtist object.
 */
- (void)getUserArtists:(NSInteger)userId completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;

/**
 Get user's match artists.
 @param completion      Completion callback block. Each element of array artists is a VMArtist object.
 */
- (void)getMatchArtistsForPage:(int)page size:(int)size Completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;

/**
 Get user's favored artists.
 @param userId          User's id
 @param completion      Completion callback block. Each element of array artists is a VMArtist object.
 */
- (void)addMatchArtistNames:(NSArray*)artistNames forType:(NSString*)sourceType completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;


/**
 This method sends a request for password reset. Upon successful request, user will get an reset email from VEVO server.
 @param email       Email address that is associated to user's account.
 @param completion  Completion callback block.
 */
- (void)requestResetPassword:(NSString *)email completion:(void(^)(BOOL success, VMError *error))completion;


/**
 Delete a user. Only works on staging. Debug only...
 @param userId          ID of the user to be deleted.
 @param completion      Completion callback block.
 */
- (void)deleteUser:(NSInteger)userId completion:(void(^)(BOOL success, VMError *error))completion;


- (void)checkIdentityAvailabilityWithType:(NSString *)type identifier:(NSString *)identifier completion:(void(^)(BOOL success, BOOL available, VMError *error))completion;

- (void)getSettingsWithCurrentAppVersion:(NSString *)version completion:(void(^)(BOOL success, id result, VMError *error))completion;


/**---------------------------------------------------------------------------------------
 * @name ChromeCast
 *  ---------------------------------------------------------------------------------------
 */

/**
 Get the google chromecast rendition information of a given ISRC.
 
 Each video has one or more renditions, and each rendition includes a stream URL, stream type and other stream related information.
 Current Google Chromecast device doesn't support HLS renditions, we have to get mp4 renditions.
 
 @param isrc The ISRC (International Standard Recard Code) of the video.
 @param completion Block called when the request comes back. success indicates whether the request is good. renditions is an NSArray object that contains all the renditions of this video if success is YES, otherwise nil. error is a VMError object that contains the error information if the request goes wrong.
 */
- (void)getGooglecastRenditionsForIsrc:(NSString *)isrc completion:(void(^)(BOOL success, NSArray *renditions, VMError *error))completion;


/**
 Get suggested artists for selected genres, we use this endpoint in FTUE artists picker.
 **Notes: the result takes the top 3 artists sorted by monthly viewcount,
 then takes the next 3 top artists who have a video released within 90 days
 then takes the next artist who's video is flagged as a premiere, then repeat the above
 @param genres          list of genres.
 @param page            Page number of the artists.
 @param size            Size of requested artists on page page.
 @param completion      Completion callback block. Each element in the artists array is a VMArtist instance object, VMPaging object is current paging with total results and pages.
 */
- (void)getSuggestedArtistsForGenres:(NSArray *)genres page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *artists, VMPaging* paging, VMError *error))completion;

/**
 Get a list of music videos(video's category is MusicVideo) for selected genres, result videos are from top artists within the genres selected. Top artists determined by artists within the highest 10% of weeklyViewcount
 We use this endpoint for genre follow/feed.
 @param type Filter type, e.g. MostViewedLastDay, ...
 @param genre array representation of list of genres.
 @param page A integer number indicating the page number of the videos that we are requesting.
 @param size A integer number indicating the number of videos we are requesting on each page.
 @param completion Callback block. Each element inside array videos is a VMVideo object representing a Featured video.
 */
- (void)getPremieresFeedForOrder:(VMVideoFilterType *)type genres:(NSArray *)genres page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *posts, VMError *error))completion;


/**
 Get a list of Vidoes by artists, use this endpoint in artist follow/feed. 
 Note: non modifyable default sort order of video start date descending, filter out non music videos.
 @param artist array representation of list of artists.
 @param page A integer number indicating the page number of the videos that we are requesting.
 @param size A integer number indicating the number of videos we are requesting on each page.
 @param completion Callback block. Each element inside array videos is a VMVideo object representing a Featured video.
 */
- (void)getVideosForArtists:(NSArray *)artists page:(int)page size:(int)size completion:(void(^)(BOOL success, NSArray *videos, VMPaging* paging, VMError *error))completion;


/**
 Create or Update user selected genres, this will replace all the user's current genres,we must add all genres in myGenres array.
 @param genre array representation of list of my genres.
 @param completion Callback block. Each element inside array genres is a VMGenre object representing a genre added.
 */
- (void)createOrReplaceMyGenres:(NSArray *)myGenres completion:(void(^)(BOOL success, NSArray *genres, VMError *error))completion;



/**
 Get a list of user genres.
 @param completion Callback block. Each element inside array genres is a VMGenre object representing a user genre.
 */
- (void)getMyGenresWithCompletion:(void(^)(BOOL success, NSArray *genres, VMError *error))completion;


/**
 Get user's premiere artists.
 @param completion      Completion callback block. Each element of array artists is a VMArtist object.
 */
- (void)getPremiereArtistsForPage:(int)page size:(int)size Completion:(void(^)(BOOL success, NSArray *artists, VMError *error))completion;

/**
 Add user's favored premiere artists.
 @param artistNames          artist name array
 @param completion      Completion callback block. Each element of array artists is a VMArtist object.
 */
- (void)addPremiereArtists:(NSArray*)artistNames completion:(void(^)(BOOL success, VMError *error))completion;

/**
 Delete user's favored premiere artists.
 @param artistNames          artist name array
 @param completion      Completion callback block. Each element of array artists is a VMArtist object.
 */
- (void)deletePremiereArtists:(NSArray*)artistNames completion:(void(^)(BOOL success, VMError *error))completion;

@end
