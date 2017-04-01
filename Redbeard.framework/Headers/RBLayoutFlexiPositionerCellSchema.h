//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Redbeard/RBLayoutFlexiPositionerMetricSchema.h>

/**
 *  Describes the sizing and layout characteristics for a cell.
 */
@interface RBLayoutFlexiPositionerCellSchema : NSObject

#pragma mark -
#pragma mark The Cell

/**
 *  Indicates that this cell is empty. If a cell is marked empty the `RBLayoutFlexiPositionerCell` will 'skip' over this cell when adding content items.
 */
@property (nonatomic, readonly) BOOL isEmpty;

/**
 *  A `RBLayoutFlexiPositionerMetricSchema` detailing the sizing for the horizontal orientation. This must be set for a cell.
 */
@property (nonatomic, readonly, nonnull) RBLayoutFlexiPositionerMetricSchema *horizontalMetric; // Required

/**
 *  A `RBLayoutFlexiPositionerMetricSchema` detailing the sizing for the vertical orientation. This is optional and may be set to as nil.
 */
@property (nonatomic, readonly, nullable) RBLayoutFlexiPositionerMetricSchema *verticalMetric; // Optional


#pragma mark -
#pragma mark Positioning Within The Cell

/**
 *  Indicates content within a cell should fill the available width.
 */
@property (nonatomic, readonly) BOOL fillToWidth;

/**
 *  Indicates content within a cell should fill the available height.
 */
@property (nonatomic, readonly) BOOL fillToHeight;

/**
 *  The margin around the content of the cell.
 */
@property (nonatomic, readonly) UIEdgeInsets margin;

/**
 *  Determines the anchor position for content within a cell in the vertical orientation.
 */
@property (nonatomic, readonly) RBVerticalAlignment verticalAlignment;

/**
 *  Determines the anchor position for content within a cell in the horizontal orientation.
 */
@property (nonatomic, readonly) RBHorizontalAlignment horizontalAlignment;


#pragma mark -
#pragma mark Creation

/**
 *  Initializes a new `RBLayoutFlexiPositionerCellSchema` object describing the sizing and layout characteristics for a cell.
 *
 *  @param horizontalMetric    The horizontal sizing details. Required.
 *  @param verticalMetric      The vertical sizing details. Optional, may be set as `nil`.
 *  @param verticalAlignment   The vertical anchoring position for the cell content.
 *  @param horizontalAlignment The horizontal anchoring position for the cell content.
 *  @param fillToWidth         Ensure content fills available width.
 *  @param fillToHeight        Ensure content fills available height.
 *  @param margin              Margin around cell content.
 *  @param isEmpty             Indicates the cell should not contain content.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerCellSchema` object representing sizing and layout characteristics for a cell.
 */
- (nonnull instancetype)initWithHorizontalMetricValue:(nonnull RBLayoutFlexiPositionerMetricSchema *)horizontalMetric
                  optionalVerticalMetricValue:(nullable RBLayoutFlexiPositionerMetricSchema *)verticalMetric
                            verticalAlignment:(RBVerticalAlignment)verticalAlignment
                          horizontalAlignment:(RBHorizontalAlignment)horizontalAlignment
                                  fillToWidth:(BOOL)fillToWidth
                                 fillToHeight:(BOOL)fillToHeight
                                       margin:(UIEdgeInsets)margin
                                      isEmpty:(BOOL)isEmpty;

/**
 *  Initializes a new `RBLayoutFlexiPositionerCellSchema` object from a schema dictionary.
 *
 *  @param schemaDictionary A dictionary containing the key `cells` that contains an array of cell data.
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerCellSchema` object representing sizing and layout characteristics for a cell.
 */
- (nonnull instancetype)initWithSchemaDictionary:(nonnull NSDictionary<NSString *, id> *)schemaDictionary;

/**
 *  Returns a representation of the sizing and layout of this instance as a schema dictionary.
 *
 *  @return The schema as an `NSDictionary`
 */
- (nonnull NSDictionary<NSString *, id> *)schemaDictionary;


#pragma mark -
#pragma mark Factory

/**
 *  Convenience class method that returns an empty flexi cell with a minimum and maximum absolute pt value set to 0.
 *
 *  @return A newly created `RBLayoutFlexiPositionerCellSchema` representing an empty flexi cell with a minimum and maximum absolute pt value set to 0.
 */
+ (nonnull instancetype)emptyFlexibleCell;

/**
 *  Convenience class method that returns an empty flexi cell representation using the provided minimum and maximum absolute widths.
 *
 *  @param minimumSize The minimum size as a pt value. Setting 0 ignores this value.
 *  @param maximumSize The maximum size as a pt value. Setting 0 ignores this value.
 *
 *  @return A newly created `RBLayoutFlexiPositionerCellSchema` representing an empty flexi cell with a minimum and maximum absolute pt value.
 */
+ (nonnull instancetype)emptyFlexibleCellWithMinimumSize:(CGFloat)minimumSize maximumSize:(CGFloat)maximumSize;

@end
