//
//  RTNavigationController.h
//  RTNavigationController
//
//  Created by ricky on 13-3-30.
//  Copyright (c) 2013年 ricky. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef SAFE_RELEASE
#if __has_feature(objc_arc)
#define SAFE_RELEASE(o) ((o) = nil)
#define SAFE_DEALLOC(o) {}
#else
#define SAFE_RELEASE(o) ([(o) release], (o) = nil)
#define SAFE_DEALLOC(o) [o dealloc]
#endif
#endif

@class RTNavigationController;

@protocol RTNavigationControllerDelegate <NSObject>

- (UIViewController*)nextViewController;

@end

@interface RTNavigationController : UIViewController <UIGestureRecognizerDelegate>
{
    UISwipeGestureRecognizer                * _swipe;
    UIPanGestureRecognizer                  * _pan;
    
    UIViewController                        * _topViewController;
    
    UINavigationBar                         * _navigationBar;
    UINavigationBar                         * _navigationBarTmp;
    
    UIView                                  * _contentView;
    UIView                                  * _contentViewTmp;
    
    UIView                                  * _viewTmp;
}

@property (nonatomic, strong) id<RTNavigationControllerDelegate> delegate;
@property (nonatomic, readonly) UIViewController *topViewController;


- (id)initWithRootViewController:(UIViewController*)controller;

- (void)pushViewController:(UIViewController*)viewController animated:(BOOL)animated;
- (UIViewController*)popViewControllerAnimated:(BOOL)animated;
- (NSArray*)popToRootViewControllerAnimated:(BOOL)animated;
- (NSArray*)popToViewController:(UIViewController *)viewController
                       animated:(BOOL)animated;

@end
