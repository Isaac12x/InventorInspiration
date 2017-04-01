//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Redbeard/RBLayoutPositioner.h>
#import <Redbeard/RBLayoutSchemaPositionerSchema.h>

@protocol RBLayoutSchemaPositionerDelegate;

// Note: This class is abstract, use its subclasses.

/**
 *  A positioner that uses a passed in schema (meta data concerning specific views) and
 *  the `UIView`'s described by the schema.
 *  When using a `RBLayoutSchemaPositioner` certain layout views methods such as 
 *  pushCell, insertCellAtIndex etc can-not be called an exception will be thrown if the 
 *  attempt is made.
 */
@interface RBLayoutSchemaPositioner : RBLayoutPositioner

/**
 *  The delegate of the positioner, to receive a positioner schema event to add or remove cells.
 */
@property (nonatomic, weak, nullable) id<RBLayoutSchemaPositionerDelegate> schemaDelegate;

/**
 *  The schema that holds the views and layout data for the positioner.
 */
@property (nonatomic, nonnull, readonly) RBLayoutSchemaPositionerSchema *schema;

/**
 *  Initializes a new `RBLayoutSchemaPositioner` using the supplied schema.
 *
 *  @param schema       The schema to use.
 *
 *  @return The initialized positioner.
 */
- (nonnull instancetype)initWithSchema:(nonnull RBLayoutSchemaPositionerSchema *)schema;

/**
 *  Removes all existing views on the positioners by calling the schemaDelegates popAllCells method and then adds 
 *  the all the views obtained via the schemas views property.
 *  This is called automatically if the schema is changed or the positioner is added to a layout view.
 *  Do not call this directly it is used internally only.
 */
- (void)resetViews;

@end

/**
 *  A delegate to receive positioner schema events.
 */
@protocol RBLayoutSchemaPositionerDelegate <NSObject>

@required

/**
 *  Push a new cell to the layout view.
 *
 *  @param cell         The cell to push to the layout view.
 *  @param positioner   The positioner making the request.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)pushCell:(nonnull __kindof UIView *)cell positioner:(nonnull RBLayoutPositioner *)positioner;

/**
 *  Insert a new cell to the layout view at the given index.
 *
 *  @param cell         The cell to insert to the layout view.
 *  @param index        The index at which to insert the cell.
 *  @param positioner   The positioner making the request.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)insertCell:(nonnull __kindof UIView *)cell atIndex:(NSInteger)index positioner:(nonnull RBLayoutPositioner *)positioner;

/**
 *  Remove the cell at the given index from the layout view.
 *
 *  @param index        The index of the cell to remove.
 *  @param positioner   The positioner making the request.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removeCellAtIndex:(NSInteger)index positioner:(nonnull RBLayoutPositioner *)positioner;

/**
 *  Remove the given cell from the layout view.
 *
 *  @param cell         The cell to remove from the layout view.
 *  @param positioner   The positioner making the request.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)removeCell:(nonnull __kindof UIView *)cell positioner:(nonnull RBLayoutPositioner *)positioner;

/**
 *  Pop the last cell from the layout view.
 *
 *  @param positioner   The positioner making the request.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)popCell:(nonnull RBLayoutPositioner *)positioner;

/**
 *  Pop all of the cells from the layout view.
 *
 *  @param positioner   The positioner making the request.
 *
 *  @return Whether or not the operation was successful.
 */
- (BOOL)popAllCells:(nonnull RBLayoutPositioner *)positioner;

@end
