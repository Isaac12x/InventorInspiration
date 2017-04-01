//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBThemeTracker.h>
#import <Redbeard/RBLayoutPositionerResult.h>

// Note: This class is abstract, use its subclasses.

@protocol RBLayoutPositionerDelegate;
@protocol RBLayoutPositionerSchemaDelegate;

/**
 *  The base layout view positioner class.
 */
@interface RBLayoutPositioner : NSObject<RBThemeTrackerDelegate>

/**
 *  The theming tracker object for the view.
 */
@property (nonatomic, readonly, nonnull) RBThemeTracker *theme;

/**
 *  The delegate of the positioner, to receive the position invalidation event (causing a relayout).
 */
@property (nonatomic, weak, nullable) id<RBLayoutPositionerDelegate> delegate;

/**
 *  The content size required when there are no cells in the layout view.
 */
@property (nonatomic, readonly) CGSize emptyContentSize;

/**
 *  The available viewport size for the positioning the cells.
 */
@property (nonatomic) CGSize viewportSize;

/**
 *  The content insets that are applied to the viewport.
 */
@property (nonatomic) UIEdgeInsets contentInsets;

/**
 *  Whether or not the current result is invalid and the positioner needs to perform a layout.
 */
@property (nonatomic, readonly) BOOL needsLayout;

/**
 *  The result of the last positioning operation.
 */
@property (nonatomic, readonly, nullable) RBLayoutPositionerResult *result;

/**
 *  Invalidates the current result, prompting a relayout.
 */
- (void)invalidate;

/**
 *  Performs a layout operation, producing new frames for each cell.
 *
 *  @param sizeBlock A block that can be called to get the recommended size of a cell given an available container size.
 *  @param viewCount The number of cells to position.
 */
- (void)layoutWithSizeBlock:(nonnull CGSize(^)(NSUInteger index, CGSize container))sizeBlock
                  viewCount:(NSUInteger)viewCount;

// Prospectively calculate the content size - does not persist results.

/**
 *  Prospectively performs a layout operation to determine what content size would be
 *  required to display those cells.
 *
 *  @param viewportSize The available viewport size.
 *  @param sizeBlock    A block that can be called to get the recommended size of a cell given an available container size.
 *  @param viewCount    The number of cells to position.
 *
 *  @return The resulting content size.
 */
- (CGSize)contentSizeWithViewportSize:(CGSize)viewportSize
                            sizeBlock:(nonnull CGSize(^)(NSUInteger index, CGSize container))sizeBlock
                            viewCount:(NSUInteger)viewCount;

#pragma mark -
#pragma mark Theming

/**
 *  The spacing between cells in the positioner. 
 *  A positioner should attempt to respect this as much as is possible.
 *  Depending on the positioner it may be ignored e.g. RBLayoutFlexiPositioner.
 */
@property (nonatomic) CGFloat spacing;

/**
 *  The margin that should be provided around the collective cell bounds.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The minimum size that the layout view will size to when `sizeThatFits:` is called.
 */
@property (nonatomic) CGSize minimumSize;

/**
 *  The maximum size that the layout view will size to when `sizeThatFits:` is called.
 *  Note this is particularly useful when you have multiple embedded `RBLayoutView`s that have 
 *  expanding positioners (e.g. `RBLayoutGridPositioner`). These in specific configurations
 *  attempt to expand the cell size and layout to consume all available space and as a viewport of
 *  1000000 maybe passed to the embedded `RBLayoutView` it may need to be restricted via the 
 *  maximumSize property.
 */
@property (nonatomic) CGSize maximumSize;

#pragma mark -
#pragma mark Subclassing

/**
 *  Whether or not the given change of the content insets should invalidate the layout,
 *  causing a repositioning.
 *
 *  @param fromContentInsets The original content insets.
 *  @param contentInsets     The new content insets.
 *
 *  @return Whether or not the layout should be invalidated.
 */
- (BOOL)shouldInvalidateDueToContentInsetsChangeFrom:(UIEdgeInsets)fromContentInsets to:(UIEdgeInsets)contentInsets;

/**
 *  Performs a recalculation of the layout.
 *
 *  @param viewportSize The available size of the viewport.
 *  @param sizeBlock    A block that can be called to get the recommended size of a cell given an available container size.
 *  @param viewCount    The number of cells to position.
 *
 *  @return The result of the recalculation of the layout.
 */
- (nonnull RBLayoutPositionerResult *)calculateWithViewportSize:(CGSize)viewportSize
                                              sizeBlock:(nonnull CGSize(^)(NSUInteger index, CGSize container))sizeBlock
                                              viewCount:(NSUInteger)viewCount;

@end

/**
 *  A delegate to receive positioner events.
 */
@protocol RBLayoutPositionerDelegate <NSObject>

@required

/**
 *  Called when the layout has been invalidated and a recalculation of the layout is needed.
 *
 *  @param positioner The positioner that has had it's layout invalidated.
 */
- (void)positionerWasInvalidated:(nonnull RBLayoutPositioner *)positioner;

@end
