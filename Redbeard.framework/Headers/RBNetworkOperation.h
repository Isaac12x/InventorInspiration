//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBOperation.h>
#import <Redbeard/RBNetworkResponse.h>

// Represents one network request and response with a single delegate.

@protocol RBNetworkOperationDelegate;

/**
 *  A network operation.
 */
@interface RBNetworkOperation : RBOperation

/**
 *  A collection of observers that implement `RBNetworkOperationDelegate` to receive delegate updates.
 */
@property (nonatomic, readonly, nonnull) RBObserverCollection *observers;

/**
 *  The underlying request object.
 */
@property (nonatomic, readonly, nonnull) NSURLRequest *request;

/**
 *  The underlying response object, `nil` until completion.
 */
@property (nonatomic, readonly, nullable) RBNetworkResponse *response;

/**
 *  The number of requests that are interested in the result of this operation.
 */
@property (atomic) unsigned int requestCounter;

/**
 *  Initializes a new network operation.
 *
 *  @param request The underlying request to be performed.
 *
 *  @return The initialized network operation.
 */
- (nonnull instancetype)initWithRequest:(nonnull NSURLRequest *)request;

@end

/**
 *  A delegate to be notified of status updates to the network operation.
 */
@protocol RBNetworkOperationDelegate <NSObject>

@required

/**
 *  The network operation did complete.
 *
 *  @param networkOperation The network operation object.
 *  @param response         The resulting response object.
 */
- (void)networkOperation:(nonnull RBNetworkOperation *)networkOperation hasResponse:(nonnull RBNetworkResponse *)response;

/**
 *  The network operation did begin receiving the response.
 *
 *  @param networkOperation           The network operation object.
 *  @param response                   The HTTP header response that was received.
 *  @param willReceiveProgressUpdates Whether or not progress updates will be forthcoming.
 */
- (void)networkOperation:(nonnull RBNetworkOperation *)networkOperation beganReceivingResponse:(nonnull NSHTTPURLResponse *)response willReceiveProgressUpdates:(BOOL)willReceiveProgressUpdates;

/**
 *  The network operation did update its progress in receiving the response.
 *
 *  @param networkOperation The network operation object.
 *  @param progress         The current progress from 0 to 1 of receiving the response.
 */
- (void)networkOperation:(nonnull RBNetworkOperation *)networkOperation hasProgress:(float)progress;

@end
