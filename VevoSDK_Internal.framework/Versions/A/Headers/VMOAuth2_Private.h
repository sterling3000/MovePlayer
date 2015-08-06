//
//  VMOAuth2_Private.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 6/3/14.
//  Copyright (c) 2014 Vevo. All rights reserved.
//

#import "VMOAuth2.h"

@interface VMOAuth2 ()

- (void)saveAndOverwriteAuthenticatedData:(NSDictionary *)data;

- (NSDictionary *)previouslyAuthenticatedData;

@end
