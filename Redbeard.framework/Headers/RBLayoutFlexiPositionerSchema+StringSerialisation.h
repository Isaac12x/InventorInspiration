//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBLayoutFlexiPositionerSchema.h>

/**
 *  Provides the ability to convert an into a `RBLayoutFlexiPositionerSchema`.
 *  TODO: Document NSArray and NSString syntax for the schemas.
 */
@interface RBLayoutFlexiPositionerSchema (StringSerialisation)

/**
 *  Initializes a new `RBLayoutFlexiPositionerSchema` object from an `NSArray`.
 *
 *  @param schema   An array or arrays (containing strings) describing the schema.
 *  @param views    An array of `UIView`'s that are referred to by the schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerSchema` object.
 */
- (nonnull instancetype)initWithStringSchema:(nonnull NSArray<NSArray<NSString *> *> *)schema
                                   withViews:(nonnull NSArray<UIView *> *)views;
/**
 *  Initializes a new `RBLayoutFlexiPositionerSchema` object from an `NSArray`.
 *
 *  @param schema   An array or arrays (containing strings) describing the schema.
 *  @param views    An array of `UIView`'s that are referred to by the schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerSchema` object.
 */
+ (nonnull instancetype)withStringSchema:(nonnull NSArray<NSArray<NSString *> *> *)schema
                               withViews:(nonnull NSArray<UIView *> *)views;

@end

/**
 * Provides the ability to convert an `NSArray` containing strings into a `RBLayoutFlexiPositionerRowSchema`.
 */
@interface RBLayoutFlexiPositionerRowSchema (StringSerialisation)

/**
 *  Initializes a new `RBLayoutFlexiPositionerRowSchema` object from an `NSArray`.
 *
 *  @param row An array of strings describing the row cell items. The first item describes the row itself.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerRowSchema` object.
 */
- (nonnull instancetype)initWithStringArray:(nonnull NSArray<NSString *> *)row;

@end

/**
 * Provides the ability to convert a string into a `RBLayoutFlexiPositionerCellSchema`.
 */
@interface RBLayoutFlexiPositionerCellSchema (StringSerialisation)

/**
 *  Initializes a new `RBLayoutFlexiPositionerCellSchema` object from an `NSString`.
 *
 *  @param string A string representation of the cell schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerCellSchema` object.
 */
- (nonnull instancetype)initWithString:(nonnull NSString *)string;

@end

/**
 * Provides the ability to convert a string into a `RBLayoutFlexiPositionerMetricSchema`.
 */
@interface RBLayoutFlexiPositionerMetricSchema (StringSerialisation)

/**
 *  Initializes a new `RBLayoutFlexiPositionerMetricSchema` object from an `NSString`.
 *
 *  @param string A string representation of the metric schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerMetricSchema` object.
 */
- (nonnull instancetype)initWithString:(nonnull NSString *)string;

@end