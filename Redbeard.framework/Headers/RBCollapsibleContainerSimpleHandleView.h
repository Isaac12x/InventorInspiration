//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBCollapsibleContainerHandleView.h>

/**
 *  A simple label toggle header for an `RBCollapsibleContainerView` object.
 */
@interface RBCollapsibleContainerSimpleHandleView : RBCollapsibleContainerHandleView

/**
 *  The text to display on the toggle header.
 */
@property (nonatomic, nullable) NSString *text;

@end
