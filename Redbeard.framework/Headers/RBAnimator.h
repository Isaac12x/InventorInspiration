//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBThemeTracker.h>

/**
 *  Performs animations with a given configuration.
 */
@interface RBAnimator : NSObject<NSCopying, RBThemeTrackerDelegate>

/**
 *  The theme tracker object. Use this to add further theme changes, apply and re-apply themes.
 */
@property (nonatomic, readonly, nonnull) RBThemeTracker *theme;

/**
 *  The duration of the animation in seconds.
 */
@property CGFloat duration;

/**
 *  The delay before beginning the animation in seconds.
 */
@property CGFloat delay;

// If zero, no spring used.

/**
 *  The velocity of the spring animation.  0 = no spring
 */
@property CGFloat springVelocity;

/**
 *  The dampening of the spring animation, determining how quickly the initial force subsides.
 */
@property CGFloat springDampening;

/**
 *  The curve of the animation.
 */
@property UIViewAnimationCurve curve;

/**
 *  The animation options.
 */
@property UIViewAnimationOptions options;

/**
 *  Creates an animator configured with the default settings.
 *
 *  @return The new animator object.
 */
+ (nonnull instancetype)defaultAnimator;

/**
 *  Creates an animator configured with the default spring animation settings.
 *
 *  @return The new animator object.
 */
+ (nonnull instancetype)defaultSpringAnimator;

/**
 *  Creates an animator configured to mimick the keyboard transition animation.
 *
 *  @return The new animator object.
 */
+ (nonnull instancetype)defaultKeyboardAnimator;

/**
 *  Perform the given changes with an animation.
 *
 *  @param animated   Whether or not the changes should be animated.
 *  @param changes    The changes block that will be called to make the UI changes. viewsToLayout should contain the list of the `UIViews` to animate.
 *  @param completion An optional block to be called when the animation has completed.
 */
- (void)performWithAnimation:(BOOL)animated
                     changes:(nonnull void (^)(NSArray<__kindof UIView *> * __nullable * __nullable viewsToLayout))changes
                  completion:(nullable dispatch_block_t)completion;

/**
 *  Enqueues a block to be executed after all currently queued animations are complete.
 *
 *  @param actionBlock The block to execute.
 */
- (void)performAfterAnimations:(nonnull dispatch_block_t)actionBlock;

@end
