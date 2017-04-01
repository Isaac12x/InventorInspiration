//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#include <Foundation/Foundation.h>

#import <Redbeard/RBToolbarButtonItemSchema.h>
#import <Redbeard/RBToolbarToggleButtonItemSchema.h>
#import <Redbeard/RBToolbarSpacingItemSchema.h>
#import <Redbeard/RBToolbarCustomItemSchema.h>

/**
 *  A schema that describes a toolbar.
 */
@interface RBToolbarSchema : NSObject

/**
 *  The items in the toolbar. The following types are supported:
 *  `RBToolbarButtonItemSchema`, `RBToolbarToggleButtonItemSchema`, RBToolbarCustomItemSchema.
 */
@property (nonatomic, readonly, nonnull) NSArray *items;

/**
 *  The orientation of the toolbar.
 */
@property (nonatomic, readonly) RBOrientation orientation;

/**
 *  Initializes a new toolbar schema.
 *
 *  @param items       The item schemas for the toolbar. The following types are supported: `RBToolbarButtonItemSchema`, RBToolbarToggleButtonItemSchema`, RBToolbarCustomItemSchema.
 *  @param orientation The orientation of the toolbar.
 *
 *  @return The initialized toolbar schema.
 */
- (nonnull instancetype)initWithItems:(nonnull NSArray *)items orientation:(RBOrientation)orientation;

@end
