//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for Redbeard.
FOUNDATION_EXPORT double RedbeardVersionNumber;

//! Project version string for Redbeard.
FOUNDATION_EXPORT const unsigned char RedbeardVersionString[];

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#import <Redbeard/RBDefinitions.h>

#import <Redbeard/RBCore.h>
#import <Redbeard/RedbeardCenter.h>
#import <Redbeard/RBAppDelegate.h>

#pragma mark -
#pragma mark Theming

#import <Redbeard/RBTheming.h>

#pragma mark -
#pragma mark Sidebar Container

#import <Redbeard/RBSidebarContainerView.h>
#import <Redbeard/RBSidebarContainerViewController.h>

#pragma mark -
#pragma mark Navigation Controller

#import <Redbeard/RBNavigationController.h>
#import <Redbeard/RBNavigationControllerView.h>

#pragma mark -
#pragma mark Navigation Controller: Animators

#import <Redbeard/RBNavigationAnimator.h> // Abstract base class
#import <Redbeard/RBNavigationDefaultAnimator.h>
#import <Redbeard/RBNavigationFadeAnimator.h>
#import <Redbeard/RBNavigationSwapAnimator.h>
#import <Redbeard/RBNavigationSlideAnimator.h>
#import <Redbeard/RBNavigationSheetAnimator.h>
#import <Redbeard/RBNavigationCardSwapAnimator.h>

#pragma mark -
#pragma mark Page

#import <Redbeard/RBPageViewController.h>

#pragma mark -
#pragma mark Page: Header

#import <Redbeard/RBPageHeaderItem.h>
#import <Redbeard/RBPageHeaderViewController.h>

#pragma mark -
#pragma mark Toolbar Container

#import <Redbeard/RBToolbarContainerView.h>

#pragma mark -
#pragma mark Toolbar

#import <Redbeard/RBToolbarView.h>

#pragma mark -
#pragma mark Toolbar Schema

#import <Redbeard/RBToolbarSchema.h>
#import <Redbeard/RBToolbarButtonItemSchema.h>
#import <Redbeard/RBToolbarCustomItemSchema.h>
#import <Redbeard/RBToolbarSpacingItemSchema.h>
#import <Redbeard/RBToolbarToggleButtonItemSchema.h>

#import <Redbeard/RBToolbarSchema+FlexiSchema.h>

#pragma mark -
#pragma mark Search Container

#import <Redbeard/RBSearchContainerView.h>
#import <Redbeard/RBSearchContainerViewController.h>

#pragma mark -
#pragma mark Search Container: Bar

#import <Redbeard/RBSearchBarView.h>

#pragma mark -
#pragma mark Search Container: As Sidebar

#import <Redbeard/RBSearchContainerSideViewController.h>

#pragma mark -
#pragma mark Sliding Page Container

#import <Redbeard/RBSlidingPageContainerView.h>
#import <Redbeard/RBSlidingPageContainerHeaderView.h>
#import <Redbeard/RBSlidingPageContainerViewController.h>

#pragma mark -
#pragma mark Tabbed Page Container

#import <Redbeard/RBTabbedPageContainerViewController.h>

#pragma mark -
#pragma mark View Container

#import <Redbeard/RBContainerView.h>
#import <Redbeard/RBCollapsibleContainerView.h>
#import <Redbeard/RBCollapsibleContainerHandleView.h>
#import <Redbeard/RBCollapsibleContainerSimpleHandleView.h>

#import <Redbeard/RBSwitchContainerView.h>
#import <Redbeard/RBSwitchContainerViewController.h>

#pragma mark -
#pragma mark Pane Container

#import <Redbeard/RBPaneView.h>
#import <Redbeard/RBPaneViewController.h>
#import <Redbeard/RBPaneContainerViewController.h>

#pragma mark -
#pragma mark Layout Views

#import <Redbeard/RBBaseLayoutView.h> // Abstract base class
#import <Redbeard/RBLayoutView.h>
#import <Redbeard/RBLazyLayoutView.h>

#pragma mark -
#pragma mark Layout Views: Animators

#import <Redbeard/RBLayoutAnimator.h> // Abstract base class
#import <Redbeard/RBLayoutCardAnimator.h>
#import <Redbeard/RBLayoutFadeAnimator.h>
#import <Redbeard/RBLayoutScaleAnimator.h>

#pragma mark -
#pragma mark Layout Views: Positioners

#import <Redbeard/RBLayoutPositioner.h> // Abstract base class

#import <Redbeard/RBLayoutSchemaPositioner.h> // Abstract base class for schema based positioners
#import <Redbeard/RBLayoutSchemaPositionerSchema.h> // Abstract base class for schemas

#import <Redbeard/RBLayoutFlowPositioner.h>
#import <Redbeard/RBLayoutGridPositioner.h>
#import <Redbeard/RBLayoutStackPositioner.h>
#import <Redbeard/RBLayoutCenterPositioner.h>
#import <Redbeard/RBLayoutColumnPercentagePositioner.h>

#import <Redbeard/RBLayoutFlexiPositioner.h>
#import <Redbeard/RBLayoutFlexiPositionerSchema.h>
#import <Redbeard/RBLayoutFlexiPositionerSchema+StringSerialisation.h>

#import <Redbeard/RBLayoutRelativePositioner.h>
#import <Redbeard/RBLayoutRelativePositionerSchema.h>
#import <Redbeard/RBLayoutRelativePositionerCellSchema.h>

#pragma mark -
#pragma mark Scroll Extend Views

#import <Redbeard/RBBaseExtendView.h> // Abstract base class
#import <Redbeard/RBRefreshExtendView.h>
#import <Redbeard/RBNextPageExtendView.h>
#import <Redbeard/RBBannerExtendView.h>

#pragma mark -
#pragma mark Cell Views

#import <Redbeard/RBBaseCellView.h> // Abstract base class
#import <Redbeard/RBImageCellView.h>
#import <Redbeard/RBSimpleCellView.h>
#import <Redbeard/RBButtonCellView.h>

#import <Redbeard/RBCellViewButtonSchema.h>

#pragma mark -
#pragma mark Menu

#import <Redbeard/RBMenuView.h>
#import <Redbeard/RBMenuSegmentHeaderView.h>
#import <Redbeard/RBMenuSegmentView.h>

#pragma mark -
#pragma mark Menu: Schema

#import <Redbeard/RBMenuSegmentSchema.h>
#import <Redbeard/RBMenuSegmentButtonSchema.h>

#pragma mark -
#pragma mark Forms: Form Fields

#import <Redbeard/RBDateTimeField.h>
#import <Redbeard/RBPhotoField.h>
#import <Redbeard/RBListField.h>
#import <Redbeard/RBMultipleChoiceField.h>
#import <Redbeard/RBPickerView.h>
#import <Redbeard/RBSliderField.h>
#import <Redbeard/RBSwitchField.h>
#import <Redbeard/RBTextField.h>
#import <Redbeard/RBTextViewField.h>
#import <Redbeard/RBRatingField.h>

#pragma mark -
#pragma mark Forms: Managed Form

#import <Redbeard/RBManagedFormView.h>
#import <Redbeard/RBManagedFormInputToolbar.h>
#import <Redbeard/RBManagedFormSeparatorView.h>

#pragma mark -
#pragma mark Forms: Managed Form Validators

#import <Redbeard/RBManagedFormValidator.h>
#import <Redbeard/RBManagedFormValidationRule.h>

#pragma mark -
#pragma mark Forms: Managed Form Input Views

#import <Redbeard/RBInputView.h> // Abstract base class
#import <Redbeard/RBDateTimeInputView.h>
#import <Redbeard/RBListInputView.h>

#pragma mark -
#pragma mark Alert View Controllers

// Note: don't use directly, call managed from UIViewController

#import <Redbeard/RBAlertViewController.h>
#import <Redbeard/RBFormAlertViewController.h>

#pragma mark -
#pragma mark General Controls

#import <Redbeard/RBScrollView.h>
#import <Redbeard/RBLabel.h>
#import <Redbeard/RBActivityView.h>
#import <Redbeard/RBButton.h>
#import <Redbeard/RBImageView.h>
#import <Redbeard/RBImageScrollView.h>
#import <Redbeard/RBToastAlertView.h>
#import <Redbeard/RBTooltipContainerView.h>
#import <Redbeard/RBTooltipView.h>
#import <Redbeard/RBPageControl.h>
#import <Redbeard/RBScrambledPinInput.h>
#import <Redbeard/RBToggleButton.h>
#import <Redbeard/RBWebViewToolbarView.h>
#import <Redbeard/RBWebView.h>
#import <Redbeard/RBCircleView.h>
#import <Redbeard/RBLineView.h>
#import <Redbeard/RBCircularProgressView.h>
#import <Redbeard/RBImageSelectionField.h>

#pragma mark -
#pragma mark SQLite

#import <Redbeard/RBSQLiteCenter.h>
#import <Redbeard/RBSQLiteConnection.h>
#import <Redbeard/RBSQLiteFieldSchema.h>
#import <Redbeard/RBSQLiteResult.h>
#import <Redbeard/RBSQLiteResultSet.h>
#import <Redbeard/RBSQLiteTableSchema.h>
#import <Redbeard/RBSQLiteVFS.h>
#import <Redbeard/RBSQLiteVFSFile.h>
#import <Redbeard/RBSQLiteWordList.h>

#pragma mark -
#pragma mark ORM

#import <Redbeard/RBORMCenter.h>
#import <Redbeard/RBORMObject.h>
#import <Redbeard/RBORMQuery.h>

#pragma mark -
#pragma mark Introspective

#import <Redbeard/RBIntrospectiveObject.h>
#import <Redbeard/RBIntrospectiveObjectPropertySchema.h>

#pragma mark -
#pragma mark JSON Objects

#import <Redbeard/RBManagedJsonObject.h>

#pragma mark -
#pragma mark Sharing

#import <Redbeard/RBSharingService.h>
#import <Redbeard/RBEmailSharingService.h>
#import <Redbeard/RBFacebookSharingService.h>
#import <Redbeard/RBTwitterSharingService.h>