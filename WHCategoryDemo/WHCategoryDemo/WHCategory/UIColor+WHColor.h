//
//  UIColor+WHColor.h
//  WHCategory
//  https://github.com/remember17/WHCategory
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (WHColor)

/// 使用 16 进制数字创建颜色，例如 0xFF0000 创建红色
/// @param hex 16 进制无符号32位整数
/// @return 颜色
+ (instancetype)wh_colorWithHex:(uint32_t)hex;

/// 生成随机颜色
/// @return 随机颜色
+ (instancetype)wh_randomColor;

/// 使用 R / G / B 数值创建颜色
+ (instancetype)wh_colorWithRed:(uint8_t)red green:(uint8_t)green blue:(uint8_t)blue;

/**
 十六进制字符串显示颜色
 
 @param color 十六进制字符串
 @param alpha 透明度
 @return 颜色
 */
+ (UIColor *)wh_colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;


/**
 *  @brief  渐变颜色
 *
 *  @param fromColor  开始颜色
 *  @param toColor    结束颜色
 *  @param height     渐变高度
 *
 *  @return 渐变颜色
 */
+ (UIColor*)wh_gradientFromColor:(UIColor*)fromColor toColor:(UIColor*)toColor withHeight:(CGFloat)height;

@end
