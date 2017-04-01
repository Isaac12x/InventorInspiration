//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** The state of the collapsible container handle. */
typedef NS_ENUM(NSInteger, RBCollapsibleContainerHandleState)
{
    /** The collapsible container handle is collapsed. */
    RBCollapsibleContainerHandleStateCollapsed,

    /** The collapsible container handle is expanded. */
    RBCollapsibleContainerHandleStateExpanded
};

@protocol RBCollapsibleContainerHandleDelegate;

/**
 *  A toggle header for an `RBCollapsibleContainerView` object.
 */
@interface RBCollapsibleContainerHandleView : UIView

/**
 *  A delegate to receive state change events.
 */
@property (nonatomic, weak, nullable) id<RBCollapsibleContainerHandleDelegate> delegate;

/**
 *  The current state of the header.
 */
@property (nonatomic) RBCollapsibleContainerHandleState state;

#pragma mark -
#pragma mark Subclassing

/**
 *  Calculates the size that is required to display the header in the given state.
 *
 *  @param size  The available size in the container.
 *  @param state The state of the header.
 *
 *  @return The size required to display the header.
 */
- (CGSize)sizeThatFits:(CGSize)size state:(RBCollapsibleContainerHandleState)state;

/**
 *  Called when the header will change it's state.
 *
 *  @param fromState The state that the header is changing from.
 *  @param toState   The state that the header is changing to.
 */
- (void)willChangeFromState:(RBCollapsibleContainerHandleState)fromState toState:(RBCollapsibleContainerHandleState)toState;

/**
 *  Called when the header has changed it's state.
 *
 *  @param fromState The state that the header is changing from.
 *  @param toState   The state that the header is changing to.
 */
- (void)didChangeFromState:(RBCollapsibleContainerHandleState)fromState toState:(RBCollapsibleContainerHandleState)toState;

@end

/**
 *  A delegate to receive state change events from an `RBCollapsibleContainerHandleView` object.
 */
@protocol RBCollapsibleContainerHandleDelegate <NSObject>

@required

/**
 *  Called when the header will change it's state.
 *
 *  @param collapsibleContainerHandleView The `RBCollapsibleContainerHandleView` object.
 *  @param fromState                      The state that the header is changing from.
 *  @param toState                        The state that the header is changing to.
 */
- (void)collapsibleContainerHandleView:(nonnull RBCollapsibleContainerHandleView *)collapsibleContainerHandleView
                   willChangeFromState:(RBCollapsibleContainerHandleState)fromState
                               toState:(RBCollapsibleContainerHandleState)toState;

/**
 *  Called when the header has changed it's state.
 *
 *  @param collapsibleContainerHandleView The `RBCollapsibleContainerHandleView` object.
 *  @param fromState                      The state that the header is changing from.
 *  @param toState                        The state that the header is changing to.
 */
- (void)collapsibleContainerHandleView:(nonnull RBCollapsibleContainerHandleView *)collapsibleContainerHandleView
                    didChangeFromState:(RBCollapsibleContainerHandleState)fromState
                               toState:(RBCollapsibleContainerHandleState)toState;

@end
