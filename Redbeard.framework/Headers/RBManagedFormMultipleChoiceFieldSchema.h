//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"
#import "RBMultipleChoiceField.h"

/**
 *  A managed form `RBMultipleChoiceField` schema.
 */
@interface RBManagedFormMultipleChoiceFieldSchema : RBManagedFormFieldSchema

/**
 *  The multiple choice options.
 */
@property (nonatomic, nullable) NSArray<RBMultipleChoiceFieldOption *> *options;

/**
 *  The multiple choice options as strings. The strings will be converted into an array of `RBMultipleChoiceFieldOption` (the value and displayText being set the same) internally. This is a convenience property.
 */
@property (nonatomic, nullable) NSArray<NSString *> *stringOptions;

/**
 *  Whether or not multiple selection is allowed. Default = `NO`.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 *  Whether or not all items can be unselected, leaving zero selected items. Default = `NO`.
 */
@property (nonatomic) BOOL zeroSelectionAllowed;

@end
