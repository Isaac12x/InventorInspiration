//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Listens for global events.
 */
@protocol RBEventListener <NSObject>

@required

/**
 * Receives and handles a raised event.
 *
 * @param eventName  The name of the event raised.
 * @param sender     The object that raised the event.
 * @param data       The user data associated with the event.
 * @param completion The completion block to call when the event has been handled.
 */
- (void)event:(nonnull NSString *)eventName
  wasRaisedBy:(nullable id)sender
     withData:(nullable id)data
   completion:(nullable dispatch_block_t)completion;

@end

/**
 * The global events center.
 */
@interface RBEventCenter : NSObject

/**
 * Register an object as a listener for an event.
 *
 * @param listener  An object that implements `RBEventListener`.
 * @param eventName The name of the event to be notified of.
 */
+ (void)registerListener:(nonnull id<RBEventListener>)listener
                forEvent:(nonnull NSString *)eventName;

/**
 * Unregister an object as a listener for an event.
 *
 * @param listener  The currently registered listener for the event.
 * @param eventName The name of the event to stop being notified of.
 */
+ (void)unregisterListener:(nonnull id<RBEventListener>)listener
                  forEvent:(nonnull NSString *)eventName;

/**
 * Unregister an object as a listener for all events.
 *
 * @param listener  The currently registered listener for one or more events.
 */
+ (void)unregisterListener:(nonnull id<RBEventListener>)listener;

/**
 * Raise an event.
 *
 * @param eventName             The name of the event to raise.
 * @param sender                The object that raised the event.
 * @param data                  User data to provide to listeners of the event.
 * @param handleSynchronously   Whether the listeners will be informed synchronously (`true`) or simultaneously (`false`).
 * @param completion            The completion block to be called when the event has been handled.
 */
+ (void)raiseEventWithName:(nonnull NSString *)eventName
                withSender:(nullable id)sender
                  withData:(nullable id)data
       handleSynchronously:(BOOL)handleSynchronously
                completion:(nullable dispatch_block_t)completion;

@end
