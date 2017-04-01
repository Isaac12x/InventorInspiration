//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Acts as a middle man enabling the interception of delegate calls.
 *
 *  If `middleMan` responds to a selector in the protocol, it will receive the delegate call
 *  instead of the end receiver.  It is recommended it then forwards the call to the receiver.
 */
@interface RBProtocolMessageInterceptor : NSObject

/**
 *  The end receiver of the delegate calls.
 */
@property (nonatomic, readonly, weak, nullable) id receiver;

/**
 *  The middle man that is provided with the opportunity to intercept delegate calls.
 */
@property (nonatomic, readonly, weak, nullable) id middleMan;

/**
 *  The protocol of the delegate.
 */
@property (nonatomic, readonly, nonnull) Protocol *protocol;

/**
 *  Initializes a new protocol message interceptor.
 *
 *  @param protocol  The protocol of the delegate to intercept.
 *  @param middleMan The middle man object to implement delegate methods to intercept.
 *  @param receiver  The end receiver of the delegate calls.
 *
 *  @return The initialized protocol message interceptor, ready to be set as a delegate.
 */
- (nonnull instancetype)initWithProtocol:(nonnull Protocol *)protocol
                       middleMan:(nullable id)middleMan
                        receiver:(nullable id)receiver;

@end
