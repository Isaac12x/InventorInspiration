//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormItemSchema.h"

/**
 *  A managed `RBImageView` form item schema.
 */
@interface RBManagedFormImageSchema : RBManagedFormItemSchema

/**
 *  The image to display.
 */
@property (nonatomic, nullable) UIImage *image;

/**
 *  The content mode of the image. Default = `UIViewContentModeScaleToFill`.
 */
@property (nonatomic) UIViewContentMode contentMode;

@end
