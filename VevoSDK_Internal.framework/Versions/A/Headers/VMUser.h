//
//  VMUser.h
//  VEVO
//
//  Created by Sterling Li on 10/2/13.
//  Copyright (c) 2013 Sterling Li. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMEntityBase.h"
#import "VMError.h"

@interface VMUser : VMEntityBase

@property (nonatomic) BOOL        isLoggedIn;

@property (nonatomic) BOOL        isConnectedToFacebook;
@property (nonatomic) BOOL        isConnectedToTwitter;
@property (nonatomic) BOOL        isConnectedToLastFm;
@property (nonatomic) BOOL        isConnectedToGooglePlus;

@property (nonatomic) NSInteger           userId;
@property (nonatomic, strong) NSString    *sessionToken;   // Deprecated
@property (nonatomic, strong, readonly) NSString    *firstName;
@property (nonatomic, strong, readonly) NSString    *lastName;
@property (nonatomic, strong, readonly) NSString    *email;
@property (nonatomic, strong, readonly) NSString    *password;
@property (nonatomic, strong, readonly) NSDate      *dob;
@property (nonatomic, readonly) NSUInteger          gender;  // 1 for male 0 for female
@property (nonatomic) BOOL                isEnabled;
@property (nonatomic, strong, readonly) NSURL       *profileImageUrl;
@property (nonatomic, strong, readonly) NSDate      *dateOfCreation;
@property (nonatomic, strong, readonly) NSString    *status;

@property (nonatomic, strong) NSString    *connectedFacebookAccountId;
@property (nonatomic, strong) NSString    *registeredFacebookAccountId;
@property (nonatomic, strong) NSString    *googlePlusAccountId;
@property (nonatomic, strong) NSString    *twitterAccountId;
@property (nonatomic, strong) NSString    *lastFmUsername;
@property (nonatomic, strong) NSString    *lastFmPassword;

@property (nonatomic, strong) NSArray             *playlists;
@property (nonatomic, strong) NSArray             *vevoFriends;
@property (nonatomic, strong) NSArray             *nonVevoFacebookFriends;

@property (nonatomic, strong) NSArray             *identities;

+ (VMUser *)currentUser;

- (void)updateInfoFromDictionary:(NSDictionary *)dictionary;



/**
 Update user friend list.
 @param completion  Completion callback block.
 */
- (void)updateFriendsWithCompletion:(void(^)(BOOL success, id result, VMError *error))completion ;



//- (void)logout;



/**
 @name Helper Methods
 */

- (BOOL)validateFirstName:(NSString *)firstName;
- (BOOL)validateLastName:(NSString *)lastName;
- (BOOL)validateEmailAddress:(NSString *)emailAddress;
- (BOOL)validatePasswordLength:(NSString *)password;
- (BOOL)validatePassword:(NSString *)password matchesPassword:(NSString *)confirmedPassword;
- (BOOL)validateDateOfBirth:(id)dob;



@end
