//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/UIView+FormField.h>

/**
 *  An item for a multiple choice field.
 */
@interface RBMultipleChoiceFieldOption : NSObject

/**
 *  The value of the item.
 */
@property (nonatomic, readonly, nonnull) NSString *value;

/**
 *  The display text of the item.
 */
@property (nonatomic, readonly, nullable) NSString *displayText;

/**
 *  The display image of the item.
 */
@property (nonatomic, readonly, nullable) UIImage *displayImage;

/**
 *  Initializes the item.
 *
 *  @param value       The value of the item.
 *  @param displayText The display text of the item.
 *
 *  @return The initialized item.
 */
- (nonnull instancetype)initWithValue:(nonnull NSString *)value displayText:(nonnull NSString *)displayText;

/**
 *  Initializes the item.
 *
 *  @param value        The value of the item.
 *  @param displayText  The display text of the item.
 *  @param displayImage The display image of the item.
 *
 *  @return The initialized item.
 */
- (nonnull instancetype)initWithValue:(nonnull NSString *)value displayText:(nullable NSString *)displayText displayImage:(nullable UIImage *)displayImage;

@end

@protocol RBMultipleChoiceFieldDelegate;

/**
 *  A multiple choice field.
 */
@interface RBMultipleChoiceField : UIControl

/**
 *  A delegate to receive item selection events.
 */
@property (nonatomic, weak, nullable) id<RBMultipleChoiceFieldDelegate> delegate;

/**
 *  Whether or not multiple selection is allowed. Default = `NO`.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 *  Whether or not the last selected item can be unselected. Default = `YES`.
 */
@property (nonatomic) BOOL zeroSelectionAllowed;

/**
 *  An array of `RBMultipleChoiceFieldOption` objects.
 */
@property (nonatomic, nullable) NSArray<RBMultipleChoiceFieldOption *> *options;

/**
 *  The values of the options that are selected.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *selectedOptionValues;

/**
 *  The size of the selection buttons. Default = 50, 50.
 */
@property (nonatomic) CGSize optionSize;

/**
 *  The overall positioner used. You may theme this positioner. Default values =
 *  spacing = 0,
 *  dimensions = 1,
 *  margin = [0, 0, 0, 0],
 *  orientation = `RBOrientationVertical`,
 *  sizing = `RBLayoutGridPositionerSizeEvenly`.
 */
@property (nonatomic, nonnull, readonly) RBLayoutGridPositioner *positioner;

/**
 *  Updates the selection state of the option with the given value.
 *
 *  @param selected Whether or not to update the option to selected (`YES`) or unselected (`NO`).
 *  @param value    The value of the option to update.
 */
- (void)setSelected:(BOOL)selected forOptionValue:(nonnull NSString *)value;

/**
 *  Unselect all options.
 */
- (void)unselectAllOptions;

@end

/**
 *  A delegate to receive option selection events from an `RBMultipleChoiceField` object.
 */
@protocol RBMultipleChoiceFieldDelegate <NSObject>

@optional

/**
 *  Called when an option was selected.
 *
 *  @param multipleChoiceField The multiple choice field.
 *  @param option              The option that is being selected.
 */
- (void)multipleChoiceField:(nonnull RBMultipleChoiceField *)multipleChoiceField didSelectOption:(nonnull RBMultipleChoiceFieldOption *)option;

/**
 *  Called when an option was unselected.
 *
 *  @param multipleChoiceField The multiple choice field.
 *  @param option              The option that is being unselected.
 */
- (void)multipleChoiceField:(nonnull RBMultipleChoiceField *)multipleChoiceField didDeselectOption:(nonnull RBMultipleChoiceFieldOption *)option;

@end
