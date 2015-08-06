//
//  VMUtilities.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/17/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VMUtilities : NSObject

+ (NSBundle *)vevoSDKBundle;
+ (NSString *)localizedStringForKey:(NSString *)key
                        withDefault:(NSString *)value;
+ (NSString *)localizedStringForKey:(NSString *)key
                        withDefault:(NSString *)value
                           inBundle:(NSBundle *)bundle;

+ (void)loadCustomFonts;
@end
