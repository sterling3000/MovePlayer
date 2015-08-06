//
//  VMReachabilityManager.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 5/6/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMReachability.h"

//@class VMReachabilityManager;

//@protocol VMReachabilityManagerDelegate <NSObject>
//
////use this delegate method sparingly. a change in reachability status indicates that
////the device has connected to a network, but it might not be able to reach the servers.
//- (void)didGoOffline:(VMReachabilityManager *)manager;
//- (void)didGoOnline:(VMReachabilityManager *)manager;
//
//@end

@interface VMReachabilityManager : NSObject


@property (nonatomic, strong) VMReachability* reachability;

//@property(nonatomic, weak) id<VMReachabilityManagerDelegate> rootDelegate;


+ (VMReachabilityManager *)sharedInstance;

- (int)currentNetworkConnectionType;

- (BOOL)isConnected;

- (BOOL)isConnectedViaWifi;
@end
