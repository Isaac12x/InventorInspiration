//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBBaseCellView.h>

/**
 *  A simple cell that provides a label and image much like a button.
 */
@interface RBButtonCellView : RBBaseCellView

/**
 *  The label.
 */
@property (nonatomic, readonly, nonnull) RBLabel *titleLabel;

/**
 *  The image.
 */
@property (nonatomic, readonly, nonnull) RBImageView *imageView;

/**
 * Whether or not the image and title should be vertically or horizontally arranged.
 * Default = `RBOrientationHorizontal`.
 */
@property (nonatomic) RBOrientation orientation;

/**
 * Whether or not the title should be before the image. Default = `NO`.
 */
@property (nonatomic) BOOL titleFirst;

/**
 * The spacing to use between the label and the image. This has the effect of increasing
 * the size of the button in the direction set via the `orientation` property. Default = `0`.
 */
@property (nonatomic) CGFloat spacing;

/**
 * The image to on the imageView.
 */
@property (nonatomic, nullable) UIImage *image;

/**
 * The title to set on the titleLabel.
 */
@property (nonatomic, nullable) NSString *title;

@end
