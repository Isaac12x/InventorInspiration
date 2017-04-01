//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBLayoutSchemaPositionerSchema.h>
#import <Redbeard/RBLayoutFlexiPositionerRowSchema.h>
#import <Redbeard/RBLayoutFlexiPositionerCellSchema.h>
#import <Redbeard/RBLayoutFlexiPositionerMetricSchema.h>

/**
 *  Describes the sizing and layout for a `RBLayoutFlexiPositioner`.
 */
@interface RBLayoutFlexiPositionerSchema : RBLayoutSchemaPositionerSchema

/**
 *  An array of `RBLayoutFlexiPositionerRowSchema` objects.
 */
@property (nonatomic, readonly, nonnull) NSArray<RBLayoutFlexiPositionerRowSchema *> *rows;

/**
 *  Returns the number of cells that contain content and hence are not empty.
 */
@property (nonatomic, readonly) NSUInteger nonEmptyCellCount;

/**
 *  Initializes a new `RBLayoutFlexiPositionerSchema` object describing a sizing and layout.
 *
 *  @param rows     An array of `RBLayoutFlexiPositionerRowSchema` objects.
 *  @param views    An array of `UIView`'s that are referred to by the schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerSchema` object representing a sizing and layout structure.
 */
- (nonnull instancetype)initWithRows:(nonnull NSArray<RBLayoutFlexiPositionerRowSchema *> *)rows
                           withViews:(nonnull NSArray<UIView *> *)views;

/**
 *  Initializes a new `RBLayoutFlexiPositionerSchema` object describing a sizing and layout.
 *
 *  @param rows     An array of `RBLayoutFlexiPositionerRowSchema` objects.
 *  @param views    An array of `UIView`'s that are referred to by the schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerSchema` object representing a sizing and layout structure.
 */
+ (nonnull instancetype)withRows:(nonnull NSArray<RBLayoutFlexiPositionerRowSchema *> *)rows
                       withViews:(nonnull NSArray<UIView *> *)views;

/**
 *  Initializes a new `RBLayoutFlexiPositionerSchema` object from a schema dictionary.
 *
 *  @param schemaDictionary A dictionary containing the key `rows` that contains an array of row data.
 *  @param views            An array of `UIView`'s that are referred to by the schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerSchema` object representing a sizing and layout structure.
 */
- (nonnull instancetype)initWithSchemaDictionary:(nonnull NSDictionary<NSString *, id> *)schemaDictionary
                                       withViews:(nonnull NSArray<UIView *> *)views;

/**
 *  Initializes a new `RBLayoutFlexiPositionerSchema` object from a schema dictionary.
 *
 *  @param schemaDictionary A dictionary containing the key `rows` that contains an array of row data.
 *  @param views            An array of `UIView`'s that are referred to by the schema.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerSchema` object representing a sizing and layout structure.
 */
+ (nonnull instancetype)withSchemaDictionary:(nonnull NSDictionary<NSString *, id> *)schemaDictionary
                                   withViews:(nonnull NSArray<UIView *> *)views;

/**
 *  Returns a representation of the sizing and layout of this instance as a schema dictionary.
 *
 *  @return The schema as an `NSDictionary`
 */
- (nonnull NSDictionary<NSString *, id> *)schemaDictionary;

@end
