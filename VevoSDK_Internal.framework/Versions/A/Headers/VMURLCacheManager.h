//
//  VMURLCacheManager.h
//  vevo-ios-sdk
//
//  Created by Hxu on 9/19/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

#define VM_URL_CACHE_SIZE_MEMORY    4*1024*1024  // 4MB
#define VM_URL_CACHE_SIZE_DISK      64*1024*1024 // 64MB

/** @name VMUrlCacheManager handles the cached data from the HTTP requests */
@interface VMURLCacheManager : NSObject

+ (VMURLCacheManager *)sharedInstance;

/**
 Save response data of a specific HTTP request to the cache.
 @param data Response data of request request.
 @param request An NSURLRequest object that has been processed.
 @param response Response of request.
 @Param interval A time interval that determines the expiration time of the cached data.
 */
- (void)saveData:(NSData *)data forRequest:(NSURLRequest*)request withResponse:(NSURLResponse *)response withExpirationInterval:(NSTimeInterval)interval;


/**
 Get cached data for a specific request.
 @param request A http request we are making. 
 @return Cached data if found in the storage, or nil if cache expired or couldn't find any associated data to this request.
 */
- (NSData*)cachedDataForRequest:(NSURLRequest*)request;


/**
 Get cached data for a specific request with the option of using expired data.
 @param request A http request we are making.
 @param useExpired A boolean value indicating whether we should use the expired data if cannot find any new data in the storage.
 @return Cached data if found in the storage, or nil if cache expired or couldn't find any associated data to this request.
 */
- (NSData*)cachedDataForRequest:(NSURLRequest*)request includeExpired:(BOOL)useExpired;

/**
 Clear all the cached data and release the space from both the memory and the disk.
 */
- (void)removeAllCachedResults;

@end
