//
//  VMLogger.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 5/12/14.
//  Copyright (c) 2014 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^VMLoggerBreadcrumbBlock)(NSString *);

@interface VMLogger : NSObject

+ (void)registerBreadcrumbService:(VMLoggerBreadcrumbBlock)service;

+ (void)registerHandledExceptionBlock:(void (^)(NSException*))handleExceptionBlock;

+ (void)leaveBreadcrumb:(NSString *)breadcrumb;

+ (void)logHandledException:(NSException *)exception;

@end
