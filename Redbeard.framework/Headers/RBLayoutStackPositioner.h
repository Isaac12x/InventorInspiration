//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBLayoutPositioner.h>

/**
 *  Provides stack positioning with alignment in a given orientation.
 */
@interface RBLayoutStackPositioner : RBLayoutPositioner

/**
 *  The orientation in which the cells should be positioned. Default = `RBOrientationVertical`.
 */
@property (nonatomic) RBOrientation orientation;

/**
 *  The vertical alignment of the cells. Default = `RBVerticalAlignmentMiddle`.
 */
@property (nonatomic) RBVerticalAlignment verticalAlignment;

/**
 *  The horizontal alignment of the cells. Default = `RBHorizontalAlignmentCenter`.
 */
@property (nonatomic) RBHorizontalAlignment horizontalAlignment;

/**
 *  Whether or not cells should fill the available width. Default = NO.
 */
@property (nonatomic) BOOL shouldFillWidth;

/**
 *  Whether or not cells should fill the available height. Default = NO.
 */
@property (nonatomic) BOOL shouldFillHeight;

@end
