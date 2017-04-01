//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

/**
 *  `UIDevice` extension methods.
 */
@interface UIDevice (Extensions)

/**
 *  Determines whether or not the system version is equal to the version given.
 *
 *  @param systemVersion The version to compare to the actual system version.
 *
 *  @return Whether or not the system version is equal to the version given.
 */
- (BOOL)systemVersionIsEqualTo:(nonnull NSString *)systemVersion;

/**
 *  Determines whether or not the system version is greater than the version given.
 *
 *  @param systemVersion The version to compare to the actual system version.
 *
 *  @return Whether or not the system version is greater than the version given.
 */
- (BOOL)systemVersionIsGreaterThan:(nonnull NSString *)systemVersion;

/**
 *  Determines whether or not the system version is greater than or equal to the version given.
 *
 *  @param systemVersion The version to compare to the actual system version.
 *
 *  @return Whether or not the system version is greater than or equal to the version given.
 */
- (BOOL)systemVersionIsGreaterThanOrEqualTo:(nonnull NSString *)systemVersion;

/**
 *  Determines whether or not the system version is less than the version given.
 *
 *  @param systemVersion The version to compare to the actual system version.
 *
 *  @return Whether or not the system version is less than the version given.
 */
- (BOOL)systemVersionIsLessThan:(nonnull NSString *)systemVersion;

/**
 *  Determines whether or not the system version is less than or equal to the version given.
 *
 *  @param systemVersion The version to compare to the actual system version.
 *
 *  @return Whether or not the system version is less than or equal to the version given.
 */
- (BOOL)systemVersionIsLessThanOrEqualTo:(nonnull NSString *)systemVersion;

/**
 *  Make the device vibrate (if it is possible).
 */
+ (void)vibrate;

/**
 *  Make the device emit the keyboard click sound (if it is possible).
 */
- (void)keyboardClickSound;

@end
