//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Redbeard/UIView+Redbeard.h>

#import <Redbeard/RBThemeTracker.h>

/**
 *  `UIViewController` theming.
 */
@interface UIViewController (Theming) <RBThemeTrackerDelegate>

/**
 *  The theming tracker object for the view controller.
 */
@property (nonatomic, readonly, nonnull) RBThemeTracker *theme;

@end
