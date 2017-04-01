//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBCellViewButtonSchema.h>

/**
 *  The base class for a lazy layout view cell.
 */
@interface RBBaseCellView : UIView

/**
 *  The body view of the cell.
 */
@property (nonatomic, readonly, nonnull) UIView *bodyView;

/**
 *  Whether or not the cell is currently highlighted.
 */
@property (nonatomic, readonly) BOOL highlighted;

/**
 *  Whether or not the left button area is currently open.
 */
@property (nonatomic, readonly) BOOL leftButtonAreaIsOpen;

/**
 *  Whether or not the right button area is currently open.
 */
@property (nonatomic, readonly) BOOL rightButtonAreaIsOpen;

/**
 *  An array of `RBCellViewButtonSchema` objects describing the buttons on the left side of the cell.
 */
@property (nonatomic, nullable) NSArray<RBCellViewButtonSchema *> *leftButtons;

/**
 *  An array of `RBCellViewButtonSchema` objects describing the buttons on the right side of the cell.
 */
@property (nonatomic, nullable) NSArray<RBCellViewButtonSchema *> *rightButtons;

/**
 *  Whether or not the cell is currently enabled and will accept user interaction. Default = `YES`.
 */
@property (nonatomic, readonly) BOOL enabled;

/**
 *  Whether or not the cell is currently selected.  Default = `NO`.
 */
@property (nonatomic, readonly) BOOL selected;

/**
 *  Whether or not this is the 'alternate' cell.  Default = `NO`.
 */
@property (nonatomic) BOOL alternate;

/**
 *  The minimum size that the cell will return when asked using `sizeThatFits:`.  Default = `CGSizeZero`.
 */
@property (nonatomic) CGSize minimumSize;

/**
 *  The maximum size that the cell will return when asked using `sizeThatFits:`.  Default = `CGSizeZero`.
 */
@property (nonatomic) CGSize maximumSize;

#pragma mark -
#pragma mark Subclassing

/**
 *  @name Subclassing Hooks
 */

/**
 *  Called when initializing the cell.  Use this method to instantiate and add
 *  the subviews to the `bodyView` object.
 *
 *  @param bodyView The body view of the cell.
 */
- (void)populateBodyView:(nonnull __kindof UIView *)bodyView;

/**
 *  Called when laying out the subviews of the cell.  Use this method to set the
 *  frames of the subviews in the `bodyView`.
 *
 *  @param bodyView The body view of the cell.
 */
- (void)layoutBodyView:(nonnull __kindof UIView *)bodyView;

/**
 *  Called when applying a theme to the cell.  Use this method to apply the theme
 *  to the subviews of the `bodyView`.
 *
 *  @param theme    The body theme dictionary.
 *  @param bodyView The body view of the cell.
 */
- (void)applyTheme:(nonnull NSDictionary<NSString *, id> *)theme toBodyView:(nonnull __kindof UIView *)bodyView;

/**
 *  Called to determine the desired size of the body view.
 *
 *  @param size The available size in the container for the cell body.
 *
 *  @return The desired cell body size.
 */
- (CGSize)bodyViewSizeThatFitsSize:(CGSize)size;

@end
