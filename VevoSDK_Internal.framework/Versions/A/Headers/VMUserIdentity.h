//
//  VMUserIdentity.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/26/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

extern NSString *const VMUserIdentityType_Vevo;
extern NSString *const VMUserIdentityType_Facebook;
extern NSString *const VMUserIdentityType_Twitter;
extern NSString *const VMUserIdentityType_Google;
extern NSString *const VMUserIdentityType_Apple;

@interface VMUserIdentity : VMEntityBase

@property (nonatomic, readonly) NSInteger           identityId;
@property (nonatomic, strong, readonly) NSString    *identifier;
@property (nonatomic, strong, readonly) NSString    *identityType;

@end
