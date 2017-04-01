//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Describes an object's state that can be independantly themed.
 */
@interface RBThemeSchemaState : NSObject

/**
 *  The name of the state.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 *  An optional note about the state.
 */
@property (nonatomic, readonly, nullable) NSString *note;

/**
 *  If this state property has further states.
 */
@property (nonatomic, readonly, nullable) NSArray<RBThemeSchemaState *> *subStates; //RBThemeSchemaState

/**
 *  Initializes a new state theme schema.
 *
 *  @param name The name of the state.
 *  @param note An optional note about the state.
 *
 *  @return The initialized schema object.
 */
- (nonnull instancetype)initWithName:(nonnull NSString *)name note:(nullable NSString *)note;

/**
 *  Serialises the theme schema state to a property list.
 *
 *  @return The serialised theme schema state.
 */
- (nonnull NSDictionary<NSString *, NSString *> *)dictionary;


/**
 *  Adds a sub state to this state.
 *
 *  @param state The sub state
 */
- (void)addSubState:(nonnull RBThemeSchemaState *)state;


@end
