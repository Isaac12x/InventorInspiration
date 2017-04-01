//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"

/**
 *  A managed `RBSwitchField` form field schema.
 */
@interface RBManagedFormSwitchFieldSchema : RBManagedFormFieldSchema

/**
 *  The label text to display next to the switch field.  Default = `nil`.
 */
@property (nonatomic, nullable) NSString *text;

@end
