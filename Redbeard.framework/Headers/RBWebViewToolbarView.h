//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RBWebViewToolbarDelegate;

/**
 *  A toolbar that provides web navigation buttons.
 */
@interface RBWebViewToolbarView : UIView

/**
 *  A delegate to receive navigation button tap events.
 */
@property (nonatomic, weak, nullable) id<RBWebViewToolbarDelegate> delegate;

/**
 *  Whether or not the toolbar should expand to fill the available space.
 */
@property (nonatomic) BOOL shouldFillAvailableSpace;

/**
 *  The orientation of the toolbar.
 */
@property (nonatomic) RBOrientation orientation;

/**
 *  Whether or not the back button should be enabled.
 */
@property (nonatomic) BOOL backButtonEnabled;

/**
 *  Whether or not the forward button should be enabled.
 */
@property (nonatomic) BOOL forwardButtonEnabled;

/**
 *  Whether or not the stop button should be enabled.
 */
@property (nonatomic) BOOL stopButtonEnabled;

/**
 *  Whether or not the reload button should be enabled.
 */
@property (nonatomic) BOOL reloadButtonEnabled;

/**
 *  Whether or not the back button should be visible.
 */
@property (nonatomic) BOOL hasBackButton;

/**
 *  Whether or not the forward button should be visible.
 */
@property (nonatomic) BOOL hasForwardButton;

/**
 *  Whether or not the stop button should be visible.
 */
@property (nonatomic) BOOL hasStopButton;

/**
 *  Whether or not the reload button should be visible.
 */
@property (nonatomic) BOOL hasReloadButton;

@end

/**
 *  A delegate that receives events from an `RBWebViewToolbarView` object.
 */
@protocol RBWebViewToolbarDelegate <NSObject>

@optional

/**
 *  Called when the back button was tapped by the user on the web toolbar view.
 *
 *  @param webViewToolbarView The `RBWebViewToolbarView` object.
 */
- (void)backSelectedWithWebViewToolbarView:(nonnull RBWebViewToolbarView *)webViewToolbarView;

/**
 *  Called when the forward button was tapped by the user on the web toolbar view.
 *
 *  @param webViewToolbarView The `RBWebViewToolbarView` object.
 */
- (void)forwardSelectedWithWebViewToolbarView:(nonnull RBWebViewToolbarView *)webViewToolbarView;

/**
 *  Called when the stop button was tapped by the user on the web toolbar view.
 *
 *  @param webViewToolbarView The `RBWebViewToolbarView` object.
 */
- (void)stopSelectedWithWebViewToolbarView:(nonnull RBWebViewToolbarView *)webViewToolbarView;

/**
 *  Called when the reload button was tapped by the user on the web toolbar view.
 *
 *  @param webViewToolbarView The `RBWebViewToolbarView` object.
 */
- (void)reloadSelectedWithWebViewToolbarView:(nonnull RBWebViewToolbarView *)webViewToolbarView;

@end
