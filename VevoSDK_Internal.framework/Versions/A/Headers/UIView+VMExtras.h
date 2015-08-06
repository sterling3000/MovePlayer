//
//  UIView+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/15/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (VMExtras)

- (UIImage *) vm_getAsImage;
- (CGRect) vm_frameInScreen;
- (void) vm_changeWidth:(float)width;
- (void) vm_changeHeight:(float)height;
- (void) vm_changeX:(float)x;
- (void) vm_changeY:(float)y;
- (void) vm_deltaWidth:(float)width;
- (void) vm_deltaHeight:(float)height;
- (void) vm_deltaX:(float)x;
- (void) vm_deltaY:(float)y;
- (void) vm_removeAllSubviews;
- (void) vm_correctHalfPixelOffset;
- (void) vm_hide;
- (void) vm_setRandomTag;
//- (UIView*) vm_subviewWithClassName:(NSString*)className;
//- (void)performSelector:(SEL)aSelector onSubviewWithClassName:(NSString*)className;

@end
