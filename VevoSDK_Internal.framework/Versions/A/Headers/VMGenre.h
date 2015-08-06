//
//  VMGenre.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

@interface VMGenre : VMEntityBase

/**
 Url safe name of this genre.
 */
@property (nonatomic, strong, readonly) NSString    *urlSafeName;

/** 
 The display name for the genre
 */
@property (nonatomic, strong, readonly) NSString    *name;

/**
 Array of subgenres that belong to each main genre. Each element of this array is a VMGenre object.
 */
@property (nonatomic, strong, readonly) NSArray     *subGenres;




@end
