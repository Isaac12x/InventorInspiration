//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBSequenceStep.h>

@protocol RBSequenceControllerDelegate;

/**
 *  Manages a sequence of transitions.
 */
@interface RBSequenceController : NSObject

/**
 *  The delegate to receive transition change events.
 */
@property (nonatomic, weak, nullable) id<RBSequenceControllerDelegate> delegate;

/**
 *  The number of steps in the sequence.
 */
@property (nonatomic, readonly) NSUInteger stepCount;

/**
 *  The index of the current step in the sequence.
 */
@property (nonatomic, readonly) NSUInteger stepIndex;

/**
 *  Whether or not the controller should automatically move to the next step.
 */
@property (nonatomic) BOOL automaticStepEnabled;

/**
 *  The delay that the controller should observe between a step being completed
 *  and transitioning to the next step.
 */
@property (nonatomic) NSTimeInterval automaticStepDelay;

/**
 *  Whether or not the controller should automatically repeat the sequence when it finishes.
 */
@property (nonatomic) BOOL shouldRepeatAtEnd;

/**
 *  Add a step to the sequence.
 *
 *  @param sequenceStep The `RBSequenceStep` object to add.
 */
- (void)addStep:(nonnull RBSequenceStep *)sequenceStep;

/**
 *  Starts the sequence.
 *
 *  @return Whether or not the operation completed successfully.
 */
- (BOOL)start;

/**
 *  Transitions to the next step in the sequence.
 *
 *  @return Whether or not the operation completed successfully.
 */
- (BOOL)nextStep;

/**
 *  Resets to the first step in the sequence.
 */
- (void)resetAndRewind;

@end

/**
 *  The sequence controller delegate to receive transition change events.
 */
@protocol RBSequenceControllerDelegate <NSObject>

@optional

/**
 *  The controller did start the sequence.
 *
 *  @param sequenceController The sequence controller object.
 */
- (void)sequenceDidStartWithController:(nonnull RBSequenceController *)sequenceController;

/**
 *  The controller did complete the transition to a step.
 *
 *  @param stepIndex          The step index that was transitioned to.
 *  @param sequenceController The sequence controller object.
 */
- (void)sequenceDidCompleteStep:(NSUInteger)stepIndex withController:(nonnull RBSequenceController *)sequenceController;

/**
 *  The controller did complete the sequence.
 *
 *  @param sequenceController The sequence controller.
 *  @param willRepeat         Whether the controller will automatically repeat the sequence.
 */
- (void)sequenceDidCompleteWithController:(nonnull RBSequenceController *)sequenceController willRepeat:(BOOL)willRepeat;

@end
