//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The response of an image request operation.
 */
@interface RBImageResponse : NSObject // Immutable

/**
 *  Whether or not the operation was cancelled.
 */
@property (nonatomic, readonly) BOOL wasCancelled;

/**
 *  The error that occurred during the operation, or `nil` if no error occurred.
 */
@property (nonatomic, readonly, nullable) NSError *error;

/**
 *  The resulting image that was retrieved.
 */
@property (nonatomic, readonly, nullable) UIImage *image;

/**
 *  Whether or not the image was retrieved from the disk cache.
 */
@property (nonatomic, readonly) BOOL isDiskCacheHit;

/**
 *  Whether or not the image was retrieved from the memory cache.
 */
@property (nonatomic, readonly) BOOL isMemoryCacheHit;

/**
 *  Whether or not the image was retrieved from either the disk or the memory cache.
 */
@property (nonatomic, readonly) BOOL isCacheHit;

/**
 *  Whether or not the response is valid.  A response is valid if no error occurred and it wasn't cancelled.
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 *  Creates a new image response with success.
 *
 *  @param image            The retrieved image.
 *  @param isDiskCacheHit   Whether or not the image was retrieved from the disk cache.
 *  @param isMemoryCacheHit Whether or not the image was retrieved from the memory cache.
 *
 *  @return The new `RBImageResponse` object.
 */
+ (nonnull RBImageResponse *)responseWithImage:(nonnull UIImage *)image isDiskCacheHit:(BOOL)isDiskCacheHit isMemoryCacheHit:(BOOL)isMemoryCacheHit;

/**
 *  Creates a new image response with an error.
 *
 *  @param error The error that occurred.
 *
 *  @return The new `RBImageResponse` object.
 */
+ (nonnull RBImageResponse *)responseWithError:(nonnull NSError *)error;

/**
 *  Creates a new image response with cancellation.
 *
 *  @return The new `RBImageResponse` object.
 */
+ (nonnull RBImageResponse *)wasCancelledResponse;

@end
