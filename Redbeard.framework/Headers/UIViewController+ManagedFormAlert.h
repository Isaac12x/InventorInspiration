//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Redbeard/RBFormAlertViewController.h>
#import <Redbeard/RBManagedFormValidator.h>
#import <Redbeard/RBManagedFormAlertSchema.h>

/**
 *  A block that is called when a managed form alert is submitted or cancelled by the user.
 *
 *  @param results      The form values that were submitted, or `nil` if the form was cancelled.
 *  @param wasCancelled Whether or not the form was cancelled by the user.
 */
typedef void (^FormAlertCompletionBlock)(NSDictionary<NSString *, id> * __nullable results, BOOL wasCancelled);

/**
 *  A block that is called when a custom button is tapped on a managed form alert.
 *
 *  @param buttonIdentifier     The identifier of the button that was tapped.
 *  @param shouldDismissAlert   Whether or not the form alert should be dismissed as a result of the button tap.
 */
typedef void (^FormAlertButtonSelectionBlock)(NSString * __nonnull buttonIdentifier, BOOL * __nonnull shouldDismissAlert);

/**
 *  Managed form alert functionality for any `UIViewController`.
 */
@interface UIViewController (ManagedFormAlert) <RBFormAlertViewControllerDelegate>

/**
 *  The default animator to use when presenting the form alert.
 */
@property (nonatomic, nonnull) RBPresentationAnimator *defaultFormAlertAnimator;

/**
 *  The default vertical alignment to use when positioning the form alert.
 */
@property (nonatomic) RBVerticalAlignment defaultFormAlertAlignment;

/**
 *  The default margin to use when positioning the form alert.
 */
@property (nonatomic) UIEdgeInsets defaultFormAlertMargin;

/**
 *  Presents a managed `RBFormAlertViewController` alert with the given schema.
 *
 *  @param schema         The schema that describes the fields and functionality of the form to display.
 *  @param buttonSelected An optional block to be called when a custom button is tapped. Not not invoked for identifers `formAlertSubmitButtonIdentifier` and `formAlertCancelButtonIdentifier`.
 *  @param animated       Whether or not the presentation should be animated.
 *  @param completion     An optional block to be called when the form is dismissed or submitted successfully.
 */
- (void)formAlertWithSchema:(nonnull RBManagedFormAlertSchema *)schema
             buttonSelected:(nullable FormAlertButtonSelectionBlock)buttonSelected
                   animated:(BOOL)animated
                 completion:(nullable FormAlertCompletionBlock)completion;

/**
 *  Dismisses the top form alert that is open.
 *
 *  @param animated   Whether the dismissal should be animated.
 *  @param completion An optional block to be called when the form alert has been dismissed.
 *
 *  @return Whether or not there was an open form alert to close.
 */
- (BOOL)dismissFormAlertWithAnimation:(BOOL)animated
                           completion:(nullable dispatch_block_t)completion;

@end
