//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBTextField.h>
#import <Redbeard/RBListInputView.h>

/**
 *  An item for a list field.
 */
@interface RBListFieldItem : NSObject

/**
 *  The value of the item.
 */
@property (nonatomic, readonly, nullable) NSString *value;

/**
 *  The display text of the item.
 */
@property (nonatomic, readonly, nullable) NSString *displayText;

/**
 *  Initializes the list field item.
 *
 *  @param value       The value of the item.
 *  @param displayText The display text of the item.
 *
 *  @return The initialized list field item.
 */
- (nonnull instancetype)initWithValue:(nonnull NSString *)value displayText:(nonnull NSString *)displayText;

@end

/**
 *  A list field.
 */
@interface RBListField : RBTextField<RBInputViewDelegate>

/**
 *  An array of `RBListFieldItem` objects.
 */
@property (nonatomic, nullable) NSArray<RBListFieldItem *> *items;

/**
 *  The current selected item value.
 */
@property (nonatomic, nullable) NSString *currentValue;

/**
 *  The current selected item display text.
 */
@property (nonatomic, nullable) NSString *currentDisplayText;

@end
