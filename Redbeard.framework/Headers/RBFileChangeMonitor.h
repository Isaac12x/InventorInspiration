//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Detects changes in a set of files.
 */
@interface RBFileChangeMonitor : NSObject

/**
 *  The unique storage key for this file change monitor.  Checksums are stored here.
 */
@property (nonatomic, readonly, nonnull) NSString *storageKey;

/**
 *  Initializes a new file change monitor with the given unique storage key.
 *
 *  @param storageKey The unique storage key to use when determining where to store the checksums.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithStorageKey:(nonnull NSString *)storageKey;

/**
 *  Checks for changes to the given files and internally tracks the changes. You may call `saveChecksums` after calling this method to
 *  save the internally tracked values.
 *
 *  @param fileUrls         The URLs to the files to check for changes in.
 *  @param modifiedFileUrls An optional `NSArray*` in which to store the URLs to the files that were modified.
 *  @param newFileUrls      An optional `NSArray*` in which to store the URLs to the files that are new.
 *  @param removedFileUrls  An optional `NSArray*` in which to store the URLs to the files that were removed.
 *
 *  @return Whether or not any changes were detected.
 */
- (BOOL)checkIfChangesOccurredInFiles:(nonnull NSArray<NSURL *> *)fileUrls
                        modifiedFiles:(NSArray<NSURL *> * __nullable * __nullable)modifiedFileUrls
                             newFiles:(NSArray<NSURL *> * __nullable * __nullable)newFileUrls
                         removedFiles:(NSArray<NSURL *> * __nullable * __nullable)removedFileUrls;

/**
 *  Saves internally tracked changes if there are any.
 */
- (void)saveChecksums;

@end
