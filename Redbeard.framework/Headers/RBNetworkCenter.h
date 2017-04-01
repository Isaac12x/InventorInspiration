//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBNetworkResponse.h>

/**
 *  A block that is called when a network operation has completed.
 *
 *  @param response The resulting `RBNetworkResponse` object of the operation.
 */
typedef void (^NetworkOperationCompletionBlock)(RBNetworkResponse * __nonnull response);

/**
 *  A block that is called when a network operation has begun and a response header
 *  has been received.
 *
 *  @param response           The HTTP header response object.
 *  @param willReceiveUpdates Whether or not progress updates will be provided as the response is received.
 */
typedef void (^NetworkOperationBeganBlock)(NSHTTPURLResponse * __nonnull response, BOOL willReceiveUpdates);

/**
 *  A block that is called to update the current progress of a network response being received.
 *
 *  @param progress The new progress value, in a range from 0 to 1.
 */
typedef void (^NetworkOperationProgressUpdateBlock)(float progress);

/**
 *  Centrally manages network connections.
 *
 *  - Manages their state.
 *  - Enables their cancellation.
 *  - Matches requests to prevent duplicate connections being made.
 */
@interface RBNetworkCenter : NSObject

/**
 *  The shared network center.
 */
+ (nonnull RBNetworkCenter *)shared;

/**
 *  The number of currently active connections being managed.
 */
@property (nonatomic, readonly) NSUInteger activeConnections;

/**
 *  Starts a network request.
 *
 *  @param request    The request to perform.
 *  @param completion The completion block to be called with the result when the operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)performRequest:(nonnull NSURLRequest *)request
                             completion:(nullable NetworkOperationCompletionBlock)completion;

/**
 *  Starts a network request.
 *
 *  @param request                The request to perform.
 *  @param beganReceivingResponse A block called when the response begins, providing headers (optional).
 *  @param progressUpdate         A block called to provide the progress receiving the response (optional).
 *  @param completion             The completion block to be called with the result when the operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)performRequest:(nonnull NSURLRequest *)request
                 beganReceivingResponse:(nullable NetworkOperationBeganBlock)beganReceivingResponse
                         progressUpdate:(nullable NetworkOperationProgressUpdateBlock)progressUpdate
                             completion:(nullable NetworkOperationCompletionBlock)completion;

@end
