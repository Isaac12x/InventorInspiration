//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"

/**
 *  A managed `RBTextField` field schema.
 */
@interface RBManagedFormTextFieldSchema : RBManagedFormFieldSchema

/**
 *  The placeholder text to display when the field is empty.
 */
@property (nonatomic, nullable) NSString *placeholder;

/**
 *  Whether or not the text input should be hidden, for passwords for example.
 */
@property (nonatomic) BOOL secureTextEntry;

/**
 *  Whether or not autocapitalisation should occur when beginning sentences.
 */
@property (nonatomic) UITextAutocapitalizationType autocapitalizationType;

/**
 *  Whether words should be autocorrected.
 */
@property (nonatomic) UITextAutocorrectionType autocorrectionType;

/**
 *  Which type of keyboard to display when the field is selected for editing.
 */
@property (nonatomic) UIKeyboardType keyboardType;

/**
 *  When to show the clear button mode.
 */
@property (nonatomic) UITextFieldViewMode clearButtonMode;

@end
