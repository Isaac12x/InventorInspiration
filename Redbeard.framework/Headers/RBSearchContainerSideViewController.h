//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBSearchContainerViewController.h>

/**
 *  A search container view controller that expands as a sidebar of an `RBSidebarContainerView`.
 */
@interface RBSearchContainerSideViewController : RBSearchContainerViewController

/**
 *  Whether or not the sidebar should expand when search is activated.
 */
@property (nonatomic) BOOL shouldExpandForSearch;

@end
