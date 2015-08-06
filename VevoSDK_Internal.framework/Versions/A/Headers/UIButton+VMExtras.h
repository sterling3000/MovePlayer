//
//  UIButton+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/15/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (VMExtras)
+ (UIButton *)vm_BlueGrayButtonWithStandardWidth:(CGFloat)standardWidth
                                         maxWidth:(CGFloat)maxWidth
                                        maxHeight:(CGFloat)maxHeight
                                             text:(NSString *)text
                                  foregroundImage:(UIImage *)image;

+ (UIButton *)vm_BlueButtonWithStandardWidth:(CGFloat)standardWidth
                                     maxWidth:(CGFloat)maxWidth
                                    maxHeight:(CGFloat)maxHeight
                                         text:(NSString *)text
                              foregroundImage:(UIImage *)image
                               ImageTextSpace:(CGFloat)space
                                     fontSize:(CGFloat)ft
                                       target:(id)target
                                     selector:(SEL)selector;

+ (UIButton *)vm_facebookLoginButtonWithTarget:(id)target selector:(SEL)selector;

+ (UIButton *)vm_buttonWith1PixelImage:(UIImage *)pixelImage title:(NSString *)title foregroundImage:(UIImage *)foregroundImage font:(UIFont *)font textColor:(UIColor *)textColor cornerRadius:(CGFloat)cornerRadius maxWidth:(CGFloat)maxWidth minWidth:(CGFloat)minWidth maxHeight:(CGFloat)maxHeight imageTextSpace:(CGFloat)space;

+ (UIButton *)vm_buttonWithClearBackgroundWithText:(NSString *)title
                                foregroundImage:(UIImage *)foregroundImage
                                           font:(UIFont *)font
                                      textColor:(UIColor *)textColor
                          textColorHightlighted:(UIColor *)textHighlightedColor
                       spaceBetweenImageAndText:(CGFloat)space
                                       minWidth:(CGFloat)minWidth
                                      minHeight:(CGFloat)minHeight
                                       maxWidth:(CGFloat)maxWidth
                                      maxHeight:(CGFloat)maxHeight;
@end
