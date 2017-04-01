//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The key chain account dictionary key for the account name.
 */
extern NSString * __nonnull RBKeychainItemKeyAccount;

/**
 *  Provides access to the key chain.
 */
@interface RBKeyChainCenter : NSObject

/**
 *  Retrieves all of the available key chain accounts.
 *
 *  @return An array of account `NSDictionary` objects.
 */
+ (nullable NSArray *)getAllAccounts;

/**
 *  Deletes an account with the given name.
 *
 *  @param account The name of the account to delete.
 *
 *  @return Whether or not the operation was successful.
 */
+ (BOOL)deleteAccount:(nonnull NSString *)account;

/**
 *  Checks whether or not an account exists with the given name.
 *
 *  @param account The name of the account to check exists.
 *
 *  @return Whether or not the account was found.
 */
+ (BOOL)accountExists:(nonnull NSString *)account;

/**
 *  Retrieves the key chain account with the given name.
 *
 *  @param account The name of the account to retrieve.
 *
 *  @return The account `NSDictionary`, or `nil` if the account was not found.
 */
+ (nullable NSDictionary *)getAccount:(nonnull NSString *)account;

/**
 *  Retrieves the raw data for the account with the given name.
 *
 *  @param account The name of the account for which to retrieve the data.
 *
 *  @return The raw data of the account, or `nil` if the account was not found.
 */
+ (nullable NSData *)getAccountData:(nonnull NSString *)account;

/**
 *  Updates or creates the account with the given name using the given raw data.
 *
 *  @param account The name of the account to create or update.
 *  @param data    The data to associate with the account.
 *
 *  @return Whether or not the operation was successful.
 */
+ (BOOL)addOrUpdateAccount:(nonnull NSString *)account withData:(nonnull NSData *)data;

/**
 *  Deletes all of the key chain accounts.
 *
 *  @return Whether or not the operation was successful.
 */
+ (BOOL)deleteAllAccounts;

/**
 *  Prints the given status value to the console.
 *
 *  @param status The status value to print.
 */
+ (void)printStatus:(OSStatus)status;

@end
