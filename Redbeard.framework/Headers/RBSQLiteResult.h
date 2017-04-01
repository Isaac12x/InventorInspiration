//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBSQLiteResultSet.h>

/** The source of an error when interacting with SQLite. */
typedef NS_ENUM(NSInteger, RBSQLiteResultErrorSource)
{
    /** The error was generated by the SQLite database. */
    RBSQLiteResultErrorSourceSQLite = 0,
    
    /** The error was generated by Redbeard. */
    RBSQLiteResultErrorSourceOther,
};

/**
 *  Holds information about the response from an SQLite database request.
 */
@interface RBSQLiteResult : NSObject

/**
 *  Indicates that the there were no errors either from SQLite or otherwise.
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 *  The error message if available detailing the error.
 */
@property (nonatomic, readonly, nullable) NSString *errorMessage;

/**
 *  The SQLite error code for the issue, for more details please visit https://www.sqlite.org/c3ref/c_abort.html
 */
@property (nonatomic, readonly) NSInteger sqliteErrorCode;

/**
 *  A `RBSQLiteResultSet` containing the data from a returned SQL query.
 */
@property (nonatomic, readonly, nullable) RBSQLiteResultSet *resultSet;

/**
 *  If an error occured, this will indicate the source of the failure.
 */
@property (nonatomic, readonly) RBSQLiteResultErrorSource errorSource;



/**
 *  Initializes a new `RBSQLiteResult` object and populating it with an existing `RBSQLiteResultSet`.
 *
 *  @param resultSet The `RBSQLiteResultSet` containing the data for this result.
 *
 *  @return A newly initialized and populated `RBSQLiteResult` object.
 */
- (nonnull instancetype)initWithResultSet:(nonnull RBSQLiteResultSet *)resultSet;

/**
 *  Initializes a new `RBSQLiteResult` object indicating a (non SQLite) failure occurred.
 *
 *  @param errorMessage The error message.
 *
 *  @return A newly initialized `RBSQLiteResult` object.
 */
- (nonnull instancetype)initWithErrorMessage:(nonnull NSString *)errorMessage;

/**
 *  Initializes a new `RBSQLiteResult` object indicating an SQLite) failure occurred.
 *
 *  @param sqliteErrorCode The SQLite error code, for more details please visit https://www.sqlite.org/c3ref/c_abort.html
 *  @param errorMessage    The error message.
 *
 *  @return A newly initialized `RBSQLiteResult` object.
 */
- (nonnull instancetype)initWithSQLiteErrorCode:(NSInteger)sqliteErrorCode withMessage:(nonnull NSString *)errorMessage;

@end
