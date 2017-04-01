//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  `UIColor` extension methods.
 */
@interface UIColor (Extensions)

/**
 *  Returns a randomly selected color.
 *
 *  @return A randomly selected `UIColor` object.
 */
+ (nonnull UIColor *)randomColor;

/**
 *  Creates a `UIColor` object from a hex color code.
 *
 *  @param hexString The hex color code to parse. May begin with '#' or '0x'. The alpha channel is optional.
 *
 *  @return The resulting `UIColor` object.
 */
+ (nullable UIColor *)colorWithRGBAHexString:(nonnull NSString *)hexString;

/**
 *  Returns the inverse of this color.
 *
 *  @return The inverse color.
 */
- (nonnull UIColor *)inverseColor;

/**
 *  Returns the hex color code for this color.
 *
 *  @return The hex color code.
 */
- (nonnull NSString *)hexString;

@end
