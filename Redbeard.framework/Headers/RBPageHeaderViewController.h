//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBPageHeaderItem.h>

@class RBPageViewController;

/**
 *  A customisable page header.
 */
@interface RBPageHeaderViewController : UIViewController

/**
 *  The `RBPageViewController` that the header belongs to.
 */
@property (nonatomic, weak, readonly, nullable) RBPageViewController *pageViewController;

/**
 *  The items to display on the header.
 */
@property (nonatomic, nullable) NSArray<RBPageHeaderItem *> *items; // RBPageHeaderItem

/**
 *  The margin to apply around the items in the header.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The spacing to apply between the items in the header.
 */
@property (nonatomic) CGFloat spacing;

/**
 *  The size that the header requires within the given page size.
 *
 *  @param pageSize The size of the page that the header will be displayed in.
 *
 *  @return The size that the header requires.
 */
- (CGSize)headerSizeWithPageSize:(CGSize)pageSize;

@end
