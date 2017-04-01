//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"

/**
 *  A managed `RBPhotoField` form field schema.
 */
@interface RBManagedFormPhotoFieldSchema : RBManagedFormFieldSchema

/**
 *  Whether or not the camera button is to be displayed. Default = `YES`.
 */
@property (nonatomic) BOOL hasCameraButton;

/**
 *  Whether or not the library button is to be displayed. Default = `YES`.
 */
@property (nonatomic) BOOL hasLibraryButton;

/**
 *  Whether or not the imageView should be displayed. Default = `YES`.
 */
@property (nonatomic) BOOL hasImageView;

@end
