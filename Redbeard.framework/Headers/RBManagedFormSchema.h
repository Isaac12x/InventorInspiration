//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBManagedFormValidationRuleSchema.h>

#import <Redbeard/RBManagedFormItemSchema.h> // Base
#import <Redbeard/RBManagedFormLabelSchema.h>
#import <Redbeard/RBManagedFormSeparatorSchema.h>
#import <Redbeard/RBManagedFormSubmitButtonSchema.h>
#import <Redbeard/RBManagedFormCancelButtonSchema.h>
#import <Redbeard/RBManagedFormFieldSchema.h> // Base
#import <Redbeard/RBManagedFormCustomItemSchema.h>
#import <Redbeard/RBManagedFormSwitchFieldSchema.h>
#import <Redbeard/RBManagedFormTextViewFieldSchema.h>
#import <Redbeard/RBManagedFormTextFieldSchema.h>
#import <Redbeard/RBManagedFormDateTimeFieldSchema.h>
#import <Redbeard/RBManagedFormPhotoFieldSchema.h>
#import <Redbeard/RBManagedFormListFieldSchema.h>
#import <Redbeard/RBManagedFormMultipleChoiceFieldSchema.h>
#import <Redbeard/RBManagedFormImageSelectionFieldSchema.h>
#import <Redbeard/RBManagedFormNumericRangeFieldSchema.h>
#import <Redbeard/RBManagedFormRatingFieldSchema.h>
#import <Redbeard/RBManagedFormImageSchema.h>
#import <Redbeard/RBManagedFormButtonSchema.h>

#import <Redbeard/RBManagedFormValidator.h>

/**
 *  The action that will be performed when the return button is tapped on the keyboard.
 */
typedef NS_ENUM(NSInteger, RBManagedFormValidationViewType)
{
    /**
     *  No view presented. Simply scrolls field into view.
     */
    RBManagedFormValidationViewTypeNone = 0,
    
    /**
     *  Displays a tooltip with the validation message.
     */
    RBManagedFormValidationViewTypeTooltip,
    
    /**
     *  Displays a toast notification with the validation message.
     */
    RBManagedFormValidationViewTypeToast
};

/**
 *  The action that will be performed when the return button is tapped on the keyboard.
 */
typedef NS_ENUM(NSInteger, RBManagedFormKeyboardReturnAction)
{
    /**
     *  Closes the keyboard only.
     */
    RBManagedFormKeyboardReturnActionCloseKeyboard = 0,
    
    /**
     *  Submits the form.
     */
    RBManagedFormKeyboardReturnActionSubmitForm,
    
    /**
     *  Performs no action.
     */
    RBManagedFormKeyboardReturnActionNone
};

/**
 *  A managed form schema.
 */
@interface RBManagedFormSchema : NSObject

/**
 *  The identifier of the theme to apply to the form prior to presenting it. When the schema is applied to a form this
 *  property has the effect of setting the managed forms theme identifier i.e. 'managedForm.theme.identifier = themeIdentifier'.
 */
@property (nonatomic, nullable) NSString *themeIdentifier;

/**
 *  Theme values to apply after any other prior theming has been applied. When the schema is applied to a form this
 *  property has the effect of applying the theme overrides to the forms theme.
 */
@property (nonatomic, nullable) NSDictionary<NSString *, id> *themeOverrides;

/**
 *  The initial form values.
 */
@property (nonatomic, readonly, nonnull) NSDictionary *initialValues;

/**
 *  The `UIModalTransitionStyle` to use when displaying any modals such as the photo picker. Default = `UIModalTransitionStyleCoverVertical`.
 */
@property (nonatomic) UIModalTransitionStyle modalTransitionStyle;

/**
 *  Whether or not the toolbar should be used on input views. Default = `YES`.
 */
@property (nonatomic) BOOL toolbarEnabled;

/**
 *  The validation view to display when highlighting incomplete fields. Default = `RBManagedFormValidationViewTypeTooltip`.
 */
@property (nonatomic) RBManagedFormValidationViewType validationViewType;

/**
 *  The action to perform when the return key is tapped on the keyboard. Default = `RBManagedFormKeyboardReturnActionCloseKeyboard`.
 */
@property (nonatomic) RBManagedFormKeyboardReturnAction keyboardReturnAction;

/**
 *  Creates a new schema with the given array of items.
 *
 *  @param items The schema items to add to the schema.
 *
 *  @return The newly initialized form schema object.
 */
+ (nonnull instancetype)schemaWithItems:(nonnull NSArray<__kindof RBManagedFormItemSchema *> *)items;

/**
 *  Creates a new form validator from the schema.
 *
 *  @return A new `RBManagedFormValidator` object.
 */
- (nonnull RBManagedFormValidator *)newValidator;

#pragma mark -
#pragma mark Items

/**
 *  An array of form item schema objects.
 */
@property (nonatomic, nonnull) NSArray<__kindof RBManagedFormItemSchema *> *items;

/**
 *  An array of the views for the form. The views are obtained via the given schema items.
 */
@property (nonatomic, nonnull, readonly) NSArray<__kindof UIView *> *views;

/**
 *  Gets the item schema with the given name.
 *
 *  @param identifier   The name of the item.
 *
 *  @return The retrieved item schema object.
 */
- (nonnull RBManagedFormItemSchema *)itemWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Gets the form field schema with the given name.
 *
 *  @param identifier   The identifier of the field.
 *
 *  @return The retrieved form field schema object.
 */
- (nonnull RBManagedFormFieldSchema *)fieldWithIdentifier:(nonnull NSString *)identifier;

@end
