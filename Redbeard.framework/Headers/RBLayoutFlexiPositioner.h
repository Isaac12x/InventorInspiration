//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBLayoutSchemaPositioner.h>
#import <Redbeard/RBLayoutFlexiPositionerSchema.h>

/**
 *  A flexible grid based positioner that provides the ability to specifically size and layout items based on a wide variety of criteria.
 *
 *  - Rows do not need to contain similar numbers of cells.
 *  - Autosize cells or rows to match contents.
 *  - Automatically grow cells and rows to take up unused space.
 *  - Set the size of cells and rows by pt or as a percentage.
 *  - Set cells or rows to be empty.
 *  - Provide minimum, maximum values for rows and cells as pt or percentage.
 *  - Anchor content within cells horizontally, vertically or both.
 *  - Expand content within cells to utilise available space horizontally, vertically or both.
 *  - Provide margins and spacing values.
 */
@interface RBLayoutFlexiPositioner : RBLayoutSchemaPositioner

/**
 *  Initializes a new `RBLayoutFlexiPositioner` using the supplied schema.
 *
 *  @param schema       The schema to use.
 *
 *  @return The initialized positioner.
 */
- (nonnull instancetype)initWithSchema:(nonnull RBLayoutFlexiPositionerSchema *)schema;

/**
 *  Initializes a new `RBLayoutFlexiPositioner` using the supplied schema.
 *
 *  @param schema       The schema to use.
 *
 *  @return The initialized positioner.
 */
+ (nonnull instancetype)withSchema:(nonnull RBLayoutFlexiPositionerSchema *)schema;

@end
