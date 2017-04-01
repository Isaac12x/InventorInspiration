//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Random value generation.
 */
@interface RBRandom : NSObject

/**
 *  Generates a random UUID/GUID string.
 *
 *  @param includeHyphens Whether hyphens should be included.
 *
 *  @return The random UUID string.
 */
+ (nonnull NSString *)UUIDStringWithHyphens:(BOOL)includeHyphens;

/**
 *  Generates a random unsigned integer within the given range.
 *
 *  @param minimumValue The minimum value of the range.
 *  @param maximumValue The maximum value of the range.
 *
 *  @return The random unsigned integer value.
 */
+ (u_int32_t)unsignedIntegerWithMinimumValue:(u_int32_t)minimumValue maximumValue:(u_int32_t)maximumValue;

/**
 *  Generates a random signed integer within the given range.
 *
 *  @param minimumValue The minimum value of the range.
 *  @param maximumValue The maximum value of the range.
 *
 *  @return The random signed integer value.
 */
+ (int32_t)integerWithMinimumValue:(int32_t)minimumValue maximumValue:(int32_t)maximumValue;

/**
 *  Generates a random `double` value within the given range.
 *
 *  @param minimumValue The minimum value of the range.
 *  @param maximumValue The maximum value of the range.
 *
 *  @return The random `double` value.
 */
+ (double)doubleWithMinimumValue:(double)minimumValue maximumValue:(double)maximumValue;

/**
 *  Generates a random boolean value.
 */
+ (BOOL)boolean;

/**
 *  Generates a random lorum ipsum string with the given word count.
 *
 *  @param wordCount The number of words to include in the string.
 *
 *  @return The random lorum ipsum string.
 */
+ (nonnull NSString *)lorumIpsumWithWordCount:(NSUInteger)wordCount;

@end
