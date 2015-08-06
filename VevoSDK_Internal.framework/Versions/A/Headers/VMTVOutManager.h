//
//  VMTVOutManager.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/15/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface VMTVOutManager : NSObject

@property (nonatomic, strong) UIWindow  *tvoutWindow;
@property (nonatomic, strong) UIView    *baseView;
@property (nonatomic) BOOL              tvoutStarted;

+ (VMTVOutManager*)defaultManager;

- (void)startTVOut;

- (void)stopTVOut;

- (BOOL)isTVOutAvailable;

- (void)resetToNormalMirroring;

@end
