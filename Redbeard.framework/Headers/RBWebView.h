//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBWebViewToolbarView.h>

/**
 *  A `UIWebView` with extended functionality.
 */
@interface RBWebView : UIWebView<RBWebViewToolbarDelegate>

/**
 *  Whether or not the insets are automatically adjusted when the keyboard opens and closes.
 */
@property (nonatomic) BOOL shouldAdjustInsetForKeyboard;

/**
 *  Whether or not the web view sizes to it's content (`sizeThatFitsSize:`).
 */
@property (nonatomic) BOOL sizeToContent;

@end
