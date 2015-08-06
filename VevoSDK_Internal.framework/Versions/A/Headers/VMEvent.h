//
//  VMEvent.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/22/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

@interface VMEvent : VMEntityBase

@property (nonatomic, readonly) NSInteger               eventId;
@property (nonatomic, strong, readonly) NSString        *name;
@property (nonatomic, readonly) double                  latitude;
@property (nonatomic, readonly) double                  longitude;
@property (nonatomic, strong, readonly) NSString        *type;
@property (nonatomic, strong, readonly) NSString        *location;
@property (nonatomic, strong, readonly) NSString        *venue;
@property (nonatomic, strong, readonly) NSURL           *venueUrl;
@property (nonatomic, strong, readonly) NSURL           *url;
@property (nonatomic, strong, readonly) NSDate          *date;

@end
