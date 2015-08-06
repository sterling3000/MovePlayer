//
//  VMSearchResultVideo.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/25/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMEntityBase.h"

@interface VMSearchResultVideo : VMEntityBase

@property (nonatomic, strong, readonly) NSString        *title;
@property (nonatomic, strong, readonly) NSString        *isrc;
@property (nonatomic, strong, readonly) NSString        *thumbnailUrl;
@property (nonatomic, readonly) NSInteger               viewCount;
@property (nonatomic, strong, readonly) NSString        *formattedViewCount;
@property (nonatomic, strong, readonly) NSMutableArray  *primaryArtists;

@end
