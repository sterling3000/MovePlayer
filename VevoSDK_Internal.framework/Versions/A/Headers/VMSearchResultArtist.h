//
//  VMSearchResultArtist.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/25/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMEntityBase.h"
#import "VMArtist.h"

@interface VMSearchResultArtist : VMEntityBase

@property (nonatomic, strong) NSString          *name;
@property (nonatomic, strong) NSString          *urlSafeName;
@property (nonatomic) NSInteger                 totalVideos;
@property (nonatomic, strong, readonly) NSString        *thumbnailUrl;

-(VMArtist *)toVMArtist;

@end
