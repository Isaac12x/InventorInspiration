//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The base schema class for a managed form item.
 */
@interface RBManagedFormItemSchema : NSObject

/**
 *  The unique identifier of this schema and the UIView that it will later create. Use this to reference fields.
 *  You should assign this if you would like to refer to a field. If you do not assign an identifier one will be 
 *  assigned automatically.
 *  The identifier is also used to reference the specific theme within the parent `RBManagedFormView` theme.
 */
@property (nonatomic, nonnull) NSString *identifier;

/**
 *  The identifier of the theme (in the `RBManagedFormView` theme) to apply to items having this themeIdentifiers
 *  e.g. if you have 3 labels that you would like to set the textColor to green give them all the same groupThemeIdentifier
 */
@property (nonatomic, nullable) NSString *groupThemeIdentifier;

/**
 *  The identifier of the theme (in the `RBManagedFormView` theme) to apply to all items of this type.
 *  Override this when creating a subclass.
 */
@property (nonatomic, readonly, nonnull) NSString *defaultThemeIdentifier;

/**
 *  Theme values to apply after any other prior theming has been applied.
 */
@property (nonatomic, nullable) NSDictionary<NSString *, id> *themeOverrides;

/**
 *  Indicates this is a 'hidden' item. The UI for this field will not be displayed nor will any validation occur. 
 *  If a form field is marked hidden it's inital value will always be returned when calling the values property on the `RBManagedFormView`.
 *  This is useful for passing values through forms.
 */
@property (nonatomic) BOOL hidden;

/**
 *  The view that represents this schema. The method `createView` is called internally to generate the view.
 */
@property (nonatomic, nonnull, readonly) UIView *view;

/**
 *  Creates a new item view from the schema details.
 *
 *  @return The new item view.
 */
- (nonnull UIView *)newView;

#pragma mark -
#pragma mark Subclassing

/**
 *  The name of this type of managed form item. This is used for serialisation.
 *
 *  @return The managed form item name.
 */
+ (nonnull NSString *)primaryTypeName;

/**
 *  An array of the type names that will be matched to this item during serialisation.
 *
 *  @return The array of type names.
 */
+ (nonnull NSArray *)validTypeNames;

/**
 *  Reset all settings to their default values.
 */
- (void)resetToDefaults;

/**
 *  Create a new item view from the schema details.
 *  This is called by internally. Never call it directly.
 *
 *  @return The new item view.
 */
- (nonnull UIView *)createView;

@end
