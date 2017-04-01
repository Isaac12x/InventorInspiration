//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBBaseLayoutView.h>
#import <Redbeard/RBFragmentedArray.h>

/**
 *  A normal layout view that is preloaded with its cells.
 */
@interface RBLayoutView : RBBaseLayoutView<RBLayoutSchemaPositionerDelegate>

/**
 *  Push a new cell to the layout view.
 *
 *  @param cell The cell to push to the layout view.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)pushCell:(nonnull __kindof UIView *)cell;

/**
 *  Insert a new cell to the layout view at the given index.
 *
 *  @param cell  The cell to insert to the layout view.
 *  @param index The index at which to insert the cell.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)insertCell:(nonnull __kindof UIView *)cell atIndex:(NSInteger)index;

/**
 *  Pop the last cell from the layout view.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)popCell;

/**
 *  Pop all of the cells from the layout view.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)popAllCells;

/**
 *  Remove the cell at the given index from the layout view.
 *
 *  @param index The index of the cell to remove.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removeCellAtIndex:(NSInteger)index;

/**
 *  Remove the given cell from the layout view.
 *
 *  @param cell The cell to remove from the layout view.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removeCell:(nonnull __kindof UIView *)cell;

/**
 *  The array of cells in the layout view.
 */
@property (nonatomic, readonly, nonnull) NSArray<__kindof UIView *> *cells;

/**
 *  Whether or not the layout view contains the given cell.
 *
 *  @param cell The cell to check for.
 *
 *  @return Whether or not the cell was found in the layout view.
 */
- (BOOL)containsCell:(nonnull __kindof UIView *)cell;

/**
 *  Gets the index of the given cell in the layout view.
 *
 *  @param cell The cell to find the index of.
 *
 *  @return The index of the cell, or `NSNotFound` if it was not found.
 */
- (NSInteger)indexOfCell:(nonnull __kindof UIView *)cell;

@end
