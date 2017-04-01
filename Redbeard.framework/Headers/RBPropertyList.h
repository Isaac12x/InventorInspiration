//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Convenience methods for working with property lists.
 */
@interface RBPropertyList : NSObject

/**
 *  Retrieves the value in the given property list at the given key path with indexes.
 *
 *  e.g. results.products[0].name
 *
 *  @param propertyList The property list to extract the value from.
 *  @param keyPath      The key path with indexes at which the value is expected.
 *
 *  @return The resulting value, or `nil` if nothing was found.
 */
+ (nullable id)valueWithPropertyList:(nonnull id)propertyList
       atKeyPathWithIndexes:(nonnull NSString *)keyPath;

/**
 *  Removes `NSNull` values from the property list recursively.
 *
 *  @param propertyList The property list to remove `NSNull` values from.
 *
 *  @return The new property list with `NSNull` values removed.
 */
+ (nonnull id)propertyListByRemovingNullValues:(nonnull id)propertyList;

/**
 *  Analyses two property lists to determine the differences between them.
 *
 *  @param fromPropertyList         The source property list to analyse.
 *  @param toPropertyList           The destination property list to analyse.
 *  @param additionDiffPropertyList The items that were added to the destination as compared with the source.
 *  @param removalDiffPropertyList  The items that were removed in the destination as compared with the source.
 */
+ (void)diffFromPropertyList:(nonnull id)fromPropertyList
              toPropertyList:(nonnull id)toPropertyList
                additionDiff:(id __nullable * __nullable)additionDiffPropertyList
                 removalDiff:(id __nullable * __nullable)removalDiffPropertyList;

/**
 *  Transforms a property list.
 *
 *  @param propertyList            The property list to transform.
 *  @param dictionaryModifierBlock An optional block that is called on all dictionaries enabling their modification.
 *  @param valueModifierBlock      An optional block that is called on all non-dictionary values, enabling their modification.
 *
 *  @return The modified property list.
 */
+ (nonnull id)transformPropertyList:(nonnull id)propertyList
    dictionaryModifierBlock:(nullable void(^)(NSString * __nullable path, NSMutableDictionary * __nonnull dictionary))dictionaryModifierBlock
         valueModifierBlock:(nullable id __nonnull(^)(NSString * __nullable path, id __nonnull value))valueModifierBlock;

@end
