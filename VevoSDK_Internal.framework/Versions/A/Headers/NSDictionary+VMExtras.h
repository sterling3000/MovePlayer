//
//  NSDictionary+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

//Add a prefix to method names in categories on framework to avoid Category Method Name Clashes
//https://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPFrameworks/Concepts/CreationGuidelines.html
//http://developer.apple.com/library/ios/#documentation/cocoa/conceptual/ProgrammingWithObjectiveC/CustomizingExistingClasses/CustomizingExistingClasses.html

#import <Foundation/Foundation.h>

@interface NSDictionary (VMExtras)
/*
 * Checks to see if the dictionary has an entry with the given key.
 */
- (BOOL)vm_hasKey:(NSString*)key;

/*
 * Ensures an NSString and not the potential NSNull value is set from a dictionary.  Perfect for serializing/deserializing from apis.
 */
- (NSString*)vm_stringForKey:(NSString*)key;


- (int)vm_intValueForKey:(NSString *)key;

- (NSInteger)vm_nsintegerForKey:(NSString *)key;

- (NSArray *)vm_arrayForKey:(NSString *)key;

- (NSDictionary *)vm_dictionaryForKey:(NSString *)key;

- (BOOL)vm_boolForKey:(NSString *)key;

- (double)vm_doubleForKey:(NSString *)key;

@end
