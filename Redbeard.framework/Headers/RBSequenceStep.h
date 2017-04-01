//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A block that performs the initialization part of an `RBSequenceStep` object.
 *
 *  @param ^completion The block to be called when the operation is complete. `contextData` will be passed to the next part of the `RBSequenceStep` operation.
 */
typedef void (^RBSequenceStepInitializationBlock)(void(^ __nonnull completion)(NSDictionary * __nonnull contextData));

/**
 *  A block that performs the completion part of an `RBSequenceStep` object.
 *
 *  @param contextData A dictionary of assignments that was passed from the initialization part of the `RBSequenceStep` operation.
 *  @param ^completion The block to be called when the operation is complete.
 */
typedef void (^RBSequenceStepCompletionBlock)(NSDictionary * __nonnull contextData, void(^ __nonnull completion)());

/**
 *  A step in a sequence.
 */
@interface RBSequenceStep : NSObject

/**
 *  The block to be called when transitioning into the sequence step.
 */
@property (nonatomic, copy, readonly, nonnull) RBSequenceStepInitializationBlock initializationBlock;

/**
 *  The block to be called when transitioning out of the sequence step.
 */
@property (nonatomic, copy, readonly, nonnull) RBSequenceStepCompletionBlock completionBlock;

/**
 *  The time in seconds to wait after the step has been fully transitioned into.
 */
@property (nonatomic, readonly) NSTimeInterval presentationDuration;

/**
 *  Whether or not the step is currently active and running.
 */
@property (atomic, readonly) BOOL isRunning;

/**
 *  Initializes a new sequence step.
 *
 *  @param initializationBlock  The block to be called when transitioning into the sequence step.
 *  @param completionBlock      The block to be called when transitioning out of the sequence step.
 *  @param presentationDuration The time in seconds to wait after the step has been fully transitioned into.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithInitializationBlock:(nonnull RBSequenceStepInitializationBlock)initializationBlock
                            completionBlock:(nonnull RBSequenceStepCompletionBlock)completionBlock
                       presentationDuration:(NSTimeInterval)presentationDuration;

/**
 *  Runs the sequence step by transitioning into the step, waiting for the duration and transitioning out.
 *
 *  @param completion An optional completion block to be called when the step has completed the final transition out.
 *
 *  @return Whether or not the transition was run successfully.
 */
- (BOOL)runWithCompletion:(nullable dispatch_block_t)completion;

@end
