//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RBEmailSharingService;

/**
 *  A social sharing service.  This is an abstract class.
 */
@interface RBSharingService : NSObject

/**
 *  The Twitter social sharing service.
 *
 *  @return The service object.
 */
+ (nonnull RBSharingService *)twitter;

/**
 *  The Facebook social sharing service.
 *
 *  @return The service object.
 */
+ (nonnull RBSharingService *)facebook;

/**
 *  The Email social sharing service.
 *
 *  @return The service object.
 */
+ (nonnull RBEmailSharingService *)email;

/**
 *  Whether or not the service is available.
 */
@property (nonatomic, readonly) BOOL serviceIsAvailable;

/**
 *  Open the relevant sharing compose UI with the given initial text.
 *
 *  @param text       The initial text to place in the compose UI.
 *  @param completion An optional block to be called when the compose UI is concluded.
 *
 *  @return Whether or not compose was available and opened.
 */
- (BOOL)composeWithText:(nonnull NSString *)text
             completion:(nullable void(^)(BOOL cancelled))completion;

@end
