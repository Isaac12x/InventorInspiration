//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  JSON serialisation and deserialisation convenience methods.
 */
@interface RBJson : NSObject

/**
 *  Deserialise the given JSON data to a property list.
 *
 *  @param data  The `NSData` object.
 *  @param error This is set to the error if one occurs, or to `nil` if no error occurs.
 *
 *  @return The resulting property list, or `nil` if there was an error.
 */
+ (nullable id)deserialiseFromData:(nonnull NSData *)data error:(NSError * _Nullable * _Nullable)error;

/**
 *  Deserialise the given JSON data to a property list.
 *
 *  @param data             The `NSData` object.
 *  @param error            This is set to the error if one occurs, or to `nil` if no error occurs.
 *  @param removeNullValues Whether or not explicitly set `null` values should be removed.
 *
 *  @return The resulting property list, or `nil` if there was an error.
 */
+ (nullable id)deserialiseFromData:(nonnull NSData *)data error:(NSError * _Nullable * _Nullable)error removeNullValues:(BOOL)removeNullValues;

/**
 *  Deserialise the given JSON string to a property list.
 *
 *  @param string  The JSON string value.
 *  @param error   This is set to the error if one occurs, or to `nil` if no error occurs.
 *
 *  @return The resulting property list, or `nil` if there was an error.
 */
+ (nullable id)deserialiseFromString:(nonnull NSString *)string error:(NSError * _Nullable * _Nullable)error;

/**
 *  Deserialise the given JSON string to a property list.
 *
 *  @param string           The JSON string value.
 *  @param error            This is set to the error if one occurs, or to `nil` if no error occurs.
 *  @param removeNullValues Whether or not explicitly set `null` values should be removed.
 *
 *  @return The resulting property list, or `nil` if there was an error.
 */
+ (nullable id)deserialiseFromString:(nonnull NSString *)string error:(NSError * _Nullable * _Nullable)error removeNullValues:(BOOL)removeNullValues;

/**
 *  Deserialise the given JSON file path to a property list.
 *
 *  @param filePath The path to a JSON file.
 *  @param error    This is set to the error if one occurs, or to `nil` if no error occurs.
 *
 *  @return The resulting property list, or `nil` if there was an error.
 */
+ (nullable id)deserialiseFromFile:(nonnull NSString *)filePath error:(NSError * _Nullable * _Nullable)error;

/**
 *  Deserialise the given JSON file path to a property list.
 *
 *  @param filePath        The path to a JSON file.
 *  @param error           This is set to the error if one occurs, or to `nil` if no error occurs.
 *  @param removeNullValues Whether or not explicitly set `null` values should be removed.
 *
 *  @return The resulting property list, or `nil` if there was an error.
 */
+ (nullable id)deserialiseFromFile:(nonnull NSString *)filePath error:(NSError * _Nullable * _Nullable)error removeNullValues:(BOOL)removeNullValues;

/**
 *  Serialises the given property list to JSON data.
 *
 *  @param propertyList The property list to serialise.
 *  @param error        This is set to the error if one occurs, or to `nil` if no error occurs.
 *
 *  @return The resulting JSON `NSData` object.
 */
+ (nullable NSData *)serialiseFromPropertyList:(nonnull id)propertyList error:(NSError * _Nullable * _Nullable)error;

@end
