//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"

/**
 *  A managed `RBRatingField` field schema.
 */
@interface RBManagedFormRatingFieldSchema : RBManagedFormFieldSchema

/**
 *  Gets or sets the maximum rating. Default = 5. Must be > 0.
 */
@property (nonatomic) NSInteger maximumRating;

/**
 *  Whether or not the rating field is currently enabled and will accept user interaction.  Default = `YES`.
 */
@property (nonatomic) BOOL enabled;

/**
 *  Whether or not zero selection is allowed.  Default = `NO`.
 */
@property (nonatomic) BOOL zeroSelection;

@end
