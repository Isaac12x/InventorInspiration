//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBToolbarSchema.h>

@protocol RBToolbarViewDelegate;

/**
 *  Provides a toolbar of buttons.
 */
@interface RBToolbarView : UIView

/**
 *  A delegate to receive button selection events.
 */
@property (nonatomic, weak, nullable) id<RBToolbarViewDelegate> delegate;

/**
 *  Whether or not the toolbar should fill it's available space.
 *  Space refers to width in the horizontal orientation and height in the vertical orientation.
 */
@property (nonatomic) BOOL shouldFillAvailableSpace;

/**
 *  Gets or sets the schema that describes the toolbar.
 */
@property (nonatomic, nonnull) RBToolbarSchema *schema;

#pragma mark -
#pragma mark Toggle Button Selection

/**
 *  The set of toggle button names that are currently selected.
 */
@property (nonatomic, readonly, nullable) NSSet *selectedToggleButtonIdentifiers;

/**
 *  Updates the selection state of a toggle button.
 *
 *  @param selected                 Whether or not the button should be set to selected (YES) or unselected (NO).
 *  @param toggleButtonIdentifier   The name of the toggle button to update.
 */
- (void)setSelected:(BOOL)selected withToggleButtonIdentifier:(nonnull NSString *)toggleButtonIdentifier;

@end

/**
 *  A delegate to receive button selection events for a `RBToolbarView` object.
 */
@protocol RBToolbarViewDelegate <NSObject>

@optional

/**
 *  Called when a toolbar button was tapped.
 *
 *  @param toolbarView          The `RBToolbarView` object.
 *  @param buttonIdentifier     The identifier of the button.
 */
- (void)toolbarView:(nonnull RBToolbarView *)toolbarView buttonWasTappedWithIdentifier:(nonnull NSString *)buttonIdentifier;

/**
 *  Called when a toolbar toggle button was tapped.
 *
 *  @param toolbarView              The `RBToolbarView` object.
 *  @param toggleButtonIdentifier   The identifier of the toggle button.
 *  @param selected                 Whether or not the toggle button was selected (YES) or unselected (NO).
 */
- (void)toolbarView:(nonnull RBToolbarView *)toolbarView toggleButtonWithIdentifier:(nonnull NSString *)toggleButtonIdentifier selectionDidChangeTo:(BOOL)selected;

@end
