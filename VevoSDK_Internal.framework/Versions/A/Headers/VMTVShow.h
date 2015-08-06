//
//  VMTVShow.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/22/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"


@interface VMTVShow : VMEntityBase


@property (nonatomic, readonly) NSInteger           showId;
@property (nonatomic, strong, readonly) NSString    *name;
@property (nonatomic, strong, readonly) NSString    *showDescription;
@property (nonatomic, strong, readonly) NSDate      *startDate;
@property (nonatomic, readonly) NSInteger           durationInMinutes;
@property (nonatomic, strong, readonly) NSDate      *endDate;
@property (nonatomic, readonly) NSInteger           channelId;

@end
