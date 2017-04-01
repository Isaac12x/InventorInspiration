//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"
#import "RBDateTimeField.h"

/**
 *  A managed `RBDateTimeField` date/time field schema.
 */
@interface RBManagedFormDateTimeFieldSchema : RBManagedFormFieldSchema

/**
 *  The date and time selection mode.
 */
@property (nonatomic) RBDateTimeFieldMode mode;

/**
 *  The placeholder text that should be displayed in the field when there is no value.
 */
@property (nonatomic, nullable) NSString *placeholder;

/**
 *  The locale. Default = `[NSLocale currentLocale]`. Setting nil returns to default.
 */
@property (nullable, nonatomic, strong) NSLocale   *locale;

/**
 *  The calendar. Default = `[NSLocale currentLocale]`. Setting nil returns to default.
 */
@property (null_resettable, nonatomic, copy)   NSCalendar *calendar;

/**
 *  The timeZone. Default = `nil`. Use current time zone or time zone from calendar
 */
@property (nullable, nonatomic, strong) NSTimeZone *timeZone;

/**
 *  The minimum date range . Default = `nil`. When min > max, the values are ignored.
 */
@property (nullable, nonatomic, strong) NSDate *minimumDate;

/**
 *  The maximum date range . Default = `nil`. When min > max, the values are ignored.
 */
@property (nullable, nonatomic, strong) NSDate *maximumDate;

@end
