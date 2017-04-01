//
// Copyright (c) 2016 Redbeard Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Redbeard/CoreInline.h>

#pragma mark -
#pragma mark NS Extensions

#import <Redbeard/NSInline.h>
#import <Redbeard/NSObject+Extensions.h>
#import <Redbeard/NSObject+Swizzle.h>
#import <Redbeard/NSObject+Debugging.h>
#import <Redbeard/NSString+Extensions.h>
#import <Redbeard/NSArray+Extensions.h>
#import <Redbeard/NSDictionary+Extensions.h>
#import <Redbeard/NSAttributedString+Extensions.h>
#import <Redbeard/NSData+Extensions.h>
#import <Redbeard/NSDate+Extensions.h>
#import <Redbeard/NSNull+Extensions.h>
#import <Redbeard/NSNumber+Extensions.h>
#import <Redbeard/NSURLRequest+Extensions.h>

#pragma mark -
#pragma mark UI Extensions

#import <Redbeard/UIInline.h>

#import <Redbeard/UIView+FormField.h>
#import <Redbeard/UIView+Extensions.h>
#import <Redbeard/UIView+Redbeard.h>
#import <Redbeard/UIView+Positioning.h>
#import <Redbeard/UIView+ActivityIndication.h>
#import <Redbeard/UIView+ToastAlerts.h>
#import <Redbeard/UIView+Customization.h>
#import <Redbeard/UIView+Theming.h>
#import <Redbeard/UIView+Wriggle.h>
#import <Redbeard/UIView+ContentChromeInset.h>
#import <Redbeard/UIView+Viewport.h>
#import <Redbeard/UIView+RotationAnimator.h>
#import <Redbeard/UIView+Tooltip.h>
#import <Redbeard/UIView+RevealBounds.h>

#import <Redbeard/UIViewController+Redbeard.h>
#import <Redbeard/UIViewController+Theming.h>
#import <Redbeard/UIViewController+PresentationController.h>
#import <Redbeard/UIViewController+ManagedAlert.h>
#import <Redbeard/UIViewController+ManagedFormAlert.h>
#import <Redbeard/UIViewController+ManagedOverlayImage.h>
#import <Redbeard/UIViewController+AppearanceState.h>
#import <Redbeard/UIViewController+AppearanceEvents.h>
#import <Redbeard/UIViewController+Parents.h>

#import <Redbeard/UIColor+Extensions.h>
#import <Redbeard/UIDevice+Extensions.h>
#import <Redbeard/UIFont+Sizing.h>
#import <Redbeard/UIGestureRecognizer+Extensions.h>
#import <Redbeard/UIImage+DSP.h>
#import <Redbeard/UIImage+Extensions.h>
#import <Redbeard/UIImage+ImageEffects.h>
#import <Redbeard/UIPasteboard+Extensions.h>
#import <Redbeard/UIScrollView+Extensions.h>

#pragma mark -
#pragma mark Redbeard Core

#import <Redbeard/RBRandom.h>
#import <Redbeard/RBEnum.h>
#import <Redbeard/RBFilesystem.h>
#import <Redbeard/RBLocaleCenter.h>
#import <Redbeard/RBJson.h>
#import <Redbeard/RBThreading.h>
#import <Redbeard/RBUICenter.h>
#import <Redbeard/RBTheming.h>
#import <Redbeard/RBThemeFileCollection.h>
#import <Redbeard/RBThemeGlyphReference.h>

#import <Redbeard/RBEventCenter.h>
#import <Redbeard/RBKeyChainCenter.h>
#import <Redbeard/RBPropertyList.h>
#import <Redbeard/RBManagedVisualEffect.h>

#pragma mark -
#pragma mark Utilities

#import <Redbeard/RBAnimator.h>
#import <Redbeard/RBPasswordManager.h>
#import <Redbeard/RBFragmentedArray.h>
#import <Redbeard/RBProtocolMessageInterceptor.h>
#import <Redbeard/RBDataPersistentCache.h>
#import <Redbeard/RBDataMemoryCache.h>
#import <Redbeard/RBReflectionUtility.h>
#import <Redbeard/RBFileChangeMonitor.h>
#import <Redbeard/RBPrecalculatedDataPersistentCache.h>
#import <Redbeard/RBPropertyListTracker.h>
#import <Redbeard/RBThemeTracker.h>
#import <Redbeard/RBProcessingQueue.h>
#import <Redbeard/RBSequenceController.h>
#import <Redbeard/RBURLBuilder.h>
#import <Redbeard/RBRestClient.h>
#import <Redbeard/RBMutableOrderedDictionary.h>

#pragma mark -
#pragma mark Network

#import <Redbeard/RBNetworkCenter.h>
#import <Redbeard/RBNetworkOperation.h>
#import <Redbeard/RBNetworkRequestOperation.h>

#pragma mark -
#pragma mark Images

#import <Redbeard/RBImageCenter.h>
#import <Redbeard/RBImageResponse.h>
#import <Redbeard/RBImageRequestOperation.h>

#pragma mark -
#pragma mark View Presentation

#import <Redbeard/RBPresentationAnimator.h>
#import <Redbeard/RBPresentationRevealAnimator.h>
#import <Redbeard/RBPresentationScaleAnimator.h>
#import <Redbeard/RBPresentationSlideAnimator.h>
#import <Redbeard/RBPresentationController.h>

#pragma mark -
#pragma mark SQLite

#import <Redbeard/RBSQLiteCenter.h>
#import <Redbeard/RBSQLiteConnection.h>
#import <Redbeard/RBSQLiteFieldSchema.h>
#import <Redbeard/RBSQLiteResult.h>
#import <Redbeard/RBSQLiteResultSet.h>
#import <Redbeard/RBSQLiteTableSchema.h>
#import <Redbeard/RBSQLiteVFS.h>
#import <Redbeard/RBSQLiteVFSFile.h>
#import <Redbeard/RBSQLiteWordList.h>

#pragma mark -
#pragma mark Introspective

#import <Redbeard/RBIntrospectiveObjectPropertySchema.h>
#import <Redbeard/RBIntrospectiveObject.h>
#import <Redbeard/RBManagedJsonObject.h>

#pragma mark -
#pragma mark Passwords

#import <Redbeard/RBPasswordManager.h>

#pragma mark -
#pragma mark Sharing

#import <Redbeard/RBSharingService.h>
#import <Redbeard/RBEmailSharingService.h>
#import <Redbeard/RBFacebookSharingService.h>
#import <Redbeard/RBTwitterSharingService.h>