//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RBORMObject;

/**
 *  Provides a FLUENT API for querying an SQLite database.
 */
@interface RBORMQuery : NSObject<NSCopying>

/**
 *  Creates a new DELETE query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)deleteQueryWithObjectType:(nonnull Class)objectType withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new SELECT query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)selectQueryWithObjectType:(nonnull Class)objectType withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new COUNT aggregate query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param propertyName       The name of the property who's values will be aggregated.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)countQueryWithObjectType:(nonnull Class)objectType ofProperty:(nonnull NSString *)propertyName withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new SUM aggregate query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param propertyName       The name of the property who's values will be aggregated.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)sumQueryWithObjectType:(nonnull Class)objectType ofProperty:(nonnull NSString *)propertyName withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new MIN aggregate query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param propertyName       The name of the property who's values will be aggregated.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)minQueryWithObjectType:(nonnull Class)objectType ofProperty:(nonnull NSString *)propertyName withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new MAX aggregate query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param propertyName       The name of the property who's values will be aggregated.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)maxQueryWithObjectType:(nonnull Class)objectType ofProperty:(nonnull NSString *)propertyName withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  Creates a new AVERAGE aggregate query for the given object type.
 *
 *  @param objectType         The type of object that will be queried.
 *  @param propertyName       The name of the property who's values will be aggregated.
 *  @param databaseIdentifier The identifier of the database to use.
 *
 *  @return An initialized instance of the `RBORMQuery` class.
 */
+ (nonnull instancetype)averageQueryWithObjectType:(nonnull Class)objectType ofProperty:(nonnull NSString *)propertyName withDatabaseIdentifier:(nonnull NSString *)databaseIdentifier;

/**
 *  The identifier of the database that the query will be executed on.
 */
@property (nonatomic, readonly, nonnull) NSString *databaseIdentifer;

/**
 *  The type of object (and corresponding database table) that the query will be executed on.
 */
@property (nonatomic, readonly, nonnull) Class objectType;

/**
 *  Whether or not the query will yield a scalar result type (such as a number).
 */
@property (nonatomic, readonly) BOOL isScalar;

/**
 *  Whether or not the query will not yield a value result, but rather the number of rows affected or an error message.
 */
@property (nonatomic, readonly) BOOL isNonQuery;

/**
 *  The SQL query string that represents this query.
 */
@property (nonatomic, readonly, nonnull) NSString *queryString;

/**
 *  The bindings that are associated respectively with the binding references in `queryString`.
 */
@property (nonatomic, readonly, nullable) NSArray *bindings;

/**
 *  Compiles and executes the query.
 *
 *  @return An `NSArray` containing a list of any returned results as managed `RBORMObject` objects. In the case of scalar queries use [array firstObject] to retrieve the scalar value. Will return nil on error.
 */
- (nullable NSArray *)execute;

#pragma mark -
#pragma mark Clauses

/**
 *  The SQL 'WHERE' clause.
 *
 *  @param criteria A filter indicating which rows to return, formatted as an SQL WHERE clause (excluding the WHERE itself).
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)where:(nonnull NSString *)criteria;

/**
 *  The SQL 'WHERE' clause.
 *
 *  @param criteria A filter indicating which rows to return, formatted as an SQL WHERE clause (excluding the WHERE itself). The criteria may contain '?' bindings.
 *  @param bindings An array of items the provide the values that should correspond to the '?' bidnings specified in the criteria.
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)where:(nonnull NSString *)criteria bindings:(nullable NSArray *)bindings;

/**
 *  THE SQL 'ORDER BY' clause.
 *
 *  @param orderBy The order in which to return the resultant rows formatted as a SQL ORDER BY clause (exclude the ORDER BY itself). Passing null will ommit any ordering
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)orderBy:(nonnull NSString *)orderBy;

/**
 *  The SQL 'LIMIT' clause.
 *
 *  @param limit The maximum number of results to return passing `0` returns all matching rows.
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)limit:(NSUInteger)limit;

/**
 *  The SQL 'OFFSET' clause.
 *
 *  @param offset The offset from which to returns rows from. A 'LIMIT' must be provided for this to take affect, this is ignored otherwise.
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)offset:(NSUInteger)offset;


#pragma mark -
#pragma mark Relational Clauses

/**
 *  Selects only those items who's foreign key property name given refers to the object given.
 *
 *  @param object       The object to filter relations to.
 *  @param propertyName The name of the foreign key property on the receiver class.
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)relatedTo:(nonnull RBORMObject *)object withKeyProperty:(nonnull NSString *)propertyName;


#pragma mark -
#pragma mark Switching Database Identifiers

/**
 *  The database identifier for this query. Set to `DEFAULT_DATABASE_IDENTIFIER` by default.
 *
 *  @param identifier A database identifier indicating which specific database this query should be run on.
 *
 *  @return The updated `RBORMQuery` object.
 */
- (nonnull RBORMQuery *)forDatabaseIdentifier:(nonnull NSString *)identifier;

@end
