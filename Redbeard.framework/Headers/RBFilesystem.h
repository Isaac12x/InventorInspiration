//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBThreading.h>

/**
 *  Filesystem convenience methods.
 */
@interface RBFilesystem : NSObject

/**
 *  Gets the local filesystem path to the given system directory.
 *
 *  @param pathDirectory The system directory.
 *
 *  @return The retrieved path.
 */
+ (nullable NSString *)pathTo:(NSSearchPathDirectory)pathDirectory;

/**
 *  The path to the documents directory.
 */
+ (nonnull NSString *)pathToDocumentsDirectory;

/**
 *  The path to the temporary directory.
 */
+ (nonnull NSString *)pathToTemporaryDirectory;

/**
 *  The path to the bundle directory.
 */
+ (nonnull NSString *)pathToBundleDirectory;

/**
 *  The path to the cache directory.
 */
+ (nonnull NSString *)pathToCacheDirectory;

/**
 *  Retrieves a list of the files at the path given.
 *
 *  @param path             The path to retrieve the list of files from.
 *  @param includeFullPaths Whether each item should include the full path, or just the name.
 *
 *  @return The `NSArray` file list.
 */
+ (nullable NSArray<NSString *> *)filesAtPath:(nonnull NSString *)path
        includeFullPaths:(BOOL)includeFullPaths;

/**
 *  Retrieves a list of the files at the path given that match the given extension.
 *
 *  @param path             The path to retrieve the list of files from.
 *  @param extension        The extension to match.
 *  @param includeFullPaths Whether each item should include the full path, or just the name.
 *
 *  @return The `NSArray` file list.
 */
+ (nullable NSArray<NSString *> *)filesAtPath:(nonnull NSString *)path
           withExtension:(nonnull NSString *)extension
        includeFullPaths:(BOOL)includeFullPaths;

/**
 *  Retrieves a list of the directories at the path given.
 *
 *  @param path             The path to retrieve the list of directories from.
 *  @param includeFullPaths Whether each item should include the full path, or just the name.
 *
 *  @return The `NSArray` directory list.
 */
+ (nullable NSArray<NSString *> *)directoriesAtPath:(nonnull NSString *)path
              includeFullPaths:(BOOL)includeFullPaths;

/**
 *  Determines whether or not a file exists at the given path.
 *
 *  @param path The path to the file.
 *
 *  @return Whether or not the file exists.
 */
+ (BOOL)fileExistsAtPath:(nonnull NSString *)path;

/**
 *  Determines whether or not a directory exists at the given path.
 *
 *  @param path The path to the directory.
 *
 *  @return Whether or not the directory exists.
 */
+ (BOOL)directoryExistsAtPath:(nonnull NSString *)path;

/**
 *  Creates a directory at the given path.
 *
 *  @param path The path to create a directory at.
 *
 *  @return Whether or not the operation was successful.
 */
+ (BOOL)createDirectoryAtPath:(nonnull NSString *)path;

/**
 *  Gets the modified date of the item at the given path.
 *
 *  @param path The path to the item.
 *
 *  @return The `NSDate` result.
 */
+ (nullable NSDate *)modifiedDateWithPath:(nonnull NSString *)path;

/**
 *  Removes the file at the given path.
 *
 *  @param path The path to the file to remove.
 *
 *  @return Whether or not the operation was successful.
 */
+ (BOOL)removeFileAtPath:(nonnull NSString *)path;

/**
 *  Reads data from the disk asynchronously.
 *
 *  @param path        The path to the item to read.
 *  @param filterBlock An optional block to filter the data.
 *  @param completion  The completion block providing the result on completion.
 *
 *  @return A task handle that can be used to cancel the operation.
 */
+ (nonnull id<RBCancellableTask>)readDataOnceInBackground:(nonnull NSString *)path
                                      filterBlock:(nullable NSData * __nonnull(^)(NSData * __nonnull data))filterBlock
                                       completion:(nullable void(^)(NSData * __nullable data, NSError * __nullable error, BOOL wasCancelled))completion;

@end
