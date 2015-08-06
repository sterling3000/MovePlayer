//
//  NSData+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (VMExtras)

//Add a prefix to method names in categories on framework to avoid Category Method Name Clashes
//https://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPFrameworks/Concepts/CreationGuidelines.html
//http://developer.apple.com/library/ios/#documentation/cocoa/conceptual/ProgrammingWithObjectiveC/CustomizingExistingClasses/CustomizingExistingClasses.html

+ (NSData *)vm_dataWithBase64EncodedStr:(NSString *) string;
- (id) initWithBase64EncodedString:(NSString *) string;

- (NSString *) vm_base64Encoding;
- (NSString *) vm_base64EncodingWithLineLength:(NSUInteger) lineLength;

- (BOOL) vm_hasPrefix:(NSData *) prefix;
- (BOOL) vm_hasPrefixBytes:(const void *) prefix length:(NSUInteger) length;

- (BOOL) vm_hasSuffix:(NSData *) suffix;
- (BOOL) vm_hasSuffixBytes:(const void *) suffix length:(NSUInteger) length;

@end
