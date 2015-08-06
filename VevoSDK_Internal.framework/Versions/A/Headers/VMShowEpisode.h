//
//  VMShowEpisode.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/28/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"
#import "VMShowSeason.h"

@interface VMShowEpisode : VMEntityBase

@property (nonatomic,retain,readonly) NSString            *title;
@property (nonatomic,retain,readonly) NSString            *playlistId;
@property (nonatomic,retain,readonly) NSString            *isrc;
@property (nonatomic,retain,readonly) NSURL               *thumbnailImageUrl;
@property (nonatomic,retain,readonly) NSString            *showTitle;

- (id)initFromDictionary:(NSDictionary *)dictionary inSeason:(VMShowSeason *)season;

- (VMShowSeason *)season;

@end
