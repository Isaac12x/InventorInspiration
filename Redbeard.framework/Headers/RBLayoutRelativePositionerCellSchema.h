//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Describes the relative layout to apply to a view. Provides a FLUENT API interface to allow chaining.
 */
@interface RBLayoutRelativePositionerCellSchema : NSObject

/**
 *  Internally used identifier.
 */
@property (nonatomic, nonnull, readonly) NSString *identifier;

/**
 *  The `UIView` that is to be layed out.
 */
@property (nonatomic, nonnull, readonly) UIView *view;

/**
 *  Whether or not to use edge and relative alignments. Default = `YES`. If set to yes the the properties
 *  anchorToEdges, toTopOf, toTopEdgeOf, toLeftOf, toLeftEdgeOf, toBottomOf, toBottomEdgeOf, toRightOf, toRightEdgeOf
 *  are made use of. If this is `NO` then the verticalAlignment and horizontalAlignment properties only are used to layout the view.
 */
@property (nonatomic) BOOL useEdgeAndRelativeAlignment; // Default = `YES`.

/**
 *  Whether or not to assume the width of the view to be zero if the views `hidden` property is set.
 *  If this is `YES` instead of using the initial width size of the view as obtained from `sizeThatFits` 
 *  or `useExplicitSize` a size of 0 will be used instead. Default = `NO`.
 *  Note if this is set width paddings and margins will not be applied.
 */
@property (nonatomic) BOOL sizeWidthToZeroIfHidden;

/**
 *  Whether or not to assume the width of the view to be zero if the views `hidden` property is set.
 *  If this is `YES` instead of using the initial width size of the view as obtained from `sizeThatFits`
 *  or `useExplicitSize` a size of 0 will be used instead. Default = `NO`.
 *  Note if this is set width paddings and margins will not be applied.
 */
@property (nonatomic) BOOL sizeHeightToZeroIfHidden;

/**
 *  The explicit non-empty size to use for the initial view size instead of the size obtained via `sizeThatFits`.
 *  If both a non-zero width and height are provided both values will be used. If only a single non-zero value is
 *  provided e.g. the width only the height will be set to that obtained via `sizeThatFits`. Default = CGSizeZero.
 */
@property (nonatomic) CGSize useExplicitSize;

/**
 *  The `UIView` above which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toTopOf;

/**
 *  The `UIView` above which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toTopEdgeOf;

/**
 *  The `UIView` to the left of which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toLeftOf;

/**
 *  The `UIView` to the left of which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toLeftEdgeOf;

/**
 *  The `UIView` below which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toBottomOf;

/**
 *  The `UIView` below which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toBottomEdgeOf;

/**
 *  The `UIView` to the right of which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toRightOf;

/**
 *  The `UIView` to the right of which the view should be arranged.
 */
@property (nonatomic, nullable) UIView *toRightEdgeOf;

/**
 *  The `UIView` to the center of which the view should be arranged. If set then toTop* and toBottom* are ignored.
 */
@property (nonatomic, nullable) UIView *toVerticalCenterOf;

/**
 *  The `UIView` to the center of which the view should be arranged. If set then toRight* and toLeft* are ignored.
 */
@property (nonatomic, nullable) UIView *toHorizontalCenterOf;

/**
 *  Attempts to set the width of the view to match width of the reference view * widthMultiplier.
 *  Note you may reference `self`. Useful for exmaple if you would like to have the width match the height of the view.
 */
@property (nonatomic, nullable) UIView *widthOf;

/**
 *  The multipler to use in conjunction with the widthOf property. Default = `1.0`.
 */
@property (nonatomic) CGFloat widthOfMultiplier;

/**
 *  Indicates that the width of the view pointed to be `widthOf` should be used. If this is `NO` then the height will be used. Default = `YES`.
 */
@property (nonatomic) BOOL widthOfUseWidth;

/**
 *  The multipler to use in conjunction with the heightOf property. Default = `1.0`.
 */
@property (nonatomic) CGFloat heightOfMultiplier;

/**
 *  Indicates that the height of the view pointed to be `heightOf` should be used. If this is `NO` then the width will be used. Default = `YES`.
 */
@property (nonatomic) BOOL heightOfUseHeight;

/**
 *  Attempts to set the height of the view to match height of the reference view * heightMultiplier.
 *  Note you may reference `self`. Useful for exmaple if you would like to have the height match the width of the view.
 */
@property (nonatomic, nullable) UIView *heightOf;

/**
 *  The sides of the view that should be anchored to the parent container view. Note this takes precedant over any `to*Of` assignments. Used when `useEdgeAndRelativeAlignment` = YES.
 */
@property (nonatomic) UIRectEdge anchorToEdges;

/**
 *  Where to place the view vertically. Used only when `useEdgeAndRelativeAlignment` = NO.
 */
@property (nonatomic) RBVerticalAlignment verticalAlignment;

/**
 *  Where to place the view horizontally. Used only when `useEdgeAndRelativeAlignment` = NO.
 */
@property (nonatomic) RBHorizontalAlignment horizontalAlignment;

/**
 *  The margin around the view. Has the effect of decreasing the size of the contents.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The margin to be applied after taking into account the properties that have been applied
 *  e.g. sizeWidthToZeroIfHidden. This is used for internal calculations.
 */
@property (nonatomic, readonly) UIEdgeInsets effectiveMargin;

/**
 *  The padding that should be added around the view bounds.
 *  Should contain positive values only. 
 *  Important views are laid out against other views with padding taken into account.
 */
@property (nonatomic) UIEdgeInsets padding;

/**
 *  The padding to be applied after taking into account the properties that have been applied 
 *  e.g. sizeWidthToZeroIfHidden. This is used for internal calculations.
 */
@property (nonatomic, readonly) UIEdgeInsets effectivePadding;

/**
 *  Creates a new `RBLayoutRelativePositionerCellSchema` using the supplied view.
 *
 *  @param view       The view.
 *
 *  @return The created schema.
 */
+ (nonnull instancetype)withView:(nonnull UIView *)view;

/**
 *  Initializes a new `RBLayoutRelativePositionerCellSchema` using the supplied view.
 *
 *  @param view       The view.
 *
 *  @return The initialized schema.
 */
- (nonnull instancetype)initWithView:(nonnull UIView *)view;

#pragma mark -
#pragma mark - Options

/**
 *  Sets the type of layout to use.
 *
 *  @param useEdgeAndRelativeAlignment       Whether or not to use edge and relative layout or to use normal horizontal/vertical alignment only.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)useEdgeAndRelativeAlignment:(BOOL)useEdgeAndRelativeAlignment;

/**
 *  Indicates that the width of the view should be set to zero if the view is hidden.
 *
 *  @param sizeWidthToZeroIfHidden       Wheter or not to set the view width to zero if it's hidden.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)sizeWidthToZeroIfHidden:(BOOL)sizeWidthToZeroIfHidden;

/**
 *  Indicates that the height of the view should be set to zero if the view is hidden.
 *
 *  @param sizeHeightToZeroIfHidden       Wheter or not to set the view height to zero if it's hidden.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)sizeHeightToZeroIfHidden:(BOOL)sizeHeightToZeroIfHidden;

/**
 *  Sets a specific size to be used for the view (ignoring any value that the view itself may determine).
 *
 *  @param useExplicitSize       The size to use.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)useExplicitSize:(CGSize)useExplicitSize;

#pragma mark -
#pragma mark - Align to edges

/**
 *  Anchors the views sides to the edges of its container view.
 *
 *  @param anchorToEdges       The edges to which the view should be anchored.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)anchorToEdges:(UIRectEdge)anchorToEdges;

#pragma mark -
#pragma mark - to XYZ Of

/**
 *  Arranges the view to the top of the view that has been provided.
 *
 *  @param toTopOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toTopOf:(nullable UIView *)toTopOf;

/**
 *  Arranges the view to the left of the view that has been provided.
 *
 *  @param toLeftOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toLeftOf:(nullable UIView *)toLeftOf;

/**
 *  Arranges the view to the bottom of the view that has been provided.
 *
 *  @param toBottomOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toBottomOf:(nullable UIView *)toBottomOf;

/**
 *  Arranges the view to the right of the view that has been provided.
 *
 *  @param toRightOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toRightOf:(nullable UIView *)toRightOf;

#pragma mark -
#pragma mark - to XYZ edge Of

/**
 *  Arranges the view to the top edge of the view that has been provided.
 *
 *  @param toTopEdgeOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toTopEdgeOf:(nullable UIView *)toTopEdgeOf;

/**
 *  Arranges the view to the left edge of the view that has been provided.
 *
 *  @param toLeftEdgeOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toLeftEdgeOf:(nullable UIView *)toLeftEdgeOf;

/**
 *  Arranges the view to the bottom edge of the view that has been provided.
 *
 *  @param toBottomEdgeOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toBottomEdgeOf:(nullable UIView *)toBottomEdgeOf;

/**
 *  Arranges the view to the right edge of the view that has been provided.
 *
 *  @param toRightEdgeOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toRightEdgeOf:(nullable UIView *)toRightEdgeOf;

#pragma mark -
#pragma mark - to center Of

/**
 *  Arranges the view vertically centered to the view that has been provided.
 *
 *  @param toVerticalCenterOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toVerticalCenterOf:(nullable UIView *)toVerticalCenterOf;

/**
 *  Arranges the view horizontally centered to the view that has been provided.
 *
 *  @param toHorizontalCenterOf       The view to arrange around.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)toHorizontalCenterOf:(nullable UIView *)toHorizontalCenterOf;

#pragma mark -
#pragma mark - Width Of

/**
 *  Sets the width of the view to equal that of the view that has been provided.
 *
 *  @param widthOf       The view to size against.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)widthOf:(nullable UIView *)widthOf;

/**
 *  Multiplies the width of the view by the amount specified.
 *
 *  @param widthOfMultiplier       The multiplier.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)widthOfMultiplier:(CGFloat)widthOfMultiplier;

/**
 *  Used in conjuction with the method `widthOf`. Indicates that the width should equal the width or height of the view 
 *  that has been set by `widthOf`.
 *
 *  @param widthOfUseWidth       Use the width (`YES) or height (`NO`) of the view pointed to by `widthOf`.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)widthOfUseWidth:(BOOL)widthOfUseWidth;

#pragma mark -
#pragma mark - Height Of

/**
 *  Sets the height of the view to equal that of the view that has been provided.
 *
 *  @param heightOf       The view to size against.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)heightOf:(nullable UIView *)heightOf;

/**
 *  Multiplies the height of the view by the amount specified.
 *
 *  @param heightOfMultiplier       The multiplier.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)heightOfMultiplier:(CGFloat)heightOfMultiplier;

/**
 *  Used in conjuction with the method `heightOf`. Indicates that the height should equal the width or height of the view
 *  that has been set by `heightOf`.
 *
 *  @param heightOfUseHeight       Use the height (`YES) or width (`NO`) of the view pointed to by `heightOf`.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)heightOfUseHeight:(BOOL)heightOfUseHeight;

#pragma mark -
#pragma mark - Padding & Margin

/**
 *  The padding to apply around the view (should not contain values < 0). Will increase the size of the view.
 *  The padding is added at the end of the layout calculation meaning it has not been added to the size of the 
 *  cell during arrangments and sizing.
 *
 *  @param padding       The padding.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)padding:(UIEdgeInsets)padding;

/**
 *  The margin to apply around the view (should not contain values < 0). Will decrease the size of the view.
 *  The margin is added at the end of the layout calculation meaning it has not been added to the size of the
 *  cell during arrangments and sizing.
 *
 *  @param margin       The margin.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)margin:(UIEdgeInsets)margin;

#pragma mark -
#pragma mark - Vertical/Horizontal alignments

/**
 *  Arranges the view horizontally within the parent view.
 *
 *  @param horizontalAlignment       The horizontal alignment.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)horizontalAlignment:(RBHorizontalAlignment)horizontalAlignment;

/**
 *  Arranges the view vertically within the parent view.
 *
 *  @param verticalAlignment       The vertical alignment.
 *
 *  @return The cell schema to allow joining method calls.
 */
- (nonnull instancetype)verticalAlignment:(RBVerticalAlignment)verticalAlignment;

@end
