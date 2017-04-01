//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBBaseExtendView.h>

/**
 *  Describes the effect to apply.
 */
typedef NS_ENUM(NSInteger, RBBannerExtendViewEffect)
{
    /**
     *  No effect applied.
     */
    RBBannerExtendViewEffectNone = 0,
    
    /**
     *  Blur effect.
     */
    RBBannerExtendViewEffectBlur,
    
    /**
     *  Colourize effect. From black & white - > color.
     */
    RBBannerExtendViewEffectColorize,
};

/**
 *  An extend view that displays an image banner that grows when dragged.
 */
@interface RBBannerExtendView : RBBaseExtendView

/**
 *  The amount of the banner to reveal when it is in the `closed` state. Default = 0.3.
 */
@property (readonly) CGFloat insetRatio;

/**
 *  The direction of the effect. For example if this is `YES` they banner image will go from normal > blurred.
 *  If `NO` the reverse will occur. Default = `YES`.
 */
@property (nonatomic) BOOL effectDirectionOpenToClose;

/**
 *  The effect for the banner. Default = RBBannerExtendViewEffectBlur.
 */
@property (nonatomic) RBBannerExtendViewEffect effect;

/**
 *  The banner image.
 */
@property (nonatomic, nullable) UIImage *bannerImage;

/**
 *  The banner image content mode. Defauilt 
 */
@property (nonatomic) UIViewContentMode bannerImageContentMode;

/**
 *  The image to use to use for the pull to refresh indicator. Default = `[[RBImageCenter shared] glyphImageWithName:@"arrow-down" tintColor:[UIColor darkGrayColor] size:@32]`.
 */
@property (nonatomic, nonnull) UIImage *pullIndicatorImage;

/**
 *  The animator to use when animating the pullIndicatorImage. Default = `[RBAnimator defaultSpringAnimator]`.
 */
@property (nonatomic, nonnull) RBAnimator *pullIndicatorAnimator;

/**
 *  The style of the refresh indicator. Default = `UIActivityIndicatorViewStyleWhite`.
 */
@property (nonatomic) UIActivityIndicatorViewStyle refreshIndicatorViewStyle;

/**
 *  Whether or not to allow the extend view to be set to the `opened` state. In effect allow pull to refresh functionality. Default = `YES`.
 *  If you would just like a banner set this to `NO`.
 */
@property (nonatomic) BOOL allowOpening;

/**
 *  Creates a new `RBBannerExtendView` with the given inset ratio.
 *  Banners are sized to equal the size of the `RBScrollView` they are attached to. Note this includes core subclasses such as
 *  RBLazyLayoutView, RBLayoutView, RBManagedFormView...
 *  The inset ratio determines how much of the banner to reveal by default as a 0 - 1 percentage.
 *  By default the `openRevealFactor` is set to equal 0.3.
 *
 *  @param insetRatio   The inset ratio. (0 - 1).
 *
 *  @return The newly initialized `RBBannerExtendView`.
 */
- (nonnull instancetype)initWithInsetRatio:(CGFloat)insetRatio;

#pragma mark -
#pragma mark Subclassing

/**
 *  For subclasses implement this method to modify the banners UI. This is called automatically on changes.
 *  All changes and updates should occur here rather than in `layoutSubviews`.
 */
- (void)performLayout;

@end
