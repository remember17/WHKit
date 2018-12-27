//
//  UIView+WHView.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <UIKit/UIKit.h>

typedef void (^TapActionBlock)(UITapGestureRecognizer *gestureRecoginzer);
typedef void (^LongPressActionBlock)(UILongPressGestureRecognizer *gestureRecoginzer);

@interface UIView (WHView)

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;

/** 截取成图片 */
- (UIImage *)wh_snapshotImage;

/** 触发点击事件 */
- (void)wh_addTapActionWithBlock:(TapActionBlock)block;

/** 触发长按事件 */
- (void)wh_addLongPressActionWithBlock:(LongPressActionBlock)block;

/** 找到指定类名的subView */
- (UIView *)wh_findSubViewWithClass:(Class)clazz;

/** 找到指定类名的所有subView */
- (NSArray *)wh_findAllSubViewsWithClass:(Class)clazz;

/** 找到指定类名的superView对象 */
- (UIView *)wh_findSuperViewWithClass:(Class)clazz;

/** 找到view上的第一响应者 */
- (UIView *)wh_findFirstResponder;

/** 找到当前view所在的viewcontroler */
- (UIViewController *)wh_findViewController;

/** 所有子View */
- (NSArray *)wh_allSubviews;

/** 移除所有子视图 */
- (void)wh_removeAllSubviews;

@property (assign,nonatomic) IBInspectable NSInteger cornerRadius;
@property (assign,nonatomic) IBInspectable BOOL masksToBounds;
@property (assign,nonatomic) IBInspectable NSInteger borderWidth;
@property (strong,nonatomic) IBInspectable NSString  *borderHexRgb;
@property (strong,nonatomic) IBInspectable UIColor   *borderColor;

+ (instancetype)wh_loadViewFromNib;
+ (instancetype)wh_loadViewFromNibWithName:(NSString *)nibName;
+ (instancetype)wh_loadViewFromNibWithName:(NSString *)nibName owner:(id)owner;
+ (instancetype)wh_loadViewFromNibWithName:(NSString *)nibName owner:(id)owner bundle:(NSBundle *)bundle;

@end
