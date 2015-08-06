//
//  VMDateFormatHelper.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 3/6/14.
//  Copyright (c) 2014 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VMDateFormatHelper : NSObject

+ (VMDateFormatHelper *)sharedInstance;

- (NSDate *)dateFromString:(NSString *)string;

@end
