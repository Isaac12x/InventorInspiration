//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  `UIView` positioning methods.
 */
@interface UIView (Positioning)

/**
 *  Sizes and aligns the view within it's parent view's bounds.
 *
 *  @param vp       The vertical alignment to align to.
 *  @param hp       The horizontal alignment to align to.
 *  @param autosize Whether or not to autosize the view.
 */
- (void)moveToVertical:(RBVerticalAlignment)vp
            horizontal:(RBHorizontalAlignment)hp
              autosize:(BOOL)autosize;

/**
 *  Sizes and aligns the view within it's parent view's bounds with a margin.
 *
 *  @param vp       The vertical alignment to align to.
 *  @param hp       The horizontal alignment to align to.
 *  @param autosize Whether or not to autosize the view.
 *  @param margin   The margin to maintain around the view within it's parent view's bounds.
 */
- (void)moveToVertical:(RBVerticalAlignment)vp
            horizontal:(RBHorizontalAlignment)hp
              autosize:(BOOL)autosize
            withMargin:(UIEdgeInsets)margin;

/**
 *  Aligns the view within it's parent view's bounds with the given size.
 *
 *  @param vp   The vertical alignment to align to.
 *  @param hp   The horizontal alignment to align to.
 *  @param size The size of the view.
 */
- (void)moveToVertical:(RBVerticalAlignment)vp
            horizontal:(RBHorizontalAlignment)hp
              withSize:(CGSize)size;

/**
 *  Aligns the view within it's parent view's bounds with the given size and a margin.
 *
 *  @param vp     The vertical alignment to align to.
 *  @param hp     The horizontal alignment to align to.
 *  @param size   The size of the view.
 *  @param margin The margin to maintain around the view within it's parent view's bounds.
 */
- (void)moveToVertical:(RBVerticalAlignment)vp
            horizontal:(RBHorizontalAlignment)hp
              withSize:(CGSize)size
            withMargin:(UIEdgeInsets)margin;

/**
 *  Sizes and aligns the view within the given frame.
 *
 *  @param frame    The frame to position the view inside of.
 *  @param vp       The vertical alignment to align to.
 *  @param hp       The horizontal alignment to align to.
 *  @param autosize Whether or not to autosize the view.
 */
- (void)moveToFrame:(CGRect)frame
           vertical:(RBVerticalAlignment)vp
         horizontal:(RBHorizontalAlignment)hp
           autosize:(BOOL)autosize;

/**
 *  Sizes and aligns the view within the given frame.
 *
 *  @param frame    The frame to position the view inside of.
 *  @param vp       The vertical alignment to align to.
 *  @param hp       The horizontal alignment to align to.
 *  @param autosize Whether or not to autosize the view.
 *  @param margin   The margin to maintain around the view within the given frame.
 */
- (void)moveToFrame:(CGRect)frame
           vertical:(RBVerticalAlignment)vp
         horizontal:(RBHorizontalAlignment)hp
           autosize:(BOOL)autosize
         withMargin:(UIEdgeInsets)margin;

/**
 *  Sizes and aligns the view within the given frame with a size.
 *
 *  @param frame    The frame to position the view inside of.
 *  @param vp       The vertical alignment to align to.
 *  @param hp       The horizontal alignment to align to.
 *  @param size     The size of the view.
 */
- (void)moveToFrame:(CGRect)frame
           vertical:(RBVerticalAlignment)vp
         horizontal:(RBHorizontalAlignment)hp
           withSize:(CGSize)size;

/**
 *  Sizes and aligns the view within the given frame with a size and margin.
 *
 *  @param frame    The frame to position the view inside of.
 *  @param vp       The vertical alignment to align to.
 *  @param hp       The horizontal alignment to align to.
 *  @param size     The size of the view.
 *  @param margin   The margin to maintain around the view within the given frame.
 */
- (void)moveToFrame:(CGRect)frame
           vertical:(RBVerticalAlignment)vp
         horizontal:(RBHorizontalAlignment)hp
           withSize:(CGSize)size
         withMargin:(UIEdgeInsets)margin;

@end
