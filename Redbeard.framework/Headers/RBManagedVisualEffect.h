//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/** The available effect types. */
typedef NS_ENUM(NSInteger, RBVisualEffectType)
{
    /** No visual effect. */
    RBVisualEffectTypeNone,
    
    /** A darkening blur visual effect. */
    RBVisualEffectTypeBlurDark,
    
    /** A darkening blur visual effect with vibrancy. */
    RBVisualEffectTypeBlurDarkWithVibrancy,
    
    /** A lightening blur visual effect. */
    RBVisualEffectTypeBlurLight,
    
    /** A lightening blur visual effect with vibrancy. */
    RBVisualEffectTypeBlurLightWithVibrancy,
    
    /** An extra-lightening blur visual effect. */
    RBVisualEffectTypeBlurExtraLight,
    
    /** An extra-lightening blur visual effect with vibrancy. */
    RBVisualEffectTypeBlurExtraLightWithVibrancy
};

/**
 *  Provides an easy method to wrap a UIView within a UIVisualEffectView with blur and vibrancy effects.
 */
@interface RBManagedVisualEffect : NSObject

/**
 *  The main view.
 */
@property (nonatomic, readonly, nonnull) UIView *view;

/**
 *  The parent view that should contain the managed view.
 */
@property (nonatomic, readonly, nonnull) UIView *parentView;

/**
 *  The effect type.
 */
@property (nonatomic) RBVisualEffectType effectType;

/**
 *  The managed view. Depending on the `RBVisualEffectType` this will either be the `view` (if effectType = RBVisualEffectTypeNone)
 *  or a `UIVisualEffectView`.
 */
@property (nonatomic, readonly, nonnull) UIView *managedView;


/**
 *  The `UIVisualEffectView` if an effect has been applied.
 */
@property (nonatomic, readonly, nullable) UIVisualEffectView *visualEffectView;

/**
 *  The `UIVisualEffectView` that corresponds to the `UIVibrancyEffect` if a effectType with vibrancy has been applied.
 */
@property (nonatomic, readonly, nullable) UIVisualEffectView *vibrancyEffectView;

/**
 *  Initializes a new `RBManagedVisualEffect` object.
 *
 *  @param view             The `UIView` that effects should be applied to.
 *  @param parentView       The parent `UIView` container that the view or the managed `UIVisualEffectView`s should be added to.
 *  @param effectType       The effect type.
 *
 *  @return A newly initialized `RBManagedVisualEffect` object.
 */
- (nonnull instancetype)initWithView:(nonnull UIView *)view
                          parentView:(nonnull UIView *)parentView
                          effectType:(RBVisualEffectType)effectType;

/**
 *  Sets the `managedView` frame to the given frame. If an effectType is applied the underlying `UIVisualEffectView`s as well 
 *  as the main view will be adjusted to match the frame size.
 *
 *  @param frame    The frame to use.
 */
- (void)layoutWithFrame:(CGRect)frame;

@end
