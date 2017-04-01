//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Redbeard/RBThemeSchema.h>
#import <Redbeard/RBThemeTracker.h>

/**
 *  `UIView` theming.
 */
@interface UIView (Theming) <RBThemeTrackerDelegate>

/**
 *  The theming tracker object for the view.
 */
@property (nonatomic, readonly, nonnull) RBThemeTracker *theme;

@end
