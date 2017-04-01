//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Redbeard/RBPasswordManager.h>

/**
 *  Provides a word list delegate that reads from an SQLite file.
 *
 *  - Expects a SQLite database file with a table named `wordlist` and a single text column named `word`.
 *  - This is for use with the `RBPasswordManager` class to match common words in a password.
 */
@interface RBSQLiteWordList : NSObject<RBPasswordManagerWordlistDelegate>

/**
 *  Initialize the word list delegate object with the given SQLite file path.
 *
 *  @param filePath The file path to an SQLite file containing words.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithFilePath:(nonnull NSString *)filePath;

@end
