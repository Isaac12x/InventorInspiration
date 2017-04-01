//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  An array that allows non-contiguous (fragmented) indexes.
 */
@interface RBFragmentedArray : NSObject

/**
 *  The first (lowest) index of an object stored in the array.
 */
@property (nonatomic, readonly) NSUInteger firstIndex;

/**
 *  The last (highest) index of an object stored in the array.
 */
@property (nonatomic, readonly) NSUInteger lastIndex;

/**
 *  The number of objects stored in the array.
 */
@property (nonatomic, readonly) NSUInteger count;

/**
 *  The first object (with the lowest index) stored in the array.
 */
@property (nonatomic, readonly, nullable) id firstObject;

/**
 *  The last object (with the highest index) stored in the array.
 */
@property (nonatomic, readonly, nullable) id lastObject;

/**
 *  An array of indexes for which objects are stored in the array.
 */
@property (nonatomic, readonly, nonnull) NSArray *indexes;

/**
 *  Sets the object stored in the array at a given index.
 *
 *  @param object The object to store. If object is `nil` the object at index will be removed. 
 *  @param index  The index at which to store the object.
 */
- (void)setObject:(nullable id)object
          atIndex:(NSUInteger)index;

/**
 *  Removes the object stored at the given index.
 *
 *  @param index The index at which the object is stored.
 */
- (void)removeObjectAtIndex:(NSUInteger)index;

/**
 *  Removes all of the objects stored in the array.
 */
- (void)removeAllObjects;

/**
 *  Determines whether an object is stored at the given index.
 *
 *  @param index The index at which to check if an object is stored.
 *
 *  @return Whether or not an object is stored at the given index.
 */
- (BOOL)hasIndex:(NSUInteger)index;

/**
 *  Retrieves the object stored at the given index.
 *
 *  @param index The index to retrieve the object for.
 *
 *  @return The object stored at the index, or nil if there was no object found.
 */
- (nullable id)objectAtIndex:(NSUInteger)index;

/**
 *  Enumerates the objects stored in the array.
 *
 *  @param block The block to call on each object in the array.
 */
- (void)enumerateObjectsUsingBlock:(nonnull void (^)(id __nonnull obj, NSUInteger idx, BOOL * __nonnull stop))block;

/**
 *  Enumerates the objects stored in the array.
 *
 *  @param opts  The enumeration options to use.
 *  @param block The block to call on each object in the array.
 */
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts
                         usingBlock:(nonnull void (^)(id __nonnull obj, NSUInteger idx, BOOL * __nonnull stop))block;

/**
 *  Enumerates each object in the array for removal.
 *
 *  @param block The block to call on each object, if the block returns true the object is removed.
 */
- (void)enumerateObjectRemovalUsingBlock:(nonnull BOOL (^)(id __nonnull obj, NSUInteger idx, BOOL * __nonnull stop))block;

@end
