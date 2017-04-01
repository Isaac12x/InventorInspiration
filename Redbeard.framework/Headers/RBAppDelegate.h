//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBObserverCollection.h>

/**
 *  An application-delegate observer.
 *  These can be registered with RBAppDelegate to provide application-delegate functionality.
 */
@protocol RBAppDelegateObserver <NSObject>

@optional

/**
 *  This event is raised when the application has finished launching.
 */
- (void)applicationDidFinishLaunching;

/**
 *  This event is raised when the application is about to finish launching.
 *
 *  @param launchOptions A dictionary of launch options.
 *  @returns Whether the tasks performed in the handler were successful.
 */
- (BOOL)applicationWillFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

/**
 *  This event is raised when the application has finished launching.
 *
 *  @param launchOptions A dictionary of launch options.
 *  @returns Whether the tasks performed in the handler were successful.
 */
- (BOOL)applicationDidFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

/**
 *  This event is raised when the application has been entered the active state.
 */
- (void)applicationDidBecomeActive;

/**
 *  This event is raised when the application is about to exit the active state.
 *  For example when the user switches to another application.
 */
- (void)applicationWillResignActive;

/**
 *  This function is called to determine whether this application will handle
 *  a given URL.
 *
 *  @param url The URL that has been opened on the device.
 *  @returns Whether this application should handle the given URL.
 */
- (BOOL)applicationHandleOpenURL:(nonnull NSURL *)url;

/**
 *  This event is raised to allow the application to handle a URL open event.
 *
 *  @param url The URL that has been opened on the device and should be handled.
 *  @param sourceApplication The identifier of the application that opened this URL.
 *  @param annotation The annotation to the event, if any.
 *  @returns `true` if the handling of this URL was successful.
 */
- (BOOL)applicationOpenURL:(nonnull NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(nonnull id)annotation;

/**
 *  This event is raised to allow the application to handle a URL open event.
 *
 *  @param url The URL that has been opened on the device and should be handled.
 *  @param options The passed options.
 *  @returns `true` if the handling of this URL was successful.
 */
- (BOOL)applicationOpenURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString*, id> *)options;

/**
 *  This event is raised when the application has received a memory warning and should
 *  reduce it's memory footprint as much as is safe.
 */
- (void)applicationDidReceiveMemoryWarning;

/**
 *  This event is raised when the application is about to terminate, which occurs for example
 *  when the user swipes to kill the application.
 */
- (void)applicationWillTerminate;

/**
 *  This event is raised when there has been a significant time change.  For example the arrival
 *  of midnight or a timezone change.
 */
- (void)applicationSignificantTimeChange;

/**
 *  This event is raised when the application is about to change the orientation of the status bar.
 *
 *  @param newStatusBarOrientation The new orientation that the status bar will transition to.
 *  @param duration The time duration that the animation will occur over.
 */
- (void)applicationWillChangeStatusBarOrientation:(UIInterfaceOrientation)newStatusBarOrientation duration:(NSTimeInterval)duration;

/**
 *  This event is raised when the application has changed the orientation of the status bar.
 *
 *  @param oldStatusBarOrientation The orientation that the status bar did transition from.
 */
- (void)applicationDidChangeStatusBarOrientation:(UIInterfaceOrientation)oldStatusBarOrientation;

/**
 *  This event is raised when the application is about to change the frame of the status bar.
 *
 *  @param newStatusBarFrame The new frame that the status bar will transition to.
 */
- (void)applicationWillChangeStatusBarFrame:(CGRect)newStatusBarFrame;

/**
 *  This event is raised when the application has changed the frame of the status bar.
 *
 *  @param oldStatusBarFrame The frame that the status bar did transition from.
 */
- (void)applicationDidChangeStatusBarFrame:(CGRect)oldStatusBarFrame;

/**
 *  Called when the application has registered a new user notification.
 *
 *  @param notificationSettings The settings of the user notification that was registered.
 */
- (void)applicationDidRegisterUserNotificationSettings:(nonnull UIUserNotificationSettings *)notificationSettings;

/**
 *  Called when the application has registered for remote notifications from devices with the given token.
 *
 *  @param deviceToken The device token that the application has registered for.
 */
- (void)applicationDidRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData *)deviceToken;

/**
 *  Called when the application has failed to register for remote notifications.
 *
 *  @param error The error that occurred.
 */
- (void)applicationDidFailToRegisterForRemoteNotificationsWithError:(nonnull NSError *)error;

/**
 *  Called when the application has received a remote notification.
 *
 *  @param userInfo The user information for the remote notification that was received.
 */
- (void)applicationDidReceiveRemoteNotification:(nonnull NSDictionary *)userInfo;

/**
 *  Called when the application has received a local notification.
 *
 *  @param notification The `UILocalNotification` object.
 */
- (void)applicationDidReceiveLocalNotification:(nonnull UILocalNotification *)notification;

/**
 *  Called when the application needs to handle an action with the given identifier for
 *  a local notification.
 *
 *  @param identifier        The identifier of the action to be performed.
 *  @param notification      The local notification that the action belongs to.
 *  @param completionHandler The completion block to be called when the action has been performed.
 */
- (void)applicationHandleActionWithIdentifier:(nullable NSString *)identifier
                         forLocalNotification:(nonnull UILocalNotification *)notification
                            completionHandler:(nonnull dispatch_block_t)completionHandler;

/**
 *  Called when the application needs to handle an action with the given identifier for
 *  a local notification.
 *
 *  @param identifier        The identifier of the action to be performed.
 *  @param notification      The local notification that the action belongs to. belongs to.
 *  @param responseInfo      The response info.
 *  @param completionHandler The completion block to be called when the action has been performed.
 */
- (void)applicationHandleActionWithIdentifier:(nullable NSString *)identifier
                        forLocalNotification:(nonnull UILocalNotification *)notification
                             withResponseInfo:(nonnull NSDictionary *)responseInfo
                            completionHandler:(nonnull dispatch_block_t) completionHandler;

/**
 *  Called when the application needs to handle an action with the given identifier for
 *  a remote notification.
 *
 *  @param identifier        The identifier of the action to be performed.
 *  @param userInfo          The user information of the remote notification that the action belongs to.
 *  @param completionHandler The completion block to be called when the action has been performed.
 */
- (void)applicationHandleActionWithIdentifier:(nullable NSString *)identifier
                        forRemoteNotification:(nonnull NSDictionary *)userInfo
                            completionHandler:(nonnull dispatch_block_t)completionHandler;

/**
 *  Called when the application needs to handle an action with the given identifier for
 *  a remote notification.
 *
 *  @param identifier        The identifier of the action to be performed.
 *  @param userInfo          The user information of the remote notification that the action belongs to.
 *  @param responseInfo      The response info.
 *  @param completionHandler The completion block to be called when the action has been performed.
 */
- (void)applicationHandleActionWithIdentifier:(nullable NSString *)identifier
                        forRemoteNotification:(nonnull NSDictionary *)userInfo
                             withResponseInfo:(nonnull NSDictionary *)responseInfo
                            completionHandler:(nonnull dispatch_block_t) completionHandler;

/**
 *  Called when the application has received a remote notification.
 *
 *  @param userInfo          The user information of the remote notification that was received.
 *  @param completionHandler The completion block to call when the notification has been processed.
 */
- (void)applicationDidReceiveRemoteNotification:(nonnull NSDictionary *)userInfo
                         fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult result))completionHandler;

/**
 *  Called when the application needs to perform a fetch.
 *
 *  @param completionHandler The completion block to call when the fetch is complete.
 */
- (void)applicationPerformFetchWithCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult result))completionHandler;

/**
 *  Called when a user selects your application from a shortcut on the homescreen.
 *
 *  @param shortcutItem The shortcut item that was selected.
 *  @param completionHandler The completion block to call when action has been performed.
 */
- (void)applicationPerformActionForShortcutItem:(nonnull UIApplicationShortcutItem *)shortcutItem completionHandler:(nonnull void(^)(BOOL succeeded))completionHandler;

/**
 *  Called when the application should handle events for a background URL session.
 *
 *  @param identifier        The identifier of the background URL session.
 *  @param completionHandler The completion block to call when the events have been handled.
 */
- (void)applicationHandleEventsForBackgroundURLSession:(nonnull NSString *)identifier
                                     completionHandler:(nonnull dispatch_block_t)completionHandler;

/**
 *  Called when the application should handle a watch kit extension request.
 *
 *  @param userInfo     The user info.
 *  @param reply        The reply block.
 */
- (void)applicationHandleWatchKitExtensionRequest:(nullable NSDictionary *)userInfo reply:(nonnull void(^)(NSDictionary * __nullable replyInfo))reply;

/**
 *  Called when a health kit request is made.
 */
- (void)applicationShouldRequestHealthAuthorization;

/**
 *  Called when the application has entered the background and the user is no longer directly interacting with the app.
 */
- (void)applicationDidEnterBackground;

/**
 *  Called when the application is about to enter the foreground for use by the user.
 */
- (void)applicationWillEnterForeground;

/**
 *  Called when the application will lose access to protected data.
 */
- (void)applicationProtectedDataWillBecomeUnavailable;

/**
 *  Called when the application will gain access to protected data.
 */
- (void)applicationProtectedDataDidBecomeAvailable;

/**
 *  Called to determine which interface orientations the application supports for the given window.
 *
 *  @param window The `UIWindow` object.
 *
 *  @return A mask of the supported interface orientations.
 */
- (NSUInteger)applicationSupportedInterfaceOrientationsForWindow:(nullable UIWindow *)window;

/**
 *  Called to determine whether the application should allow the extension point identifier given.
 *
 *  @param extensionPointIdentifier The extension point identifier string.
 *
 *  @return Whether or not permission is granted.
 */
- (BOOL)applicationShouldAllowExtensionPointIdentifier:(nonnull NSString *)extensionPointIdentifier;

#pragma mark -
#pragma mark State Restoration protocol adopted by UIApplication delegate

/**
 *  Called to restore the `UIViewController` object using the given restoration identifier path.
 *
 *  @param identifierComponents The components of the restoration identifier path.
 *  @param coder                The `NSCoder` object.
 *
 *  @return The restored `UIViewController` object.
 */
- (nullable UIViewController *)applicationViewControllerWithRestorationIdentifierPath:(nonnull NSArray *)identifierComponents
                                                                                coder:(nonnull NSCoder *)coder;

/**
 *  Called to determine whether the application should save it's application state.
 *
 *  @param coder The `NSCoder` object.
 *
 *  @return Whether or not to save the application state.
 */
- (BOOL)applicationShouldSaveApplicationState:(nonnull NSCoder *)coder;

/**
 *  Called to determine whether the application should restore it's application state.
 *
 *  @param coder The `NSCoder` object.
 *
 *  @return Whether or not to restore the application state.
 */
- (BOOL)applicationShouldRestoreApplicationState:(nonnull NSCoder *)coder;

/**
 *  Called when the application will encode/serialise it's restorable application state with the given coder.
 *
 *  @param coder The `NSCoder` object.
 */
- (void)applicationWillEncodeRestorableStateWithCoder:(nonnull NSCoder *)coder;

/**
 *  Called when the application has encoded/serialised it's restorable application state with the given coder.
 *
 *  @param coder The `NSCoder` object.
 */
- (void)applicationDidDecodeRestorableStateWithCoder:(nonnull NSCoder *)coder;

#pragma mark -
#pragma mark User Activity Continuation protocol adopted by UIApplication delegate

/**
 *  Called to determine whether the application will continue user activity with the given type.
 *
 *  @param userActivityType The user activity type string.
 *
 *  @return Whether or not the activity will continue.
 */
- (BOOL)applicationWillContinueUserActivityWithType:(nonnull NSString *)userActivityType;

/**
 *  Called to continue the user activity given.
 *
 *  @param userActivity       The `NSUserActivity` object of the activity to continue.
 *  @param restorationHandler A block to call to provide the restorable objects.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)applicationContinueUserActivity:(nonnull NSUserActivity *)userActivity restorationHandler:(nonnull void(^)(NSArray * __nullable restorableObjects))restorationHandler;

/**
 *  Called when the application failed to continue a user activity with the given type.
 *
 *  @param userActivityType The user activity type string.
 *  @param error            The error that occurred.
 */
- (void)applicationDidFailToContinueUserActivityWithType:(nonnull NSString *)userActivityType error:(nonnull NSError *)error;

/**
 *  Called when the application successfully updated the given user activity.
 *
 *  @param userActivity The `NSUserActivity` object.
 */
- (void)applicationDidUpdateUserActivity:(nonnull NSUserActivity *)userActivity;

@end

/**
 * The Redbeard Application Delegate.
 * Objects that implement RBAppDelegateObserver can be registered to respond to
 * application-delegate events.
 */
@interface RBAppDelegate : UIResponder<UIApplicationDelegate>

/** The UIWindow of the iOS application. */
@property (nonatomic, nullable) UIWindow *window;

/**
 * The collection of observers that implement RBAppDelegateObserver and
 * receive and respond to application-delegate events.
 */
@property (nonatomic, readonly, nonnull) RBObserverCollection *observers;

@end
