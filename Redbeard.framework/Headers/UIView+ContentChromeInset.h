//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  `UIView` content chrome insets transmission and events.
 *
 *  The content chrome insets are the content inset that must be used to avoid
 *  overarching chrome such as toolbars.
 */
@interface UIView (ContentChromeInset)

/**
 * The insets to be used when laying out content to avoid any overlapping
 * chrome from the parent view(s).
 */
@property (nonatomic) UIEdgeInsets contentChromeInset;

/**
 * Whether the view should inherit its `contentChromeInset` value from
 * the parent on layout.  The default value is true.
 */
@property (nonatomic) BOOL shouldAutomaticallyReceiveContentChromeInsetFromSuperview;

/**
 * Whether the view should automatically set the `contentChromeInset` values
 * of it's subviews on layoutSubviews.
 */
@property (nonatomic) BOOL shouldAutomaticallyForwardContentChromeInsetsForSubviews;

/**
 * The bounds available for content after having applied the `contentChromeInset`.
 */
@property (nonatomic, readonly) CGRect contentBounds;

#pragma mark -
#pragma mark Subclassing

/**
 *  Calculates the content chrome insets for a subview.
 *
 *  @param subview The subview to calculate the content chrome insets for.
 *
 *  @return The calculated content chrome insets.
 */
- (UIEdgeInsets)contentChromeInsetForSubview:(nullable UIView *)subview;

/**
 *  Called when the content chrome insets are changed.
 *
 *  @param contentChromeInset     The prevous content chrome insets.
 *  @param fromContentChromeInset The new and current content chrome insets.
 */
- (void)contentChromeInsetDidChangeTo:(UIEdgeInsets)contentChromeInset fromInset:(UIEdgeInsets)fromContentChromeInset;

@end
