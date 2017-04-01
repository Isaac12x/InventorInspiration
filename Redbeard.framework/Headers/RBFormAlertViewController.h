//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBManagedFormView.h>

/**
 *  The submit button identifier for an `RBFormAlertViewController`. You may use this in the `setButtons:` method. Using this value will provide a button that will submit the form when pressed. The value of this is = 'formAlertSubmitButtonIdentifier'
 */
extern NSString * __nonnull const formAlertSubmitButtonIdentifier;

/**
 *  The cancel button identifier for an `RBFormAlertViewController`. You may use this in the `setButtons:` method. Using this value will provide a button that will cancel the form when pressed. The value of this is = 'formAlertCancelButtonIdentifier'
 */
extern NSString * __nonnull const formAlertCancelButtonIdentifier;

@protocol RBFormAlertViewControllerDelegate;

/**
 *  A managed form alert view controller. Used by UIViewController+ManagedFormAlert.h.
 */
@interface RBFormAlertViewController : UIViewController

/**
 *  A delegate to receive form events such as submission and button taps.
 */
@property (nonatomic, weak, nullable) id<RBFormAlertViewControllerDelegate> delegate;

/**
 *  The underlying form schema.
 */
@property (nonatomic, nullable) RBManagedFormSchema *formSchema;

/**
 *  The current form values.
 */
@property (nonatomic, nullable) NSDictionary *formValues;

/**
 *  The titles of the buttons on the form alert.
 */
@property (nonatomic, nullable, readonly) NSArray<NSString *> *buttonTitles;

/**
 *  The identifiers of the buttons on the form alert.
 */
@property (nonatomic, nullable, readonly) NSArray<NSString *> *buttonIdentifiers;

/**
 *  Whether or not the first editable field should be selected when the form opens.
 */
@property (nonatomic) BOOL shouldOpenFirstFieldForEditing;

/**
 *  The action that should be performed when the keyboard return button is tapped.
 */
@property (nonatomic) RBManagedFormKeyboardReturnAction keyboardReturnAction;

/**
 *  The `RBLayoutPositioner` to handle the layout of form elements. Default = See positioner on `RBManagedFormView` for default.
 *  You may theme this positioner.
 */
@property (nonatomic, nonnull) RBLayoutPositioner *formPositioner;

/**
 *  The overall layout positioner used. You may theme this positioner. Default values =
 *  spacing = 10,
 *  dimensions = 1,
 *  margin = [10, 10, 10, 10],
 *  orientation = `RBOrientationVertical`,
 *  sizing = `RBLayoutGridPositionerSizeEvenly`.
 */
@property (nonatomic, nonnull, readonly) RBLayoutGridPositioner *positioner;

/**
 *  The layout positioner used for the buttons. You may theme this positioner. Default values =
 *  spacing = 10,
 *  dimensions = 1,
 *  margin = [0, 0, 0, 0],
 *  orientation = `RBOrientationVertical`,
 *  sizing = `RBLayoutGridPositionerSizeEvenly`.
 */
@property (nonatomic, nonnull, readonly) RBLayoutGridPositioner *buttonPositioner;

/**
 *  The size required to present the form in the given available container size.
 *
 *  @param containerSize The available container size.
 *
 *  @return The size required to present the form.
 */
- (CGSize)sizeWithContainerSize:(CGSize)containerSize;

/**
*  Defines the buttons that will be provided.
*
*  @param identifiers  The unique identifier for each button. Note you may use the pre-defined identifier constants `formAlertSubmitButtonIdentifier` and `formAlertCancelButtonIdentifier` to easily add submit and cancel buttons that call the `submitForm` and `cancelFrom` methods on the managed form.
*  @param titles       The buttons titles.
*/
- (void)setButtons:(nonnull NSArray<NSString *> *)identifiers withTitles:(nonnull NSArray<NSString *> *)titles;

@end

/**
 *  A delegate to receive form events such as submission and button taps for an `RBFormAlertViewController`.
 */
@protocol RBFormAlertViewControllerDelegate <NSObject>

@required

/**
 *  Called when the form is successfully submitted.
 *
 *  @param formAlertViewController The `RBFormAlertViewController` object.
 *  @param values                  The form values that were submitted.
 */
- (void)formAlertViewController:(nonnull RBFormAlertViewController *)formAlertViewController didSubmitWithValues:(nonnull NSDictionary *)values;

/**
 *  Called when the form alert was cancelled.
 *
 *  @param formAlertViewController The `RBFormAlertViewController` object.
 */
- (void)formAlertViewControllerDidCancel:(nonnull RBFormAlertViewController *)formAlertViewController;

/**
 *  Called when a form alert button was tapped.
 *
 *  @param formAlertViewController The `RBFormAlertViewController` object.
 *  @param identifier               The identifier of the button that was tapped.
 */
- (void)formAlertViewController:(nonnull RBFormAlertViewController *)formAlertViewController buttonWasSelectedWithIdentifier:(nonnull NSString *)identifier;

@optional

/**
 *  Called for each schema items corresponding `UIView` when the form is being setup.
 *
 *  @param formAlertViewController  The `RBFormAlertViewController` object.
 *  @param view                     The `UIView` object that the schema with the provided identifier has created.
 *  @param identifier               The identifier of the schema.
 */
- (void)formAlertViewController:(nonnull RBFormAlertViewController *)formAlertViewController
                      setupView:(nonnull UIView *)view
                  forIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a field will have it's value changed.
 *
 *  @param formAlertViewController  The `RBFormAlertViewController` object.
 *  @param identifier               The identifier of the field.
 *  @param value                    The current value of the field.
 *  @param newValue                 The new value that will be assigned to the field.
 */
- (void)formAlertViewController:(nonnull RBFormAlertViewController *)formAlertViewController
            fieldWithIdentifier:(nonnull NSString *)identifier
            willUpdateFromValue:(nullable id)value
                        toValue:(nullable id)newValue;

/**
 *  Called when a field value has changed.
 *
 *  @param formAlertViewController  The `RBFormAlertViewController` object.
 *  @param identifier               The identifier of the field.
 *  @param previousValue            The previous value of the field.
 *  @param value                    The new value of the field.
 */
- (void)formAlertViewController:(nonnull RBFormAlertViewController *)formAlertViewController
            fieldWithIdentifier:(nonnull NSString *)identifier
             didUpdateFromValue:(nullable id)previousValue
                        toValue:(nullable id)value;

/**
 *  Gets the view controller that should be used when presenting the photo library or camera.
 *
 *  @param formAlertViewController The `RBFormAlertViewController` object.
 *
 *  @return The `UIViewController` to present with.
 */
- (nonnull UIViewController *)presentingViewControllerForFormAlertViewController:(nonnull RBFormAlertViewController *)formAlertViewController;

@end


