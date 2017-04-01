//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The sizing mode
 */
typedef NS_ENUM(NSInteger, RBLayoutFlexiPositionerSizingMode) {
    /**
     *  The size should adjust to fit content.
     */
    RBLayoutFlexiPositionerSizingModeAutosize = 0,
    /**
     *  The size is fixed.
     */
    RBLayoutFlexiPositionerSizingModeFixed,
    /**
     *  The size can adjust to the available space.
     */
    RBLayoutFlexiPositionerSizingModeFlexible
};

/**
 *  Describes how sizing and sizing values should be calculated for an orientation when used for a row or cell.
 */
@interface RBLayoutFlexiPositionerMetricSchema : NSObject

/**
 *  The sizing mode for this instance.
 */
@property (nonatomic, readonly) RBLayoutFlexiPositionerSizingMode sizingMode;

/**
 *  Provides a weighting bias when distributing available flexible spacing amongst other flexible metrics. Optional, percentage value (0.0 - 1.0).
 */
@property (nonatomic, readonly) CGFloat flexibleSizingModeWeightingPercentage;

/**
 *  The size. Specified as an absolute pt value or 0.0 - 1.0 percentage value (depending on `sizingValueIsAbsolute` field)
 */
@property (nonatomic, readonly) CGFloat sizingValue;

/**
 *  Indicates that the `sizingValue` value should be interpreted as an absolute pt value or a percentage. Default set as `YES`
 */
@property (nonatomic, readonly) BOOL sizingValueIsAbsolute;

/**
 *  The minimum size. Optional, a value of 0 indicates this should be ignored. Specified as an absolute pt value or 0.0 - 1.0 percentage value (depending on `sizingValueMinimumIsAbsolute` field).
 */
@property (nonatomic, readonly) CGFloat sizingValueMinimum; // Optional value in same units as described by sizingMode

/**
 *  Indicates that the `sizingValueMinimum` value should be interpreted as an absolute pt value or a percentage. Default set as `YES`
 */
@property (nonatomic, readonly) BOOL sizingValueMinimumIsAbsolute; // TRUE by default

/**
 *  The maximum size. Optional, a value of 0 indicates this should be ignored. Specified as an absolute pt value or 0.0 - 1.0 percentage value (depending on `sizingValueMaximumIsAbsolute` field)
 */
@property (nonatomic, readonly) CGFloat sizingValueMaximum;

/**
 *  Indicates that the `sizingValueMaximum` value should be interpreted as an absolute pt value or a percentage. Default set as `YES`
 */
@property (nonatomic, readonly) BOOL sizingValueMaximumIsAbsolute;

/**
 *  Initializes a new `RBLayoutFlexiPositionerMetricSchema` object from a schema dictionary.
 *
 *  @param schemaDictionary A dictionary containing keys that provide specifc data for populating an instance.
 *                          Expects the following keys in the dictionary:
 *                          - `sizingMode` that provides an number value
 *                          - `flexibleSizingModeWeightingPercentage` that provides an `NSNumber` value (0.0 - 1.0)
 *                          - `sizingValue` that provides an `NSNumber` value
 *                          - `sizingValueIsAbsolute` that provides an `NSNumber` value boolean
 *                          - `sizingValueMinimum` that provides an `NSNumber` value
 *                          - `sizingValueMinimumIsAbsolute` that provides an `NSNumber` value boolean
 *                          - `sizingValueMaximum` that provides an `NSNumber` value
 *                          - `sizingValueMaximumIsAbsolute` that provides an `NSNumber` value boolean
 *
 *  @return A newly initialized `RBLayoutFlexiPositionerMetricSchema` object representing sizing data for a orientation.
 */
- (nonnull instancetype)initWithSchemaDictionary:(nonnull NSDictionary<NSString *, id> *)schemaDictionary;

/**
 *  Returns a representation of sizing data of this instance as a schema dictionary.
 *
 *  @return The schema as an `NSDictionary`
 */
- (nonnull NSDictionary<NSString *, id> *)schemaDictionary;

#pragma mark -
#pragma mark Factory

/**
 *  Convenience class method that returns an autosize mode metric.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)autosize;

/**
 *  Convenience class method that returns an autosize mode metric using the provided minimum and maximum absolute pt values.
 *
 *  @param minimum The minimum absolute pt value, 0 ignores.
 *  @param maximum The maximum absolute pt value, 0 ignores.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)autosizeWithAbsoluteMinimum:(CGFloat)minimum maximum:(CGFloat)maximum;

/**
 *  Convenience class method that returns a fixed mode metric using the provided sizing value.
 *
 *  @param value The absolute pt sizing value.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)absoluteWithValue:(CGFloat)value;

/**
 *  Convenience class method that returns a fixed mode metric using the provided sizing, minimum and maximum absolute pt values.
 *
 *  @param value   The absolute pt sizing value.
 *  @param minimum The minimum absolute pt value, 0 ignores.
 *  @param maximum The maximum absolute pt value, 0 ignores.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)absoluteWithValue:(CGFloat)value minimum:(CGFloat)minimum maximum:(CGFloat)maximum;

/**
 *  Convenience class method that returns a fixed mode metric using the provided sizing percentage value.
 *
 *  @param value The percentage sizing value (0.0 - 1.0).
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)percentageWithValue:(CGFloat)value;

/**
 *  Convenience class method that returns a fixed mode metric using the provided sizing, minimum and maximum percentage values.
 *
 *  @param value   The percentage sizing value (0.0 - 1.0).
 *  @param minimum The minimum percentage sizing value (0.0 - 1.0), 0 ignores.
 *  @param maximum The maximum percentage sizing value (0.0 - 1.0), 0 ignores.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)percentageWithValue:(CGFloat)value minimum:(CGFloat)minimum maximum:(CGFloat)maximum;

/**
 *  Convenience class method that returns a flexible mode metric.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)flexible;

/**
 *  Convenience class method that returns a flexible mode metric using the provided minimum and maximum absolute values.
 *
 *  @param minimum The minimum absolute pt value, 0 ignores.
 *  @param maximum The maximum absolute pt value, 0 ignores.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)flexibleWithAbsoluteMinimum:(CGFloat)minimum maximum:(CGFloat)maximum;

/**
 *  Convenience class method that returns a flexible mode metric using the provided minimum and maximum percentage values.
 *
 *  @param minimum The minimum percentage sizing value (0.0 - 1.0), 0 ignores.
 *  @param maximum The maximum percentage sizing value (0.0 - 1.0), 0 ignores.
 *
 *  @return A newly created `RBLayoutFlexiPositionerMetricSchema`.
 */
+ (nonnull instancetype)flexibleWithPercentageMinimum:(CGFloat)minimum maximum:(CGFloat)maximum;

@end
