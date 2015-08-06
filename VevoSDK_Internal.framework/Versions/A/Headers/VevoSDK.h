//
//  VevoSDK.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMConstants.h"
#import "VMError.h"
#import "VMApiFacade.h"
#import "VMData.h"
#import "VMSettings.h"
#import "VMMoviePlayerController.h"
#import "VMMoviePlayerControllerDelegate.h"
#import "VMPlayerOverlayObject.h"

@interface VevoSDK : NSObject

/**
 Check the authentication status. If not authenticated or expired, it will reauthenticate.
 
 @param clientId The ID of the integration client. A string value that is assigned to a specific client.
 @param secret The Client Secret that should be provided to the client in association with the Client ID.
 
 */
+ (void)checkAuthenticationWithClientId:(NSString *)clientId secret:(NSString *)secret;


/**
 Check the authentication status. If not authenticated or expired, it will reauthenticate.
 
 @param clientId The ID of the integration client. A string value that is assigned to a specific client.
 @param secret The Client Secret that should be provided to the client in association with the Client ID.
 @param completion A success/failure block whose input parameters contain the authentication result.
 
 */
+ (void)checkAuthenticationWithClientId:(NSString *)clientId secret:(NSString *)secret completion:(void (^)(BOOL success, VMError *error, id result))completion;


/**
 Set the log level of the SDK.
 @param logLevel A VMLogLevel value that can be one of the three values: VM_LOG_LEVEL_QUIET, VM_LOG_LEVEL_INFO, VM_LOG_LEVEL_VERBOSE
 */
+ (void)setVMLoggingLevel:(VMLogLevel)logLevel;

/**
 Get the current SDK version.
 */
+ (NSString *)version;

@end
