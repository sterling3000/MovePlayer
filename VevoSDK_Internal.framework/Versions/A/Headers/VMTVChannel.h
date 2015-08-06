//
//  VMTVChannel.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/22/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

@interface VMTVChannel : VMEntityBase


@property (nonatomic, readonly) NSInteger               channelId;
@property (nonatomic, strong, readonly) NSString        *name;
@property (nonatomic, strong, readonly) NSString        *channelDescription;
@property (nonatomic, strong, readonly) NSString        *stream;
@property (nonatomic, strong, readonly) NSString        *isrc;
@property (nonatomic, strong, readonly) NSURL           *thumbnailUrl;
@property (nonatomic, strong, readonly) NSArray         *shows;


@end
