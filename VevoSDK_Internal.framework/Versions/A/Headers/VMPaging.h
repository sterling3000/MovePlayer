//
//  VMPaging.h
//  vevo-ios-sdk
//
//  Created by Hxu on 3/10/15.
//  Copyright (c) 2015 Vevo. All rights reserved.
//

#import "VMEntityBase.h"


@interface VMPaging : VMEntityBase

@property (nonatomic, readonly) NSUInteger                  total;
@property (nonatomic, readonly) NSUInteger                  currentPage;
@property (nonatomic, readonly) NSUInteger                  pages;
@property (nonatomic, readonly) NSUInteger                  pageSize;
@property (nonatomic, strong, readonly) NSString*           next;

@end
