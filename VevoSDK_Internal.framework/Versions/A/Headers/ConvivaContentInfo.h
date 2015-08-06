//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//

#import <Foundation/Foundation.h>

/// @name cdnNames
/// Names of content delivery networks typically stored in cdnName field
///@{
#define CDN_NAME_AKAMAI @"AKAMAI"
#define CDN_NAME_AMAZON @"AMAZON"
#define CDN_NAME_ATT @"ATT"
#define CDN_NAME_BITGRAVITY @"BITGRAVITY"
#define CDN_NAME_BT @"BT"
#define CDN_NAME_CDNETWORKS @"CDNETWORKS"
#define CDN_NAME_CHINACACHE @"CHINACACHE"
#define CDN_NAME_EDGECAST @"EDGECAST"
#define CDN_NAME_HIGHWINDS @"HIGHWINDS"
#define CDN_NAME_INTERNAP @"INTERNAP"
#define CDN_NAME_LEVEL3 @"LEVEL3"
#define CDN_NAME_LIMELIGHT @"LIMELIGHT"
#define CDN_NAME_OCTOSHAPE @"OCTOSHAPE"
#define CDN_NAME_SWARMCAST @"SWARMCAST"
#define CDN_NAME_VELOCIX @"VELOCIX"
#define CDN_NAME_TELEFONICA @"TELEFONICA"
#define CDN_NAME_MICROSOFT @"MICROSOFT"
#define CDN_NAME_CDNVIDEO @"CDNVIDEO"
#define CDN_NAME_QBRICK @"QBRICK"
#define CDN_NAME_NGENIX @"NGENIX"
#define CDN_NAME_IPONLY @"IPONLY"
#define CDN_NAME_INHOUSE @"INHOUSE"
#define CDN_NAME_COMCAST @"COMCAST"
#define CDN_NAME_NICE @"NICE"
#define CDN_NAME_TELENOR @"TELENOR"
#define CDN_NAME_TALKTALK @"TALKTALK"
#define CDN_NAME_FASTLY @"FASTLY"
#define CDN_NAME_TELIA @"TELIA"
#define CDN_NAME_CHINANETCENTER @"CHINANETCENTER"
#define CDN_NAME_OTHER @"OTHER"
///@}

@interface ConvivaContentInfo : NSObject

/// A unique identifier for the content, preferably human-readable.
@property (readonly, nonatomic) NSString *assetName;
/// A string identifying the CDN used to stream video.
@property (retain,   nonatomic) NSString *cdnName;
/// A set of key-value pairs used in resource selection and policy evaluation
@property (retain,   nonatomic) NSDictionary *tags;
/// Set to true if the session includes live content, and false otherwise.
@property (assign,   nonatomic) BOOL isLive;
/// The URL from which video is loaded.
@property (retain,   nonatomic) NSString *streamUrl;
/// A string identifying the viewer and is optional.
@property (retain,   nonatomic) NSString *viewerId;
/// A string identifying the player in use, preferably human-readable.
@property (retain,   nonatomic) NSString *playerName;
/// @brief The resource name used when the streamer does not itself know the
/// resource being played.
/// @note If this is null, then the value of cdnName is used for reporting.
@property (retain,   nonatomic) NSString *resource;
/// @brief Timestamp when ConvivaContentInfo was instantiated
/// @deprecated Not used
@property (readonly, nonatomic) NSTimeInterval timestamp;

/// @brief Create a new ConvivaContentInfo with specified assetName.
/// @note Missing tags parameter
+ (id)createInfoForLightSessionWithAssetName:(NSString *)assetName;

@end
