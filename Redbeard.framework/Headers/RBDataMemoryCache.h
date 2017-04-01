//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const NSUInteger defaultMaximumMemoryCacheSize;

/**
 *  A managed memory cache for `NSData` objects.
 */
@interface RBDataMemoryCache : NSObject

/**
 *  The maximum size that the cache can be in bytes.
 */
@property (nonatomic, readonly) NSUInteger maximumCacheSizeInBytes;

/**
 *  The current size of the cache.
 */
@property (nonatomic, readonly) NSUInteger cacheSizeInBytes;

/**
 *  Creates a new cache with the given maximum size.
 *
 *  @param maximumCacheSizeInBytes The maximum size that the cache can be in bytes.
 *
 *  @return The new cache object.
 */
- (nonnull instancetype)initWithMaximumCacheSize:(NSUInteger)maximumCacheSizeInBytes;

/**
 *  Store a data item in the cache.
 *
 *  @param dataItem       The `NSData` object.
 *  @param key            The unique key to store the data with.
 *  @param group          The group name to store the data in (optional).
 *  @param expiryInterval The time span after which the data is expired and removed.
 */
- (void)storeDataItem:(nonnull NSData *)dataItem
                  key:(nonnull NSString *)key
                group:(nullable NSString *)group
       expiryInterval:(NSTimeInterval)expiryInterval;

/**
 *  Determines whether or not a data item is stored with the given key.
 *
 *  @param key The key for which to check if there is a data item stored.
 *
 *  @return Whether a data item was found with the key.
 */
- (BOOL)dataItemExistsWithKey:(nonnull NSString *)key;

/**
 *  Retrieves the data item stored with the given key.
 *
 *  @param key The key with which to retrieve the data item.
 *
 *  @return The retrieved data item.
 */
- (nullable NSData *)fetchDataItemWithKey:(nonnull NSString *)key;

/**
 *  Remove the data item stored with the given key.
 *
 *  @param key The key to remove the stored data item for.
 */
- (void)removeDataItemWithKey:(nonnull NSString *)key;

/**
 *  Remove all of the items stored in the given group.
 *
 *  @param group The group for which to remove all stored data items.
 */
- (void)removeAllItemsWithGroup:(nonnull NSString *)group;

/**
 *  Removes all data items that have expired.
 */
- (void)removeAllExpiredItems;

@end
