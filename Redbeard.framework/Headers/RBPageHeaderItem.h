//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The horizontal alignment of a page header item.
 */
typedef NS_ENUM(NSInteger, RBPageHeaderItemAlignment){
    /**
     *  The item will align to the left of the header page header.
     */
    RBPageHeaderItemAlignmentLeft,
    /**
     *  The item will align to the center of the header page header.
     */
    RBPageHeaderItemAlignmentCenter,
    /**
     *  The item will align to the right of the header page header.
     */
    RBPageHeaderItemAlignmentRight
};

/**
 *  An item to be displayed in a page header.
 */
@interface RBPageHeaderItem : NSObject

/**
 *  The identifier of the theme (in the page header) to be applied to this item.
 */
@property (nonatomic, readonly, nullable) NSString *themeIdentifier;

/**
 *  The horizontal alignment of the item within the page header.
 */
@property (nonatomic, readonly) RBPageHeaderItemAlignment alignment;

/**
 *  The item view to display within the page header.
 */
@property (nonatomic, readonly, nonnull) UIView *view;

/**
 *  Initializes a new page header item.
 *
 *  @param themeIdentifier  The identifier of the theme (in the page header) to apply to the item.
 *  @param alignment        The horizontal alignment of the item within the page header.
 *  @param view             The item view to display within the page header.
 *
 *  @return The initialized page header item.
 */
- (nonnull instancetype)initWithThemeIdentifier:(nullable NSString *)themeIdentifier
                        alignment:(RBPageHeaderItemAlignment)alignment
                             view:(nonnull UIView *)view;

@end
