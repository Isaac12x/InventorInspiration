//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Abstract base class that is used to hold information for schema based positioners.
 */
@interface RBLayoutSchemaPositionerSchema : NSObject

/**
 *  An array of `UIView` objects in the order that they should be added to a layout view.
 */
@property (nonatomic, nonnull, readonly) NSArray<UIView *> *views;

@end
