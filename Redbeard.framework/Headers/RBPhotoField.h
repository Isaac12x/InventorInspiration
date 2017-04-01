//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RBPhotoFieldDelegate;

/**
 *  An image selection form field.
 */
@interface RBPhotoField : UIControl

/**
 *  The placeholder image to display when there is no image selected.
 */
@property (nonatomic, nullable) UIImage *emptyImage;

/**
 *  The margin to display around the placeholder image.
 */
@property (nonatomic) UIEdgeInsets emptyImageMargin;

/**
 *  The margin to display around the buttons.
 */
@property (nonatomic) UIEdgeInsets buttonMargins;

/**
 *  The spacing between buttons.
 */
@property (nonatomic) float buttonSpacing;

/**
 *  The current value of the image field.
 */
@property (nonatomic, nullable) UIImage *currentValue;

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

/**
 *  The delegate to receive image selection events.
 */
@property (nonatomic, weak, nullable) id<RBPhotoFieldDelegate> delegate;

@end

/**
 *  The delegate to receive image selection events from a `RBImageField` object.
 */
@protocol RBPhotoFieldDelegate <NSObject>

@required

/**
 *  Called when the camera button is selected by the image field.
 *
 *  @param photoField The image field object.
 */
- (void)cameraSelectedWithPhotoField:(nonnull RBPhotoField *)photoField;

/**
 *  Called when the image library button is selected by the image field.
 *
 *  @param photoField The image field object.
 */
- (void)librarySelectedWithPhotoField:(nonnull RBPhotoField *)photoField;

@end
