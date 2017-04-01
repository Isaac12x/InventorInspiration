//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Redbeard/RBBaseExtendView.h>

/**
 *  A text refresh extend view.
 */
@interface RBRefreshExtendView : RBBaseExtendView

/**
 *  The text to display when the extend view is being revealed.
 */
@property (nullable) NSString *textWhenRevealing;

/**
 *  The text to display when the extend view is fully revealed.
 */
@property (nullable) NSString *textWhenRevealed;

/**
 *  The text to display when the extend view is open.
 */
@property (nullable) NSString *textWhenRefreshing;

@end
