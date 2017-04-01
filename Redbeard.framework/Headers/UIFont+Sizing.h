//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  `UIFont` sizing methods.
 */
@interface UIFont (Sizing)

/**
 *  Calculates the maximum size that a string of a given length can be with this font.
 *
 *  @param numberOfCharacters The number of characters in a string.
 *
 *  @return The maximum size that such a string could occupy in this font.
 */
- (CGSize)maxSizeWithNumberOfCharacters:(int)numberOfCharacters;

/**
 *  Calculates the maximum size that a character can be in this font.
 *
 *  @return The maximum size that a character can be in this font.
 */
- (CGSize)maxCharacterSize;

@end
