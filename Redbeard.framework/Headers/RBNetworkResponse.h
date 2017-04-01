//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A network operation response.
 */
@interface RBNetworkResponse : NSObject // Immutable

/**
 *  Whether or not the response is valid.  A response is valid if there was no error or cancellation.
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 *  The error that occurred, or `nil` if no error occurred.
 */
@property (nonatomic, readonly, nullable) NSError *error;

/**
 *  Whether or not the network operation was cancelled.
 */
@property (nonatomic, readonly) BOOL wasCancelled;

/**
 *  The raw `NSHTTPURLResponse` object.
 */
@property (nonatomic, readonly, nonnull) NSHTTPURLResponse *httpResponse;

/**
 *  The body data of the response.
 */
@property (nonatomic, readonly, nullable) NSData *data;

/**
 *  Whether or not the response is from the cache.
 */
@property (nonatomic, readonly) BOOL isCacheHit;

/**
 *  Initializes a new network response with an error.
 *
 *  @param error The error that occurred.
 *
 *  @return The initialized network response object.
 */
- (nonnull instancetype)initWithError:(nonnull NSError *)error;

/**
 *  Initializes a new network response with cancellation.
 *
 *  @return The initialized network response object.
 */
- (nonnull instancetype)initWithCancellation;

/**
 *  Initializes a new network response.
 *
 *  @param response   The `NSHTTPURLResponse` object received.
 *  @param data       The final body data of the response.
 *  @param isCacheHit Whether or not the response is a cache hit.
 *
 *  @return The initialized network response object.
 */
- (nonnull instancetype)initWithResponse:(nonnull NSHTTPURLResponse *)response data:(nullable NSData *)data isCacheHit:(BOOL)isCacheHit;

@end
