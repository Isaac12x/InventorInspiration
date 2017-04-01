//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBNetworkResponse.h>
#import <Redbeard/RBURLBuilder.h>

/**
 *  A block that is called when a rest client request has been completed.
 *
 *  @param networkResponse The resulting `RBNetworkResponse` object.
 */
typedef void(^RBRestClientCompletionBlock)(RBNetworkResponse * __nonnull networkResponse);

/**
 *  A block that is called when a raw data rest client request has been completed.
 *
 *  @param networkResponse The resulting `RBNetworkResponse` object.
 */
typedef void(^RBRestClientDataCompletionBlock)(RBNetworkResponse * __nonnull networkResponse);

/**
 *  A block that is called when a JSON data rest client request has been completed.
 *
 *  @param jsonResponse    The received JSON response.
 *  @param networkResponse The resulting `RBNetworkResponse` object.
 */
typedef void(^RBRestClientJsonCompletionBlock)(id __nullable jsonResponse, RBNetworkResponse * __nonnull networkResponse);

@protocol RBRestClientDelegate;

/**
 *  A HTTP REST client.
 */
@interface RBRestClient : NSObject

/**
 *  A delegate to receive rest client events.
 */
@property (nonatomic, weak, nullable) id<RBRestClientDelegate> delegate;

/**
 *  Cancel all active requests.
 */
- (void)cancelAllRequests;

#pragma mark -
#pragma mark Raw

/**
 *  Perform a raw network request.
 *
 *  @param request    The network request to perform.
 *  @param completion The block to call when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)performRequest:(nonnull NSURLRequest *)request
                                     completion:(nullable RBRestClientDataCompletionBlock)completion;

#pragma mark -
#pragma mark Data Requests

/**
 *  Perform a GET request, providing the response as a `NSData` object.
 *
 *  @param targetUrl   The target URL to send the request to.
 *  @param httpHeaders The http headers to use in the request.
 *  @param completion  The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)getTo:(nonnull NSURL *)targetUrl
                           httpHeaders:(nullable NSDictionary *)httpHeaders
                            completion:(nullable RBRestClientDataCompletionBlock)completion;

/**
 *  Perform a POST request, providing the response as a `NSData` object.
 *
 *  @param targetUrl   The target URL to send the request to.
 *  @param bodyData    The raw body data to include in the request.
 *  @param httpHeaders The http headers to use in the request.
 *  @param completion  The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)postTo:(nonnull NSURL *)targetUrl
                               bodyData:(nullable NSData *)bodyData
                            httpHeaders:(nullable NSDictionary *)httpHeaders
                             completion:(nullable RBRestClientDataCompletionBlock)completion;

/**
 *  Perform a PUT request.
 *
 *  @param targetUrl   The target URL to send the request to.
 *  @param bodyData    The raw body data to include in the request.
 *  @param httpHeaders The http headers to use in the request.
 *  @param completion  The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)putTo:(nonnull NSURL *)targetUrl
                              bodyData:(nullable NSData *)bodyData
                           httpHeaders:(nullable NSDictionary *)httpHeaders
                            completion:(nullable RBRestClientCompletionBlock)completion;

/**
 *  Perform a DELETE request.
 *
 *  @param targetUrl   The target URL to send the request to.
 *  @param httpHeaders The http headers to use in the request.
 *  @param completion  The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)deleteTo:(nonnull NSURL *)targetUrl
                              httpHeaders:(nullable NSDictionary *)httpHeaders
                               completion:(nullable RBRestClientCompletionBlock)completion;

#pragma mark -
#pragma mark Json Requests

/**
 *  Perform a GET request, providing the response as a JSON deserialised property list.
 *
 *  @param targetUrl   The target URL to send the request to.
 *  @param httpHeaders The http headers to use in the request.
 *  @param completion  The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nonnull id<RBCancellableTask>)jsonGetTo:(nonnull NSURL *)targetUrl
                               httpHeaders:(nullable NSDictionary *)httpHeaders
                                completion:(nullable RBRestClientJsonCompletionBlock)completion;

/**
 *  Perform a POST request, providing the response as a JSON deserialised property list.
 *
 *  @param targetUrl        The target URL to send the request to.
 *  @param bodyPropertyList A property list (NSDictionary, NSArray) that will be serialised to JSON and sent as the body of the request.
 *  @param httpHeaders      The http headers to use in the request.
 *  @param completion       The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nullable id<RBCancellableTask>)jsonPostTo:(nonnull NSURL *)targetUrl
                           bodyPropertyList:(nullable id)bodyPropertyList
                                httpHeaders:(nullable NSDictionary *)httpHeaders
                                 completion:(nullable RBRestClientJsonCompletionBlock)completion;

/**
 *  Perform a PUT request, providing the response as a JSON deserialised property list.
 *
 *  @param targetUrl        The target URL to send the request to.
 *  @param bodyPropertyList A property list (NSDictionary, NSArray) that will be serialised to JSON and sent as the body of the request.
 *  @param httpHeaders      The http headers to use in the request.
 *  @param completion       The block to be called when the network operation concludes.
 *
 *  @return A handle that can be used to cancel the job.
 */
- (nullable id<RBCancellableTask>)jsonPutTo:(nonnull NSURL *)targetUrl
                           bodyPropertyList:(nullable id)bodyPropertyList
                                httpHeaders:(nullable NSDictionary *)httpHeaders
                                 completion:(nullable RBRestClientCompletionBlock)completion;

@end

/**
 *  A delegate to receive rest client events.
 */
@protocol RBRestClientDelegate <NSObject>

@optional

/**
 *  Called when the `RBRestClient` object will cancel all outstanding network jobs.
 *
 *  @param restClient The `RBRestClient` object.
 */
- (void)restClientWillCancelAllRequests:(nonnull RBRestClient *)restClient;

/**
 *  Called when the `RBRestClient` object did cancel all outstanding network jobs.
 *
 *  @param restClient The `RBRestClient` object.
 */
- (void)restClientDidCancelAllRequests:(nonnull RBRestClient *)restClient;

/**
 *  Called before the `RBRestClient` object will perform a request.
 *  Use this to transform or observe the requests being performed.
 *
 *  @param restClient The `RBRestClient` object.
 *  @param request    The request that is intended to be performed.
 *
 *  @return The request that will be performed.  `nil` is not a valid return value.
 */
- (nonnull NSURLRequest *)restClient:(nonnull RBRestClient *)restClient willPerformRequest:(nonnull NSURLRequest *)request;

/**
 *  Called before the `RBRestClient` object will process the received response.
 *  Use this to transform or observe the raw responses.
 *
 *  @param restClient The `RBRestClient` object.
 *  @param response   The response object that is intended to be processed.
 *  @param request    The request that is being performed.
 *
 *  @return The response object that will be processed.
 */
- (nonnull RBNetworkResponse *)restClient:(nonnull RBRestClient *)restClient willReceiveResponse:(nonnull RBNetworkResponse *)response forRequest:(nonnull NSURLRequest *)request;

/**
 *  Called after the final response has been received and the completion block called.
 *
 *  @param restClient The `RBRestClient` object.
 *  @param response   The final response object that was received.
 *  @param request    The request that was performed.
 */
- (void)restClient:(nonnull RBRestClient *)restClient didReceiveFinalResponse:(nonnull RBNetworkResponse *)response forRequest:(nonnull NSURLRequest *)request;

/**
 *  Called before the `RBRestClient` object will process the received JSON response.
 *  Use this to transform or observe the JSON responses.
 *
 *  @param restClient   The `RBRestClient` object.
 *  @param jsonResponse The JSON response that is intended to be processed.
 *  @param request      The request that is being performed.
 *
 *  @return The JSON response that will be processed.
 */
- (nonnull id)restClient:(nonnull RBRestClient *)restClient willReceiveJsonResponse:(nullable id)jsonResponse forRequest:(nonnull NSURLRequest *)request;

/**
 *  Called after the final response has been received and the completion block called.
 *
 *  @param restClient   The `RBRestClient` object.
 *  @param jsonResponse The final JSON response that was received.
 *  @param request      The request that was performed.
 */
- (void)restClient:(nonnull RBRestClient *)restClient didReceiveFinalJsonResponse:(nullable id)jsonResponse forRequest:(nonnull NSURLRequest *)request;

@end
