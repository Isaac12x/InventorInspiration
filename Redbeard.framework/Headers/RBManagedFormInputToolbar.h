//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RBManagedFormInputToolbarDelegate;

/**
 *  An input view toolbar for `RBManagedFormView` managed fields.
 */
@interface RBManagedFormInputToolbar : UIToolbar

/**
 *  A delegate to receive button selection events.
 */
@property (nonatomic, weak, nullable) id<RBManagedFormInputToolbarDelegate, UIToolbarDelegate> delegate;

@end

/**
 *  A delegate to receive button selection events from an `RBManagedFormView` object.
 */
@protocol RBManagedFormInputToolbarDelegate <NSObject>

@required

/**
 *  Called when the 'Previous' button is selected on the input view of a managed toolbar.
 *
 *  @param managedFormInputToolbar The `RBManagedFormInputToolbar` object.
 */
- (void)prevSelectedWithManagedFormInputToolbar:(nonnull RBManagedFormInputToolbar *)managedFormInputToolbar;

/**
 *  Called when the 'Next' button is selected on the input view of a managed toolbar.
 *
 *  @param managedFormInputToolbar The `RBManagedFormInputToolbar` object.
 */
- (void)nextSelectedWithManagedFormInputToolbar:(nonnull RBManagedFormInputToolbar *)managedFormInputToolbar;

/**
 *  Called when the 'Done' button is selected on the input view of a managed toolbar.
 *
 *  @param managedFormInputToolbar The `RBManagedFormInputToolbar` object.
 */
- (void)doneSelectedWithManagedFormInputToolbar:(nonnull RBManagedFormInputToolbar *)managedFormInputToolbar;

@end
