//
//  VMOAuth2.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/8/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMError.h"

@interface VMOAuth2 : NSObject

/**
 Acccess Token
 */
@property (nonatomic, strong, readonly) NSString    *accessToken;

/**
 App refresh token.
 */
@property (nonatomic, strong, readonly) NSString    *refreshToken;

/**
 App access token experiation date.
 */
@property (nonatomic, strong, readonly) NSDate      *expirationDate;

/**
 Token type. Should be "Bearer"
 */
@property (nonatomic, strong, readonly) NSString    *tokenType;

/**
 Get the singleton instance.
 */
+ (VMOAuth2 *)sharedInstance;

- (void)reauthenticateIfNecessaryWithClientId:(NSString *)clientId secret:(NSString *)secret completion:(void (^)(BOOL success, VMError *error, id result))completion;


- (void)refreshAuthenticationWithClientId:(NSString *)clientId secret:(NSString *)secret completion:(void (^)(BOOL success, VMError *error, id result))completion;

/**
 Authentication call.
 */
- (void)authenticateWithClientId:(NSString *)clientId secret:(NSString *)secret completion:(void (^)(BOOL success, VMError *error, id result))completion;

/**
 Authentication with user credentials.
 */
- (void)authenticateWithClientId:(NSString *)clientId secret:(NSString *)secret username:(NSString *)username password:(NSString *)password completion:(void (^)(BOOL success, VMError *error, id result))completion;

/**
 Synchronous
 Authentication with user credentials.
 */
- (void)authenticateSyncWithClientId:(NSString *)clientId secret:(NSString *)secret facebookToken:(NSString *)fbToken completion:(void (^)(BOOL success, VMError *error, id result))completion;

/**
 Authentication with 3rd party.
 */
- (void)authenticateWithClientId:(NSString *)clientId secret:(NSString *)secret providerType:(NSString*)providerType providerToken:(NSString *)providerToken completion:(void (^)(BOOL success, VMError *error, id result))completion;


- (void)reauthenticateWithPreviouslySavedData:(void (^)(BOOL success, VMError *error, id results))completion;

/**
 Call to refresh token. This method will ONLY work if any of the above three authentication methods was called successfully previously.
 */
- (void)refreshWithCompletion:(void (^)(BOOL success, VMError *error, id result))completion;

/**
 Synchronous
 Call to refresh token. This method will ONLY work if any of the above three authentication methods was called successfully previously.
 */
- (void)refreshSyncWithCompletion:(void (^)(BOOL success, VMError *error, id results))completion;

/**
 @return Boolean value telling the receiver that if the current access token is valid and not expired.
 */
- (BOOL)hasValidToken;

/**
 Clear all saved tokens.
 */
- (void)clearTokens;


/**
 Clear up all the previously used user auth info. e.g. email, password, etc.
 */
- (void)clearUserAuthenticationData;

@end
