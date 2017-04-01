//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/** For localizing `timesince` please use the following values for localization.

Singular
 
   NSLocalizedStringFromTable(@"year", @"NSDate+timesince", nil),
   NSLocalizedStringFromTable(@"month", @"NSDate+timesince", nil),
   NSLocalizedStringFromTable(@"week", @"NSDate+timesince", nil),
   NSLocalizedStringFromTable(@"day", @"NSDate+timesince", nil),
   NSLocalizedStringFromTable(@"hour", @"NSDate+timesince", nil),
   NSLocalizedStringFromTable(@"minute", @"NSDate+timesince", nil)

Plural
 
    NSLocalizedStringFromTable(@"years", @"NSDate+timesince", nil),
    NSLocalizedStringFromTable(@"months", @"NSDate+timesince", nil),
    NSLocalizedStringFromTable(@"weeks", @"NSDate+timesince", nil),
    NSLocalizedStringFromTable(@"days", @"NSDate+timesince", nil),
    NSLocalizedStringFromTable(@"hours", @"NSDate+timesince", nil),
    NSLocalizedStringFromTable(@"minutes", @"NSDate+timesince", nil)
 
**/



/** The depth to which to describe the time span. */
typedef NS_ENUM(NSInteger, RBTimesinceDepth)
{
    /** Describe the time span in seconds. */
    RBTimesinceDepthSeconds = 0,

    /** Describe the time span in minutes and seconds. */
    RBTimesinceDepthMinutes = 1,

    /** Describe the time span in hours, minutes and seconds. */
    RBTimesinceDepthHours   = 2,

    /** Describe the time span in days, hours, minutes and seconds. */
    RBTimesinceDepthDays    = 3,

    /** Describe the time span in weeks, days, hours, minutes and seconds. */
    RBTimesinceDepthWeeks   = 4,

    /** Describe the time span in months, weeks, days, hours, minutes and seconds. */
    RBTimesinceDepthMonths  = 5,

    /** Describe the time span in years, months, weeks, days, hours, minutes and seconds. */
    RBTimesinceDepthYears   = 6
};

/** `NSDate` extensions. */
@interface NSDate (Extensions)

/**
 * Returns a string describing in natural language the time since this `NSDate`. Can be localized if localization 
 * tables are provided. See above for examples.
 *
 * @return A string describing in natural language the time since this `NSDate`.
 */
- (nonnull NSString *)timesince;

/**
 * Returns a string describing in natural language the time since this `NSDate` using
 * the given `RBTimesinceDepth`.
 *
 * @param depth The depth to describe the time span to.
 * @return A string describing in natural language the time since this `NSDate`.
 */
- (nonnull NSString *)timesinceWithDepth:(RBTimesinceDepth)depth;

/**
 * Returns a string describing in natural language the time span from this `NSDate`
 * since the `NSDate` given, to the given `RBTimesinceDepth`.
 *
 * @param date The date to calculate the timespan from this `NSDate` to.
 * @param depth The depth to describe the time span to.
 * @return A string describing in natural language the time since this `NSDate`.
 */
- (nonnull NSString *)timesinceDate:(nonnull NSDate *)date withDepth:(RBTimesinceDepth)depth;

/**
 *  Returns the string describing in natural language the time span given.
 *
 *  @param timeInterval The time span to describe.
 *  @param depth        The depth to describe the time span to.
 *
 *  @return A string describing the time span in natural language.
 */
+ (nonnull NSString *)timesinceWithTimeInterval:(NSTimeInterval)timeInterval depth:(RBTimesinceDepth)depth;

/**
 * Calculates the beginning of the day of this `NSDate`.
 *
 * @return A new `NSDate` at the beginning of the day of this `NSDate`.
 */
- (nonnull NSDate *)beginningOfDay;

/**
 * Whether this `NSDate` is today.
 *
 * @return `true` if it is today, `false` if not.
 */
- (BOOL)isToday;

/**
 * Creates an `NSDate` for today at the given time.
 *
 * @param hour The hour of the day.
 * @param minute The minute of the hour.
 * @param second The second of the minute.
 * @return The `NSDate` object.
 */
+ (nonnull NSDate *)todayAtHour:(int)hour minute:(int)minute second:(int)second;

/**
 * Creates an `NSDate` for the given date at the given time.
 *
 * @param date The calendar date to apply the time components to.
 * @param hour The hour of the day.
 * @param minute The minute of the hour.
 * @param second The second of the minute.
 * @return The `NSDate` object.
 */
+ (nonnull NSDate *)date:(nonnull NSDate *)date atHour:(int)hour minute:(int)minute second:(int)second;

/**
 * Creates an `NSDate` for the given date at the beginning of the day.
 *
 * @param date The calendar date.
 * @return The `NSDate` object.
 */
+ (nonnull NSDate *)dateWithZeroTime:(nonnull NSDate *)date;

/**
 * Creates an `NSDate` for today plus the given `NSTimeInterval`.
 *
 * @param interval The `NSTimeInterval` from the beginning of the day.
 * @return The `NSDate` object.
 */
+ (nonnull NSDate *)todayAtInterval:(NSTimeInterval)interval;

/**
 * Creates an `NSDate` for the given date at the given time.
 *
 * @param date The calendar date to use.
 * @param time The time of the day to use.
 * @return The `NSDate` object.
 */
+ (nonnull NSDate *)dateTimeFromDate:(nonnull NSDate *)date time:(nonnull NSDate *)time;

/**
 *  Gets the date at the given interval from the start of the day.
 *
 *  @param timeIntervalFromStartOfDay The time interval since the start of the day.
 *
 *  @return The new `NSDate` object.
 */
- (nonnull NSDate *)dateAtTimeIntervalFromStartOfDay:(NSTimeInterval)timeIntervalFromStartOfDay;

/**
 *  Gets the `NSTimeInterval` from the start of the day.
 *
 *  @return The interval from the start of the day.
 */
- (NSTimeInterval)timeIntervalFromStartOfDay;

@end
