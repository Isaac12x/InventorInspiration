//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Provides locality-specific serialisations and conversions - e.g. dates, numbers, currencies, etc.
 */
@interface RBLocaleCenter : NSObject

/**
 *  The main locale center.
 */
+ (nonnull RBLocaleCenter *)main;

/**
 *  The default number formatting style.
 */
@property (nonatomic) NSNumberFormatterStyle defaultNumberStyle;

/**
 *  The default date formatting style.
 */
@property (nonatomic) NSDateFormatterStyle defaultDateStyle;

/**
 *  The default time formatting style.
 */
@property (nonatomic) NSDateFormatterStyle defaultTimeStyle;

/**
 *  Parses a string to retrieve a number.
 *
 *  @param numberString The string that contains a number.
 *
 *  @return The resulting `NSNumber` object or `nil`.
 */
- (nullable NSNumber *)numberFromString:(nonnull NSString *)numberString;

/**
 *  Parses a string to retrieve a number.
 *
 *  @param numberString The string that contains a number.
 *  @param numberStyle  The formatting style to expect in the string.
 *
 *  @return The resulting `NSNumber` object or `nil`.
 */
- (nullable NSNumber *)numberFromString:(nonnull NSString *)numberString
                    usingStyle:(NSNumberFormatterStyle)numberStyle;

/**
 *  Formats a number to a string.
 *
 *  @param number The number to format.
 *
 *  @return The resulting formatted string.
 */
- (nonnull NSString *)stringFromNumber:(nonnull NSNumber *)number;

/**
 *  Formats a number to a string.
 *
 *  @param number      The number to format.
 *  @param numberStyle The formatting style to use.
 *
 *  @return The resulting formatted string.
 */
- (nonnull NSString *)stringFromNumber:(nonnull NSNumber *)number
                    usingStyle:(NSNumberFormatterStyle)numberStyle;

/**
 *  Parses a date from a string.
 *
 *  @param dateString    The string to parse.
 *  @param universalTime Whether the date is UTC.
 *
 *  @return The parsed `NSDate` object.
 */
- (nonnull NSDate *)dateFromString:(nonnull NSString *)dateString
             universalTime:(BOOL)universalTime;

/**
 *  Parses a date from a string.
 *
 *  @param dateString    The string to parse.
 *  @param dateStyle     The formatting style to expect for the date component of the string.
 *  @param timeStyle     The formatting style to expect for the time component of the string.
 *  @param universalTime Whether the date is UTC.
 *
 *  @return The parsed `NSDate` object.
 */
- (nullable NSDate *)dateFromString:(nonnull NSString *)dateString
            usingDateStyle:(NSDateFormatterStyle)dateStyle
                 timeStyle:(NSDateFormatterStyle)timeStyle
             universalTime:(BOOL)universalTime;

/**
 *  Formats an `NSDate` into a string.
 *
 *  @param date          The `NSDate` to format.
 *  @param universalTime Whether the date is UTC.
 *
 *  @return The formatted string value.
 */
- (nonnull NSString *)stringFromDate:(nonnull NSDate *)date
               universalTime:(BOOL)universalTime;;

/**
 *  Formats an `NSDate` into a string.
 *
 *  @param date          The `NSDate` to format.
 *  @param dateStyle     The formatting style to use for the date component.
 *  @param timeStyle     The formatting style to use for the time component.
 *  @param universalTime Whether the date is UTC.
 *
 *  @return The formatted string value.
 */
- (nonnull NSString *)stringFromDate:(nonnull NSDate *)date
              usingDateStyle:(NSDateFormatterStyle)dateStyle
                   timeStyle:(NSDateFormatterStyle)timeStyle
               universalTime:(BOOL)universalTime;

@end
