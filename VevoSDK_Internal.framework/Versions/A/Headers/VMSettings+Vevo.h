//
//  VMSettings+Vevo.h
//  vevo-ios-sdk
//
//  Created by Hxu on 12/11/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

//#import <VevoSDK_Internal/VevoSDK_Internal.h>

#import "VMSettings.h"

@interface VMSettings (Vevo)

/**
 Flag indicating if we should show Bitrate.
 */
- (BOOL)showBitrates;

- (void)setShowBitrates:(BOOL)value;
@end
