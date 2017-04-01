//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

// Note - a given key can exist in only one group.

extern const NSUInteger defaultMaximumDiskCacheSize;

/**
 *  A cache that persists items to disk.
 */
@interface RBDataPersistentCache : NSObject

/**
 *  Whether or not the cache is valid or an error occurred and the cache is invalid.
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 *  The error that occurred if the cache is invalid.
 */
@property (nonatomic, readonly, nullable) NSError *error;

/**
 *  The path to which items are stored.
 */
@property (nonatomic, readonly, nonnull) NSString *storagePath;

/**
 *  The maximum size in bytes of the cache.
 */
@property (nonatomic, readonly) NSUInteger maximumCacheSizeInBytes;

/**
 *  The current size of the cache in bytes.
 */
@property (atomic, readonly) NSUInteger cacheSizeInBytes;

/**
 *  Initializes a new persistent cache with default settings.
 *
 *  @return The initialized persistent cache.
 */
- (nonnull instancetype)init;

/**
 *  Initializes a new persistent cache with the given settings.
 *
 *  @param storagePath             The path at which to store items.
 *  @param maximumCacheSizeInBytes The maximum size of the cache in bytes.
 *  @param ns                      The namespace of the cache.
 *
 *  @return The initialized cache.
 */
- (nonnull instancetype)initWithStoragePath:(nonnull NSString *)storagePath
                   maximumCacheSize:(NSUInteger)maximumCacheSizeInBytes
                          namespace:(nonnull NSString *)ns;

/**
 *  Asynchronously stores the given data item.
 *
 *  @param dataItem       The data item to store.
 *  @param key            The unique key to store the item with.
 *  @param group          The group in which to store the item (optional).
 *  @param expiryInterval The time span after which the item expires.
 *  @param completion     An optional block to be called when storage is complete.
 */
- (void)storeDataItem:(nonnull NSData *)dataItem
                  key:(nonnull NSString *)key
                group:(nullable NSString *)group
       expiryInterval:(NSTimeInterval)expiryInterval
           completion:(nullable dispatch_block_t)completion;

/**
 *  Determines whether a non-expired item is stored for the given key.
 *
 *  @param key The key to search for.
 *
 *  @return Whether or not an item was found.
 */
- (BOOL)dataItemExistsWithKey:(nonnull NSString *)key;

/**
 *  Determines whether a non-expired item is stored for the given key.
 *
 *  @param key        The key to search for.
 *  @param completion The completion block that is called with the result.
 */
- (void)fetchDataItemWithKey:(nonnull NSString *)key
                  completion:(nonnull void(^)(NSData * __nullable data))completion;

/**
 *  Removes the data item stored with the given key.
 *
 *  @param key The key with which the item stored is to be removed.
 */
- (void)removeDataItemWithKey:(nonnull NSString *)key;

/**
 *  Removes all stored data items in the given group.
 *
 *  @param group The group to remove all stored data items in.
 */
- (void)removeAllItemsWithGroup:(nonnull NSString *)group;

/**
 *  Removes all stored data items in the cache.
 */
- (void)removeAllExpiredItems;

@end
