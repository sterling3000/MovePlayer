//
//  VMVideoCredit.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 11/23/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

@interface VMVideoCredit : VMEntityBase

@property (nonatomic, strong, readonly) NSString    *name;
@property (nonatomic, strong, readonly) NSString    *credit;

@end
