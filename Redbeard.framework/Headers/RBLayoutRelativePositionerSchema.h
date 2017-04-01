//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Redbeard/RBLayoutSchemaPositionerSchema.h>
#import <Redbeard/RBLayoutRelativePositionerCellSchema.h>

/**
 *  Validates and holds cell schemas that describe the layout for a `RBLayoutRelativePositioner`.
 */
@interface RBLayoutRelativePositionerSchema : RBLayoutSchemaPositionerSchema

/**
 *  An array of `UIView` objects in the order that they should be added to a layout view. 
 *  The `UIView`s are extracted from the provided cell schemas.
 */
@property (nonatomic, nonnull, readonly) NSArray<UIView *> *views;

/**
 *  An array of `RBLayoutRelativePositionerCellSchema` objects that detail the layout of views.
 */
@property (nonatomic, nonnull, readonly) NSArray<RBLayoutRelativePositionerCellSchema *> *cellSchemas;

/**
 *  Creates a new `RBLayoutRelativePositionerSchema` using the supplied cell schemas.
 *
 *  @param cellSchemas       The cells schemas to use.
 *
 *  @return The created schema.
 */
+ (nonnull instancetype)withCellSchemas:(nonnull NSArray<RBLayoutRelativePositionerCellSchema *> *)cellSchemas;

/**
 *  Initializes a new `RBLayoutRelativePositionerSchema` using the supplied cell schemas.
 *
 *  @param cellSchemas       The cells schemas to use.
 *
 *  @return The initialized schema.
 */
- (nonnull instancetype)initWithCellSchemas:(nonnull NSArray<RBLayoutRelativePositionerCellSchema *> *)cellSchemas;

/**
 *  Finds the cell schema that pertains to the `UIView` provided.
 *
 *  @param view       The view.
 *
 *  @return The corresponding `RBLayoutRelativePositionerCellSchema` or nil if not found.
 */
- (nullable RBLayoutRelativePositionerCellSchema *)schemaForView:(nonnull UIView *)view;


@end
