//
//  VMError.h
//  VEVO
//
//  Created by Sterling Li on 5/23/13.
//  Copyright (c) 2013 VEVO. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VMErrorCode) {
    kVMErrorCode_Success                = 200,
    kVMErrorCode_InvalidArguments       = 1000,
    
    kVMRequestErrorCodeBadJson = 700,
    
    // Response data is NULL
    kVMRequestErrorCodeNullResult,
    
    // Bad response data.
    kVMRequestErrorCodeBadData,
    
    // Invalid request URL.
    kVMRequestErrorCodeBadUrl,
    
    // Error for unknown reason
    kVMRequestErrorCodeUnknown,
    
    // Error for no internet conneciton
    kVMRequestErrorCodeNoConnection         = -1,
    
    // Reauest get a 401 response code.
    kVMRequestErrorCodeUnAuthorized        = 401,
    
    // User does not exist error.
    kVMRequestErrorCode_NotExist           = 404,
    
    // Access token expired.
    kVMRequestErrorCode_VevoAccessTokenExpired       = 16,
    
    // Refresh token expired.
    kVMRequestErrorCode_VevoRefreshTokenExpired      = 207,
    
    // user is not verified.
    kEmailLoginErrorCode_Unverified        = 612,
    
    // The email used to log in already exists.
    kEmailLoginErrorCode_EmailAlreadyExits = 611
};

extern NSString *VMErrorTypeKey;

/**
    @name A subclass of NSError
 */
@interface VMError : NSError

@property (nonatomic, strong) NSArray   *errors;

+ (VMError *)errorWithCode:(NSInteger)code type:(NSString *)type message:(NSString *)message;

+ (VMError *)errorWithError:(NSError *)error;

@end
