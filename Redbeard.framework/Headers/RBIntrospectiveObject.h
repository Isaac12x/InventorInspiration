//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  An `NSObject` that provides information about it's properties.
 *
 *  Note: The `BOOL` type is recognised as a `signed char`.  To explicitly recognise as a boolean
 *        use the `bool` (lowercase) type instead.
 */
@interface RBIntrospectiveObject : NSObject

/**
 *  Gets `RBIntrospectiveObjectPropertySchema` objects for each of the properties on this class and
 *  it's superclasses that are not marked to be ignored.
 *
 *  @return A dictionary of property names to `RBIntrospectiveObjectPropertySchema` objects.
 */
+ (nonnull NSDictionary<NSString *, RBIntrospectiveObjectPropertySchema *> *)propertySchemas;

/**
 *  Populates the properties with random values.
 *
 *  @param depth The depth to which to add child objects.
 */
- (void)populateRandomValuesWithDepth:(uint)depth;

#pragma mark -
#pragma mark Ignoring Properties

/**
 *  Gets an `NSArray` of the names of properties to ignore in this class and it's superclasses.
 *
 *  @return The resulting `NSArray` object of property names strings (`NSString`).
 */
+ (nullable NSArray<NSString *> *)ignoreProperties;

/**
 *  Gets an `NSArray` of the types (`NSNumber` wrapped `RBIntrospectiveObjectPropertyType` values) of
 *  properties to ignore in this class and it's superclasses.
 *
 *  @return The resulting `NSArray` object of property types.
 */
+ (nullable NSArray<NSNumber *> *)ignorePropertyTypes;

@end
