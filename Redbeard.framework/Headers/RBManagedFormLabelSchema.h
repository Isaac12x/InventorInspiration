//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormItemSchema.h"

/**
 *  A schema for a managed `RBLabel`.
 */
@interface RBManagedFormLabelSchema : RBManagedFormItemSchema

/**
 *  The text to display in the label.
 */
@property (nonatomic, nullable) NSString *text;

/**
 *  The attributed text to display in the label.
 */
@property (nonatomic, nullable) NSAttributedString *attributedText;

@end
