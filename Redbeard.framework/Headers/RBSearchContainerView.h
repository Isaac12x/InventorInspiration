//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBSearchBarView.h>

@protocol RBSearchContainerViewDelegate;

/**
 *  A container view providing a search bar at the top and a transition to a search view.
 */
@interface RBSearchContainerView : UIView

/**
 *  The search bar view.
 */
@property (nonatomic, readonly, nonnull) RBSearchBarView *searchBarView;

/**
 *  The body view, when search mode is closed.
 */
@property (nonatomic, nullable) UIView *bodyView;

/**
 *  The search results view, when the search mode is opened.
 */
@property (nonatomic, nullable) UIView *resultView;

/**
 *  Whether or not search results should be updated while the user is typing.
 */
@property (nonatomic) BOOL liveSearchEnabled;

/**
 *  The delegate that receives search and state transition events.
 */
@property (nonatomic, weak, nullable) id<RBSearchContainerViewDelegate> delegate;

#pragma mark -
#pragma mark State

/**
 *  The `RBAnimator` object to use when animating transitions.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *animator;

/**
 *  Whether or not search mode is currently activated.
 */
@property (nonatomic, readonly) BOOL inSearchMode;

/**
 *  Opens search mode, presenting the `resultView` and optionally opening
 *  the search query field for editing.
 *
 *  @param animated     Whether or not the transition should be animated.
 *  @param openKeyboard Whether or not to open the keyboard for editing the search query field.
 *  @param completion   An optional block to be called when the transition is complete.
 */
- (void)openSearchWithAnimation:(BOOL)animated openKeyboard:(BOOL)openKeyboard completion:(nullable dispatch_block_t)completion;

/**
 *  Closes search mode, presenting the `bodyView` again and closing the keyboard if necessary.
 *
 *  @param animated     Whether or not the transition should be animated.
 *  @param completion   An optional block to be called when the transition is complete.
 */
- (void)closeSearchWithAnimation:(BOOL)animated completion:(nullable dispatch_block_t)completion;

#pragma mark -
#pragma mark Search

/**
 *  The last query string that was searched.
 */
@property (nonatomic, readonly, nullable) NSString *lastQueryString;

/**
 *  The current query string as it appears in the text field.
 */
@property (nonatomic, nullable) NSString *queryString;

/**
 *  Performs a search with the given query.  The query is assigned to `lastQueryString`.
 *  The delegate is notified that the search has been requested.
 *
 *  @param queryString The query string to search with.
 */
- (void)performSearchWithQuery:(nonnull NSString *)queryString;

#pragma mark -
#pragma mark Keyboard Management

/**
 *  Opens the keyboard for editing the search query string.
 *
 *  @param completion An optional block to be called when the keyboard has been opened.
 */
- (void)openKeyboardWithCompletion:(nullable dispatch_block_t)completion;

/**
 *  Closes the keyboard for editing the search query string.
 *
 *  @param completion An optional block to be called when the keyboard has been closed.
 */
- (void)closeKeyboardWithCompletion:(nullable dispatch_block_t)completion;

@end

/**
 *  The delegate that receives search and state transition events for an `RBSearchContainerView` object.
 */
@protocol RBSearchContainerViewDelegate <NSObject>

@required

/**
 *  Called when the search container view requests that a search be performed.
 *
 *  @param searchContainerView  The `RBSearchContainerView` object.
 *  @param queryString          The search query string.
 */
- (void)searchContainerView:(nonnull RBSearchContainerView *)searchContainerView didRequestSearchWithQuery:(nonnull NSString *)queryString;

@optional

/**
 *  Whether or not search mode should be opened when the query string field is tapped.
 *
 *  @param searchContainerView The `RBSearchContainerView` object.
 *
 *  @return Whether or not to open search mode.
 */
- (BOOL)searchContainerViewShouldOpenOnQueryEdit:(nonnull RBSearchContainerView *)searchContainerView;

/**
 *  Whether or not search mode should be closed when the cancel button is tapped.
 *
 *  @param searchContainerView The `RBSearchContainerView` object.
 *
 *  @return Whether or not to close search mode.
 */
- (BOOL)searchContainerViewShouldCloseOnCancelTapped:(nonnull RBSearchContainerView *)searchContainerView;

/**
 *  Called when the search mode will open.
 *
 *  @param searchContainerView The `RBSearchContainerView` object.
 *  @param animated            Whether the transition is animated.
 */
- (void)searchContainerView:(nonnull RBSearchContainerView *)searchContainerView willOpenSearchWithAnimation:(BOOL)animated;

/**
 *  Called when the search mode did open.
 *
 *  @param searchContainerView The `RBSearchContainerView` object.
 *  @param animated            Whether the transition is animated.
 */
- (void)searchContainerView:(nonnull RBSearchContainerView *)searchContainerView didOpenSearchWithAnimation:(BOOL)animated;

/**
 *  Called when the search mode will close.
 *
 *  @param searchContainerView The `RBSearchContainerView` object.
 *  @param animated            Whether the transition is animated.
 */
- (void)searchContainerView:(nonnull RBSearchContainerView *)searchContainerView willCloseSearchWithAnimation:(BOOL)animated;

/**
 *  Called when the search mode did close.
 *
 *  @param searchContainerView The `RBSearchContainerView` object.
 *  @param animated            Whether the transition is animated.
 */
- (void)searchContainerView:(nonnull RBSearchContainerView *)searchContainerView didCloseSearchWithAnimation:(BOOL)animated;

@end
