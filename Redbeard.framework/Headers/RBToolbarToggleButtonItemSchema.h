//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A schema of a toggle toolbar button.
 */
@interface RBToolbarToggleButtonItemSchema : NSObject

/**
 *  The unqiue identifier of the toolbar button. Identifier is also used as theme identifier within the toolbar theme.
 */
@property (nonatomic, readonly, nonnull) NSString *identifier;

/**
 *  Theme values to apply after any other prior theming has been applied.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *themeOverrides;

/**
 *  Whether or not the button should be disabled.
 */
@property (nonatomic, readonly) BOOL disabled;

/**
 *  Whether or not the button image should be loaded from the url.
 */
@property (nonatomic, readonly) BOOL shouldLoadButtonImageFromUrl;

/**
 *  The `NSURL` of the button image to use.
 */
@property (nonatomic, readonly, nullable) NSURL *buttonImageUrl;

/**
 *  The title for the button that will be created from this schema.
 */
@property (nonatomic, readonly, nullable) NSString *title;

/**
 *  Initializes a new toolbar button schema.
 *
 *  @param identifier       The unique identifier of the button.
 *  @param title            The title of the button.
 *  @param disabled         Whether or not the button should be disabled.
 *  @param themeOverrides   Theme values to apply after any other prior theming has been applied.
 *
 *  @return The initialized toolbar button schema.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                                     title:(nullable NSString *)title
                                  disabled:(BOOL)disabled
                            themeOverrides:(nullable NSDictionary<NSString *, id> *)themeOverrides;

/**
 *  Initializes a new toolbar button schema.
 *
 *  @param identifier       The unique identifier of the button.
 *  @param title            The title of the button.
 *  @param disabled         Whether or not the button should be disabled.
 *  @param themeOverrides   Theme values to apply after any other prior theming has been applied.
 *  @param buttonImageUrl   An `NSURL` to an image to use as the button image.
 *
 *  @return The initialized toolbar button schema.
 */
- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)identifier
                                     title:(nullable NSString *)title
                                  disabled:(BOOL)disabled
                            themeOverrides:(nullable NSDictionary<NSString *, id> *)themeOverrides
                      withButtonImageAtUrl:(nonnull NSURL *)buttonImageUrl;

@end
