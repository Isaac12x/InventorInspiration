//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBNetworkCenter.h>
#import <Redbeard/RBImageResponse.h>

/**
 * The singleton center for the retrieval of images.
 */
@interface RBImageCenter : NSObject

/**
 *  The underlying `NSCache` that is used to cache images processed by `RBImageCenter`. By default the cache size is 100 MB.
 */
@property (nonatomic, readonly, nonnull) NSCache *memoryCache;

/**
 * The shared singleton.
 */
+ (nonnull RBImageCenter *)shared;

/**
 * Gets a resizable image from the bundle.
 *
 * @param name   The name of the image in the bundle.
 * @param insets The fixed edge insets to use for the resizeable image.
 * @return       The retrieved image.
 */
+ (nullable UIImage *)resizableImageWithName:(nonnull NSString *)name withInsets:(UIEdgeInsets)insets;

/**
 * Gets an image from the bundle.
 *
 * @param name   The name of the image in the bundle.
 * @return       The retrieved image.
 */
+ (nullable UIImage *)bundleImageWithName:(nonnull NSString *)name;

/**
 * Gets an image from the given filesystem path.
 *
 * @param path   The path of the image in the filesystem.
 * @return       The retrieved image.
 */
+ (nullable UIImage *)imageWithPath:(nonnull NSString *)path;

/**
 * Gets a glyph image from the bundle, optionally with a specified color or size.
 *
 * @param name       The name of the glyph image in the bundle.
 * @param tintColor The optional color with which to tint the glyph.
 * @param size       The optional size (specified in height points) with which to scale the glyph.
 * @return           The requested glyph image.
 */
- (nullable UIImage *)glyphImageWithName:(nonnull NSString *)name tintColor:(nullable UIColor *)tintColor size:(nullable NSNumber *)size;

/**
 * Retrieves a decoded image asynchronously over HTTP using the request given.
 *
 * @param request        The network request to use for retrieval.
 * @param completion     The completion block to be called on completion or failure. Must not be `nil`.
 * @return               A cancellation object or `nil` if a request was not made as the image was locally available (via cache).
 */
- (nullable id<RBCancellableTask>)imageWithRequest:(nonnull NSURLRequest *)request
                               completion:(nonnull void(^)(RBImageResponse * __nonnull response))completion;

/**
 * Retrieves a decoded image asynchronously over HTTP using the request given.
 *
 * @param request                The network request to use for retrieval.
 * @param beganReceivingResponse An optional block called at the beginning of the HTTP response.
 * @param progressUpdate         An optional block to be called to provide progress updates.
 * @param completion             The completion block to be called on completion or failure. Must not be `nil`.
 * @return                       A cancellation object or `nil` if a request was not made as the image was locally available (via cache).
 */
- (nullable id<RBCancellableTask>)imageWithRequest:(nonnull NSURLRequest *)request
                   beganReceivingResponse:(nullable NetworkOperationBeganBlock)beganReceivingResponse
                           progressUpdate:(nullable NetworkOperationProgressUpdateBlock)progressUpdate
                               completion:(nonnull void(^)(RBImageResponse * __nonnull response))completion;

@end
