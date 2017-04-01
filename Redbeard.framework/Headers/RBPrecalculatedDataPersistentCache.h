//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Stores the result of a calculation, recalculating when invalidated.
 */
@interface RBPrecalculatedDataPersistentCache : NSObject

/**
 *  The unique storage key determining where the precalculated data is stored.
 */
@property (nonatomic, readonly, nonnull) NSString *storageKey;

/**
 *  Initializes a new calculated data persistent cache with the given settings.
 *
 *  @param storageKey         The unique storage key to use when saving and loading precalculated data.
 *  @param recalculationBlock The block to call to recalculate the data.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithStorageKey:(nonnull NSString *)storageKey
                recalculationBlock:(nonnull NSData * __nullable(^)())recalculationBlock;

/**
 *  Invalidates the data causing a recalculation before the next retrieval.
 */
- (void)invalidate;

/**
 *  Retrieve the most recently calculated data.
 *
 *  @return An `NSData` object.
 */
- (nullable NSData *)retrieveData;

@end
