//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RBSearchContainerViewControllerDelegate;

/**
 *  A container view controller that manages pages with tabs.
 */
@interface RBSearchContainerViewController : UIViewController

/**
 *  The underlying search container view object.
 */
@property (nonatomic, nonnull) RBSearchContainerView *view;

/**
 *  The primary content view controller.
 */
@property (nonatomic, nonnull) UIViewController *bodyViewController;

/**
 *  The search mode content view controller.
 */
@property (nonatomic, nonnull) UIViewController *resultViewController;

/**
 *  The delegate that receives search and state transition events.
 */
@property (nonatomic, weak, nullable) id<RBSearchContainerViewControllerDelegate> delegate;

/**
 *  Whether or not search mode is currently activated.
 */
@property (nonatomic, readonly) BOOL inSearchMode;

/**
 *  The current query string as it appears in the text field.
 */
@property (nonatomic, nullable) NSString *queryString;

/**
 *  Opens search mode, presenting the `resultView` and optionally opening
 *  the search query field for editing.
 *
 *  @param animated     Whether or not the transition should be animated.
 *  @param openKeyboard Whether or not to open the keyboard for editing the search query field.
 *  @param completion   An optional block to be called when the transition is complete.
 */
- (void)openSearchWithAnimation:(BOOL)animated
                   openKeyboard:(BOOL)openKeyboard
                     completion:(nullable dispatch_block_t)completion;

/**
 *  Closes search mode, presenting the `bodyView` again and closing the keyboard if necessary.
 *
 *  @param animated     Whether or not the transition should be animated.
 *  @param completion   An optional block to be called when the transition is complete.
 */
- (void)closeSearchWithAnimation:(BOOL)animated completion:(nullable dispatch_block_t)completion;

/**
 *  Closes the keyboard for editing the search query string.
 *
 *  @param completion An optional block to be called when the keyboard has been closed.
 */
- (void)closeKeyboardWithCompletion:(nullable dispatch_block_t)completion;

/**
 *  Performs a search with the given query.
 *  The delegate is notified that the search has been requested.
 *
 *  @param queryString The query string to search with.
 */
- (void)performSearchWithQuery:(nonnull NSString *)queryString;

@end

/**
 *  The delegate that receives search and state transition events
 *  for an `RBSearchContainerViewController` object.
 */
@protocol RBSearchContainerViewControllerDelegate <NSObject>

@required

/**
 *  Called when the search container view requests that a search be performed.
 *
 *  @param searchContainerViewController  The `RBSearchContainerViewController` object.
 *  @param queryString                    The search query string.
 */
- (void)searchContainerViewController:(nonnull RBSearchContainerViewController *)searchContainerViewController didRequestSearchWithQuery:(nonnull NSString *)queryString;

@optional

/**
 *  Whether or not search mode should be opened when the query string field is tapped.
 *
 *  @param searchContainerViewController The `RBSearchContainerViewController` object.
 *
 *  @return Whether or not to open search mode.
 */
- (BOOL)searchContainerViewControllerShouldOpenOnQueryEdit:(nonnull RBSearchContainerViewController *)searchContainerViewController;

/**
 *  Whether or not search mode should be closed when the cancel button is tapped.
 *
 *  @param searchContainerViewController The `RBSearchContainerViewController` object.
 *
 *  @return Whether or not to close search mode.
 */
- (BOOL)searchContainerViewControllerShouldCloseOnCancelTapped:(nonnull RBSearchContainerViewController *)searchContainerViewController;

/**
 *  Called when the search mode will open.
 *
 *  @param searchContainerViewController The `RBSearchContainerViewController` object.
 *  @param animated                      Whether the transition is animated.
 */
- (void)searchContainerViewController:(nonnull RBSearchContainerViewController *)searchContainerViewController willOpenSearchWithAnimation:(BOOL)animated;

/**
 *  Called when the search mode did open.
 *
 *  @param searchContainerViewController The `RBSearchContainerViewController` object.
 *  @param animated                      Whether the transition is animated.
 */
- (void)searchContainerViewController:(nonnull RBSearchContainerViewController *)searchContainerViewController didOpenSearchWithAnimation:(BOOL)animated;

/**
 *  Called when the search mode will close.
 *
 *  @param searchContainerViewController The `RBSearchContainerViewController` object.
 *  @param animated                      Whether the transition is animated.
 */
- (void)searchContainerViewController:(nonnull RBSearchContainerViewController *)searchContainerViewController willCloseSearchWithAnimation:(BOOL)animated;

/**
 *  Called when the search mode did close.
 *
 *  @param searchContainerViewController The `RBSearchContainerViewController` object.
 *  @param animated                      Whether the transition is animated.
 */
- (void)searchContainerViewController:(nonnull RBSearchContainerViewController *)searchContainerViewController didCloseSearchWithAnimation:(BOOL)animated;

@end
