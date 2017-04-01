//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#include <Foundation/Foundation.h>

/**
 *  A schema of a toolbar spacing item.
 */
@interface RBToolbarSpacingItemSchema : NSObject

/**
 *  The minimum size in points of the spacing.
 */
@property (nonatomic, readonly) CGFloat minimumSize;

/**
 *  The maximum size in points of the spacing.
 */
@property (nonatomic, readonly) CGFloat maximumSize;

/**
 *  Initializes a new schema for a toolbar spacing item.
 *
 *  @param minimumSize The minimum size in points of the spacing.
 *  @param maximumSize The maximum size in points of the spacing.
 *
 *  @return The initialized custom toolbar item schema.
 */
- (instancetype)initWithMinimumSize:(CGFloat)minimumSize
                        maximumSize:(CGFloat)maximumSize;

@end
