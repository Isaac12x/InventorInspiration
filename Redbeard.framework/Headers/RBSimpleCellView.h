//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBBaseCellView.h>
#import <Redbeard/RBLayoutView.h>
#import <Redbeard/RBLabel.h>

/**
 *  A simple label cell which provides a title and detail label as well as an accompanying image view.
 */
@interface RBSimpleCellView : RBBaseCellView

/**
 *  The underlying image view.
 */
@property (nonatomic, readonly, nonnull) RBImageView *imageView;

/**
 *  The underlying layout view for the labels.
 */
@property (nonatomic, readonly, nonnull) RBLayoutView *layoutView;

/**
 *  The underlying title label view.
 */
@property (nonatomic, readonly, nonnull) RBLabel *titleLabel;

/**
 *  The underlying detail label view.
 */
@property (nonatomic, readonly, nonnull) RBLabel *detailLabel;

/**
 *  The margin to provide around the cell content.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The spacing to provide between the image and the labels.
 */
@property (nonatomic) CGFloat spacing;

/**
 *  Whether or not an image is displayed in the cell.
 */
@property (nonatomic) BOOL imageEnabled;

/**
 *  The width of the image in pixels.
 */
@property (nonatomic) CGFloat imageWidth;

/**
 *  The attributed title text to display in the label.
 */
@property (nonatomic, nullable) NSAttributedString *attributedTitle;

/**
 *  The title text to display in the label.
 */
@property (nonatomic, nullable) NSString *title;

/**
 *  The attributed detail text to display in the label.
 */
@property (nonatomic, nullable) NSAttributedString *attributedDetail;

/**
 *  The detail text to display in the label.
 */
@property (nonatomic, nullable) NSString *detail;

@end
