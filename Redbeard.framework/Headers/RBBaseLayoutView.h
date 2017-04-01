//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBScrollView.h>
#import <Redbeard/RBFragmentedArray.h>
#import <Redbeard/RBLayoutPositioner.h>
#import <Redbeard/RBLayoutSchemaPositioner.h>

/**
 *  The position to scroll to.
 */
typedef NS_ENUM(NSInteger, RBBaseLayoutViewScrollPosition)
{
    /**
     *  Scroll to position the cell at the start. Which is the top if orientation is vertical or the left if horizontal.
     */
    RBBaseLayoutViewScrollPositionStart = 0,
    
    /**
     *  Scroll to position the cell in the middle depending on orientation.
     */
    RBBaseLayoutViewScrollPositionMiddle,
    
    /**
     *  Scroll to position the cell at the end. Which is the bottom if orientation is vertical or the right if horizontal.
     */
    RBBaseLayoutViewScrollPositionEnd
};

@class RBLayoutAnimator;

// Note: This class is abstract - use it's subclasses!

@protocol RBBaseLayoutViewDelegate;

/**
 *  The abstract base class for layout views.
 */
@interface RBBaseLayoutView : RBScrollView<RBLayoutPositionerDelegate>
{
    NSMutableArray *cells; // Visible Views (UIView)
    RBFragmentedArray *visibleCells;
    
    BOOL userScrollEnabled;
}

/**
 *  Whether or not a schema based is supported by this layout.
 */
@property (nonatomic, readonly) BOOL supportsSchemaBasedPositioners;

/**
 *  The positioner that determines how the cells are positioned and sized.
 */
@property (nonatomic, nonnull) RBLayoutPositioner *positioner;

/**
 *  The animator to animate cells as they appear and disappear.
 */
@property (nonatomic, nullable) RBLayoutAnimator *animator;

/**
 *  Whether or not animation should occur during scrolling only.
 */
@property (nonatomic) BOOL animateScrollOnly;

/**
 *  The delegate to be informed of appearance and positioning events.
 */
@property (nonatomic, weak, nullable) id<RBBaseLayoutViewDelegate, RBScrollViewDelegate> delegate;

/**
 *  An array of the cells that are currently visible.
 */
@property (nonatomic, readonly, nonnull) RBFragmentedArray *visibleCells;

/**
 *  The frame of the cell at the given index.
 *
 *  @param index The index of the cell.
 *
 *  @return The frame of the cell or `CGRectNull` if a cell with the requested index does not exist.
 */
- (CGRect)cellFrameAtIndex:(NSInteger)index;

/**
 *  Scroll to the given cell index.
 *
 *  @param index        The index of the cell.
 *  @param position     The position of the cell.
 *  @param orientation  The orientation of the scrolling movement.
 *  @param offset       An additional offset to apply to the scroll position.
 *  @param animated     Animate the scrolling.
 *
 *  @return The index of the cell or `NSNotFound` if the cell is not visible or otherwise unavailable.
 */
- (void)scrollToCellAtIndex:(NSInteger)index position:(RBBaseLayoutViewScrollPosition)position orientation:(RBOrientation)orientation offset:(CGFloat)offset animated:(BOOL)animated;

#pragma mark -
#pragma mark Subclassing

/**
 *  Whether or not an appearing or disappearing cell should animate.
 */
@property (nonatomic, readonly) BOOL shouldAnimate;

/**
 *  Whether or not scrolling should be disabled.  Override this to disable scrolling while you
 *  perform an update.
 */
@property (nonatomic, readonly) BOOL shouldDisableScrolling;

/**
 *  Notify the layout view to update whether scrolling is enabled or disabled
 *  based on the value of `shouldDisableScrolling`.
 */
- (void)setScrollEnabledNeedsUpdate;

/**
 *  Called when a cell will be positioned with a new frame.
 *
 *  @param view  The view of the cell.
 *  @param index The index of the cell in the layout view.
 *  @param frame The new frame being applied to the cell.
 */
- (void)cellWillPosition:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell was positioned with a new frame.
 *
 *  @param view  The view of the cell.
 *  @param index The index of the cell in the layout view.
 *  @param frame The new frame being applied to the cell.
 */
- (void)cellDidPosition:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell will appear.
 *
 *  @param view  The view of the cell.
 *  @param index The index of the cell in the layout view.
 *  @param frame The frame that the cell is appearing with.
 */
- (void)cellWillAppear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell did appear.
 *
 *  @param view  The view of the cell.
 *  @param index The index of the cell in the layout view.
 *  @param frame The frame that the cell is appearing with.
 */
- (void)cellDidAppear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell will disappear.
 *
 *  @param view  The view of the cell.
 *  @param index The index of the cell in the layout view.
 */
- (void)cellWillDisappear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index;

/**
 *  Called when a cell did disappear.
 *
 *  @param view  The view of the cell.
 *  @param index The index of the cell in the layout view.
 */
- (void)cellDidDisappear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index;

@end

/**
 *  A delegate to be informed of cell positioning and appearance events.
 */
@protocol RBBaseLayoutViewDelegate <NSObject, RBScrollViewDelegate>

@optional

/**
 *  Called when a cell will be positioned with a new frame.
 *
 *  @param layoutView The layout view object.
 *  @param view       The view of the cell.
 *  @param index      The index of the cell in the layout view.
 *  @param frame      The new frame being applied to the cell.
 */
- (void)layoutView:(nonnull RBBaseLayoutView *)layoutView cellWillPosition:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell was positioned with a new frame.
 *
 *  @param layoutView The layout view object.
 *  @param view       The view of the cell.
 *  @param index      The index of the cell in the layout view.
 *  @param frame      The new frame being applied to the cell.
 */
- (void)layoutView:(nonnull RBBaseLayoutView *)layoutView cellDidPosition:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell will appear.
 *
 *  @param layoutView The layout view object.
 *  @param view       The view of the cell.
 *  @param index      The index of the cell in the layout view.
 *  @param frame      The frame that the cell is appearing with.
 */
- (void)layoutView:(nonnull RBBaseLayoutView *)layoutView cellWillAppear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell did appear.
 *
 *  @param layoutView The layout view object.
 *  @param view       The view of the cell.
 *  @param index      The index of the cell in the layout view.
 *  @param frame      The frame that the cell is appearing with.
 */
- (void)layoutView:(nonnull RBBaseLayoutView *)layoutView cellDidAppear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index withFrame:(CGRect)frame;

/**
 *  Called when a cell will disappear.
 *
 *  @param layoutView The layout view object.
 *  @param view       The view of the cell.
 *  @param index      The index of the cell in the layout view.
 */
- (void)layoutView:(nonnull RBBaseLayoutView *)layoutView cellWillDisappear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index;

/**
 *  Called when a cell did disappear.
 *
 *  @param layoutView The layout view object.
 *  @param view       The view of the cell.
 *  @param index      The index of the cell in the layout view.
 */
- (void)layoutView:(nonnull RBBaseLayoutView *)layoutView cellDidDisappear:(nonnull __kindof UIView *)view withIndex:(NSInteger)index;

@end
