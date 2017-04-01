//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBObserverCollection.h>
#import <Redbeard/RBTheming.h>

/**
 *  An observer of changes to the device orientation.
 */
@protocol RBDeviceOrientationObserver <NSObject>

@optional

/**
 *  Called when the orientation of the device changed.
 *
 *  @param deviceOrientation The new device orientation.
 *  @param isLandscape       Whether or not the new orientation is a landscape orientation.
 *  @param isPortrait        Whether or not the new orientation is a portrait orientation.
 */
- (void)deviceOrientationDidChangeTo:(UIDeviceOrientation)deviceOrientation isLandscape:(BOOL)isLandscape isPortrait:(BOOL)isPortrait;

@end

/**
 *  An observer of changes to the keyboard state.
 */
@protocol RBKeyboardObserver <NSObject>

@optional

/**
 *  Called when the keyboard will open.
 *
 *  @param frame The frame that the keyboard will occupy when opened.
 */
- (void)keyboardWillOpenWithFrame:(CGRect)frame;

/**
 *  Called when the keyboard did open.
 *
 *  @param frame The frame that the keyboard occupied when it opened.
 */
- (void)keyboardDidOpenWithFrame:(CGRect)frame;

/**
 *  Called when the keyboard will hide.
 */
- (void)keyboardWillHide;

/**
 *  Called when the keyboard did hide.
 */
- (void)keyboardDidHide;

/**
 *  Called when the keyboard frame will change.
 *
 *  @param frame         The new frame that the keyboard will use.
 *  @param previousFrame The previous frame.
 */
- (void)keyboardFrameWillChangeTo:(CGRect)frame from:(CGRect)previousFrame;

/**
 *  Called when the keyboard frame has changed.
 *
 *  @param frame         The new frame that the keyboard changed to.
 *  @param previousFrame The previous frame.
 */
- (void)keyboardFrameDidChangeTo:(CGRect)frame from:(CGRect)previousFrame;

@end

/**
 *  Provides state and convenience methods for the application's UI.
 */
@interface RBUICenter : NSObject<RBObserverCollectionDelegate>

/**
 *  The shared UI center.
 */
+ (nonnull RBUICenter *)shared;

/**
 *  The application window.
 */
@property (nonatomic, readonly, nullable) UIWindow *window;

/**
 *  The application root view controller.
 */
@property (nonatomic, readonly, nullable) UIViewController *rootViewController;

/**
 *  The application root view.
 */
@property (nonatomic, readonly, nullable) UIView *rootView;

/**
 *  Gets the top-most presented view controller.
 *
 *  This is not for view controllers presented with `RBPresentationController`.
 */
- (nullable UIViewController *)topViewController;

// The current rotation-adjusted screen size.
/**
 *  The current rotation-adjusted screen size.
 */
+ (CGSize)screenSize;

/**
 *  Calculates the status bar frame that occupies the given view.
 *
 *  @param view The view to use as the local coordinate system.
 *
 *  @return The resulting `CGRect` frame.
 */
- (CGRect)statusBarFrameInView:(nonnull UIView *)view;

#pragma mark -
#pragma mark DEVICE ORIENTATION

/**
 *  The current device orientation.
 */
@property (nonatomic, readonly) UIDeviceOrientation deviceOrientation;

/**
 *  Whether or not the current device orientation is landscape.
 */
@property (nonatomic, readonly) BOOL deviceOrientationIsLandscape;

/**
 *  Whether or not the current device orientation is portrait.
 */
@property (nonatomic, readonly) BOOL deviceOrientationIsPortrait;

/**
 *  A collection of observers to be notified of changes to the device orientation.
 */
@property (nonatomic, readonly, nonnull) RBObserverCollection *deviceOrientationObservers;

#pragma mark -
#pragma mark KEYBOARD STATE

/**
 *  Whether or not the keyboard is currently opening.
 */
@property (nonatomic, readonly) BOOL keyboardIsOpening;

/**
 *  Whether or not the keyboard is currently hiding.
 */
@property (nonatomic, readonly) BOOL keyboardIsHiding;

/**
 *  Whether or not the keyboard is currently open.
 */
@property (nonatomic, readonly) BOOL keyboardIsOpen;

/**
 *  Calculates the frame of the keyboard that occupies the given view.
 *
 *  @param view The view to use as the local coordinate system.
 *
 *  @return The resulting `CGRect` value.
 */
- (CGRect)keyboardFrameInView:(nonnull UIView *)view;

/**
 *  The animation duration used for keyboard open/hide transitions.
 */
@property (nonatomic, readonly) NSTimeInterval keyboardAnimationDuration;

/**
 *  The animation curve used for keyboard open/hide transitions.
 */
@property (nonatomic, readonly) UIViewAnimationCurve keyboardAnimationCurve;

/**
 *  A collection of observers to be notified of changes to the keyboard state.
 */
@property (nonatomic, readonly, nonnull) RBObserverCollection *keyboardObservers;

/**
 *  Returns the frame in the view where the keyboard intersects with the view.
 *
 *  @param view The view to use as the local coordinate system.
 *
 *  @return The resulting `CGRect` value.
 */
- (CGRect)keyboardIntersectionWithView:(nonnull UIView *)view;

/**
 *  Returns the insets that would be required in the given view to avoid the keyboard.
 *
 *  @param view The view to use as the local coordinate system.
 *
 *  @return The resulting `CGRect` value.
 */
- (UIEdgeInsets)keyboardInsetsWithView:(nonnull UIView *)view;

@end
