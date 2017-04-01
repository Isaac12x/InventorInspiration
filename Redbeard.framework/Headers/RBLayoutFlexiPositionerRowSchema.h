//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Redbeard/RBLayoutFlexiPositionerCellSchema.h>
#import <Redbeard/RBLayoutFlexiPositionerMetricSchema.h>

/**
 *  Describes the sizing and layout characteristics for a row and its cells.
 */
@interface RBLayoutFlexiPositionerRowSchema : NSObject

/**
 *  An array of `RBLayoutFlexiPositionerCellSchema` objects that describe sizing and layout for individual cells.
 */
@property (nonatomic, readonly, nonnull) NSArray<RBLayoutFlexiPositionerCellSchema *> *cells;

/**
 *  A `RBLayoutFlexiPositionerMetricSchema` detailing the sizing for the overall row.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerMetricSchema *verticalMetric;

/**
 *  Initializes a new `RBLayoutFlexiPositionerRowSchema` object describing sizing and layout for a row and its cells.
 *
 *  @param cells          An array of `RBLayoutFlexiPositionerCellSchema` objects that describe sizing and layout for individual cells.
 *  @param verticalMetric A `RBLayoutFlexiPositionerMetricSchema` that details the sizing for the overall row.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerRowSchema` object representing sizing and layout structure for a row.
 */
- (nonnull instancetype)initWithCells:(nonnull NSArray<RBLayoutFlexiPositionerCellSchema *> *)cells
          verticalMetricValue:(nonnull RBLayoutFlexiPositionerMetricSchema *)verticalMetric;

/**
 *  Initializes a new `RBLayoutFlexiPositionerRowSchema` object from a schema dictionary.
 *
 *  @param schemaDictionary A dictionary containing the key `cells` that contains an array of cell data.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerRowSchema` object representing sizing and layout structure for a row.
 */
- (nonnull instancetype)initWithSchemaDictionary:(nonnull NSDictionary<NSString *, id> *)schemaDictionary;

/**
 *  Returns a representation of the sizing and layout of this instance as a schema dictionary.
 *
 *  @return The schema as an `NSDictionary`
 */
- (nonnull NSDictionary<NSString *, id> *)schemaDictionary;

@end
