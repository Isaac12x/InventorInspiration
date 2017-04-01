//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBOperation.h>
#import <Redbeard/RBNetworkCenter.h>
#import <Redbeard/RBImageResponse.h>

/**
 *  A block that is called when an image request has been completed.
 *
 *  @param response The resulting `RBImageResponse` object.
 */
typedef void(^RBImageRequestCompletionBlock)(RBImageResponse * __nonnull response);

/**
 *  An image network request operation.
 */
@interface RBImageRequestOperation : RBOperation

/**
 *  The underlying network request object.
 */
@property (nonatomic, readonly, nonnull) NSURLRequest *request;

/**
 *  The block to call when the response has begun being received.
 */
@property (nonatomic, readonly, nullable) NetworkOperationBeganBlock beganReceivingResponseBlock;

/**
 *  The block to call to notify the progress of receiving the response.
 */
@property (nonatomic, readonly, nullable) NetworkOperationProgressUpdateBlock progressUpdateBlock;

/**
 *  The block to call to notify the final response.
 */
@property (nonatomic, readonly, nullable) RBImageRequestCompletionBlock responseCompletionBlock;

/**
 *  The queue that will be used for image processing.
 */
@property (nonatomic, weak, readonly, nullable) dispatch_queue_t imageProcessingQueue;

/**
 *  Initializes a new image request operation.
 *
 *  @param request                The network request to perform.
 *  @param imageProcessingQueue   The queue to use for image decoding.
 *  @param beganReceivingResponse An optional block to receive the headers at the beginning of the response.
 *  @param progressUpdate         An optional block to receive progress updates on receiving the response body.
 *  @param completion             The completion block.
 *
 *  @return The initialized image request operation.
 */
- (nonnull instancetype)initWithRequest:(nonnull NSURLRequest *)request
           imageProcessingQueue:(nonnull dispatch_queue_t)imageProcessingQueue
         beganReceivingResponse:(nullable NetworkOperationBeganBlock)beganReceivingResponse
                 progressUpdate:(nullable NetworkOperationProgressUpdateBlock)progressUpdate
                     completion:(nonnull RBImageRequestCompletionBlock)completion;

@end
