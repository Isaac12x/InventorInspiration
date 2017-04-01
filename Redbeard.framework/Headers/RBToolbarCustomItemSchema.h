//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

/**
 *  A schema for a custom toolbar item.
 */
@interface RBToolbarCustomItemSchema : NSObject

/**
 *  The unqiue identifier of the toolbar button. Identifier is also used as theme identifier within the toolbar theme.
 */
@property (nonatomic, readonly, nonnull) NSString *identifier;

/**
 *  Theme values to apply after any other prior theming has been applied.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *themeOverrides;

/**
 *  The view to place in the toolbar.
 */
@property (nonatomic, readonly, nonnull) UIView *view;

/**
 *  Initializes a schema for a custom toolbar item.
 *
 *  @param identifier       The unique identifier of the button.
 *  @param view             The view to place in the toolbar.
 *  @param themeOverrides   Theme values to apply after any other prior theming has been applied.
 *
 *  @return The initialized schema object.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                                      view:(nonnull UIView *)view
                            themeOverrides:(nullable NSDictionary<NSString *, id> *)themeOverrides;

@end
