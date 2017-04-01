//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBThemeSchemaState.h>

/**
 *  The native types that are supported as theme property values.
 */
typedef NS_ENUM(NSInteger, RBThemeNativeType){
    /**
     *  An integer value.
     */
    RBThemeNativeTypeInteger,
    
    /**
     *  A decimal number.
     */
    RBThemeNativeTypeDecimal,
    
    /**
     *  A percentage decimal.
     */
    RBThemeNativeTypeDecimalPercentage,
    
    /**
     *  A boolean value.
     */
    RBThemeNativeTypeBoolean
};

/**
 *  Describes the theming options that are available on an object or enumeration type.
 */
@interface RBThemeSchema : NSObject

/**
 *  The object type that the schema describes the available theming options for.  `nil` if not an object.
 */
@property (nonatomic, readonly, nullable) Class typeClass;

/**
 *  The string name of the type that the schema describes the available theming options for.
 */
@property (nonatomic, readonly, nonnull) NSString *typeName;

/**
 *  Whether or not the type is an enumeration.
 */
@property (nonatomic, readonly) BOOL typeIsEnum;

/**
 *  An array of notes about the theming options available on this type.
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *notes; // NSString

/**
 *  An array of `RBThemeSchemaState` of the different states that can be optionally independantly themed.
 */
@property (nonatomic, readonly, nullable) NSArray<RBThemeSchemaState *> *states; // RBThemeSchemaState

/**
 *  A dictionary containing the `RBThemeSchema` objects for each field key on this type.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, RBThemeSchema *> *fields;

#pragma mark -
#pragma mark Creation

// parentSchema is used to keep weak references to parent for recursion protection.
// It can be nil.

/**
 *  Initializes a new theme schema for an object type.
 *
 *  @param typeClass    The `Class` of the object type.
 *  @param parentSchema The parent schema, or `nil` if this is a root schema.
 *                      This is used to keep weak references to the parent for
 *                      recursion protection.
 *
 *  @return The initialized theme schema instance.
 */
- (nonnull instancetype)initWithTypeClass:(nonnull Class)typeClass withParentSchema:(nullable RBThemeSchema *)parentSchema;

/**
 *  Initializes a new theme schema for a named type.
 *
 *  @param nativeType   The native type of the property.
 *  @param parentSchema The parent schema, or `nil` if this is a root schema.
 *                      This is used to keep weak references to the parent for
 *                      recursion protection.
 *
 *  @return The initialized theme schema instance.
 */
- (nonnull instancetype)initWithNativeType:(RBThemeNativeType)nativeType withParentSchema:(nullable RBThemeSchema *)parentSchema;

/**
 *  Initializes a new theme schema for a named type.
 *
 *  @param typeName     The name of the type.
 *  @param parentSchema The parent schema, or `nil` if this is a root schema.
 *                      This is used to keep weak references to the parent for
 *                      recursion protection.
 *
 *  @return The initialized theme schema instance.
 */
- (nonnull instancetype)initWithTypeName:(nonnull NSString *)typeName withParentSchema:(nullable RBThemeSchema *)parentSchema;

/**
 *  Initializes a new theme schema for an enumeration type.
 *
 *  @param enumTypeName The name of the enumeration type.
 *  @param parentSchema The parent schema, or `nil` if this is a root schema.
 *                      This is used to keep weak references to the parent for
 *                      recursion protection.
 *
 *  @return The initialized theme schema instance.
 */
- (nonnull instancetype)initWithEnumTypeName:(nonnull NSString *)enumTypeName withParentSchema:(nullable RBThemeSchema *)parentSchema;

/**
 *  Imports the properties, states and notes from the given theme schema into the current schema.
 *
 *  @param themeSchema The `RBThemeSchema` object to import.
 */
- (void)importThemeSchema:(nonnull RBThemeSchema *)themeSchema;

/**
 *  Imports the specified properties from the given theme schema into the current schema.
 *
 *  @param properties   The names of the properties to import.
 *  @param themeSchema  The `RBThemeSchema` object to import properties from.
 */
- (void)importProperties:(nonnull NSArray<NSString *> *)properties fromThemeSchema:(nonnull RBThemeSchema *)themeSchema;

/**
 *  Add a note to the theme schema.
 *
 *  @param noteString The note string to add.
 */
- (void)addNote:(nonnull NSString *)noteString;

/**
 *  Add a state that can be independantly themed.
 *
 *  @param state The details of the state.
 */
- (void)addState:(nonnull RBThemeSchemaState *)state;

/**
 *  Set the `RBThemeSchema` object for a given property name.
 *
 *  @param propertyName The name of the property.
 *  @param themeSchema  The `RBThemeSchema` object.
 *
 *  @return The assigned `RBThemeSchema` object.
 */
- (nullable RBThemeSchema *)setPropertyWithName:(nonnull NSString *)propertyName schema:(nonnull RBThemeSchema *)themeSchema;

/**
 *  Set a theme property to an object type.
 *
 *  @param propertyName The name of the property.
 *  @param type         The `Class` object type.
 *  @param notes        An optional accompanying note for the property.
 *
 *  @return The assigned `RBThemeSchema` object.
 */
- (nullable RBThemeSchema *)setPropertyWithName:(nonnull NSString *)propertyName type:(nonnull Class)type notes:(nullable NSString *)notes;

/**
 *  Set a theme property to an object type.
 *
 *  @param propertyName The name of the property.
 *  @param nativeType   The native type of the property.
 *  @param notes        An optional accompanying note for the property.
 *
 *  @return The assigned `RBThemeSchema` object.
 */
- (nullable RBThemeSchema *)setPropertyWithName:(nonnull NSString *)propertyName nativeType:(RBThemeNativeType)nativeType notes:(nullable NSString *)notes;

/**
 *  Set a theme property to a named type.
 *
 *  @param propertyName The name of the property.
 *  @param typeName     The name of the type of the property.
 *  @param notes        An optional accompanying note for the property.
 *
 *  @return The assigned `RBThemeSchema` object.
 */
- (nullable RBThemeSchema *)setPropertyWithName:(nonnull NSString *)propertyName typeName:(nonnull NSString *)typeName notes:(nullable NSString *)notes;

/**
 *  Set a theme property to an enumeration type.
 *
 *  @param propertyName        The name of the property.
 *  @param enumerationTypeName The name of the enumeration type.
 *  @param notes               An optional accompanying note for the property.
 *
 *  @return The assigned `RBThemeSchema` object.
 */
- (nullable RBThemeSchema *)setEnumPropertyWithName:(nonnull NSString *)propertyName enumerationTypeName:(nonnull NSString *)enumerationTypeName notes:(nullable NSString *)notes;

#pragma mark -
#pragma mark Removal

/**
 *  Removes the state with the given name.
 *
 *  @param stateName    The name of the state to remove.
 */
- (void)removeStateWithName:(nonnull NSString *)stateName;

/**
 *  Removes the property with the given name.
 *
 *  @param propertyName The name of the state to remove.
 */
- (void)removePropertyWithName:(nonnull NSString *)propertyName;

/**
 *  Removes all notes.
 */
- (void)removeAllNotes;

/**
 *  Removes all states.
 */
- (void)removeAllStates;

/**
 *  Removes all properties.
 */
- (void)removeAllProperties;

#pragma mark -
#pragma mark Output

/**
 *  Serialises the theme schema to a property list.
 *
 *  @return The serialised theme schema.
 */
- (nonnull NSDictionary<NSString *, id> *)dictionary;

#pragma mark -
#pragma mark Reflection

/**
 *  Searches for and returns an array of all the `Class` types that have theme schemas.
 *
 *  @return The `NSArray` of `Class` objects that have the selector 'generateThemeSchemaWithParent' objects.
 */
+ (nullable NSArray<Class> *)allTypesWithSchemas;

/**
 *  Recursively generates theme schemas for the given types,
 *  returning the schemas in a serialised property list tree.
 *
 *  @param types The types to generate schemas for.
 *
 *  @return An array of dictionaries containing the serialised theme schemas.
 */
+ (nonnull NSArray<NSDictionary<NSString *, id> *> *)treesForTypes:(nonnull NSArray<Class> *)types;

@end
