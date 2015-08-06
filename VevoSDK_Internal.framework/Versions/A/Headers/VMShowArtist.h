//
//  VMShowArtist.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/28/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

/** @name VMShowArtist  This class ONLY applies to the Certified artists and Emerging artists category.
 
 */
@interface VMShowArtist : VMEntityBase

@property (nonatomic,retain,readonly) NSString        *title;
@property (nonatomic,retain,readonly) NSURL           *thumbnailImageUrl;
@property (nonatomic,retain,readonly) NSURL           *originalImageUrl;
@property (nonatomic,retain,readonly) NSURL           *mobileImageUrl;
@property (nonatomic,retain,readonly) NSString        *facebookId;
@property (nonatomic,retain,readonly) NSString        *twitterId;
@property (nonatomic,retain,readonly) NSString        *playlistId;

@end
