//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBButton.h>

/**
 *  Tab page items, stores the tab view controller and identifier.
 */
@interface RBTabbedPageItem : NSObject

/**
 *  Whether or no the tab button should fill all available space.
 */
@property (nonatomic) BOOL fill;

/**
 *  The location of the tab button.
 */
@property (nonatomic) RBHorizontalAlignment alignment;

/**
 *  The identifier of the tab.
 */
@property (nonatomic, nonnull, readonly) NSString *identifier;

/**
 *  The view controller that provides the contents of the tab.
 */
@property (nonatomic, nonnull, readonly) UIViewController *viewController;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller.
 *  @param title            The title to apply to the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                        withViewController:(nonnull UIViewController *)viewController
                                 withTitle:(nonnull NSString *)title
                             withAlignment:(RBHorizontalAlignment)alignment;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller.
 *  @param image            The image to apply to the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                        withViewController:(nonnull UIViewController *)viewController
                                 withImage:(nonnull UIImage *)image
                             withAlignment:(RBHorizontalAlignment)alignment;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller.
 *  @param title            The title to apply to the tab button.
 *  @param image            The image to apply to the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                        withViewController:(nonnull UIViewController *)viewController
                                 withTitle:(nonnull NSString *)title
                                 withImage:(nonnull UIImage *)image
                             withAlignment:(RBHorizontalAlignment)alignment;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller.
 *  @param button           A custom button to use as the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                        withViewController:(nonnull UIViewController *)viewController
                                withButton:(nonnull RBButton *)button
                             withAlignment:(RBHorizontalAlignment)alignment;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller.
 *  @param title            The title to apply to the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
+ (nonnull instancetype)withIdentifier:(nonnull NSString *)identifier
                    withViewController:(nonnull UIViewController *)viewController
                             withTitle:(nonnull NSString *)title
                         withAlignment:(RBHorizontalAlignment)alignment;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller
 *  @param image            The image to apply to the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
+ (nonnull instancetype)withIdentifier:(nonnull NSString *)identifier
                    withViewController:(nonnull UIViewController *)viewController
                             withImage:(nonnull UIImage *)image
                         withAlignment:(RBHorizontalAlignment)alignment;

/**
 *  Initializes a new `RBTabbedPageItem`.
 *
 *  @param identifier       The unique identifier of the tab page item.
 *  @param viewController   The view controller.
 *  @param title            The title to apply to the tab button.
 *  @param image            The image to apply to the tab button.
 *  @param alignment        The location of the tab button.
 *
 *  @return The initialized `RBTabbedPageItem`.
 */
+ (nonnull instancetype)withIdentifier:(nonnull NSString *)identifier
                    withViewController:(nonnull UIViewController *)viewController
                             withTitle:(nonnull NSString *)title
                             withImage:(nonnull UIImage *)image
                         withAlignment:(RBHorizontalAlignment)alignment;

@end


@protocol RBTabbedPageContainerViewControllerDelegate;

/**
 *  A container view that manages pages with tabs.
 */
@interface RBTabbedPageContainerViewController : UIViewController

/**
 *  A delegate to receive tab page selection events.
 */
@property (nonatomic, weak, nullable) id<RBTabbedPageContainerViewControllerDelegate> delegate;

/**
 *  Whether or not the tab bar is visible. Default = `YES`.
 */
@property (nonatomic, readonly) BOOL tabBarVisible;

/**
 *  The tab bar animator. Default = `[RBAnimator defaultAnimator]`.
 */
@property (nonatomic, nonnull) RBAnimator *tabBarAnimator;

/**
 *  The tab bar height. Default = 49.
 */
@property (nonatomic) CGFloat tabBarHeight;

/**
 *  The tab bar visual effect to apply. Default = `RBVisualEffectTypeNone`.
 */
@property (nonatomic) RBVisualEffectType tabBarVisualEffect;

/**
 *  Whether or not the tab bar should over lap the contents. If this is `YES` then the contentChromeInsets 
 *  are not used and hence the tab bar will overlap. Default = `NO`.
 */
@property (nonatomic) BOOL tabBarShouldOverlapContent;

/**
 *  The number of tab pages currently in the container.
 */
@property (nonatomic, readonly) NSUInteger pageCount;

/**
 *  Gets or sets the current tab page via the identifier.
 */
@property (nonatomic, nullable) NSString* selectedPageIdentifier;

/**
 *  Gets or sets the selected tab page via the index. Returns NSNotFound if a page is not set.
 */
@property (nonatomic) NSInteger selectedPageIndex;

/**
 *  Gets or sets the selected tab page.
 */
@property (nonatomic, nullable) UIViewController* selectedPage;

/**
 *  Hides the tabBar if it is not already hidden.
 *
 *  @param animated   Whether or not to animate hiding the tabBar.
 */
- (void)hideTabBar:(BOOL)animated;

/**
 *  Shows the tabBar if it is not already being shown.
 *
 *  @param animated   Whether or not to animate showing the tabBar.
 */
- (void)showTabBar:(BOOL)animated;

/**
 *  Adds a page tab with the given details.
 *
 *  @param item         The `RBTabbedPageItem` that encapsulates the page view controller and button.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)addPage:(nonnull RBTabbedPageItem *)item;

/**
 *  Removes the given page view from the container.
 *
 *  @param identifier   The identifier of the page to remove.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removePageWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Removes the given page view from the container.
 *
 *  @param page The page view to remove.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removePage:(nonnull UIViewController *)page;

/**
 *  Removes all pages from the container.
 */
- (void)removeAllPages;

/**
 *  Adds a custom view to the tab bar with the given details.
 *
 *  @param view         The view to add.
 *  @param alignment    The alignment of the tab button.
 *  @param fill         Wheter or not to have the button fill the available space (default = `YES`)
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)addTabBarView:(nonnull UIView *)view
        withAlignment:(RBHorizontalAlignment)alignment
             withFill:(BOOL)fill;

/**
 *  Removes a custom view from the tab bar;
 *
 *  @param view         The view to add.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removeTabBarView:(nonnull UIView *)view;

#pragma mark -
#pragma mark Subclassing

/**
 *  Called to notify that a tab will be selected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 */
- (void)tabWillSelectPage:(nonnull UIViewController *)page
           withIdentifier:(nonnull NSString *)identifier
                 animated:(BOOL)animated;

/**
 *  Called to notify that a tab will be deselected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 */
- (void)tabWillDeselectPage:(nonnull UIViewController *)page
             withIdentifier:(nonnull NSString *)identifier
                   animated:(BOOL)animated;

/**
 *  Called to notify that a tab was selected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 */
- (void)tabDidSelectPage:(nonnull UIViewController *)page
          withIdentifier:(nonnull NSString *)identifier
                animated:(BOOL)animated;

/**
 *  Called to notify that a tab was deselected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 */
- (void)tabDidDeselectPage:(nonnull UIViewController *)page
            withIdentifier:(nonnull NSString *)identifier
                  animated:(BOOL)animated;

/**
 *  Called to notify that a tab button was tapped.
 *
 *  @param button           The button that was tapped.
 *  @param identifier       The identifier of the tab that was tapped.
 */
- (void)tabButtonWasTapped:(nonnull RBButton *)button
            withIdentifier:(nonnull NSString *)identifier;

/**
 *  Called to notify that the tab bar will appear.
 */
- (void)tabBarWillAppear;

/**
 *  Called to notify that the tab bar will disappear.
 */
- (void)tabBarWillDisappear;

/**
 *  Called to notify that the tab bar did appear.
 */
- (void)tabBarDidAppear;

/**
 *  Called to notify that the tab bar did disappear.
 */
- (void)tabBarDidDisappear;


@end

/**
 *  A delegate to receive tab page selection events.
 */
@protocol RBTabbedPageContainerViewControllerDelegate <NSObject>

@optional

/**
 *  Called to notify that a tab will be selected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 *  @param container        The tabbed page container object.
 */
- (void)tabWillSelectPage:(nonnull UIViewController *)page
           withIdentifier:(nonnull NSString *)identifier
                 animated:(BOOL)animated
                container:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that a tab will be deselected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 *  @param container        The tabbed page container object.
 */
- (void)tabWillDeselectPage:(nonnull UIViewController *)page
             withIdentifier:(nonnull NSString *)identifier
                   animated:(BOOL)animated
                  container:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that a tab was selected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 *  @param container        The tabbed page container object.
 */
- (void)tabDidSelectPage:(nonnull UIViewController *)page
          withIdentifier:(nonnull NSString *)identifier
                animated:(BOOL)animated
               container:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that a tab was deselected.
 *
 *  @param page             The view controller.
 *  @param identifier       The identifier of the page that will be selected.
 *  @param animated         Whether or not the transition to the page will be animated.
 *  @param container        The tabbed page container object.
 */
- (void)tabDidDeselectPage:(nonnull UIViewController *)page
            withIdentifier:(nonnull NSString *)identifier
                  animated:(BOOL)animated
                 container:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that a tab button was tapped.
 *
 *  @param button           The button that was tapped.
 *  @param identifier       The identifier of the tab that was tapped.
 *  @param container        The tabbed page container object.
 */
- (void)tabButtonWasTapped:(nonnull RBButton *)button
            withIdentifier:(nonnull NSString *)identifier
       container:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that the tab bar will appear.
 *
 *  @param container The tabbed page container object.
 */
- (void)tabBarWillAppear:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that the tab bar will disappear.
 *
 *  @param container The tabbed page container object.
 */
- (void)tabBarWillDisappear:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that the tab bar did appear.
 *
 *  @param container The tabbed page container object.
 */
- (void)tabBarDidAppear:(nonnull RBTabbedPageContainerViewController *)container;

/**
 *  Called to notify that the tab bar did disappear.
 *
 *  @param container The tabbed page container object.
 */
- (void)tabBarDidDisappear:(nonnull RBTabbedPageContainerViewController *)container;

@end
