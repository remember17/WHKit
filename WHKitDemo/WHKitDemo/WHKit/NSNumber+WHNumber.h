//
//  NSNumber+WHNumber.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <Foundation/Foundation.h>

@interface NSNumber (WHNumber)

/** 对应的罗马数字 */
- (NSString *)romanNumeral;

/** 转换为百分比字符串 */
- (NSString*)toDisplayPercentageWithDigit:(NSInteger)digit;

/**
 四舍五入

 @param digit 限制最大位数
 @return 四舍五入后的结果
 */
- (NSNumber*)doRoundWithDigit:(NSUInteger)digit;

/**
 上取整

 @param digit 限制最大位数
 @return 上取整后的结果
 */
- (NSNumber*)doCeilWithDigit:(NSUInteger)digit;

/**
 下取整

 @param digit 限制最大位数
 @return 下取整后的结果
 */
- (NSNumber*)doFloorWithDigit:(NSUInteger)digit;

- (NSString*)toDisplayNumberWithDigit:(NSInteger)digit;

@end
