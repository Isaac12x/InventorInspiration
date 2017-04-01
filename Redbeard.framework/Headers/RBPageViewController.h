//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBPageHeaderViewController.h>

/**
 *  A page view controller with a header (optional).
 */
@interface RBPageViewController : UIViewController

/**
 *  The header to display within the page.
 */
@property (nonatomic, nullable) RBPageHeaderViewController *header;

/**
 *  Whether or not the page header is hidden or not (can be animated).
 */
@property (nonatomic) BOOL headerIsHidden;

@end
