//
//  VMFriend.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/26/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

typedef NS_ENUM(NSInteger, VMFriendSource) {

    VMFriendSource_Facebook,
    VMFriendSource_Twitter,
    VMFriendSource_GooglePlus
};

@interface VMFriend : VMEntityBase

@property (nonatomic, readonly) VMFriendSource      source;
@property (nonatomic, strong, readonly) NSString    *name;
@property (nonatomic, strong, readonly) NSString    *userId;
@property (nonatomic, readonly) BOOL                isOnVevo;

- (id)initFromDictionary:(NSDictionary *)dictionary sourceType:(VMFriendSource)type;

@end
