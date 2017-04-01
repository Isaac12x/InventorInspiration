//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RBScrambledPinInputDelegate;

/**
 *  A numeric pin input view that can scramble the button layout.
 */
@interface RBScrambledPinInput : UIView

/**
 *  A delegate to receive button selection events.
 */
@property (nonatomic, weak, nullable) id<RBScrambledPinInputDelegate> delegate;

/**
 *  The `RBAnimator` object to use when animating button layout change transitions.
 */
@property (nonatomic, readonly, nonnull) RBAnimator *animator;

/**
 *  The margin to provide around the buttons.
 */
@property (nonatomic) UIEdgeInsets margin;

/**
 *  The spacing to provide between the buttons.
 */
@property (nonatomic) CGFloat spacing;

/**
 *  Whether or not button A is enabled.
 */
@property (nonatomic) BOOL buttonAEnabled;

/**
 *  Whether or not button B is enabled.
 */
@property (nonatomic) BOOL buttonBEnabled;

/**
 *  Scrambles the buttons.
 */
- (void)scramble;

@end

/**
 *  A delegate to receive button selection events for an `RBScrambledPinInput` object.
 */
@protocol RBScrambledPinInputDelegate <NSObject>

@required

/**
 *  Called when a digit button has been selected.
 *
 *  @param scrambledPinInput The `RBScrambledPinInput` object.
 *  @param digit             The digit.
 */
- (void)scrambledPinInput:(nonnull RBScrambledPinInput *)scrambledPinInput digitWasPushed:(int)digit;

@optional

/**
 *  Called when button A was pushed.
 *
 *  @param scrambledPinInput The `RBScrambledPinInput` object.
 */
- (void)buttonAPushedWithScrambledPinInput:(nonnull RBScrambledPinInput *)scrambledPinInput;

/**
 *  Called when button B was pushed.
 *
 *  @param scrambledPinInput The `RBScrambledPinInput` object.
 */
- (void)buttonBPushedWithScrambledPinInput:(nonnull RBScrambledPinInput *)scrambledPinInput;

@end
