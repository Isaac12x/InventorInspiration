//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  A page indication control.
 *
 *  Provides more theming options than `UIPageControl` but does not provide user interaction.
 */
@interface RBPageControl : UIView

/**
 *  Whether or not the control is enabled or disabled.
 */
@property (nonatomic) BOOL enabled;

/**
 *  The margin to be provided around the dots.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The total number of pages.
 */
@property (nonatomic) NSUInteger numberOfPages;

/**
 *  The current page index that is selected.
 */
@property (nonatomic) NSUInteger currentPage;

/**
 *  The diameter of the dots in pt.
 */
@property (nonatomic) CGFloat dotDiameter;

/**
 *  The spacing between dots in pt.
 */
@property (nonatomic) CGFloat dotSpacing;

/**
 *  The color of the current page dot.
 */
@property (nonatomic, nonnull) UIColor *dotColorCurrentPage;

/**
 *  The color of an inactive page dot.
 */
@property (nonatomic, nonnull) UIColor *dotColorOtherPage;

@end
