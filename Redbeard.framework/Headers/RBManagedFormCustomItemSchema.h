//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormItemSchema.h"

/**
 *  A custom managed form view schema. Wraps the given view.
 */
@interface RBManagedFormCustomItemSchema : RBManagedFormItemSchema

/**
 *  The item view to use in the managed form.
 */
@property (nonatomic, nonnull) UIView *customView;

/**
 *  Whether or not the managed form (`RBManagedFormView`) this schema is attached to should be set as the item's delegate.
 *  This will mean the customView will be checked to see if it responds to the methods 
 *  `setDelegate` and `setControlValueDelegate`. If this is the case the form will be set to as the delegate.
 */
@property (nonatomic) BOOL shouldSetFormAsDelegate;

@end
