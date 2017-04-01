//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormItemSchema.h"
#import "RBManagedFormValidationRule.h"

/**
 *  The base managed form field schema class.
 */
@interface RBManagedFormFieldSchema : RBManagedFormItemSchema

/**
 *  An optional label string to be displayed above the item in the form. Will not be displayed if `nil`.
 */
@property (nonatomic, nullable) NSString *label;

/**
 *  The initial value for the field.
 */
@property (nonatomic, nullable) id initialValue;

/**
 *  An array of `RBManagedFormValidationRuleSchema` objects.
 */
@property (nonatomic, nullable) NSArray<RBManagedFormValidationRuleSchema *> *validationRules;

/**
 *  The `RBLabel` that represents the attached label. Only applicable if the `label` property is not `nil`.
 */
@property (nonatomic, nullable, readonly) RBLabel *labelView;


/**
 *  Theme values to apply to the labelView after any other prior theming has been applied.
 */
@property (nonatomic, nullable) NSDictionary<NSString *, id> *labelThemeOverrides;

@end
