//
//  UIBarButtonItem+WHBarButtonItem.h
//  WHCategory
//  https://github.com/remember17/WHCategory
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (WHBarButtonItem)

//快速创建导航栏按钮
+(instancetype _Nullable )wh_barButtonItemWithTitle:(NSString *_Nullable)title imageName:(NSString *_Nullable)imageName target:(nullable id)target action:(nonnull SEL)action fontSize:(CGFloat)fontSize titleNormalColor:(UIColor *_Nullable)normalColor titleHighlightedColor:(UIColor *_Nullable)highlightedColor;

@end
