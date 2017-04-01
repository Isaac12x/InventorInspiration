//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A task that can be cancelled.
 */
@protocol RBCancellableTask <NSObject>

@required

/**
 *  Cancel the task.
 */
- (void)cancel;

@end

/**
 *  Threading convenience methods.
 */
@interface RBThreading : NSObject

/**
 *  Executes a block after a delay.
 *
 *  @param taskBlock     The block to execute.
 *  @param delay         The delay in seconds until the block will be executed.
 *  @param dispatchQueue The queue to execute the block in.
 *
 *  @return A `id<RBCancellableTask>` object that can be cancelled before execution.
 */
+ (nonnull id<RBCancellableTask>)dispatchTaskBlock:(nonnull dispatch_block_t)taskBlock
                                afterDelay:(NSTimeInterval)delay
                        usingDispatchQueue:(nonnull dispatch_queue_t)dispatchQueue;

/**
 *  Measures the time that it takes to complete a task.
 *
 *  @param taskBlock  The block to execute the task.
 *  @param completion The completion block that is called at the end with the result.
 */
+ (void)measureTask:(nonnull void(^)(__nonnull dispatch_block_t))taskBlock
         completion:(nonnull void(^)(NSTimeInterval timeTaken))completion;

@end

/**
 *  A task that executes a block and allows cancellation before execution.
 */
@interface RBCancellableBlockTask : NSObject<RBCancellableTask>

/**
 *  The block to be executed.
 */
@property (nonatomic, readonly, nonnull) dispatch_block_t taskBlock;

/**
 *  Whether the task has been cancelled.
 */
@property (nonatomic, readonly) BOOL cancelled;

/**
 *  Whether the task has been started.
 */
@property (nonatomic, readonly) BOOL started;

/**
 *  Whether the task has been completed.
 */
@property (nonatomic, readonly) BOOL finished;

/**
 *  Initializes a new task with the given block.
 *
 *  @param taskBlock The block to execute.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithTaskBlock:(nonnull dispatch_block_t)taskBlock;

/**
 *  Starts the task by executing the block.
 *
 *  @return Whether the task was started successfully.
 */
- (BOOL)start;

@end
