//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBCollapsibleContainerHandleView.h>
#import <Redbeard/RBCollapsibleContainerSimpleHandleView.h>

/** The state of the collapsible container. */
typedef NS_ENUM(NSInteger, RBCollapsibleContainerState)
{
    /** The collapsible container is collapsed. */
    RBCollapsibleContainerStateCollapsed,

    /** The collapsible container is expanded. */
    RBCollapsibleContainerStateExpanded
};

@protocol RBCollapsibleContainerViewDelegate;

/**
 *  Provides a view container with a header that can expand and collapse.
 */
@interface RBCollapsibleContainerView : UIView<RBCollapsibleContainerHandleDelegate>

/**
 *  A delegate to receive state change events.
 */
@property (nonatomic, weak, nullable) id<RBCollapsibleContainerViewDelegate> delegate;

/**
 *  The handle view that can be used to expand and collapse the container view.
 */
@property (nonatomic, nullable) RBCollapsibleContainerHandleView *handleView;

/**
 *  The child view of the container.
 */
@property (nonatomic, nullable) UIView *view;

/**
 *  The current state of the container.
 */
@property (nonatomic) RBCollapsibleContainerState state;

/**
 *  Changes the state of the container.
 *
 *  @param state    The new state of the container to transition to.
 *  @param animated Whether the transition should be animated.
 */
- (void)setState:(RBCollapsibleContainerState)state animated:(BOOL)animated;

/**
 *  The margin to be applied around the child view.
 */
@property (nonatomic) UIEdgeInsets viewMargin;

/**
 *  The `RBAnimator` to use when animating state change transitions.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *animator;

/**
 *  Whether or not layouts should be performed immediately on state changes so that
 *  they can be included in parent animations.
 */
@property (nonatomic) BOOL shouldUseAnimations;

/**
 *  The size that is required to display the container view in the given state.
 *
 *  @param size  The available size in the container.
 *  @param state The state to calculate the size for.
 *
 *  @return The calculated `CGSize` value.
 */
- (CGSize)sizeThatFits:(CGSize)size state:(RBCollapsibleContainerState)state;

@end

/**
 *  A delegate to receive state change events from an `RBCollapsibleContainerView` object.
 */
@protocol RBCollapsibleContainerViewDelegate <NSObject>

@optional

/**
 *  Called when the container view will expand.
 *
 *  @param collapsibleContainerView The `RBCollapsibleContainerView` object.
 */
- (void)collapsibleContainerViewWillExpand:(nonnull RBCollapsibleContainerView *)collapsibleContainerView;

/**
 *  Called when the container view was expanded.
 *
 *  @param collapsibleContainerView The `RBCollapsibleContainerView` object.
 */
- (void)collapsibleContainerViewDidExpand:(nonnull RBCollapsibleContainerView *)collapsibleContainerView;

/**
 *  Called when the container view will collapse.
 *
 *  @param collapsibleContainerView The `RBCollapsibleContainerView` object.
 */
- (void)collapsibleContainerViewWillCollapse:(nonnull RBCollapsibleContainerView *)collapsibleContainerView;

/**
 *  Called when the container view was collapsed.
 *
 *  @param collapsibleContainerView The `RBCollapsibleContainerView` object.
 */
- (void)collapsibleContainerViewDidCollapse:(nonnull RBCollapsibleContainerView *)collapsibleContainerView;

@end
