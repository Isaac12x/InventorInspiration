//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The type of an object property on an `RBIntrospectiveObject` subclass.
 */
typedef NS_ENUM(NSInteger, RBIntrospectiveObjectPropertyType){
    /**
     *  An unknown or incompatible object property type.
     */
    RBIntrospectiveObjectPropertyTypeUnknownOrIncompatible = 0,
    
    /**
     *  A signed integer property.
     */
    RBIntrospectiveObjectPropertyTypeInt,
    
    /**
     *  A signed character property.
     */
    RBIntrospectiveObjectPropertyTypeChar,
    
    /**
     *  A signed long integer property.
     */
    RBIntrospectiveObjectPropertyTypeLong,
    
    /**
     *  A boolean property.
     */
    RBIntrospectiveObjectPropertyTypeBool,
    
    /**
     *  A signed short integer property.
     */
    RBIntrospectiveObjectPropertyTypeShort,
    
    /**
     *  A floating point decimal property.
     */
    RBIntrospectiveObjectPropertyTypeFloat,
    
    /**
     *  A double precision floating point decimal property.
     */
    RBIntrospectiveObjectPropertyTypeDouble,
    
    /**
     *  An unsigned integer property.
     */
    RBIntrospectiveObjectPropertyTypeUnsignedInt,
    
    /**
     *  An unsigned character property.
     */
    RBIntrospectiveObjectPropertyTypeUnsignedChar,
    
    /**
     *  An unsigned long integer property.
     */
    RBIntrospectiveObjectPropertyTypeUnsignedLong,
    
    /**
     *  An unsigned short integer property.
     */
    RBIntrospectiveObjectPropertyTypeUnsignedShort,
    
    /**
     *  A signed long long integer property.
     */
    RBIntrospectiveObjectPropertyTypeLongLong,
    
    /**
     *  An unsigned long long integer property.
     */
    RBIntrospectiveObjectPropertyTypeUnsignedLongLong,
    
    /**
     *  An `NSData` object property.
     */
    RBIntrospectiveObjectPropertyTypeData,
    
    /**
     *  An `NSDate` object property.
     */
    RBIntrospectiveObjectPropertyTypeDate,
    
    /**
     *  An `NSString` object property.
     */
    RBIntrospectiveObjectPropertyTypeString,
    
    /**
     *  An `NSArray` object property.
     */
    RBIntrospectiveObjectPropertyTypeArray,
    
    /**
     *  An `NSDictionary` object property.
     */
    RBIntrospectiveObjectPropertyTypeDictionary,
    
    /**
     *  An object property.
     */
    RBIntrospectiveObjectPropertyTypeId,
    
    /**
     *  An `RBIntrospectiveObject` object property.
     */
    RBIntrospectiveObjectPropertyTypeRBIntrospectiveObject
};

/**
 *  The schema details of a property on an `RBIntrospectiveObject` instance.
 */
@interface RBIntrospectiveObjectPropertySchema : NSObject

/**
 *  The name of the property.
 */
@property (readonly, nonnull) NSString *name;

/**
 *  The type of the property.
 */
@property (readonly) RBIntrospectiveObjectPropertyType propertyType;

/**
 *  The `Class` object of the property's type.
 */
@property (readonly, nonnull) Class classType;

/**
 *  Whether or not the property is readonly.
 */
@property (readonly) BOOL isReadOnly;

/**
 *  Initializes an `RBIntrospectiveObject` property schema.
 *
 *  @param name           The name of the schema.
 *  @param propertyString The system type string of the property.
 *
 *  @return The initialized property schema object.
 */
- (nonnull instancetype)initWithName:(nonnull NSString *)name
           andPropertyString:(nonnull NSString *)propertyString;

@end
