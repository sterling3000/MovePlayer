//
//  NSURL+VMExtras.h
//  vevo-ios-sdk
//
//  Created by Hxu on 4/8/14.
//  Copyright (c) 2014 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (VMExtras)

- (NSURL *)vm_urlByAppendParameters:(NSDictionary *)params;

@end
