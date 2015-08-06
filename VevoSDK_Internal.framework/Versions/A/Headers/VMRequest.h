//
//  VMRequest.h
//  VEVO
//
//  Created by Tommy Hass on 3/22/13.
//  Copyright (c) 2013 VEVO. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "VMError.h"


extern NSString *VMRequestContentType_Json;
extern NSString *VMRequestContentType_form;


@interface VMRequest : NSObject


/** 
 HTTPS or HTTP
*/
@property (nonatomic, assign) BOOL secure;

/**
 Action of the reqeust, one of the four options:GET, POST, PUT, DELETE. Default is GET.
 */
@property (nonatomic, copy) NSString *httpVerb;

/**
 Content Type. If not specified, "application/json; charset=utf-8" will be used.
 */
@property (nonatomic, copy, readwrite) NSString *contentType;

/** 
 If NO, only the object for the 'result' key is returned.
 If YES, the object for the full response is returned.
 */
@property (nonatomic, assign) BOOL returnFullResponse;

/**
 Legacy property for API v1. When YES, the request includes the media api key in the HTTP header.
 */
@property (nonatomic, assign) BOOL addMediaAPIKeyHeader;

/**
 Flag indicating if this request should include the vevo auth access token. This is only used for interfacing with V2 APIs.
 */
@property (nonatomic, assign) BOOL  useVevoAccessToken;

/**
 Grant type of this request. E.g. "client_credientials"
 */
@property (nonatomic, strong) NSString *grantType;

/**
 When set, the country code (e.g. US, GB, ...) and locale of the device (e.g. en-US) will be added into the reqeust header.
 */
@property (nonatomic) BOOL  addCountryAndLocale;


/**
 When set, the country code (e.g. US, GB, ...) of the device (e.g. en-US) will be added into the reqeust header.
 */
@property (nonatomic) BOOL  addCountryCode;


/**
 When set,locale of the device (e.g. en-US) will be added into the reqeust header.
 */
@property (nonatomic) BOOL  addLocale;

/**
 When set, pass @"languageCulture":{locale} into the HTTP header of the request. Currently only used when fetching data from VEVO CMS.
 */
@property (nonatomic) BOOL  addLocaleInHttpHeader;

/**
 Set this boolean to pass the special key to get .mp4 videos instead of HLS, so that it can be used by ChromeCast
 */
@property (nonatomic, assign) BOOL addMediaAPIKeyHeaderGooglecast;

/**
 POST data.
 */
@property (nonatomic, retain) NSData *postData;


/**
 Set this boolean to use v1 legacy APIs. By default, all the request are making to the v2 API endpoints.
 */
@property (nonatomic) BOOL  v1;

/**
 Locking flag used to indicate whether this request is a dependant request of some other requests. If set to 1, this request will tell the request manager to hold off on all the other reqeust and run this one first. As soon as this request finishes, the on-hold request will be relieved and fired. For example, for all the authentication calls we set locking to 1.
 */
@property (nonatomic) BOOL  locking;

@property (nonatomic) BOOL  ignoreLocalCache;

@property (nonatomic) BOOL  ignoreResponse;

/**
 Class method to initialize a VMRequest object with a given relative URL string.
 @param urlString Relative string that is going to be appended to the base url.
 */
+ (id)requestWithRelativeURLString:(NSString *)urlString;

/**
 Class method to initialize a VMRequest object with a given relative URL string.
 @param urlString Relative string that is going to be appended to the base url.
 @param interval Experiation timer length. When expired, all the cache will be cleared.
 */
+ (id)requestWithRelativeURLString:(NSString *)urlString cacheExpiration:(NSTimeInterval)interval;


/**
 Class method to initialize a VMReqeust object with a given absolute URL.
 @param url An absolute url.
 */
+ (id)requestWithAbsoluteURL:(NSURL *)url;

/**
 Class method to intialize a VMReqest instance variable with a given time-out interval for data caching.
 @param url An absolute url.
 @param interval Experiation timer length. When expired, all the cache will be cleared.
 */
+ (id)requestWithAbsoluteURL:(NSURL *)url cacheExpiration:(NSTimeInterval)interval;

/**
 Call this method to include session token in the HTTP header.
 Not every call needs the session token.
 @param token
 */
- (void)addSessionTokenInHeader:(NSString *)token;

/**
 Add any key-value pair in the HTTP header.
 @param value
 @param key
 */
- (void)addHeaderValue:(NSString *)value forKey:(NSString *)key;



/** @name Send Request */

/**
 Asynchronous request.
 
 This is the most commonly used method, as most of the requests we are making are asynchronous.
 @param completionHandler
 @param errorHandler
 */
- (void)startAsyncWithCompletion:(void(^)(id result))completionHandler errorHandler:(void(^)(VMError *error))errorHandler;


/**
 Synchronous request.
 
 This is the most commonly used method, as most of the requests we are making are asynchronous.
 @param completionHandler
 @param errorHandler
 */
- (void)startSyncWithCompletion:(void (^)(id))completionHandler errorHandler:(void (^)(VMError *))errorHandler;


- (NSData*)rawResponseData;

@end