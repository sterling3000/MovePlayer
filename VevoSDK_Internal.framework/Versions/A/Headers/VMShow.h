//
//  VMShow.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/28/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

@interface VMShow : VMEntityBase

@property (nonatomic,readonly) NSInteger                  showId;
@property (nonatomic,retain,readonly) NSString            *title;
@property (nonatomic,retain,readonly) NSString            *showDescription;
@property (nonatomic,retain,readonly) NSString            *slug;
@property (nonatomic,retain,readonly) NSString            *link;
@property (nonatomic,retain,readonly) NSString            *redirectLink;
@property (nonatomic,retain,readonly) NSMutableArray      *seasons;
@property (nonatomic,retain,readonly) NSURL               *headerImageUrl;
@property (nonatomic,retain,readonly) NSURL               *mobileImageUrl;
@property (nonatomic,retain,readonly) NSURL               *thumbnailImageUrl;
@property (nonatomic,retain,readonly) NSString            *country;
@property (nonatomic,retain,readonly) NSString            *language;
@property (nonatomic,retain,readonly) NSString            *region;

@end
