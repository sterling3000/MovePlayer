//
//  NSArray+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/15/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (VMExtras)

/*
 * Checks to see if the array exists and has at least one item.
 */
- (BOOL)vm_hasItems;

@end
