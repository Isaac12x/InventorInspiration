//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBBaseCellView.h"

/**
 *  A simple image view cell. Provides an image view that is the size of the cell 
 *  alongside an optional overlay image view.
 */
@interface RBImageCellView : RBBaseCellView

/**
 *  The image view.
 */
@property (nonatomic, readonly, nonnull) RBImageView *imageView;

/**
 *  An image view that maybe used as an overlay.
 */
@property (nonatomic, readonly, nonnull) RBImageView *overlayImageView;

@end
