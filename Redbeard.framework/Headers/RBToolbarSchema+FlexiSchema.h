//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#include <Foundation/Foundation.h>

#import <Redbeard/RBToolbarSchema.h>
#import <Redbeard/RBLayoutFlexiPositionerSchema.h>

@interface RBToolbarSchema (FlexiSchema)

/**
*  The required schema for an `RBLayoutFlexiPositioner` object to display this element of the toolbar schema.
*
*  @param views An array of `UIView`'s that are to be used by the schema.
*
*  @return A newly initialized `RBLayoutFlexiPositionerSchema` object representing the toolbar elements.
*/
- (nonnull RBLayoutFlexiPositionerSchema *)flexiSchemaWithViews:(nonnull NSArray<UIView *> *)views;

@end

@interface RBToolbarButtonItemSchema (FlexiSchema)

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this row element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerRowSchema *flexiRowSchema;

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this cell element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerCellSchema *flexiCellSchema;

@end

@interface RBToolbarToggleButtonItemSchema (FlexiSchema)

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this row element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerRowSchema *flexiRowSchema;

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this cell element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerCellSchema *flexiCellSchema;

@end

@interface RBToolbarCustomItemSchema (FlexiSchema)

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this row element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerRowSchema *flexiRowSchema;

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this cell element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerCellSchema *flexiCellSchema;

@end

@interface RBToolbarSpacingItemSchema (FlexiSchema)

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this row element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerRowSchema *flexiRowSchema;

/**
 *  The required schema for an `RBLayoutFlexiPositioner` object to display this cell element of the toolbar schema.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerCellSchema *flexiCellSchema;

@end
