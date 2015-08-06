//
//  VMEntityBase.h
//  vevo-ios-sdk
//
//  Created by Harry Xu on 4/9/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
    Base class of some of the data classes.
*/
@interface VMEntityBase : NSObject

/**
    Custom init function. Initialize the class from a dictionary object containing all the attributes of this object. 
 
 @param dictionary A dictionary object that is supposed to contain the values of all the attributes of this object.
 
 */
- (id)initFromDictionary:(NSDictionary *)dictionary;


/**
    Convert the current state of the object to a property list dictionary object. 
 */
- (NSDictionary *)toDictionary;


@end