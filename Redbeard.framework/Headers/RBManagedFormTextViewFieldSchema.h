//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"

/**
 *  A managed `RBTextViewField` form field schema. This is a multiline text field.
 */
@interface RBManagedFormTextViewFieldSchema : RBManagedFormFieldSchema

/**
 *  The placeholder text to display when the field is empty.
 */
@property (nonatomic, nullable) NSString *placeholder;

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
 *  The minimum size that the text view field will be given in the managed form.
 */
@property (nonatomic) CGSize minimumSize;

/**
 *  The maximum size that the text view field will be given in the managed form.
 */
@property (nonatomic) CGSize maximumSize;

@end
