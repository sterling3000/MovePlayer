 //
//  VMConstants.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/14/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#ifdef __cplusplus
#define VM_EXTERN			extern "C"
#else
#define VM_EXTERN			extern
#endif

#import <Foundation/Foundation.h>

/**
 @name SDK Debug logging levels.
 */
typedef NS_ENUM(NSInteger, VMLogLevel) {
    
    /** low log level. No log will print */
	VM_LOG_LEVEL_QUIET		=	1,
    
    /** Mid log level. */
	VM_LOG_LEVEL_INFO		=	7,
    
    /** Verbose log. Print verything */
	VM_LOG_LEVEL_VERBOSE	=	13
};

/**
 @name Define the video filtering type class.
 */
typedef NSString VMVideoFilterType;

VM_EXTERN VMVideoFilterType *const VMVideoFilterType_MostViewdLastDay;
VM_EXTERN VMVideoFilterType *const VMVideoFilterType_MostViewdLastWeek;
VM_EXTERN VMVideoFilterType *const VMVideoFilterType_MostViewdLastMonth;
VM_EXTERN VMVideoFilterType *const VMVideoFilterType_MostViewdAllTime;
VM_EXTERN VMVideoFilterType *const VMVideoFilterType_MostRecent;


/**
 @name Define the artist filtering type class.
 */
typedef NSString VMArtistFilterType;

VM_EXTERN VMArtistFilterType *const VMArtistFilterType_MostViewedToday;
VM_EXTERN VMArtistFilterType *const VMArtistFilterType_MostViewedThisWeek;
VM_EXTERN VMArtistFilterType *const VMArtistFilterType_MostViewedThisMonth;
VM_EXTERN VMArtistFilterType *const VMArtistFilterType_MostViewedAllTime;
VM_EXTERN VMArtistFilterType *const VMArtistFilterType_MostViewedRecent;


/**
 @name Define the video isExplicit filtering type.
 */
typedef NS_ENUM(NSUInteger, VMVideoExplicitFilterType) {
    VMVideoExplicitFilterType_Both,
    VMVideoExplicitFilterType_Explicit,
    VMVideoExplicitFilterType_Clean,
};

/**
    Notification contants
 */
/**
  Notification made when AirPlayDetector isAirPlayAvailable changes
 */
VM_EXTERN NSString *const VMAirPlayAvailabilityChangedNotification;

/**
 @name Dictionary keys to retreive artist info from VMVideo and VMSearchResultVideo
 */

VM_EXTERN NSString *const kVMVideoArtistName;
VM_EXTERN NSString *const kVMVideoArtistUrlSafeName;