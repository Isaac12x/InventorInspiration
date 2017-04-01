//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBBaseExtendView.h>
#import <Redbeard/RBObserverCollection.h>

@protocol RBScrollViewDelegate;
@protocol RBScrollViewObserver;

/**
 *  A `UIScrollView` with extensions.
 */
@interface RBScrollView : UIScrollView

/**
 *  A delegate to receive scroll view events.
 */
@property (nonatomic, weak, nullable) id<RBScrollViewDelegate, UIScrollViewDelegate> delegate;

/**
 *  A collection of `RBScrollViewObserver` objects to receive scroll view events.
 */
@property (nonatomic, readonly, nonnull) RBObserverCollection *observers;

/**
 *  Whether or not the scroll view should automatically update it's insets according
 *  to changes to `contentChromeInset`.
 */
@property (nonatomic) BOOL shouldAutomaticallyAdjustContentInsetForChrome;

/**
 *  Whether or not the scroll view should force scroll to be enabled - even if it's not required
 *  to access the content.  Such as when you need a pull-to-refresh.
 */
@property (nonatomic) BOOL shouldForceScrollEnabled;

#pragma mark -
#pragma mark State

/**
 *  The current vector of change in the current scroll.
 */
@property (nonatomic, readonly) CGVector currentScrollVector;

/**
 *  The vector of change in the previous scroll operation.
 */
@property (nonatomic, readonly) CGVector lastScrollUpdateVector;

/**
 *  The frame within the content that is currently in view (in the viewport).
 */
@property (nonatomic, readonly) CGRect visibleContentFrame;

/**
 *  The frame within the bounds where the content is visible.
 */
@property (nonatomic, readonly) CGRect contentViewport;

#pragma mark - 
#pragma mark Extend Views

/**
 *  The top extend view. Note extend views manage and set `contentInsets` and `contentOffsets`.
 */
@property (nonatomic, nullable) RBBaseExtendView *topExtendView;

/**
 *  The bottom extend view. Note extend views manage and set `contentInsets` and `contentOffsets`.
 */
@property (nonatomic, nullable) RBBaseExtendView *bottomExtendView;

/**
 *  The left extend view. Note extend views manage and set `contentInsets` and `contentOffsets`.
 */
@property (nonatomic, nullable) RBBaseExtendView *leftExtendView;

/**
 *  The right extend view. Note extend views manage and set `contentInsets` and `contentOffsets`.
 */
@property (nonatomic, nullable) RBBaseExtendView *rightExtendView;

#pragma mark -
#pragma mark Subclassing

/**
 *  Called when the scroll view is tapped anywhere.
 */
- (void)scrollViewWasTapped;

/**
 *  Called when a scroll operation will begin.
 *
 *  @param origin The content origin at the start of the scroll operation.
 */
- (void)willBeginScrollAtOrigin:(CGPoint)origin;

/**
 *  Called when the scroll operation did update to the given content offset.
 *
 *  @param origin     The current content offset of the scroll operation.
 *  @param fromOrigin The original content offset of the scroll operation.
 */
- (void)didScrollToOrigin:(CGPoint)origin fromOrigin:(CGPoint)fromOrigin;

/**
 *  Called when the user stopped the dragging interaction part of the scroll.
 *
 *  @param willDecelerate Whether or not the scroll will continue in deceleration mode.
 */
- (void)didEndDragging:(BOOL)willDecelerate;

/**
 *  Called when a scroll operation has finished.
 *
 *  @param origin     The final content offset of the scroll operation.
 *  @param fromOrigin The original content offset of the scroll operation.
 */
- (void)didFinishScrollToOrigin:(CGPoint)origin fromOrigin:(CGPoint)fromOrigin;

@end

/**
 *  An observer to receive scroll view events for an `RBScrollView` object.
 */
@protocol RBScrollViewObserver <NSObject>

@optional

/**
 *  Called when the scroll view is tapped anywhere.
 *
 *  @param scrollView The `RBScrollView` object.
 */
- (void)scrollViewWasTapped:(nonnull RBScrollView *)scrollView;

/**
 *  Called when a scroll operation will begin.
 *
 *  @param scrollView The `RBScrollView` object.
 *  @param origin     The content origin at the start of the scroll operation.
 */
- (void)scrollView:(nonnull RBScrollView *)scrollView willBeginScrollAtOrigin:(CGPoint)origin;

/**
 *  Called when the scroll operation did update to the given content offset.
 *
 *  @param scrollView The `RBScrollView` object.
 *  @param origin     The current content offset of the scroll operation.
 *  @param fromOrigin The original content offset of the scroll operation.
 */
- (void)scrollView:(nonnull RBScrollView *)scrollView didScrollToOrigin:(CGPoint)origin fromOrigin:(CGPoint)fromOrigin;

/**
 *  Called when the user stopped the dragging interaction part of the scroll.
 *
 *  @param scrollView     The `RBScrollView` object.
 *  @param willDecelerate Whether or not the scroll will continue in deceleration mode.
 */
- (void)scrollView:(nonnull RBScrollView *)scrollView didEndDragging:(BOOL)willDecelerate;

/**
 *  Called when a scroll operation has finished.
 *
 *  @param scrollView The `RBScrollView` object.
 *  @param origin     The final content offset of the scroll operation.
 *  @param fromOrigin The original content offset of the scroll operation.
 */
- (void)scrollView:(nonnull RBScrollView *)scrollView didFinishScrollToOrigin:(CGPoint)origin fromOrigin:(CGPoint)fromOrigin;

/**
 *  Called when the visible content frame has changed.
 *
 *  @param scrollView          The `RBScrollView` object.
 *  @param visibleContentFrame The content frame that is currently visible.
 */
- (void)scrollView:(nonnull RBScrollView *)scrollView visibleContentFrameDidChangeTo:(CGRect)visibleContentFrame;

@end

/**
 *  An delegate to receive scroll view events for an `RBScrollView` object.
 */
@protocol RBScrollViewDelegate <NSObject, UIScrollViewDelegate, RBScrollViewObserver>

@optional

@end

