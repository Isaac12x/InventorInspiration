//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A schema to describe a managed form alert.
 */
@interface RBManagedFormAlertSchema : NSObject

/**
 *  The schema of the managed form that will be presented.
 */
@property (nonatomic, nonnull) RBManagedFormSchema *formSchema;

/**
 *  The titles of the buttons on the form alert.
 */
@property (nonatomic, nullable, readonly) NSArray<NSString *> *buttonTitles;

/**
 *  The identifiers of the buttons on the form alert.
 */
@property (nonatomic, nullable, readonly) NSArray<NSString *> *buttonIdentifiers;

/**
 *  Whether or not the alignment specified in this schema should be used
 *  rather than the default value on the presenting view controller. Default = NO.
 */
@property (nonatomic) BOOL shouldUseSchemaAlignment;

/**
 *  The vertical alignment to use when positioning the form alert view.
 */
@property (nonatomic) RBVerticalAlignment alignment;

/**
 *  Whether or not the margin specified in this schema should be used
 *  rather than the default value on the presenting view controller.
 */
@property (nonatomic) BOOL shouldUseSchemaMargin;

/**
 *  The margin to use around the outside of the form alert view when
 *  positioning it within the presenting view controller.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The animator to use when animating the presentation and dismissal transitions.
 */
@property (nonatomic, nullable) RBPresentationAnimator *animator;

/**
 *  Whether or not the first editable field should be automatically
 *  selected (opening the input view) when the form alert is opening. Default = NO.
 */
@property (nonatomic) BOOL shouldOpenFirstFieldForEditing;

/**
 *  The action that should be performed when the return button is
 *  tapped on the keyboard. Default = `RBManagedFormKeyboardReturnActionCloseKeyboard`
 */
@property (nonatomic) RBManagedFormKeyboardReturnAction keyboardReturnAction;

/**
 *  The identifier of the theme to apply to the managed alert form prior to presenting it.
 */
@property (nonatomic, nullable) NSString *themeIdentifier;

/**
 *  Theme values to apply after any other prior theming has been applied.
 */
@property (nonatomic, nullable) NSDictionary<NSString *, id> *themeOverrides;

/**
 *  Defines the buttons that will be provided. By default a functioning submit and cancel button are provided.
 *
 *  @param identifiers  The unique identifier for each button. Note you may use the pre-defined identifier constants in `RBFormAlertViewController` i.e. `formAlertSubmitButtonIdentifier` and `formAlertCancelButtonIdentifier` to easily add submit and cancel buttons that call the `submitForm` and `cancelFrom` methods on the managed form.
 *  @param titles       The buttons titles.
 */
- (void)setButtons:(nonnull NSArray<NSString *> *)identifiers withTitles:(nonnull NSArray<NSString *> *)titles;

@end
