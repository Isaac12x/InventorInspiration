//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A dictionary with ordered values.
 */
@interface RBMutableOrderedDictionary : NSMutableDictionary

/**
 *  An `NSEnumerator` object to enumerate the keys in order.
 *
 *  @return The `NSEnumerator` object.
 */
- (nonnull NSEnumerator *)keyEnumerator;

/**
 *  An `NSEnumerator` object to enumerate the keys in reverse order.
 *
 *  @return The `NSEnumerator` object.
 */
- (nonnull NSEnumerator *)reverseKeyEnumerator;

@end
