//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A convenience URL builder class.
 */
@interface RBURLBuilder : NSObject

/**
 *  The root `NSURL` object.
 */
@property (nonatomic, readonly, nonnull) NSURL *urlRoot;

/**
 *  Initializes a new URL builder with the given root URL.
 *
 *  @param urlRoot The root URL to use.
 *
 *  @return The initialized object.
 */
- (nonnull instancetype)initWithUrlRoot:(nonnull NSURL *)urlRoot;

/**
 *  The parameter keys that are currently configured in the URL.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *parameterKeys;

/**
 *  The values that are associated with the given parameter key.
 *
 *  @param key The parameter key.
 *
 *  @return The values that are associated with the key.
 */
- (nonnull NSArray<NSString *> *)parameterValuesWithKey:(nonnull NSString *)key;

/**
 *  Add a new parameter value to the URL.
 *
 *  @param value The value of the parameter.
 *  @param key   The key of the parameter.
 */
- (void)addParameterValue:(nonnull NSString *)value withKey:(nonnull NSString *)key;

/**
 *  Remove all of the parameters.
 */
- (void)removeAllParameterValues;

/**
 *  The result `NSURL` object.
 */
@property (nonatomic, readonly, nonnull) NSURL *url;

@end
