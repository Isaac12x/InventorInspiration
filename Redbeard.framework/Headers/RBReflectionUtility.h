//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Reflection utility methods.
 */
@interface RBReflectionUtility : NSObject

/**
 *  Finds the subclasses of the given type.
 *
 *  @param type The type to find subclasses for.
 *
 *  @return A set of the subclasses that were found.
 */
+ (nullable NSSet *)subclassesOf:(nonnull Class)type;

/**
 *  Finds all of the classes that match the given block.
 *
 *  @param classMatchBlock The block to determine whether a given type is acceptable.
 *
 *  @return A set of the matching classes.
 */
+ (nullable NSSet *)classesThatMatch:(nonnull BOOL(^)(Class __nonnull typeClass))classMatchBlock;

@end
