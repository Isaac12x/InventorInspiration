//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBBaseCellView.h>
#import <Redbeard/RBBaseLayoutView.h>

@protocol RBLazyLayoutViewDataSource;
@protocol RBLazyLayoutViewDelegate;

/**
 *  The lazy loading layout view.
 */
@interface RBLazyLayoutView : RBBaseLayoutView<UIGestureRecognizerDelegate>

/**
 *  A delegate that receives cell loading, appearance and positioning events.
 */
@property (nonatomic, weak, nullable) id<RBLazyLayoutViewDelegate, RBBaseLayoutViewDelegate> delegate;

/**
 *  The data source that provides cells to the layout view.
 */
@property (nonatomic, weak, nullable) id<RBLazyLayoutViewDataSource> dataSource;

/**
 *  Whether or not the cell allows selection. Default = `YES`.
 */
@property (nonatomic) BOOL allowsSelection;

/**
 *  Whether or not the cell allows selection. Default = `NO`.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 *  Whether or not the last selected item can be unselected. Default = `YES`.
 */
@property (nonatomic) BOOL zeroSelectionAllowed;

/**
 *  The count of the currently selected cells.
 */
@property (nonatomic, readonly) NSInteger selectedCellCount;

/**
 *  The indexes of the currently selected cells.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *selectedCellIndexes;

/**
 *  Indicates whether or not laying out cells, reloadData, reloadCellAt and changes to viewports 
 *  will update the view.
 */
@property (nonatomic, readonly) BOOL updatesPaused;

/**
 *  The animator that is used when sliding the body view to reveal the button area. Default = `[RBAnimator defaultSpringAnimator]`.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *buttonAreaAnimator;

/**
 *  The animator that is used when transitioning between states (none, highlighted, selected, disabled).
 *  Default = `[RBAnimator defaultSpringAnimator]` (with duration 0.1).
 */
@property (nonatomic, readonly, nonnull) RBAnimator *transitionAnimator;

/**
 *  Reloads the cells from the data source.
 */
- (void)reloadData;

/**
 *  Reloads the cells from the data source at the given index. Note only does so if the cell is currently visible.
 *
 *  @param index    The index of the cell.
 */
- (void)reloadCellAt:(NSInteger)index;

/**
 *  Gets an instantiated or reused cell of the given type. The layout view is capable of managing
 *  multiple types. The returned cell will have theming applied on creation.
 *
 *  @param cellType                The type of the cell to reuse or instantiate.
 *  @param configurationOnCreation An optional block to be called only on instantiation (not on reuse).
 *
 *  @return The cell object for configuration.
 */
- (nonnull __kindof RBBaseCellView *)reusableCellWithType:(nonnull Class)cellType configurationOnCreation:(nullable void(^)(__kindof RBBaseCellView *__nonnull cell))configurationOnCreation;

/**
 *  Gets an instantiated or reused cell of the given type. The layout view is capable of managing
 *  multiple types.
 *
 *  @param cellType                The type of the cell to reuse or instantiate.
 *  @param applyTheming            Whether or not to apply theming to the cell immediately on creation.
 *  @param configurationOnCreation An optional block to be called only on instantiation (not on reuse).
 *
 *  @return The cell object for configuration.
 */
- (nonnull __kindof RBBaseCellView *)reusableCellWithType:(nonnull Class)cellType shouldApplyTheming:(BOOL)applyTheming configurationOnCreation:(nullable void(^)(__kindof RBBaseCellView *__nonnull cell))configurationOnCreation;

/**
 *  The cell view at the given index if it is visible.
 *
 *  @param index The index of the cell.
 *
 *  @return The cell view or `nil` if a cell with the requested index is out of range or is not visible.
 */
- (nullable RBBaseCellView *)cellAtIndex:(NSInteger)index;

/**
 *  The index of the given cell view. For cells that are not 'on screen' this will return `nil`.
 *
 *  @param index The index of the cell.
 *
 *  @return The index of the cell or `NSNotFound` if the cell is not visible or otherwise unavailable.
 */
- (NSInteger)indexForCell:(nonnull RBBaseCellView *)cell;

/**
 *  Indicates if the cell at the given index is currently selected.
 *
 *  @param index    The index of the cell.
 *
 *  @return Whether or not the cell is selected.
 */
- (BOOL)isCellSelectedAt:(NSInteger)index;

/**
 *  Indicates if the cell at the given index is currently highlighted.
 *  Note this returns ONLY for cells highlighted using `setCellHighlightedAt:` method.
 *
 *  @param index    The index of the cell.
 *
 *  @return Whether or not the cell is highlighted.
 */
- (BOOL)isCellHighlightedAt:(NSInteger)index;

/**
 *  Indicates if the cell at the given index is currently enabled.
 *
 *  @param index    The index of the cell.
 *
 *  @return Whether or not the cell is enabled.
 */
- (BOOL)isCellEnabledAt:(NSInteger)index;

/**
 *  Sets the enabled state of the cell at the given index.
 *  Ignores the `allowsSelection`, `allowsMultipleSelection`, `zeroSelectionAllowed` values.
 *  Events `willEnable`, `didEnable` etc are NOT raised when using this method.
 *
 *  @param enabled      The enabled state to set.
 *  @param index        The index of the cell.
 *  @param animated     Animate the state change.
 *
 *  @return Whether or not the state requested has been set.
 */
- (BOOL)setCellEnabled:(BOOL)enabled at:(NSInteger)index animated:(BOOL)animated;

/**
 *  Sets the selected state of the cell at the given index.
 *  Ignores the `allowsSelection`, `allowsMultipleSelection`, `zeroSelectionAllowed` values.
 *  Events `willSelect`, `didSelect` etc are NOT raised when using this method.
 *
 *  @param selected     The selected state to set.
 *  @param index        The index of the cell.
 *  @param animated     Animate the state change.
 *
 *  @return Whether or not the state requested has been set.
 */
- (BOOL)setCellSelected:(BOOL)selected at:(NSInteger)index animated:(BOOL)animated;

/**
 *  Sets the highlighted state of the cell at the given index. 
 *  Ignores the `allowsSelection`, `allowsMultipleSelection`, `zeroSelectionAllowed` values.
 *  Events `shouldHighlight`, `didHighlight` etc are NOT raised when using this method.
 *
 *  @param highlighted  The highlighted state to set.
 *  @param index        The index of the cell.
 *  @param animated     Animate the state change.
 *
 *  @return Whether or not the state requested has been set.
 */
- (BOOL)setCellHighlighted:(BOOL)highlighted at:(NSInteger)index animated:(BOOL)animated;

/**
 *  Clears all the currently highlighted cells.
 *  Note this applies ONLY for cells highlighted using `setCellHighlightedAt:` method.
 *
 *  @param animated     Animate the state change.
 */
- (void)clearAllHighlightedCells:(BOOL)animated;

/**
 *  Clears all the currently selected cells.
 *
 *  @param animated     Animate the state change.
 */
- (void)clearAllSelectedCells:(BOOL)animated;

/**
 *  Clears all the currently disabled cells.
 *
 *  @param animated     Animate the state change.
 */
- (void)clearAllDisabledCells:(BOOL)animated;

/**
 *  Slide the body view to reveal the left button area to the user.
 *
 *  @param index        The index of the cell on which to open the button area.
 *  @param animated     Whether or not the transition should be animated.
 */
- (void)openLeftButtonAreaAt:(NSInteger)index withAnimation:(BOOL)animated;

/**
 *  Slide the body view to reveal the right button area to the user.
 *
 *  @param index        The index of the cell on which to open the button area.
 *  @param animated     Whether or not the transition should be animated.
 */
- (void)openRightButtonAreaAt:(NSInteger)index withAnimation:(BOOL)animated;

/**
 *  Close the exposed button area cell.
 *
 *  @param animated   Whether or not the transition should be animated.
 */
- (void)closeButtonAreaWithAnimation:(BOOL)animated;

/**
 *  Pauses updates to the lazylayout view. This means no reloading fo cells, even on scrolling.
 */
- (void)pauseUpdates;

/**
 *  Resumes updates to the lazylayout view. Will call `reloadData` if `reloadData` was called whilst paused.
 */
- (void)resumeUpdates;

#pragma mark -
#pragma mark Subclassing

/**
 *  Called when the cell at the given index will be loaded.
 *
 *  @param cell  The cell that will be loaded.
 *  @param index The index of the cell in the layout.
 */
- (void)cellWillLoad:(nonnull __kindof RBBaseCellView *)cell atIndex:(NSInteger)index;

/**
 *  Called when the cell at the given index was loaded.
 *
 *  @param cell  The cell that was loaded.
 *  @param index The index of the cell in the layout.
 */
- (void)cellDidLoad:(nonnull __kindof RBBaseCellView *)cell atIndex:(NSInteger)index;

/**
 *  Called when the cell at the given index will be unloaded.
 *
 *  @param cell  The cell that will be unloaded.
 *  @param index The index of the cell in the layout.
 */
- (void)cellWillUnload:(nonnull __kindof RBBaseCellView *)cell atIndex:(NSInteger)index;

/**
 *  Called when the cell at the given index was unloaded.
 *
 *  @param cell  The cell that was unloaded.
 *  @param index The index of the cell in the layout.
 */
- (void)cellDidUnload:(nonnull __kindof RBBaseCellView *)cell atIndex:(NSInteger)index;

/**
 *  Called when the layout view will reload it's cells from the data source.
 */
- (void)willReloadData;

/**
 *  Called when the layout view has reloaded it's cells from the data source.
 */
- (void)didReloadData;

@end

/**
 *  The data source that provides cells to a `RBLazyLayoutView`.
 */
@protocol RBLazyLayoutViewDataSource <NSObject>

@required

/**
 *  Gets the number of cells to be displayed in the layout view.
 *
 *  @param layoutView The layout view object.
 *
 *  @return The number of cells.
 */
- (NSInteger)countForLayoutView:(nonnull RBLazyLayoutView *)layoutView;

/**
 *  Gets the desired size of the cell at the given index, with the
 *  available container size provided.
 *
 *  @param index      The index of the cell to size.
 *  @param container  The available size for the cell in it's container.
 *  @param layoutView The layout view object.
 *
 *  @return The desired size of the cell.
 */
- (CGSize)cellSizeAtIndex:(NSInteger)index withContainer:(CGSize)container forLayoutView:(nonnull RBLazyLayoutView *)layoutView;

/**
 *  Gets the cell to be presented in the layout view at the given index.
 *  The `reusableCellWithType:configurationOnCreation:` or `reusableCellWithType:shouldApplyTheming:configurationOnCreation` methods should be used.
 *  The first is a convienance method that passes `YES` as the the shouldApplyTheming parameter to the second.
 *
 *  @param index      The index of the cell.
 *  @param layoutView The layout view object.
 *
 *  @return The prepared cell.
 */
- (nonnull __kindof RBBaseCellView *)cellAtIndex:(NSInteger)index forLayoutView:(nonnull RBLazyLayoutView *)layoutView;

@optional

/**
 *  Called when a cell will be removed from the layout view and stored
 *  for reuse at a later stage. Use this to stop any image download jobs, etc.
 *
 *  @param layoutView The layout view object.
 *  @param cell       The cell that is being removed.
 *  @param index      The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView willRemoveCell:(nonnull __kindof RBBaseCellView *)cell atIndex:(NSInteger)index;

@end

/**
 *  A delegate that receives cell loading, appearance and positioning events.
 */
@protocol RBLazyLayoutViewDelegate <NSObject, RBBaseLayoutViewDelegate>

@optional

/**
 *  Called when the layout view will reload it's cells from the data source.
 *
 *  @param layoutView       The layout view.
 */
- (void)layoutViewWillReloadData:(nonnull RBLazyLayoutView *)layoutView;

/**
 *  Called when the layout view has reloaded it's cells from the data source.
 *
 *  @param layoutView       The layout view.
 */
- (void)layoutViewDidReloadData:(nonnull RBLazyLayoutView *)layoutView;

//////

// TOUCH

/**
 *  Called to determine if a touch event that will affect the button area or affect the cell state should be allowed.
 *
 *  @param layoutView       The layout view object.
 *  @param touch            The touch data.
 *
 *  @return Whether or not the touch should be allowed.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView shouldReceiveTouch:(nonnull UITouch *)touch;

// Select

/**
 *  Called when a cell will be selected and used to determine if the state change should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 *
 *  @return Whether or not to allow the state change.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView willSelectCellAt:(NSInteger)index;

/**
 *  Called when a cell has been selected.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didSelectCellAt:(NSInteger)index;

/**
 *  Called when a cell will be deselected and used to determine if the state change should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 *
 *  @return Whether or not to allow the state change.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView willDeselectCellAt:(NSInteger)index;

/**
 *  Called when a cell has been deselected.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didDeselectCellAt:(NSInteger)index;

// Enable

/**
 *  Called when a cell will be enabled and used to determine if the state change should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 *
 *  @return Whether or not to allow the state change.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView willEnableCellAt:(NSInteger)index;

/**
 *  Called when a cell has been enabled.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didEnableCellAt:(NSInteger)index;

/**
 *  Called when a cell will be disabled and used to determine if the state change should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 *
 *  @return Whether or not to allow the state change.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView willDisableCellAt:(NSInteger)index;

/**
 *  Called when a cell has been disabled.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didDisableCellAt:(NSInteger)index;

// Highlight

/**
 *  Called when a cell will be highlighted and used to determine if the state change should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 *
 *  @return Whether or not to allow the state change.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView shouldHighlightCellAt:(NSInteger)index;

/**
 *  Called when a cell has been highlighted.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didHighlightCellAt:(NSInteger)index;

/**
 *  Called when a cell has been unhighlighted.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didUnhighlightCellAt:(NSInteger)index;

// Button area open / close

/**
 *  Called when a cells button area will open and used to determine if this should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 *
 *  @return Whether or not to allow the button area to open.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView canOpenButtonAreaAt:(NSInteger)index;

/**
 *  Called when a cells button area has been open.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didOpenButtonAreaAt:(NSInteger)index;

/**
 *  Called when a cells button area has been closed.
 *
 *  @param layoutView       The layout view.
 *  @param index            The index of the cell.
 */
- (void)layoutView:(nonnull RBLazyLayoutView *)layoutView didCloseButtonAreaAt:(NSInteger)index;

// Button area select

/**
 *  Called when a cells button area will open and used to determine if this should be allowed.
 *
 *  @param layoutView       The layout view.
 *  @param identifier       The identifier of the selected button.
 *  @param left             Which button area was opened the left (`YES`) or the right (`NO`).
 *  @param index            The index of the cell.
 *
 *  @return Whether or not close the button area.
 */
- (BOOL)layoutView:(nonnull RBLazyLayoutView *)layoutView didSelectButtonAreaButtonWithIdentifier:(nonnull NSString *)identifier leftArea:(BOOL)left at:(NSInteger)index;

@end
