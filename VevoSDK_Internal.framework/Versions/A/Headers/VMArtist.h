//
//  VMArtist.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/16/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"


/**
    @name Artist data class.
 */
@interface VMArtist : VMEntityBase

/**
    A string representing the this artist's id.
 */
@property (nonatomic, strong, readonly) NSString  *artistId __attribute__((deprecated("API endpoints are migrating to v2.")));

/**
    Artist's name.
 */
@property (nonatomic, strong, readonly) NSString  *name;


/**
    Artist's twitter screen name. e.g. Shakira
 */
@property (nonatomic, strong, readonly) NSString  *twitterScreenName;

/**
    Artist's Songkick id.
 */
@property (nonatomic, strong, readonly) NSString  *songkickId;

/**
    A string indicating the artist's url safe name.
 */
@property (nonatomic, strong, readonly) NSString  *urlSafeName;


/**
    Number of video counts of this artist.
 */
@property (nonatomic, readonly) NSUInteger               videoCount;

/**
    Number of favorite count of this artist.
 */
@property (nonatomic, readonly) NSUInteger               favoriteCount;

/**
    A boolean value indicating whether this artist is currently on tour.
 */
@property (nonatomic, readonly) BOOL    isOnTour;

/**
 A boolean value indicating whether this artist is a VEVO LIFT artist.
 */
@property (nonatomic, readonly) BOOL    isLift;

/**
    The fan page url of this artist in string. 
 */
@property (nonatomic, strong, readonly) NSString  *fanPageUrl;

/**
    The iTunes url of this artist. 
 */
@property (nonatomic, strong, readonly) NSString  *iTunesUrl;

/**
 A string representing this artist's home page url.
 */
@property (nonatomic, strong, readonly) NSString  *homepageUrl;

/**
    A URL string pointing to the image file of this artist.
 */
@property (nonatomic, strong, readonly) NSURL      *imageUrl;

/**
 An array of genres that this artist belongs to. Each element is an NSString object represeting the genre name.
 */
@property (nonatomic, strong, readonly) NSArray     *genres;

/**
 An integer number telling the total views of this artist's videos.
 */
@property (nonatomic, readonly) NSUInteger          totalViews;


@end
