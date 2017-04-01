//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The result of a layout view positioning operation.
 */
@interface RBLayoutPositionerResult : NSObject

/**
 *  The calculated frame of each view in the given viewport. Array contains 'NSValue`s that wrap `CGRect`s.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSValue *> *frames;

/**
 *  The content size for the calculated frames in the given viewport.
 */
@property (nonatomic, readonly) CGSize contentSize;

/**
 *  The recommended content size in the given viewport (i.e. with flexible spacing collapsed).
 */
@property (nonatomic, readonly) CGSize recommendedContentSize;

/**
 *  Initializes a new layout view positioning result.
 *
 *  @param frames                  The calculated frame of each view in the given viewport.
 *  @param contentSize             The content size for the calculated frames in the given viewport.
 *
 *  @return The initialized layout view positioning result.
 */
- (nonnull instancetype)initWithFrames:(nonnull NSArray<NSValue *> *)frames
                   contentSize:(CGSize)contentSize;

/**
 *  Initializes a new layout view positioning result.
 *
 *  @param frames                  The calculated frame of each view in the given viewport.
 *  @param contentSize             The content size for the calculated frames in the given viewport.
 *  @param recommendedContentSize  The recommended content size in the given viewport (i.e. with flexible spacing collapsed).
 *
 *  @return The initialized layout view positioning result.
 */
- (nonnull instancetype)initWithFrames:(nonnull NSArray<NSValue *> *)frames
                   contentSize:(CGSize)contentSize
        recommendedContentSize:(CGSize)recommendedContentSize;

/**
 *  Adds a margin to the result, adjusting all frames and content sizes accordingly.
 *
 *  @param margin The margin to add to the result.
 *
 *  @return The updated `RBLayoutPositionerResult` object.
 */
- (nonnull RBLayoutPositionerResult *)resultByApplyingMargin:(UIEdgeInsets)margin;

@end
