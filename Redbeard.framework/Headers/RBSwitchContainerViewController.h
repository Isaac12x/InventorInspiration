//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  A container of view controllers that can be switched.
 */
@interface RBSwitchContainerViewController : UIViewController

/**
 *  Gets or sets the currently displayed view controller, or `nil` if no view controller is currently displayed.
 */
@property (nonatomic, nullable) UIViewController *currentViewController;

/**
 *  The number of view controllers in the container.
 */
@property (nonatomic, readonly) NSUInteger viewControllerCount;

/**
 *  Gets the child view controller at the given index.
 *
 *  @param index The index of the child view controller.
 *
 *  @return The retrieved child view controller.
 */
- (nonnull UIViewController *)viewControllerAtIndex:(NSUInteger)index;

/**
 *  Add a new child view controller to the container.
 *
 *  @param viewController The child view controller.
 */
- (void)addViewController:(nonnull UIViewController *)viewController;

/**
 *  Remove the child view controller.
 *
 *  @param viewController The child view controller.
 */
- (void)removeViewController:(nonnull UIViewController *)viewController;

@end
