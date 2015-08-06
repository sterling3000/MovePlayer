//
//  NSString+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (VMExtras)

//Add a prefix vm_ to method names in categories on framework to avoid Category Method Name Clashes
//https://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPFrameworks/Concepts/CreationGuidelines.html
//http://developer.apple.com/library/ios/#documentation/cocoa/conceptual/ProgrammingWithObjectiveC/CustomizingExistingClasses/CustomizingExistingClasses.html

+ (NSString *)vm_uuidString;
+ (NSString *)vm_decode:(NSString *)source;
+ (NSDate*)vm_getDateFromJSON:(NSString *)dateString;
+ (NSString*)vm_formattedTimeFromInterval:(NSTimeInterval)interval;
+ (NSString *)vm_convertDateToFriendlyTime:(NSDate *)date;
+ (NSString*)vm_getFormattedDate:(NSString*)timeString;
+ (NSDate*)vm_getDateFromString:(NSString*)timeString;
+ (NSString*)vm_getFormattedDateFromUTC:(NSString*)timeString;
+ (NSDate*)vm_getDateFromUTCString:(NSString*)timeString;
+ (NSString*)vm_getFriendlyTimeStamp:(NSString*)timeString;
+ (NSDictionary *)vm_parseQueryString:(NSString *)query;
- (UIColor*)vm_colorFromHex;
- (NSString*)vm_toBase64String;
- (NSString*)vm_decodeFromBase64String;
- (NSString*)vm_formattedNumberFormat;
- (BOOL)vm_isValidEmail;
- (UIFont*)vm_adjustedFont:(UIFont*)font constrainedToSize:(CGSize)size;
- (UIImage *)vm_imageRepresentationWithFont:(UIFont*)font color:(UIColor*)color constrainedToSize:(CGSize)size;

- (NSString*)vm_stringWithEscapedApostrophe;

- (BOOL)vm_hasChars;

/*
 * Checks to see if the string contains the given string, case insenstive
 */
- (BOOL)vm_containsString:(NSString*)string;

/*
 * Checks to see if the string contains the given string while allowing you to define the compare options
 */
- (BOOL)vm_containsString:(NSString*)string options:(NSStringCompareOptions)options;

/*
 * If the string starts with the given prefix, this returns it without that prefix.
 */
- (NSString*)vm_startWithout:(NSString*)without;

/*
 * Returns the starting index within the string of another string.  Case sensitive.
 */
- (int) vm_indexOf:(NSString *)match;

/*
 * Returns the starting index within the string of another string, optionally ignoring case.
 */
- (int) vm_indexOf:(NSString *)match ignoreCase:(BOOL)ignoreCase;

/*
 * Gets the string that comes before the first occurance of the match is found.  For example, calling [@"I eat hot dog" before:@"hot"] would return "i eat ".Returns nil if the match wasn't found.
 */
- (NSString *) vm_before:(NSString *)match;

/*
 * Gets the string that comes before the first occurance of the match is found.  For example, calling [@"I eat hot dog" before:@"hot"] would return "i eat ".Returns nil if the match wasn't found.
 */
- (NSString *) vm_before:(NSString *)match ignoreCase:(BOOL)ignoreCase;

- (NSString *) vm_after:(NSString *)match;

- (NSString *) vm_after:(NSString *)match ignoreCase:(BOOL)ignoreCase;

- (CGSize)sizeWithFont:(UIFont *)font maxSize:(CGSize)maxSize;

- (NSString *)vm_urlEncodeUsingEncoding:(NSStringEncoding)encoding;

@end
