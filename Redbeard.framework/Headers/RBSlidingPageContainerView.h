//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBSlidingPageContainerHeaderView.h>

@protocol RBSlidingPageContainerViewDelegate;

/**
 *  A sliding container of pages.
 */
@interface RBSlidingPageContainerView : UIView

/**
 *  The underlying header view.
 */
@property (nonatomic, readonly, nonnull) RBSlidingPageContainerHeaderView *header;

/**
 *  Whether or not the header is enabled (visible).  Default = false.
 */
@property (nonatomic) BOOL headerEnabled;

/**
 *  Whether or not the user can swipe between pages.  Default = true.
 */
@property (nonatomic) BOOL panningEnabled;

/**
 *  The minimum size of the sliding page container view.
 */
@property (nonatomic) CGSize minimumSize;

/**
 *  Whether or not the container view sizes to fit the current page only (true)
 *  or to fit all of the pages (false).  Default = false.
 */
@property (nonatomic) BOOL sizeToCurrentPageOnly;

/**
 *  The `RBAnimator` to use when sliding between pages.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *animator;

/**
 *  The delegate to be informed of page transition events.
 */
@property (nonatomic, weak, nullable) id<RBSlidingPageContainerViewDelegate> delegate;

/**
 *  The number of pages in the container.
 */
@property (nonatomic, readonly) NSUInteger pageCount;

/**
 *  Retrieves the page view at the given index.
 *
 *  @param index The page index.
 *
 *  @return The retrieved page view.
 */
- (nonnull UIView *)pageViewAtIndex:(NSUInteger)index;

/**
 *  Retrieves the title of the page at the given index.
 *
 *  @param index The page index.
 *
 *  @return The title of the page.
 */
- (nonnull NSString *)pageTitleAtIndex:(NSUInteger)index;

/**
 *  Adds a new page with the given title.
 *
 *  @param pageView The page view.
 *  @param title    The title of the page.
 */
- (void)addPage:(nonnull UIView *)pageView title:(nonnull NSString *)title;

/**
 *  Inserts a new page with the given title at the given index.
 *
 *  @param pageView The page view.
 *  @param title    The title of the page.
 *  @param index    The page index at which to insert.
 */
- (void)insertPage:(nonnull UIView *)pageView title:(nonnull NSString *)title atIndex:(NSUInteger)index;

/**
 *  Removes the page with the given view.
 *
 *  @param pageView The page view.
 */
- (void)removePage:(nonnull UIView *)pageView;

/**
 *  Removes the page at the given index.
 *
 *  @param index The page index.
 */
- (void)removePageAtIndex:(NSUInteger)index;

/**
 *  Removes all pages.
 */
- (void)removeAllPages;

/**
 *  Sets the title of the page at the given index.
 *
 *  @param title The title of the page.
 *  @param index The page index.
 */
- (void)setPageTitle:(nonnull NSString *)title atIndex:(NSUInteger)index;

/**
 *  The index of the current page.
 */
@property (nonatomic, readonly) NSUInteger currentPageIndex;

/**
 *  Moves to the page with the given view.
 *
 *  @param pageView   The page view.
 *  @param animated   Whether or not the transition should be animated.
 *  @param completion An optional block to be called when the transition is complete.
 */
- (void)moveToPage:(nonnull UIView *)pageView animated:(BOOL)animated completion:(nullable dispatch_block_t)completion;

/**
 *  Moves to the page at the given index.
 *
 *  @param index      The page index.
 *  @param animated   Whether or not the transition should be animated.
 *  @param completion An optional block to be called when the transition is complete.
 */
- (void)moveToPageAtIndex:(NSUInteger)index animated:(BOOL)animated completion:(nullable dispatch_block_t)completion;

#pragma mark -
#pragma mark Subclassing

/**
 *  Called when a swipe gesture will reveal the page at the given index (but not select it).
 *
 *  @param index The page index.
 */
- (void)willPeakAtIndex:(NSUInteger)index;

/**
 *  Called when a swipe gesture did reveal the page at the given index (but not select it).
 *
 *  @param index                The page index.
 *  @param didBecomeCurrentPage Whether or not the page did become the current page.
 */
- (void)didPeakAtIndex:(NSUInteger)index didBecomeCurrentPage:(BOOL)didBecomeCurrentPage;

/**
 *  Called when the container will move from one page to another.
 *
 *  @param fromIndex The index of the page being moved away from.
 *  @param toIndex   The index of the page being moved to.
 *  @param animated  Whether or not the transition is animated.
 */
- (void)willMoveFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex animated:(BOOL)animated;

/**
 *  Called when the container did move from one page to another.
 *
 *  @param fromIndex The index of the page being moved away from.
 *  @param toIndex   The index of the page being moved to.
 *  @param animated  Whether or not the transition is animated.
 */
- (void)didMoveFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex animated:(BOOL)animated;

@end

/**
 *  An `RBSlidingPageContainerView` delegate that receives events related to the sliding between pages.
 */
@protocol RBSlidingPageContainerViewDelegate <NSObject>

@optional

/**
 *  Called when a swipe gesture will reveal the page at the given index (but not select it).
 *
 *  @param slidingPageContainerView The sliding page container view.
 *  @param index                    The page index.
 */
- (void)slidingPageContainerView:(nonnull RBSlidingPageContainerView *)slidingPageContainerView willPeakAtIndex:(NSUInteger)index;

/**
 *  Called when a swipe gesture did reveal the page at the given index (but not select it).
 *
 *  @param slidingPageContainerView The sliding page container view.
 *  @param index                    The page index.
 *  @param didBecomeCurrentPage     Whether or not the page did become the current page.
 */
- (void)slidingPageContainerView:(nonnull RBSlidingPageContainerView *)slidingPageContainerView didPeakAtIndex:(NSUInteger)index didBecomeCurrentPage:(BOOL)didBecomeCurrentPage;

/**
 *  The sliding page container view will slide from one page to another.
 *
 *  @param slidingPageContainerView The sliding page container view.
 *  @param fromIndex                The index of the page being moved away from.
 *  @param toIndex                  The index of the page being moved to.
 *  @param animated                 Whether or not the operation is animated.
 */
- (void)slidingPageContainerView:(nonnull RBSlidingPageContainerView *)slidingPageContainerView willMoveFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex animated:(BOOL)animated;

/**
 *  The sliding page container view did slide from one page to another.
 *
 *  @param slidingPageContainerView The sliding page container view.
 *  @param fromIndex                The index of the page being moved away from.
 *  @param toIndex                  The index of the page being moved to.
 *  @param animated                 Whether or not the operation is animated.
 */
- (void)slidingPageContainerView:(nonnull RBSlidingPageContainerView *)slidingPageContainerView didMoveFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex animated:(BOOL)animated;

@end
