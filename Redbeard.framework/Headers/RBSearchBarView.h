//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RBSearchBarViewDelegate;

/**
 *  A search bar consisting of a text field and optionally a cancel button.
 */
@interface RBSearchBarView : UIView

/**
 *  A delegate to receive search and state change events.
 */
@property (nonatomic, weak, nullable) id<RBSearchBarViewDelegate> delegate;

/**
 *  Whether or not a cancel button should be provided.
 */
@property (nonatomic) BOOL cancelButtonEnabled;

/**
 *  Whether or not the keyboard should close when a search is performed.
 */
@property (nonatomic) BOOL shouldCloseKeyboardOnSearch;

/**
 *  The margin to provide around the text field and cancel button in the view.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The spacing to provide between the text field and the cancel button.
 */
@property (nonatomic) CGFloat spacing;

#pragma mark -
#pragma mark Search

/**
 *  Gets or sets the current query string.
 */
@property (nonatomic, nullable) NSString *queryString;

/**
 *  Performs a search with the given query string.  This notifies the delegate
 *  that a search has been requested.
 *
 *  @param queryString The query string to perform the search with.
 */
- (void)performSearchWithQuery:(nonnull NSString *)queryString;

#pragma mark -
#pragma mark State

/**
 *  The `RBAnimator` object to use when animating state changes.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *animator;

/**
 *  Whether or not the search bar is currently activated.
 */
@property (nonatomic, readonly) BOOL isActivated;

/**
 *  Activates the search bar, revealing the cancel button and optionally
 *  opening the keyboard to edit the search query string.
 *
 *  @param animated     Whether or not the transition should be animated.
 *  @param openKeyboard Whether or not the keyboard should also be opened.
 *  @param completion   An optional block to be called on completion.
 */
- (void)activateWithAnimation:(BOOL)animated
                 openKeyboard:(BOOL)openKeyboard
                   completion:(nullable dispatch_block_t)completion;

/**
 *  Deactivates the search bar, hiding the cancellation button and closing
 *  the keyboard.
 *
 *  @param animated     Whether or not the transition should be animated.
 *  @param completion   An optional block to be called on completion.
 */
- (void)deactivateWithAnimation:(BOOL)animated
                     completion:(nullable dispatch_block_t)completion;

#pragma mark -
#pragma mark Keyboard

/**
 *  Whether or not the keyboard is currently open editing the search query string.
 */
@property (nonatomic, readonly) BOOL keyboardIsOpen;

/**
 *  Opens the keyboard to edit the search query string.
 *
 *  @param completion An optional block to be called when the keyboard has been opened.
 */
- (void)openKeyboardWithCompletion:(nullable dispatch_block_t)completion;

/**
 *  Closes the keyboard if it is currently opened to edit the search query string.
 *
 *  @param completion An optional block to be called when the keyboard has been closed.
 */
- (void)closeKeyboardWithCompletion:(nullable dispatch_block_t)completion;

@end

/**
 *  A delegate to receive search and state change events for an `RBSearchBarView` object.
 */
@protocol RBSearchBarViewDelegate <NSObject>

@required

/**
 *  Called when the search bar view has requested that a search is performed.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *  @param queryString   The query string to perform a search with.
 */
- (void)searchBarView:(nonnull RBSearchBarView *)searchBarView didRequestSearchWithQuery:(nonnull NSString *)queryString;

@optional

/**
 *  Whether or not the search bar view should activate after the query string field has been tapped.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *
 *  @return Whether or not to allow activation.
 */
- (BOOL)searchBarViewShouldActivateOnQueryEdit:(nonnull RBSearchBarView *)searchBarView;

/**
 *  Whether or not the search bar view should deactivate after the cancel button has been tapped.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *
 *  @return Whether or not to allow deactivation.
 */
- (BOOL)searchBarViewShouldDeactivateOnCancelTapped:(nonnull RBSearchBarView *)searchBarView;

/**
 *  Called when the query string was updated.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *  @param queryString   The new query string.
 */
- (void)searchBarView:(nonnull RBSearchBarView *)searchBarView queryDidChangeTo:(nonnull NSString *)queryString;

/**
 *  Called when the query string is cleared in a search bar view.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 */
- (void)searchBarViewDidClearQuery:(nonnull RBSearchBarView *)searchBarView;

/**
 *  Called when the search bar view will be activated.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *  @param animated      Whether or not the transition is animated.
 */
- (void)searchBarView:(nonnull RBSearchBarView *)searchBarView willActivateWithAnimation:(BOOL)animated;

/**
 *  Called when the search bar view was activated.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *  @param animated      Whether or not the transition is animated.
 */
- (void)searchBarView:(nonnull RBSearchBarView *)searchBarView didActivateWithAnimation:(BOOL)animated;

/**
 *  Called when the search bar view will be deactivated.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *  @param animated      Whether or not the transition is animated.
 */
- (void)searchBarView:(nonnull RBSearchBarView *)searchBarView willDeactivateWithAnimation:(BOOL)animated;

/**
 *  Called when the search bar view was deactivated.
 *
 *  @param searchBarView The `RBSearchBarView` object.
 *  @param animated      Whether or not the transition is animated.
 */
- (void)searchBarView:(nonnull RBSearchBarView *)searchBarView didDeactivateWithAnimation:(BOOL)animated;

@end
