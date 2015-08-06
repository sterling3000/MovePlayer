//
//  AppDelegate.m
//  MovePlayer
//
//  Created by Zhiye Li on 7/30/15.
//  Copyright (c) 2015 Sterling. All rights reserved.
//

#import "AppDelegate.h"
#import <VevoSDK_Internal/VevoSDK.h>

#define VEVO_APP_CLIENT_ID_IPHONE       @"7295a757d2a74d2dbb6f691aed3cddbd"//@"FF7901F570F5467DB0B33BF08C045433"
#define VEVO_APP_CLIENT_SECRET_IPHONE   @"d1e84fc46d3041ac9e35bc8969505de8"//@"0063E641BC7049C0AE46F232AA0636F5"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [VevoSDK checkAuthenticationWithClientId:VEVO_APP_CLIENT_ID_IPHONE secret:VEVO_APP_CLIENT_SECRET_IPHONE];
    
    [VMSettings defaultSettings].disableFreeFheelAdVideoInTestBuild = YES;
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
