//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBLayoutPositioner.h"

/**
 *  Provides a vertically scrolling table grid layout with columns
 *  of given width percentages.
 */
@interface RBLayoutColumnPercentagePositioner : RBLayoutPositioner

/**
 *  An array of column width percentages.  These specifies how many columns
 *  will be used in the layout and how their widths will be allocated. Default = [ 1 ].
 */
@property (nonatomic) NSArray<NSNumber *> *columnPercentages; // [ 0.2, 0.2, 0.6 ]

/**
 *  Whether or not cells should fit to their total available width (in the column). Default = YES.
 */
@property (nonatomic) BOOL fitToWidth;

@end
