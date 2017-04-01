//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/RBLayoutPositioner.h>

/**
 *  Provides a flow layout across rows.
 */
@interface RBLayoutFlowPositioner : RBLayoutPositioner

/**
 *  Whether or not the cells should fit to their fixed edge (width if vertical orientation, height if horizontal orientation). Default = NO.
 */
@property (nonatomic) BOOL fitToFixedEdge;

@end
