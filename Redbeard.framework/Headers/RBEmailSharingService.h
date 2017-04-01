//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Redbeard/RBSharingService.h>

#import <MessageUI/MessageUI.h>


/**
 *  Represents an email attachment
 */
@interface RBEmailAttachment : NSObject

/**
 * The contents for the attachment. Must not be `nil`.
 */
@property (nonatomic, nonnull) NSData *data;

/**
 * The mime type for the attachment (IANA http://www.iana.org/assignments/media-types/). Must not be `nil`.
 */
@property (nonatomic, nonnull) NSString *mimeType;

/**
 * The intended filename for the attachment. Must not be `nil`.
 */
@property (nonatomic, nonnull) NSString *filename;

@end


/**
 *  The Email social sharing service.
 */
@interface RBEmailSharingService : RBSharingService<MFMailComposeViewControllerDelegate>

/**
 *  Opens the compose UI to send an e-mail.
 *
 *  @param subject     The initial subject string value.
 *  @param to          An array of recipient e-mail addresses.
 *  @param cc          An array of e-mail addresses to CC in the e-mail.
 *  @param bcc         An array of e-mail addresses to BCC in the e-mail.
 *  @param body        The initial body string value.
 *  @param isHtml      Whether or not the body is in HTML format.
 *  @param attachments An array of `RBEmailAttachment` items.
 *  @param completion  An optional block to be called when the compose UI is concluded.
 *
 *  @return Whether or not the compose UI was opened successfully.
 */
- (BOOL)composeWithSubject:(nonnull NSString *)subject
                        to:(nullable NSArray<NSString *> *)to
                        cc:(nullable NSArray<NSString *> *)cc
                       bcc:(nullable NSArray<NSString *> *)bcc
                      body:(nonnull NSString *)body
                    isHtml:(BOOL)isHtml
               attachments:(nullable NSArray<RBEmailAttachment *> *)attachments
                completion:(nullable void(^)(BOOL cancelled))completion;

@end
