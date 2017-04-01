//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"
#import "RBListField.h"

/**
 *  A managed `RBListField` form field schema.
 */
@interface RBManagedFormListFieldSchema : RBManagedFormFieldSchema

/**
 *  The placeholder text to display when there is no value chosen.
 */
@property (nonatomic, nullable) NSString *placeholder;

/**
 *  The items assigned to the underlying `RBListField`.
 */
@property (nonatomic, nullable) NSArray<RBListFieldItem *> *items;

/**
 *  The list items as strings. The strings will be converted into an array of `RBListFieldItem` (the value and displayText being set the same) internally. This is a convenience property.
 */
@property (nonatomic, nullable) NSArray<NSString *> *stringItems;

@end
