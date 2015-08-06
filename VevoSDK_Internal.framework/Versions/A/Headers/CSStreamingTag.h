//
//  CSStreamingTag.h
//  comScore
//
//  Copyright (c) 2014 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSStreamingTag : NSObject

- (void) playAdvertisement;
- (void) playContentPartWithMetadata:(NSDictionary *)metadata;
- (void) stop;

@end
