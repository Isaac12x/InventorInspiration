//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBOperation.h>
#import <Redbeard/RBNetworkOperation.h>

@protocol RBNetworkRequestOperationDelegate;

/**
 *  A network request operation, representing one interested party in an `RBNetworkOperation`.
 */
@interface RBNetworkRequestOperation : RBOperation

/**
 *  A delegate to be informed of completion or cancellation.
 */
@property (nonatomic, weak, nullable) id<RBNetworkRequestOperationDelegate> delegate;

/**
 *  The underlying network operation that this request awaits completion of.
 */
@property (nonatomic, readonly, nonnull) RBNetworkOperation *networkOperation;

/**
 *  The block to call to notify the caller that the operation began receiving a response.
 */
@property (nonatomic, readonly, nullable) NetworkOperationBeganBlock operationBeganBlock;

/**
 *  The block to call to notify the caller of the latest progress in receiving the response.
 */
@property (nonatomic, readonly, nullable) NetworkOperationProgressUpdateBlock operationProgressUpdateBlock;

/**
 *  The block to call to notify the caller of the response when the operation is completed.
 */
@property (nonatomic, readonly, nullable) NetworkOperationCompletionBlock operationCompletionBlock;

/**
 *  Initializes a new request operation.
 *
 *  @param networkOperation    The underlying network operation that this request awaits completion of.
 *  @param operationBeganBlock The block to call to notify the caller that the operation began receiving a response.
 *  @param progressUpdateBlock The block to call to notify the caller of the latest progress in receiving the response.
 *  @param completionBlock     The block to call to notify the caller of the response when the operation is completed.
 *
 *  @return The initialized request operation.
 */
- (nonnull instancetype)initWithNetworkOperation:(nonnull RBNetworkOperation *)networkOperation
                     operationBeganBlock:(nullable NetworkOperationBeganBlock)operationBeganBlock
                     progressUpdateBlock:(nullable NetworkOperationProgressUpdateBlock)progressUpdateBlock
                         completionBlock:(nonnull NetworkOperationCompletionBlock)completionBlock;

@end

/**
 *  A delegate to be notified of the conclusion of a network request operation.
 */
@protocol RBNetworkRequestOperationDelegate <NSObject>

@required

/**
 *  Called to notify that the given request operation has concluded (completion or cancellation).
 *
 *  @param networkRequestOperation The network request operation object.
 *  @param response                The response object.
 *  @param request                 The request object.
 *  @param networkOperationIsDone  Whether or not the underlying network operation is done.
 */
- (void)networkRequestOperation:(nonnull RBNetworkRequestOperation *)networkRequestOperation
                    hasResponse:(nonnull RBNetworkResponse *)response
                     forRequest:(nonnull NSURLRequest *)request
         networkOperationIsDone:(BOOL)networkOperationIsDone;

@end

