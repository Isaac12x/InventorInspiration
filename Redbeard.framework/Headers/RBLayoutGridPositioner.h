//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBLayoutPositioner.h>

/** Commonly used sizing methods. */
typedef NS_ENUM(NSInteger, RBLayoutGridPositionerSize)
{
    /** Cells are sized to evenly to fill all available space in the unfixed orientation.
     *  e.g. for vertical orientation, widths will expand to fit available space.
     *  e.g. for horizontal orientation, heights will expand to fit available space. */
    RBLayoutGridPositionerSizeEvenly,
    
    /** Cells are sized according to the size they request. */
    RBLayoutGridPositionerSizeToSize,
    
    /** Cells are sized according to the size they request and spaced evenly in the unfixed orientation.
     *  e.g. for vertical orientation, cells will be spaced evenly across the whole width of the available space.
     *  e.g. for horizontal orientation, cells will be spaced evenly across the whole height of the available space. */
    RBLayoutGridPositionerSizeToSizeSpacedEvenly
};

/**
 *  Provides a simple table grid layout.
 */
@interface RBLayoutGridPositioner : RBLayoutPositioner

/**
 *  The orientation of the grid, and thus how it expands to fit views pushed to it.
 *  e.g. a vertical grid will expand vertically.
 *  Default = `RBOrientationVertical`.
 */
@property (nonatomic) RBOrientation orientation;

/**
 *  The number of rows/columns (depending on orientation), for each row set (repeats).
 *  i.e. [ 2, 3 ] will have a 2, 3, 2, 3, ... repeating number of dimensions. Default = [ 1 ].
 */
@property (nonatomic, nonnull) NSArray<NSNumber *> *dimensions;

/**
 *  The method of sizing child views. Default = `RBLayoutGridPositionerSizeEvenly`.
 */
@property (nonatomic) RBLayoutGridPositionerSize sizing;

@end
