//
//  VMPlayerOverlayObject.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 5/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
    Define overlay types
 */
typedef NS_ENUM(NSInteger, VMOverlayType) {
    
    /** Player control bar as the overlay */
    VMOverlayTypePlayer = 0,
    
    /** General overlay such as top bar. */
    VMOverlayTypeVideo  = 1,
    
    /** Overlay that's in response to the button action */
    VMOverlayTypeButtonAction  = 2
	
};

/**
    Interface for customizied overlay view on top of the movie player
 */
@protocol VMPlayerOverlayObject <NSObject>

/**
    If implemented, is called when the overlay view should appear. 
 
    This method itself does not handle any animation, in order to do that, you need to fill in with an animation block.
 */
- (void)transitionIn;

/**
 If implemented, is called when the overlay view should disappear.
 
 This method itself does not handle any animation, in order to do that, you need to fill in with an animation block.
 */
- (void)transitionOut;

/** 
    Implement this method to provide a fadeout animation duration.
 @return A float value in seconds representing the animatino duration.
 */
- (float)fadeOutSeconds;

/**
    Implement this method to provide the overlay type information of the current overlay view.
 @return Overlay type.
 */
- (VMOverlayType)playerOverlayType;

/**
    Implement this method in the delegate controller to decide whether the overlay should responde to the touch event.
 @return A boolean value indicating whether the overlay should show upon the touch-up event.
 */
- (BOOL)showOnTouch;

/**
    Implement this method to provide the currnet visual status of the overlay.
 */
- (BOOL)isOverlayCurrentlyShowing;


@end
