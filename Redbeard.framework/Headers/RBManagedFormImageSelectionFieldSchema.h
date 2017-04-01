//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import "RBManagedFormFieldSchema.h"
#import "RBImageSelectionFieldItem.h"

/**
 *  The managed `RBImageSelectionField` selection field schema.
 */
@interface RBManagedFormImageSelectionFieldSchema : RBManagedFormFieldSchema

/**
 *  An array of `RBImageSelectionFieldItem` objects.
 */
@property (nonatomic, nullable) NSArray<RBImageSelectionFieldItem *> *items;

/**
 *  Whether or not selection is allowed. Default = `YES`.
 */
@property (nonatomic) BOOL allowsSelection;

/**
 *  Whether or not multiple selection is allowed. Default = `NO`.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 *  Whether or not all items can be unselected, leaving zero selected items. Default = `NO`.
 */
@property (nonatomic) BOOL zeroSelectionAllowed;

@end
