//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBNavigationController.h>
#import <Redbeard/RBSidebarContainerViewController.h>
#import <Redbeard/RBPaneContainerViewController.h>

/**
 *  Provides access to parent view controllers of interest.
 */
@interface UIViewControllerParentCollection : NSObject

/**
 *  Initializes the collection with the given view controller.
 *
 *  @param viewController The subject view controller to provide parental access for.
 *
 *  @return The initialized collection object.
 */
- (nonnull instancetype)initWithViewController:(nonnull UIViewController *)viewController;

/**
 *  The closest parent navigation controller in the view controller heirarchy, or `nil` if there none exist.
 */
@property (nonatomic, readonly, nullable) RBNavigationController *navigationController;

/**
 *  The closest parent sidebar container in the view controller heirarchy, or `nil` if there none exist.
 */
@property (nonatomic, readonly, nullable) RBSidebarContainerViewController *sidebarContainer;

/**
 *  The closest parent pane container in the view controller heirarchy, or `nil` if there none exist.
 */
@property (nonatomic, readonly, nullable) RBPaneContainerViewController *paneContainer;

@end
