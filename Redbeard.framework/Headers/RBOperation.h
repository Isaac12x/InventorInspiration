//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  An operation with convenience subclassing hooks.
 */
@interface RBOperation : NSOperation<RBCancellableTask>

/**
 *  Add the operation to a queue.
 *
 *  @param operationQueue The operation queue to add the operation to.
 */
- (void)addToOperationQueue:(nonnull NSOperationQueue *)operationQueue;

/**
 *  Completes the operation.
 */
- (void)done;

#pragma mark -
#pragma mark Subclassing Hooks

/**
 *  Called when the operation has begun processing.
 */
- (void)operationDidStart;

/**
 *  Called when the operation has finished processing.
 */
- (void)operationDidFinish;

/**
 *  Called when the operation has been cancelled.
 */
- (void)operationDidCancel;

@end
