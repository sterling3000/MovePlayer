//
//  UIDevice+VevoSDK.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 2/3/14.
//  Copyright (c) 2014 Vevo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (VevoSDK)

+ (NSString *)platformString;
+ (NSString *)platform;
+ (BOOL)isIPod;
+ (BOOL)isIPhone;
+ (BOOL)isIPad;

@end
