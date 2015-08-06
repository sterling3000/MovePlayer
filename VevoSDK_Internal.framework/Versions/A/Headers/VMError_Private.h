//
//  VMError_Private.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 9/23/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VevoSDK.h"



@interface VMError ()


+ (id)errorWithCode:(NSInteger)code localizedDescription:(NSString *)message;

+ (id)apiRequestNullResultError;

+ (id)invalidArgumentsError;

+ (id)apiRequestBadDataError;

@end
