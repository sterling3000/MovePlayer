//
//  VMTVVideo.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/22/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

@class VMVideo;

@interface VMTVVideo : VMEntityBase

@property (nonatomic, readonly) NSInteger       videoId;
@property (nonatomic, readonly) NSInteger       parentId;
@property (nonatomic, readonly) NSInteger       offsetInSeconds;
@property (nonatomic, readonly) NSInteger       durationInSeconds;
@property (nonatomic, readonly) NSInteger       currentOffsetInSeconds;
@property (nonatomic, strong, readonly) VMVideo *video;


@end
