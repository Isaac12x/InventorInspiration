//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Redbeard/RBIntrospectiveObject.h>

/**
 *  A class of properties that provides built in `JSON` serialisation.
 *
 *  Note: Collection properties cannot contain elements of mixed types.
 */
@interface RBManagedJsonObject : RBIntrospectiveObject

#pragma mark -
#pragma mark Schema

/**
 *  Gets a dictionary of the names of `NSArray` properties to the `Class` type of their elements.
 *
 *  @return The dictionary of `Class` types to property names.
 */
+ (nullable NSDictionary<NSString *, Class> *)arrayMappings;

/**
 *  Gets a dictionary of the names of `NSDictionary` properties to the `Class` type of their values.
 *
 *  @return The dictionary of `Class` types to property names.
 */
+ (nullable NSDictionary<NSString *, Class> *)dictionaryMappings;

/**
 *  Gets the `JSON` key that should be used for the given property name.
 *
 *  @param propertyName The name of the property on the class.
 *
 *  @return The key string that will be used in `JSON` serialisation.
 */
- (nonnull NSString *)jsonKeyForPropertyName:(nonnull NSString *)propertyName;

/**
 *  Serialise the given `NSDate` property value to a string.
 *
 *  @param date         The `NSDate` property value.
 *  @param propertyName The name of the property.
 *
 *  @return The resulting `NSString` object.
 */
- (nonnull NSString *)convertDateToString:(nonnull NSDate *)date propertyName:(nonnull NSString *)propertyName;

/**
 *  Deserialise a date string to an `NSDate` property.
 *
 *  @param dateString   The serialised string value.
 *  @param propertyName The name of the property.
 *
 *  @return The resulting `NSDate` object.
 */
- (nullable NSDate *)convertStringToDate:(nonnull NSString *)dateString propertyName:(nonnull NSString *)propertyName;

#pragma mark -
#pragma mark Serialisation

/**
 *  Initialize the managed `JSON` object with the given property list dictionary.
 *
 *  @param dictionary The property list `NSDictionary` object.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithDictionary:(nonnull NSDictionary<NSString *, id> *)dictionary;

/**
 *  Serialises the value of the object to a property list `NSDictionary`.
 *  The result includes recursively the values of it's children.
 *
 *  @return The resulting property list `NSDictionary` object.
 */
- (nonnull NSDictionary<NSString *, id> *)dictionary;

/**
 *  Serialises the value of the object to `NSData` containing the `JSON` representation of the object.
 *  The result includes recursively the values of it's children.
 *
 *  @return The resulting `JSON` as a `NSData`.
 */
- (nonnull NSData *)data;

/**
 *  Serialises the value of the object to a `JSON` string.
 *  The result includes recursively the values of it's children.
 *
 *  @return The resulting json string.
 */
- (nonnull NSString *)string;

#pragma mark -
#pragma mark Convenience

/**
 *  Builds an object by deserialising the given `JSON` data.
 *
 *  @param jsonData The `JSON` data to deserialise.
 *  @param error    An `NSError` pointer that will be assigned if there is an error.
 *
 *  @return The deserialised object, or `nil` if it could not be deserialised.
 */
+ (nullable instancetype)objectFromJsonData:(nonnull NSData *)jsonData error:(NSError * _Nullable * _Nullable)error;

/**
 *  Builds an object by deserialising the given `JSON` string.
 *
 *  @param jsonString   The `JSON` string to deserialise.
 *  @param error        An `NSError` pointer that will be assigned if there is an error.
 *
 *  @return The deserialised object, or `nil` if it could not be deserialised.
 */
+ (nullable instancetype)objectFromJsonString:(nonnull NSString *)jsonString error:(NSError * _Nullable * _Nullable)error;

/**
 *  Builds an array of objects by deserialising the given `JSON` data.
 *
 *  @param jsonData The `JSON` data to deserialise.
 *  @param error    An `NSError` pointer that will be assigned if there is an error.
 *
 *  @return The deserialised object, or `nil` if it could not be deserialised.
 */
+ (nullable NSArray *)objectsFromJsonData:(nonnull NSData *)jsonData error:(NSError * _Nullable * _Nullable)error;

/**
 *  Builds an array of objects by deserialising the given `JSON` string.
 *
 *  @param jsonString   The `JSON` string to deserialise.
 *  @param error        An `NSError` pointer that will be assigned if there is an error.
 *
 *  @return The deserialised object, or `nil` if it could not be deserialised.
 */
+ (nullable NSArray *)objectsFromJsonString:(nonnull NSString *)jsonString error:(NSError * _Nullable * _Nullable)error;

@end
