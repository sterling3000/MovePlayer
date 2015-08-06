//
//  VMTopPlaylist.h
//  vevo-ios-sdk
//
//  Created by Heyward on 1/29/15.
//  Copyright (c) 2015 Vevo. All rights reserved.
//

#import "VMPlaylist.h"

@interface VMTopPlaylist : VMPlaylist

- (instancetype)initFromCMSDictionary:(NSDictionary *)cmsDictionary;
@end
