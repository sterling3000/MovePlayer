//
//  VMSettings.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/14/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMConstants.h"

@interface VMSettings : NSObject

/**
 Set the current Vevo SDK logging level.
 */
@property (nonatomic, readwrite) VMLogLevel loggingLevel;


/**
 Retrieve is use Free Wheel test network.
 */
@property (nonatomic, readwrite) BOOL useFreeWheelTestNetwork;


/**
 Flag indicating if we should point our API request to Staging enc points.
 */
@property (nonatomic, readwrite) BOOL useVevoStagingAPIEndpoints;

/**
 Flag indicating if we should disable free Wheel video ad.
 */
@property (nonatomic, readwrite) BOOL disableFreeFheelAdVideoInTestBuild;


/**
 Flag indicating if we should disable Conviva.
 */
@property (nonatomic, readwrite) BOOL disableConviva;

/**
 Flag that is used to globally set the API endpoints versions. Default NO, which means all the API endpoints point to the new API v2. For using the legacy API (v1) this property must be set to YES.
 */
@property (nonatomic, readwrite) BOOL useApiV1;

/**
 Country code of the current device.
 */
@property (nonatomic, strong) NSString  *countryCode;


/**
 App Client ID.
 */
@property (nonatomic, strong) NSString  *clientId;


/**
 App Client Secret.
 */
@property (nonatomic, strong) NSString  *clientSecret;

/**
 String representatino of the current device Locale. E.g. "en-US"
 */
@property (nonatomic, readonly) NSString    *locale;

/**
 Returns the name of the partner who is integreting the SDK.
 */
@property (nonatomic, readonly) NSString    *partnerName;

/**
 Returns the boolean that says if the app was launched in a vevo non-active country.
 */
@property (nonatomic) BOOL        hasAppLaunchedInVevoInactiveCountry;


/**
 Class method to get the reference of the singleton class.
 */
+ (VMSettings *)defaultSettings;


- (void)clearSettings;


@end
