//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Redbeard/RBSQLiteResultSet.h>

#import <Redbeard/RBIntrospectiveObject.h>
#import <Redbeard/RBIntrospectiveObjectPropertySchema.h>

#import <Redbeard/RBORMQuery.h>

#define PRIMARY_KEY_COLUMN_NAME (@"pk")

/**
 *  Provides a managed ORM (Object relationship management) object for use with SQLite.
 *
 *  - Note: NSDates are automatically serialized and deserialized. Dates are stored on disk in the ISO 8601 format.
 */
@interface RBORMObject : RBIntrospectiveObject

/**
 *  Returns the table name to be used. The default implementation returns the name of the class stripping any non alphanumeric characters.
 *
 *  @return The name of the table.
 */
+ (nonnull NSString *)tableName;

/**
 *  A list of the nullable properties for this object.
 *
 *  @return A list of the properites that are permitted to be null or nil.
 */
+ (nonnull NSArray<NSString *> *)nullableProperties;

/**
 *  A mapping of property names to database column names when the names differ.
 *
 *  @return A mapping of the property names and their corresponding database column names.
 */
+ (nonnull NSDictionary<NSString *, NSString *> *)propertiesToColumnNames;

/**
 *  The primary key assigned to this object by SQLite. Will be set to a value < 1 if the object has not yet been saved.
 */
@property (readonly) NSInteger pk;

/**
 *   Indiciates that a valid primary key value has been set and assigned by SQLite.
 */
@property (nonatomic, readonly) BOOL hasPrimaryKey;

/**
 *  The database identifier this object is associated it. This allows multiple databases to be used at once.
 */
@property (readonly, nonnull) NSString *databaseIdentifier;

/**
 *  Initializes a new `RBORMObject` object with the default database identifier (`DEFAULT_DATABASE_IDENTIFIER`).
 *
 *  @return A newly initialized `RBORMObject` object.
 */
- (nonnull instancetype)init;

/**
 *  Initializes a new `RBORMObject` object with a specific database identifier.
 *
 *  @param identifier The database identifier.
 *
 *  @return A newly initialized `RBORMObject` object.
 */
- (nonnull instancetype)initWithDatabaseIdentifier:(nonnull NSString *)identifier;

/**
 *  Deletes this object from the database. Do not override this method.
 *
 *  @return Returns `YES` if successful.
 */
- (BOOL)deleteFromDatabase;

/**
 *  Saves this object. An insert or update occurs as needed.
 *
 *  @return Returns `YES` if successful.
 */
- (BOOL)save;

#pragma mark -
#pragma mark Subclassing

/**
 *  This method is called before inserting.
 */
- (void)willInsert;

/**
 *  This method is called before updating.
 */
- (void)willUpdate;

/**
 *  Called after inserting.
 *
 *  @param success If `YES` then the object has been saved successfully.
 */
- (void)didInsert:(BOOL)success;

/**
 *  Called after updating.
 *
 *  @param success If `YES` then the object has been saved successfully.
 */
- (void)didUpdate:(BOOL)success;

/**
 *  This method is called before deletion.
 */
- (void)willDeleteFromDatabase;

/**
 *  Called after deletion.
 *
 *  @param success If `YES` then the object has been saved deleted.
 */
- (void)didDeleteFromDatabase:(BOOL)success;

/**
 *  This method is called before populating the data in the object instance.
 */
- (void)willPopulate;

/**
 *  Called after population.
 *
 *  @param success If `YES` then the object has been saved populated.
 */
- (void)didPopulate:(BOOL)success;


#pragma mark -
#pragma mark Class methods

/**
 *  Initializes a new `RBORMObject` object with the default database identifier (`DEFAULT_DATABASE_IDENTIFIER`).
 *
 *  @return A newly initialized `RBORMObject` object.
 */
+ (nonnull instancetype)objectWithDefaultDatabaseIdentifier;

/**
 *  Initializes a new `RBORMObject` object with a specific database identifier.
 *
 *  @param identifier The database identifier.
 *
 *  @return A newly initialized `RBORMObject` object.
 */
+ (nonnull instancetype)objectWithDatabaseIdentifier:(nonnull NSString *)identifier;

/**
 *  Initializes a new `RBORMObject` object using the specified `NSDictionary` to populate it with and a database identifier.
 *
 *  @param record     The data to used for populating.
 *  @param identifier The database identifier.
 *
 *  @return A newly initialized and populated `RBORMObject` object.
 */
+ (nonnull instancetype)populateWithDictionary:(nonnull NSDictionary<NSString *, id> *)record databaseIdentifier:(nonnull NSString *)identifier;

/**
 *  Initializes a new `RBORMObject` object from a `RBSQLiteResultSet` given the row index and a database identifier.
 *
 *  @param results    The `RBSQLiteResultSet` to be used for populating.
 *  @param row        The row index within the `RBSQLiteResultSet` to use.
 *  @param identifier The database identifier.
 *
 *  @return A newly initialized and populated `RBORMObject` object.
 */
+ (nonnull instancetype)populateWithResultSet:(nonnull RBSQLiteResultSet *)results atRow:(NSUInteger)row databaseIdentifier:(nonnull NSString *)identifier;

#pragma mark -
#pragma mark Table

/**
 *  Determines whether a table exists for this object type in the database who's identifier is provided.
 *
 *  @param identifier The identifier of the database.
 *
 *  @return Whether or not the table exists.
 */
+ (BOOL)tableExistsWithDatabaseIdentifier:(nonnull NSString *)identifier;

/**
 *  Creates the table for this object type in the database who's identifier is provided, only if the table is missing.
 *
 *  @param identifier The identifier of the database.
 *
 *  @return Whether or not the table exists or was created.
 */
+ (BOOL)createTableIfMissingWithDatabaseIdentifier:(nonnull NSString *)identifier;

#pragma mark -
#pragma mark Query Methods

/**
 *  Returns the object for the given primary key value.
 *
 *  @param pk   The primary key. Must be > 0.
 *
 *  @return The object matching the primary key or `nil` if not found.
 */
+ (nullable instancetype)forPk:(NSInteger)pk;

/**
 *  Executes a given SQL query string with the given bindings on the database who's identifier is given.
 *  Expects the results to be of the receiver type, which are then deserialised and an array of objects is
 *  returned.
 *
 *  @param queryString        The SQL query string to execute.
 *  @param bindings           The corresponding bindings for the SQL query string given.
 *  @param databaseIdentifier The identifier of the database to query.
 *
 *  @return An array of the resulting objects of the receiver's type or nil on error.
 */
+ (nullable NSArray<__kindof RBORMObject *> *)executeQueryWithString:(nonnull NSString *)queryString bindings:(nullable NSArray *)bindings databaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new `RBORMQuery` as an SQL 'SELECT * FROM [table name]' query.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array of 0 or more typed objects will be returned.
 */
+ (nonnull RBORMQuery *)select;

/**
 *  Creates a new `RBORMQuery` as an SQL 'DELETE FROM [table name]' query.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array containing a single item of type `NSNumber` containing a boolean value will be returned.
 */
+ (nonnull RBORMQuery *)delete;

/**
 *  Creates a new `RBORMQuery` as an SQL 'SELECT COUNT(*)' query.
 *
 *  @param propertyName The property corresponding to the database column that should be counted.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array containing a single item of type `NSNumber` will be returned.
 */
+ (nonnull RBORMQuery *)countOf:(nonnull NSString *)propertyName;

/**
 *  Creates a new `RBORMQuery` as an SQL 'SELECT SUM([property]) FROM [table name]' query.
 *
 *  @param propertyName The property corresponding to the database column that should be summed.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array containing a single item of type `NSNumber` or `[NSNull null] will be returned.
 */
+ (nonnull RBORMQuery *)sumOf:(nonnull NSString *)propertyName;

/**
 *  Creates a new `RBORMQuery` as an SQL 'SELECT AVG([property]) FROM [table name]' query.
 *
 *  @param propertyName The property corresponding to the database column that should be averaged.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array containing a single item of type `NSNumber` or `[NSNull null] will be returned.
 */
+ (nonnull RBORMQuery *)averageOf:(nonnull NSString *)propertyName;

/**
 *  Creates a new `RBORMQuery` as an SQL 'SELECT MIN([property]) FROM [table name]' query.
 *
 *  @param propertyName The property corresponding to the database column that should be averaged.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array containing a single item of type `NSNumber` or `[NSNull null] will be returned.
 */
+ (nonnull RBORMQuery *)minOf:(nonnull NSString *)propertyName;

/**
 *  Creates a new `RBORMQuery` as an SQL 'SELECT MAX([property]) FROM [table name]' query.
 *
 *  @param propertyName The property corresponding to the database column that should be averaged.
 *
 *  @return A newly initialized `RBORMQuery` object. When executing this query an array containing a single item of type `NSNumber` or `[NSNull null] will be returned.
 */
+ (nonnull RBORMQuery *)maxOf:(nonnull NSString *)propertyName;

@end
