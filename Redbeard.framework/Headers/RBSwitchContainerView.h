//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  A container of views that can be switched.
 */
@interface RBSwitchContainerView : UIView

/**
 *  Gets or sets the currently displayed view, or `nil` if no view is currently displayed.
 */
@property (nonatomic, nullable) UIView *currentView;

/**
 *  The number of views in the container.
 */
@property (nonatomic, readonly) NSUInteger viewCount;

/**
 *  Gets the child view at the given index.
 *
 *  @param index The index of the child view.
 *
 *  @return The retrieved child view.
 */
- (nonnull UIView *)viewAtIndex:(NSUInteger)index;

/**
 *  Add a new child view to the container.
 *
 *  @param view The child view.
 */
- (void)addView:(nonnull UIView *)view;

/**
 *  Remove the child view.
 *
 *  @param view The child view.
 */
- (void)removeView:(nonnull UIView *)view;

@end
