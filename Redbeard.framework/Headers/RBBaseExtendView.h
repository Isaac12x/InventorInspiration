//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol RBExtendViewDelegate;

/**
 *  The position of an extend view.
 */
typedef NS_ENUM(NSInteger, RBExtendViewPosition)
{
    /**
     *  Positioned at the top.
     */
    RBExtendViewPositionTop = 0,
    
    /**
     *  Positioned at the bottom.
     */
    RBExtendViewPositionBottom,
    
    /**
     *  Positioned to the left.
     */
    RBExtendViewPositionLeft,
    
    /**
     *  Positioned to the right.
     */
    RBExtendViewPositionRight
};

/**
 *  The state of an extend view.
 */
typedef NS_ENUM(NSInteger, RBExtendViewState)
{
    /**
     *  The closed state/
     */
    RBExtendViewStateClosed = 0,
    
    /**
     *  The opended state.
     */
    RBExtendViewStateOpened,
    
    /**
     *  The opening state.
     */
    RBExtendViewStateOpening,
    
    /**
     *  The closing state.
     */
    RBExtendViewStateClosing
};

/**
 *  A base class for extend views for `RBExtendContainerView`.
 */
@interface RBBaseExtendView : UIView

/**
 *  The position of the extend view.
 */
@property (nonatomic, readonly) RBExtendViewPosition position;

/**
 *  The current factor by which the extend view is revealed (0 - 1). This takes into account the `insetBy` value. Reveal factor 1 = (dimension - insetBy) where dimension = width or height depending on the position of the extend view.
 */
@property (nonatomic, readonly) CGFloat revealFactor;

/**
 *  The reveal factor at which to consider the extend view opened. Default = 1.
 *  If you set a openRevealFactor greater than 1 essentially the extend view can never acheive the 'opened' state.
 *  Setting an extend view openRevealFactor greater than 1 can be useful in certain cicrumstances.
 *  For certain scenarios and types of extend views it might be useful to have the open state at a different
 *  value e.g. 0.75 (75%).
 */
@property (nonatomic) CGFloat openRevealFactor;

/**
 *  The state of the extend view
 */
@property (nonatomic, readonly) RBExtendViewState state;

/**
 *  The animator to use when opening and closing the extend view. Default = `[RBAnimator defaultAnimator]`.
 */
@property (nonatomic, nonnull) RBAnimator *animator;

/**
 *  A delegate to receive events.
 */
@property (nonatomic, weak, nullable) id<RBExtendViewDelegate> delegate;

/**
 *  Whether or not the extend view is enabled. If it is not enabled then it is hidden and cannot be revealed or opened.
 *  Default = `YES`.
 */
@property (nonatomic) BOOL enabled;

/**
 *  Whether or not the extend view should close if it is in the open state and the 
 *  scroll view is dragged in the closing direction. Default = `NO`.
 */
@property (nonatomic) BOOL closeOnDrag;

/**
 *  Opens the extend view.
 */
- (void)open;

/**
 *  Closes the extend view.
 */
- (void)close;

/**
 *  Calculates the exposed area of the extend view for the given reveal factor.
 *
 *  @param revealFactor The reveal factor.
 *
 *  @return The exposed region of the extend view.
 */
- (CGRect)exposedFrameForRevealFactor:(CGFloat)revealFactor;

#pragma mark -
#pragma mark Subclassing

/**
 *  How much to inset the extend view by. Default = 0. (The view is placed with no inset and so appears hidden).
 *  If you would like the extend view to be partially or fully visible provide an inset > 0.
 *  The inset value will show the partial/full extend view by the amount provided in the given position.
 */
- (CGFloat)insetBy;

/**
 *  Whether or not to allow the extend view to remain opened and extended when the `opened` state is first set. Default = YES.
 */
- (BOOL)keepExtendedWhenOpen;

/**
 *  Called to determine if the extend view may open. Default = `YES`.
 */
- (BOOL)shouldOpen;

/**
 *  Called when the extend view will open.
 */
- (void)willOpen;

/**
 *  Called when the extend view did open.
 */
- (void)didOpen;

/**
 *  Called when the extend view will close.
 */
- (void)willClose;

/**
 *  Called when the extend view did close.
 */
- (void)didClose;

/**
 *  Called when the extend view has been added to indicate the side that is was added to.
 */
- (void)positionDidChange;

/**
 *  Called when the reveal factor has changed.
 *
 *  @param to       The new reveal factor.
 *  @param from     The previous reveal factor.
 */
- (void)revealFactorDidChange:(CGFloat)to from:(CGFloat)from;

@end


/**
 *  A delegate to receive `RBExtendView` events.
 */
@protocol RBExtendViewDelegate <NSObject>

@optional

/**
 *  Called to notify that the extend view will open.
 *
 *  @param extendView          The extend view that will open.
 */
- (void)extendViewWillOpen:(nonnull RBBaseExtendView *)extendView;

/**
 *  Called to notify that the extend view did open.
 *
 *  @param extendView          The extend view that did open.
 */
- (void)extendViewDidOpen:(nonnull RBBaseExtendView *)extendView;

/**
 *  Called to notify that the extend view will close.
 *
 *  @param extendView          The extend view that will close.
 */
- (void)extendViewWillClose:(nonnull RBBaseExtendView *)extendView;

/**
 *  Called to notify that the extend view did close.
 *
 *  @param extendView          The extend view that did close.
 */
- (void)extendViewDidClose:(nonnull RBBaseExtendView *)extendView;

/**
 *  Called to notify changes in the reveal factor for the extend view.
 *
 *  @param extendView          The extend view being revealed.
 *  @param revealFactor        The factor by which the extend view is revealed. 0 - 1.
 */
- (void)extendView:(nonnull RBBaseExtendView *)extendView didRevealByFactor:(CGFloat)revealFactor;

@end