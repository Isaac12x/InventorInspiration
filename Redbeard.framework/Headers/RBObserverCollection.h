//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RBObserverCollectionDelegate;

/**
 *  A weak or strong collection of observer delegates.
 */
@interface RBObserverCollection : NSObject

/**
 *  A delegate to be informed of collection events.
 */
@property (nonatomic, weak, nullable) id<RBObserverCollectionDelegate> delegate;

/**
 *  The number of observers currently referenced in the collection.
 */
@property (nonatomic, readonly) NSUInteger observerCount;

/**
 *  Whether or not the delegate observers are stored with strong references (retained).
 */
@property (nonatomic, readonly) BOOL doesRetainObservers;

/**
 *  Add a new delegate observer to the collection.
 *
 *  @param observer The observer object to add to the collection.
 */
- (void)addObserver:(nonnull id)observer;

/**
 *  Remove a delegate observer from the collection.
 *
 *  @param observer The observer object to remove from the collection.
 */
- (void)removeObserver:(nonnull id)observer;

/**
 *  Enumerates the delegate observer objects in the collection.
 *
 *  @param enumerationBlock The enumeration block to call on each delegate observer object.
 */
- (void)enumerateObserversWithBlock:(nonnull void(^)(id __nonnull observer, BOOL * __nonnull stop))enumerationBlock;

/**
 *  Initializes a new observer collection that keeps weak references (does not retain)
 *  to its delegate observer objects.
 *
 *  @return The initialized observer collection object.
 */
- (nonnull instancetype)init;

/**
 *  Initializes a new observer collection that keeps strong references (retains) to its
 *  delegate observer objects.
 *
 *  @return The initialized observer collection object.
 */
- (nonnull instancetype)initWithObserverRetention;

@end

/**
 *  A delegate observer collection delegate.
 */
@protocol RBObserverCollectionDelegate <NSObject>

@optional

/**
 *  Called when the last delegate observer was removed and the collection became empty.
 *
 *  @param observerCollection The observer collection object.
 */
- (void)observerCollectionBecameEmpty:(nonnull RBObserverCollection *)observerCollection;

/**
 *  Called when the first delegate observer was added and the collection became non-empty.
 *
 *  @param observerCollection The observer collection object.
 */
- (void)observerCollectionBecameNonEmpty:(nonnull RBObserverCollection *)observerCollection;

@end
