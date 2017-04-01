//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  The header view for an `RBSlidingPageContainerView` object.
 */
@interface RBSlidingPageContainerHeaderView : UIView

/**
 *  The `RBAnimator` to use when animating the page sliding.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *animator;

/**
 *  The margin to apply to the content of the header.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  Whether or not sibling labels should stay within view.
 */
@property (nonatomic) BOOL shouldClipLabelsToView;

/**
 *  Whether or not sibling labels should peak at the edges.
 */
@property (nonatomic) BOOL shouldPeakLabelsAtEdges;

/**
 *  The minimum spacing that should be maintained between labels.
 */
@property (nonatomic) CGFloat minimumSpacing;

#pragma mark -
#pragma mark Panning Updates

/**
 *  Notify the header view that the user began panning the sliding page container.
 */
- (void)panningDidBegin;

/**
 *  Notify the header view that the user panned the sliding page container to a new offset.
 *
 *  @param swipeOffset The new offset.
 */
- (void)panningDidUpdateTo:(CGFloat)swipeOffset;

/**
 *  Notify the header view that the user finished panning the sliding page container.
 */
- (void)panningDidFinish;

#pragma mark -
#pragma mark Titles

/**
 *  The number of page title labels in the header.
 */
@property (nonatomic, readonly) NSUInteger titleCount;

/**
 *  The title of the page at the given index.
 *
 *  @param index The page index.
 *
 *  @return The title of the page.
 */
- (nonnull NSString *)titleAtIndex:(NSUInteger)index;

/**
 *  Adds a page title.
 *
 *  @param title The title of the page.
 */
- (void)addTitle:(nonnull NSString *)title;

/**
 *  Inserts a new page title at the given index.
 *
 *  @param title The title of the page.
 *  @param index The index to add the page title to.
 */
- (void)insertTitle:(nonnull NSString *)title atIndex:(NSUInteger)index;

/**
 *  Removes the given page title.
 *
 *  @param title The title of the page.
 */
- (void)removeTitle:(nonnull NSString *)title;

/**
 *  Removes the page title at the given index.
 *
 *  @param index The page index.
 */
- (void)removeTitleAtIndex:(NSUInteger)index;

/**
 *  Removes all of the page titles.
 */
- (void)removeAllTitles;

/**
 *  Updates the page title at the given index to the given title.
 *
 *  @param index The page index.
 *  @param title The title of the page.
 */
- (void)modifyTitleAtIndex:(NSUInteger)index title:(nonnull NSString *)title;

/**
 *  The index of the current page.
 */
@property (nonatomic, readonly) NSUInteger currentTitleIndex;

/**
 *  Move to the page at the given index.
 *
 *  @param index      The page index.
 *  @param animated   Whether or not to animate the transition.
 *  @param completion An optional block to be called when the transition is complete.
 */
- (void)moveToTitleAtIndex:(NSUInteger)index animated:(BOOL)animated completion:(nullable dispatch_block_t)completion;

@end
