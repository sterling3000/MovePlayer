//
//  VMShowSeason.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/28/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"
#import "VMShow.h"

@interface VMShowSeason : VMEntityBase

@property (nonatomic,retain,readonly) NSString        *title;
@property (nonatomic,retain,readonly) NSString        *slug;
@property (nonatomic,retain,readonly) NSURL           *headerImageUrl;
@property (nonatomic,retain,readonly) NSURL           *mobileImageUrl;
@property (nonatomic,retain,readonly) NSURL           *thumbnailImageUrl;
@property (nonatomic,retain,readonly) NSMutableArray  *episodes;
@property (nonatomic,retain,readonly) NSString        *showTitle;

- (id)initFromDictionary: (NSDictionary *)dictionary inShow:(VMShow *)show;

- (VMShow *)show;

@end
