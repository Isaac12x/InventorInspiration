//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Manages a queue of items to be processed.
 */
@interface RBProcessingQueue : NSObject

/**
 *  The total set of items that were queued to be processed.
 */
@property (nonatomic, readonly, nullable) NSSet *items;

/**
 *  The set of items that were queued and have been processed.
 */
@property (nonatomic, readonly, nullable) NSSet *processedItems;

/**
 *  The set of items that were queued and have not yet been processed.
 */
@property (nonatomic, readonly, nullable) NSSet *pendingItems;

/**
 *  Adds a new item to the queue to be processed.
 *
 *  @param item The item to add to the queue.
 */
- (void)enqueueItem:(nonnull id)item;

/**
 *  Marks whether an item in the queue has been processed.
 *
 *  @param item      The item to mark as processed or not processed.
 *  @param processed Whether or not the item should be marked as processed (true) or unprocessed (false).
 */
- (void)markItem:(nonnull id)item asProcessed:(BOOL)processed;

@end
