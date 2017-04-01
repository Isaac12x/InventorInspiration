//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  Provides access to the preferred reveal bounds for a `UIView`.
 *
 *  An example of it's use is by the `RBTextViewField` class to ensure that when
 *  it is scrolled to, the region where the user is typing is revealed in the case
 *  when the view is larger than the viewable area.
 *
 *  Subclass to provide custom reveal behaviour.
 */
@interface UIView (RevealBounds)

/**
 *  The bounds that should be revealed when scrolling to reveal this view.
 */
@property (nonatomic, readonly) CGRect preferredBoundsToReveal;

@end
