//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBLayoutView.h>
#import <Redbeard/RBLayoutPositioner.h>

#import <Redbeard/RBManagedFormSchema.h>
#import <Redbeard/RBManagedFormValidator.h>
#import <Redbeard/RBManagedFormInputToolbar.h>
#import <Redbeard/RBManagedFormSeparatorView.h>

#import <Redbeard/RBInputView.h>
#import <Redbeard/RBDateTimeInputView.h>
#import <Redbeard/RBListInputView.h>

#import <Redbeard/UIView+FormField.h>

@protocol RBManagedFormViewDelegate;

/**
 *  A view that provides a managed form.
 */
@interface RBManagedFormView : UIView

/**
 *  A delegate to receive form events.
 */
@property (nonatomic, weak, nullable) id<RBManagedFormViewDelegate, RBBaseLayoutViewDelegate> delegate;

/**
 *  The `RBLayoutPositioner` to handle the layout of form elements. Default = `RBLayoutGridPositioner` with values
 *  spacing = 0,
 *  dimensions = 1,
 *  margin = [0, 0, 0, 0],
 *  orientation = `RBOrientationVertical`,
 *  sizing = `RBLayoutGridPositionerSizeEvenly`.
 */
@property (nonatomic, nonnull) RBLayoutPositioner *positioner;

/**
 *  The `UIScrollView` to scroll and adjust when managing fields and input views.
 *  If `nil`, the layout view of the form itself is used.  Default is `nil`.
 */
@property (nonatomic, weak, nullable) UIScrollView *scroller;

/**
 *  The `UIModalTransitionStyle` to use when displaying any modals such as the photo picker. Default = `UIModalTransitionStyleCoverVertical`.
 */
@property (nonatomic) UIModalTransitionStyle modalTransitionStyle;

#pragma mark -
#pragma mark InputView/Keyboard Toolbar

/**
 *  The toolbar to be used on input views when editing form fields.
 */
@property (nonatomic, readonly, nonnull) RBManagedFormInputToolbar *accessoryToolbarView;

/**
 *  Whether or not the toolbar should be used on input views. Default = `YES`.
 */
@property (nonatomic) BOOL toolbarEnabled;

/**
 *  The action to perform when the return key is tapped on the keyboard.
 */
@property (nonatomic) RBManagedFormKeyboardReturnAction keyboardReturnAction;

/**
 *  The validation view to display when highlighting incomplete fields. Default = `RBManagedFormValidationViewTypeTooltip`.
 */
@property (nonatomic) RBManagedFormValidationViewType validationViewType;

#pragma mark -
#pragma mark Form Schema

/**
 *  Resets the form to empty.
 */
- (void)resetForm;

/**
 *  Updates the form using the given schema.
 *
 *  @param formSchema The `RBManagedFormSchema` object.
 */
- (void)setFormSchema:(nonnull RBManagedFormSchema *)formSchema;

/**
 *  Retrieves the item schema for the given identifier.
 *
 *  @param identifier   The identifer of the schema item object.
 *
 *  @return The `RBManagedFormItemSchema` object.
 */
- (nullable RBManagedFormItemSchema *)itemSchemaForIdentifier:(nonnull NSString *)identifier;

#pragma mark -
#pragma mark Views

/**
 *  Returns the `UIView` that was created for the schema item matching the given identifier.
 *
 *  @param identifier   The identifier of the schema item object.
 *
 *  @return The `UIView` for the given identifier.
 */
- (nullable UIView *)viewForIdentifier:(nonnull NSString *)identifier;

#pragma mark -
#pragma mark Values

/**
 *  The current value of the form fields. If hidden form fields are present the initial 
 *  values of these fields will be included returned when calling this property. Note setting hidden form fields using this property has no effect.
 */
@property (nonatomic, nonnull) NSDictionary<NSString *, id> *values;

/**
 *  Resets the form fields to the initial values specified in the schema.
 */
- (void)resetToInitialValues;

/**
 *  Updates the current value of the (non hidden) form fields with the given values dictionary.
 *
 *  @param keyedValues The `NSDictionary<NSString *, id>` object containing field values.
 */
- (void)updateValuesWithDictionary:(nonnull NSDictionary<NSString *, id> *)keyedValues;

#pragma mark -
#pragma mark Keyboard

/**
 *  Opens the keyboard/inputview on the first editable field.
 */
- (void)selectFirstField;

/**
 *  Opens the keyboard/inputview on the editable field with the given identifier.
 *
 *  @param identifier   The name of the field to select for editing.
 */
- (void)selectFieldWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Close the open keyboard/inputview.
 *
 *  @param completion An optional block to be called when the keyboard has been closed.
 */
- (void)closeKeyboardWithCompletion:(nullable dispatch_block_t)completion;

#pragma mark -
#pragma mark Validation & Submission

/**
 *  Runs validation for the field with the given identifier.
 *
 *  @param identifier   The field identifier.
 *
 *  @return Whether or not the field validated.
 */
- (BOOL)validateFieldWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Runs validation on the form, returning the result.
 *
 *  @return Whether or not the form is valid.
 */
- (BOOL)validateForm;

/**
 *  Submits the form, prompting validation and delegate calls if successful.
 *
 *  @return Whether or not the form validated and was submitted.
 */
- (BOOL)submitForm; // does nothing if not validated

/**
 *  Cancels the form, calling the delegate method.
 */
- (void)cancelForm;

@end

/**
 *  A delegate to receive managed form events from an `RBManagedFormView` object.
 */
@protocol RBManagedFormViewDelegate <NSObject, RBBaseLayoutViewDelegate>

@optional

/**
 *  Called for each schema items corresponding `UIView` when the form is being setup.
 *
 *  @param view         The `UIView` object that the schema with the provided identifier has created.
 *  @param identifier   The identifier of the schema.
 *  @param managedFormView  The `RBManagedFormView` object.
 */
- (void)setupView:(nonnull UIView *)view
    forIdentifier:(nonnull NSString *)identifier
    withManagedFormView:(nonnull RBManagedFormView *)managedFormView;

/**
 *  Called when the form is validated and submitted.
 *
 *  @param managedFormView The `RBManagedFormView` object.
 */
- (void)managedFormViewWasSubmitted:(nonnull RBManagedFormView *)managedFormView;

/**
 *  Called when the form is cancelled.
 *
 *  @param managedFormView The `RBManagedFormView` object.
 */
- (void)managedFormViewWasCancelled:(nonnull RBManagedFormView *)managedFormView;

/**
 *  Called when a field will have it's value changed.
 *
 *  @param identifier       The identifier of the field.
 *  @param value            The current value of the field.
 *  @param newValue         The new value that will be assigned to the field.
 *  @param managedFormView  The `RBManagedFormView` object.
 */
- (void)fieldWithIdentifier:(nonnull NSString *)identifier
        willUpdateFromValue:(nullable id)value
                    toValue:(nullable id)newValue
        withManagedFormView:(nonnull RBManagedFormView *)managedFormView;

/**
 *  Called when a field value has changed.
 *
 *  @param identifier       The identifier of the field.
 *  @param previousValue    The previous value of the field.
 *  @param value            The new value of the field.
 *  @param managedFormView  The `RBManagedFormView` object.
 */
- (void)fieldWithIdentifier:(nonnull NSString *)identifier
         didUpdateFromValue:(nullable id)previousValue
                    toValue:(nullable id)value
        withManagedFormView:(nonnull RBManagedFormView *)managedFormView;

/**
 *  Gets the view controller that should be used when presenting the photo library or camera.
 *
 *  @param managedFormView The `RBManagedFormView` object.
 *
 *  @return The `UIViewController` to present with.
 */
- (nonnull UIViewController *)presentingViewControllerForFormView:(nonnull RBManagedFormView *)managedFormView;

@end
