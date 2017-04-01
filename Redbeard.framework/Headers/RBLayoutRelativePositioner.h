//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBLayoutSchemaPositioner.h>
#import <Redbeard/RBLayoutRelativePositionerSchema.h>

/**
 *  A positioner that arranges view relative to each other and the parent view edges. 
 */
@interface RBLayoutRelativePositioner : RBLayoutSchemaPositioner

/**
 *  Initializes a new `RBLayoutRelativePositioner` using the supplied schema.
 *
 *  @param schema       The schema to use.
 *
 *  @return The initialized positioner.
 */
- (nonnull instancetype)initWithSchema:(nonnull RBLayoutRelativePositionerSchema *)schema;

/**
 *  Initializes a new `RBLayoutRelativePositioner` using the supplied schema.
 *
 *  @param schema       The schema to use.
 *
 *  @return The initialized positioner.
 */
+ (nonnull instancetype)withSchema:(nonnull RBLayoutRelativePositionerSchema *)schema;

@end
