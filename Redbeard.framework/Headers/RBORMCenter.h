//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBORMObject.h>
#import <Redbeard/RBSQLiteResult.h>
#import <Redbeard/RBSQLiteResultSet.h>
#import <Redbeard/RBSQLiteConnection.h>

/**
 *  The default database identifier
 */
#define DEFAULT_DATABASE_IDENTIFIER (@"*default*")

@protocol RBORMObserver;

/**
 *  Centrally manages SQLite databases and ORM objects.
 *
 *  - Manages multiple SQLite databases.
 *  - Creates tables.
 *  - Manages RBORMObjects, and provides CRUD support.
 *  - Runs SQL queries directly.
 */
@interface RBORMCenter : NSObject

/**
 * The shared singleton `RBORMCenter`.
 */
+ (nonnull RBORMCenter *)shared;

/**
 *  Registers an object to receive notifications whenever an interaction occurs with a managed `RBORMObject` or `RBSQLiteConnection` objects.
 *
 *  @param receiver The object that should receive notification events.
 *
 *  @return Returns `YES` if registration was succesful.
 */
- (BOOL)registerNotificationReceiver:(nonnull id<RBORMObserver>)receiver;

/**
 *  Detaches an existing object from receiving event notifications. 
 *
 *  @param receiver The object that should no longer receive notifications.
 */
- (void)deregisterNotificationReceiver:(nonnull id<RBORMObserver>)receiver;


/**
 *  Attaches a `RBSQLiteConnection` connection for management by the `RBORMCenter`.
 *
 *  @param databaseConnection The database connection to manage.
 *  @param identifier         An identifier which will be used to reference this specific database connection.
 *
 *  @return Returns `YES` if the `RBSQLiteConnection` was successfully attached.
 */
- (BOOL)attachDatabaseConnection:(nonnull RBSQLiteConnection *)databaseConnection withIdentifier:(nonnull NSString *)identifier;

/**
 *  Detaches an existing `RBSQLiteConnection` database connection.
 *
 *  @param identifier The database identifier reference for the database connection to detach.
 *
 *  @return Returns the detached `RBSQLiteConnection` connection or nil.
 */
- (nullable RBSQLiteConnection *)detachDatabaseConnectionWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Returns the `RBSQLiteConnection` database connection that corresponds to the specified identifier.
 *
 *  @param identifier The database identifier.
 *
 *  @return Returns the `RBSQLiteConnection` database connection or nil.
 */
- (nullable RBSQLiteConnection *)databaseConnectionForIdentifier:(nonnull NSString *)identifier;

/**
 *  Executes a SQL query directly on a database and returns a `RBSQLiteResult`.
 *
 *  @param queryString The formatted SQL query string, may contain '?' bindings.
 *  @param bindings    An array of items the provide the values that should correspond to the '?' bindings specified in the query string.
 *  @param identifier  The database identifier indicating which underlying database connection to query.
 *
 *  @return Returns a `RBSQLiteResult`.
 */
- (nullable RBSQLiteResult *)executeQuery:(nonnull NSString *)queryString bindings:(nullable NSArray *)bindings databaseIdentifier:(nonnull NSString *)identifier;

@end

/**
 *  Provides the abilitiy to receive notifications for various `RBORMCenter` events.
 */
@protocol RBORMObserver <NSObject>

@optional

/**
 *  Called when a database connection is about to be attached.
 *
 *  @param databaseConnection The `RBSQLiteConnection` database connection that will be attached.
 *  @param identifier         The corresponding database identifier.
 */
- (void)databaseConnection:(nonnull RBSQLiteConnection *)databaseConnection willAttachWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a database connection attachment request completes.
 *
 *  @param databaseConnection     The `RBSQLiteConnection` database connection that was attempted to be attached.
 *  @param identifier             The corresponding database identifier.
 *  @param operationWasSuccessful `Yes' is successful.
 */
- (void)databaseConnection:(nonnull RBSQLiteConnection *)databaseConnection didAttachWithIdentifier:(nonnull NSString *)identifier operationWasSuccessful:(BOOL)operationWasSuccessful;

/**
 *  Called when a database connection is about to be detached.
 *
 *  @param databaseConnection The `RBSQLiteConnection` database connection that will be detached.
 *  @param identifier         The corresponding database identifier.
 */
- (void)databaseConnection:(nonnull RBSQLiteConnection *)databaseConnection willDetachWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a database connection detachment request completes.
 *
 *  @param databaseConnection The `RBSQLiteConnection` database connection that was attempted to be detached.
 *  @param identifier         The corresponding database identifier.
 */
- (void)databaseConnection:(nonnull RBSQLiteConnection *)databaseConnection didDetachWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a `RBORMObject` object will be inserted.
 *
 *  @param object     The `RBORMObject` that will be inserted.
 *  @param identifier The database identifier that references the underlying database connection.
 */
- (void)object:(nonnull RBORMObject *)object willInsertWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a `RBORMObject` object will be updated.
 *
 *  @param object     The `RBORMObject` that will be updated.
 *  @param identifier The database identifier that references the underlying database connection.
 */
- (void)object:(nonnull RBORMObject *)object willUpdateWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a `RBORMObject` object insert request completes.
 *
 *  @param object                 The `RBORMObject` that was attempted to be inserted.
 *  @param identifier             The database identifier that references the underlying database connection.
 *  @param operationWasSuccessful `YES` if successful.
 *  @param result                 The `RBSQLiteResult` containing the return data or the error details if the operation failed.
 */
- (void)object:(nonnull RBORMObject *)object didInsertWithIdentifier:(nonnull NSString *)identifier operationWasSuccessful:(BOOL)operationWasSuccessful result:(nullable RBSQLiteResult *)result;

/**
 *  Called when a `RBORMObject` object update request completes.
 *
 *  @param object                 The `RBORMObject` that was attempted to be updated.
 *  @param identifier             The database identifier that references the underlying database connection.
 *  @param operationWasSuccessful `YES` if successful.
 *  @param result                 The `RBSQLiteResult` containing the return data or the error details if the operation failed.
 */
- (void)object:(nonnull RBORMObject *)object didUpdateWithIdentifier:(nonnull NSString *)identifier operationWasSuccessful:(BOOL)operationWasSuccessful result:(nullable RBSQLiteResult *)result;

/**
 *  Called when a `RBORMObject` object will be deleted.
 *
 *  @param object     The `RBORMObject` that will be deleted.
 *  @param identifier The database identifier that references the underlying database connection.
 */
- (void)object:(nonnull RBORMObject *)object willDeleteWithIdentifier:(nonnull NSString *)identifier;

/**
 *  Called when a `RBORMObject` object delete request completes.
 *
 *  @param object                 The `RBORMObject` that was attempted to be deleted.
 *  @param identifier             The database identifier that references the underlying database connection.
 *  @param operationWasSuccessful `YES` if successful.
 *  @param result                 The `RBSQLiteResult` containing the return data or the error details if the operation failed.
 */
- (void)object:(nonnull RBORMObject *)object didDeleteWithIdentifier:(nonnull NSString *)identifier operationWasSuccessful:(BOOL)operationWasSuccessful result:(nullable RBSQLiteResult *)result;

@end
