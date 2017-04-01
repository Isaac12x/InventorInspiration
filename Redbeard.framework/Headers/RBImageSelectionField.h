//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Redbeard/RBImageSelectionFieldItem.h>

/**
 *  Describes how to size `RBImageSelectionFieldItem`s.
 */
typedef NS_ENUM(NSInteger, RBImageSelectionFieldItemSizeMode)
{
    /**
     *  Indicates that the `itemSize` property should be used to allocate the size of items.
     */
    RBImageSelectionFieldItemSizeModeSize,
    
    /**
     *  Indicates that the size of each item should match the `RBImageSelectionFieldItem` itself. In this case the `itemSize` is ignored.
     */
    RBImageSelectionFieldItemSizeModeFill,
    
    /**
     *  Indicates that the vertical size of each item should be obtained from the height applied to the `RBImageSelectionFieldItem` itself. In this case the height `itemSize` component is ignored and only the width is used.
     */
    RBImageSelectionFieldItemSizeModeFillVertical,
    
    /**
     *  Indicates that the horizontal size of each item should be obtained from the width applied to the `RBImageSelectionFieldItem` itself. In this case the width `itemSize` component is ignored and only the height is used.
     */
    RBImageSelectionFieldItemSizeModeFillHorizontal
};

@protocol RBImageSelectionFieldDelegate;

/**
 *  An image selection field.
 */
@interface RBImageSelectionField : UIView

/**
 *  A delegate to receive image selection field events.
 */
@property (nonatomic, weak, nullable) id<RBImageSelectionFieldDelegate> delegate;

/**
 *  The size of image item cells. Default = `150, 150`.
 */
@property (nonatomic) CGSize itemSize;

/**
 *  The sizing moode of items. Default = `RBImageSelectionFieldItemSizeModeSize`.
 */
@property (nonatomic) RBImageSelectionFieldItemSizeMode itemSizeMode;

/**
 *  Whether or not selection is allowed. Setting this to `NO` is useful if you just want to display a set of images.  Default = `YES`.
 */
@property (nonatomic) BOOL allowsSelection;

/**
 *  Whether or not multiple selection is allowed. Default = `NO`.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 *  Whether or not zero selection is allowed.  Default = `YES`.
 */
@property (nonatomic) BOOL zeroSelectionAllowed;

/**
 *  An optional image that should be displayed if a failure occurs loading images.
 */
@property (nonatomic, nullable) UIImage *failureImage;

/**
 *  The content mode of the failure image.
 */
@property (nonatomic) UIViewContentMode failureImageContentMode;

/**
 *  The optional image overlay when selected.
 */
@property (nonatomic, nullable) UIImage *selectedOverlayImage;

/**
 *  The content mode of the selected overlay image.
 */
@property (nonatomic) UIViewContentMode selectedOverlayImageContentMode;

/**
 *  The default image to be used when an image is being downloaded.
 */
@property (nonatomic, nullable) UIImage *loadingImage;

/**
 *  The content mode of the loading image.
 */
@property (nonatomic) UIViewContentMode loadingImageContentMode;

/**
 *  Whether or not paging is enabled. This means the underlying scroll view stops on multiples of the scroll view’s bounds.  Default = `NO`.
 */
@property (nonatomic) BOOL pagingEnabled;

/**
 *  Whether or not to show vertical scroll indicators.  Default = `YES`.
 */
@property (nonatomic) BOOL showsVerticalScrollIndicator;

/**
 *  Whether or not to show horizontal scroll indicators.  Default = `YES`.
 */
@property (nonatomic) BOOL showsHorizontalScrollIndicator;

/**
 *  An array of `RBImageSelectionFieldItem` objects.
 */
@property (nonatomic, nullable) NSArray<RBImageSelectionFieldItem *> *items;

/**
 *  The selected items by index.
 */
@property (nonatomic, readonly, nullable) NSArray<NSNumber *> *selectedIndexes;

/**
 *  The layout positioner used. You may theme this positioner. Default values =
 *  spacing = 10,
 *  dimensions = 1,
 *  margin = [0, 0, 0, 0],
 *  orientation = `RBOrientationHorizontal`,
 *  sizing = `RBLayoutGridPositionerSizeToSize`.
 */
@property (nonatomic, nonnull, readonly) RBLayoutGridPositioner *positioner;

/**
 *  Updates the selection state of the image at the given index.
 *
 *  @param selected  Whether or not the image item should be selected.
 *  @param index    The index of the image item to update the selection state of.
 */
- (void)setSelected:(BOOL)selected at:(NSInteger)index;

/**
 *  Unselects all image items.
 */
- (void)unselectAllItems;

/**
 *  The default layout positioner used. You may theme this positioner. Default = `RBLayoutGridPositioner` with values
 *  spacing = 0,
 *  dimensions = 1,
 *  margin = [0, 0, 0, 0],
 *  orientation = `RBOrientationVertical`,
 *  sizing = `RBLayoutGridPositionerSizeToSize`.
 *
 *  @return The default positioner.
 */
+ (nonnull RBLayoutPositioner *)defaultPositioner;

@end

/**
 *  A delegate to receive image selection field events for an `RBImageSelectionField` object.
 */
@protocol RBImageSelectionFieldDelegate <NSObject>

@optional

/**
 *  Called when an image item was selected.
 *
 *  @param imageSelectionField  The `RBImageSelectionField` object.
 *  @param index                The index of the image item that was selected.
 */
- (void)imageSelectionField:(nonnull RBImageSelectionField *)imageSelectionField didSelectItemAt:(NSInteger)index;

/**
 *  Called when an image item was unselected.
 *
 *  @param imageSelectionField  The `RBImageSelectionField` object.
 *  @param index                The index of the image item that was unselected.
 */
- (void)imageSelectionField:(nonnull RBImageSelectionField *)imageSelectionField didDeselectItemAt:(NSInteger)index;

@end
