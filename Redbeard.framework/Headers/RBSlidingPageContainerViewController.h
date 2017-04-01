//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBSlidingPageContainerView.h>

@protocol RBSlidingPageContainerViewControllerDelegate;

/**
 *  A container view controller that manages pages with tabs.
 */
@interface RBSlidingPageContainerViewController : UIViewController<RBSlidingPageContainerViewDelegate>

/**
 *  The underlying `RBSlidingPageContainerView` object.
 */
@property (nonatomic, nonnull) RBSlidingPageContainerView *view;

/**
 *  A delegate to receive tab page selection events.
 */
@property (nonatomic, weak, nullable) id<RBSlidingPageContainerViewControllerDelegate> delegate;

/**
 *  The number of tab pages currently in the container.
 */
@property (nonatomic, readonly) NSUInteger pageControllerCount;

/**
 *  The index of the current page.
 */
@property (nonatomic, readonly) NSUInteger currentPageControllerIndex;

/**
 *  The current page `UIViewController` object.
 */
@property (nonatomic, readonly, nullable) UIViewController *currentPageViewController;

/**
 *  Gets the page view controller at the given index.
 *
 *  @param index The index of the page.
 *
 *  @return The `UIViewController` object at the given index.
 */
- (nonnull UIViewController *)pageControllerAtIndex:(NSUInteger)index;

/**
 *  Gets the title of the page at the given index.
 *
 *  @param index The index of the page
 *
 *  @return The title of the page.
 */
- (nonnull NSString *)pageTitleAtIndex:(NSUInteger)index;

/**
 *  Add a new page to the controller.
 *
 *  @param pageController The page `UIViewController` object.
 *  @param title          The title of the page.
 */
- (void)addPageController:(nonnull UIViewController *)pageController title:(nonnull NSString *)title;

/**
 *  Insert a new page to the controller at the given index.
 *
 *  @param pageController The page `UIViewController` object.
 *  @param title          The title of the page.
 *  @param index          The index at which to insert the page.
 */
- (void)insertPageController:(nonnull UIViewController *)pageController title:(nonnull NSString *)title atIndex:(NSUInteger)index;

/**
 *  Remove the given page from the container.
 *
 *  @param pageController The page `UIViewController` object.
 */
- (void)removePageController:(nonnull UIViewController *)pageController;

/**
 *  Remove the page at the given index.
 *
 *  @param index The index of the page to remove.
 */
- (void)removePageControllerAtIndex:(NSUInteger)index;

/**
 *  Remove all pages from the container.
 */
- (void)removeAllPageControllers;

/**
 *  Set the title of the page at the given index.
 *
 *  @param title The title to assign to the page.
 *  @param index The index of the page to update the title of.
 */
- (void)setPageControllerTitle:(nonnull NSString *)title atIndex:(NSUInteger)index;

/**
 *  Moves to the given page view controller.
 *
 *  @param pageController The page `UIViewController` object to move to.
 *  @param animated       Whether or not the transition should be animated.
 *  @param completion     An optional block to be called when the transition is complete.
 */
- (void)moveToPageController:(nonnull UIViewController *)pageController animated:(BOOL)animated completion:(nullable dispatch_block_t)completion;

/**
 *  Moves to the given page view controller.
 *
 *  @param index      The index of the page to move to.
 *  @param animated   Whether or not the transition should be animated.
 *  @param completion An optional block to be called when the transition is complete.
 */
- (void)moveToPageControllerAtIndex:(NSUInteger)index animated:(BOOL)animated completion:(nullable dispatch_block_t)completion;

@end

/**
 *  A delegate to receive tab page selection events for an `RBSlidingPageContainerViewController`.
 */
@protocol RBSlidingPageContainerViewControllerDelegate <NSObject>

@optional

/**
 *  Called when a page will be moved to.
 *
 *  @param slidingPageViewController The `RBSlidingPageContainerViewController` object.
 *  @param fromIndex                 The index of the page being moved away from.
 *  @param toIndex                   The index of the page being moved to.
 *  @param animated                  Whether or not the transition is animated.
 */
- (void)slidingPageViewController:(nonnull RBSlidingPageContainerViewController *)slidingPageViewController
                willMoveFromIndex:(NSUInteger)fromIndex
                          toIndex:(NSUInteger)toIndex
                         animated:(BOOL)animated;

/**
 *  Called when a page was moved to.
 *
 *  @param slidingPageViewController The `RBSlidingPageContainerViewController` object.
 *  @param fromIndex                 The index of the page being moved away from.
 *  @param toIndex                   The index of the page being moved to.
 *  @param animated                  Whether or not the transition is animated.
 */
- (void)slidingPageViewController:(nonnull RBSlidingPageContainerViewController *)slidingPageViewController
                 didMoveFromIndex:(NSUInteger)fromIndex
                          toIndex:(NSUInteger)toIndex
                         animated:(BOOL)animated;

@end
