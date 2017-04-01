//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/** The type of password composition. */
typedef NS_ENUM(NSInteger, RBPasswordType)
{
    /** A password composed entirely of numeric characters. */
    RBPasswordTypeNumeric,
    
    /** A password composed entirely of alpha characters. */
    RBPasswordTypeAlpha,
    
    /** A password composed entirely of symbol characters. */
    RBPasswordTypeSymbols,
    
    /** A password composed entirely of alpha and numeric characters. */
    RBPasswordTypeAlphaNumeric,

    /** A password composed entirely of alpha, numeric and symbol characters. */
    RBPasswordTypeAlphaNumericSymbols
};

/** The grade of a password's strength. */
typedef NS_ENUM(NSInteger, RBPasswordGrade)
{
    /** An insecure password strength (the weakest). */
    RBPasswordGradeInsecure,
    /** An weak password strength. */
    RBPasswordGradeWeak,
    /** An strong password strength. */
    RBPasswordGradeStrong,
    /** An secure password strength (the strongest). */
    RBPasswordGradeSecure
};

@protocol RBPasswordManagerWordlistDelegate;

/**
 *  Generates and grades passwords.
 */
@interface RBPasswordManager : NSObject

/**
 *  A delegate to provide access to a word list.
 */
@property (nonatomic, nullable) id<RBPasswordManagerWordlistDelegate> wordlistDelegate;

/**
 *  Generates a new password of the given type.
 *
 *  @param type The type of password to generate.
 *
 *  @return The generated password string.
 */
- (nonnull NSString *)generateWithType:(RBPasswordType)type;

/**
 *  Generates a password of the given type between the given maximum and minimum lengths.
 *
 *  @param minLen The minimum length the generated password should be.
 *  @param maxLen The maximum length the generated password should be.
 *  @param type   The type of password to generate.
 *
 *  @return The generated password string.
 */
- (nonnull NSString *)generateWithMinLength:(int)minLen
                       andMaxLength:(int)maxLen
                            andType:(RBPasswordType)type;

/**
 *  Generates a password at the given length.
 *
 *  @param len  The length that the password should be generated as.
 *  @param type The type of password to generate.
 *
 *  @return The generated password string.
 */
- (nonnull NSString *)generateWithLength:(int)len
                         andType:(RBPasswordType)type;

/**
 *  Score the given password.
 *
 *  @param password The password to score.
 *
 *  @return The calculated password score.
 */
- (float)scoreWithPassword:(nonnull NSString *)password;

/**
 *  Grade the given password score.
 *
 *  @param score The score that the password was awarded.
 *
 *  @return The `RBPasswordGrade` value.
 */
+ (RBPasswordGrade)gradeWithScore:(float)score;

@end

/**
 *  Provides a word list.
 */
@protocol RBPasswordManagerWordlistDelegate <NSObject>

@required

/**
 *  The word list contained a match for the given string.
 *
 *  @param string The string to search for in the word list.
 *
 *  @return Whether or not the string was matched in the word list.
 */
- (BOOL)wordMatchIn:(nonnull NSString *)string;

@end
