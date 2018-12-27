//
//  NSDate+WHDate.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <Foundation/Foundation.h>

@interface NSDate (WHDate)

/** 根据日期返回字符串 */
+ (NSString *)stringWithDate:(NSDate *)date format:(NSString *)format;

/** 对象方法，返回时间字符串 */
- (NSString *)stringWithFormat:(NSString *)format;

/** 根据字符串返回NSDate */
+ (NSDate *)dateWithString:(NSString *)string format:(NSString *)format;

/** 根据TimeInterval获取字符串,带有时区偏移 */
+ (NSString *)stringWithTimeInterval:(unsigned int)time Formatter:(NSString *)format;

/** 根据字符串和格式获取TimeInterval时间,带有时区偏移 */
+ (NSTimeInterval )timeIntervalFromString:(NSString *)timeStr Formatter:(NSString *)format;

/** 当前TimeInterval时间,带有时区偏移 */
+ (NSTimeInterval )now;

/** yyyy-MM-dd HH:mm:ss格式的当前时间 */
+ (NSString *)stringNowWithFullFormatter;

/** YYYY-MM-dd格式的日期字符串 */
- (NSString *)formatYMD;

/** YYYY-MM-dd格式的日期字符串 */
+ (NSString *)formatYMD:(NSDate *)date;

/** 自定义格式的当前时间 */
+ (NSString *)stringNowWithFormatter:(NSString *)format;

- (NSUInteger)day;
- (NSUInteger)month;
- (NSUInteger)year;
- (NSUInteger)hour;
- (NSUInteger)minute;
- (NSUInteger)second;
+ (NSUInteger)day:(NSDate *)date;
+ (NSUInteger)month:(NSDate *)date;
+ (NSUInteger)year:(NSDate *)date;
+ (NSUInteger)hour:(NSDate *)date;
+ (NSUInteger)minute:(NSDate *)date;
+ (NSUInteger)second:(NSDate *)date;

/** 一年的总天数 */
- (NSUInteger)daysInYear;

/** 一年的总天数 */
+ (NSUInteger)daysInYear:(NSDate *)date;

/** 判断是否是润年 */
- (BOOL)isLeapYear;

/** 判断是否是润年 */
+ (BOOL)isLeapYear:(NSDate *)date;

/** 获取该日期是该年的第几周 */
- (NSUInteger)weekOfYear;

/** 获取该日期是该年的第几周 */
+ (NSUInteger)weekOfYear:(NSDate *)date;

/** 当前月一共有几周(可能为4,5,6) */
- (NSUInteger)weeksOfMonth;

/** 当前月一共有几周(可能为4,5,6) */
+ (NSUInteger)weeksOfMonth:(NSDate *)date;

/** 获取该月的第一天 */
- (NSDate *)begindayOfMonth;

/** 获取该月的第一天 */
+ (NSDate *)begindayOfMonth:(NSDate *)date;

/** 获取该月的最后一天 */
- (NSDate *)lastdayOfMonth;

/** 获取该月的最后一天 */
+ (NSDate *)lastdayOfMonth:(NSDate *)date;

/** day天后的日期(若day为负数,则为|day|天前的日期) */
- (NSDate *)dateAfterDay:(NSUInteger)day;

/** day天后的日期(若day为负数,则为|day|天前的日期) */
+ (NSDate *)dateAfterDate:(NSDate *)date day:(NSInteger)day;

/** month月后的日期(若month为负数,则为|month|月前的日期) */
- (NSDate *)dateAfterMonth:(NSUInteger)month;

/** month月后的日期(若month为负数,则为|month|月前的日期) */
+ (NSDate *)dateAfterDate:(NSDate *)date month:(NSInteger)month;

/** numYears年后的日期 */
- (NSDate *)offsetYears:(int)numYears;

/** numYears年后的日期 */
+ (NSDate *)offsetYears:(int)numYears fromDate:(NSDate *)fromDate;

/** numHours小时后的日期 */
- (NSDate *)offsetHours:(int)hours;

/** numHours小时后的日期 */
+ (NSDate *)offsetHours:(int)numHours fromDate:(NSDate *)fromDate;

/** 距离该日期前几天 */
- (NSUInteger)daysAgo;

/** 距离该日期前几天 */
+ (NSUInteger)daysAgo:(NSDate *)date;

/** 星期几 */
- (NSInteger)weekday;

/** 星期几 */
+ (NSInteger)weekday:(NSDate *)date;

/** 获取星期几(字符串 */
- (NSString *)dayFromWeekday;

/** 获取星期几(字符串 */
+ (NSString *)dayFromWeekday:(NSDate *)date;

/** 获取阴历 */
- (NSString*)lunar;

/** 日期是否相等 */
- (BOOL)isSameDay:(NSDate *)anotherDate;

/** 是否是今天 */
- (BOOL)isToday;

/** 增加几天之后的日期 */
- (NSDate *)dateByAddingDays:(NSUInteger)days;

/** 获取英文字符串月份 */
+ (NSString *)monthWithMonthNumber:(NSInteger)month;

/** 获取指定月份的天数 */
- (NSUInteger)daysInMonth:(NSUInteger)month;

/** 获取指定月份的天数 */
+ (NSUInteger)daysInMonth:(NSDate *)date month:(NSUInteger)month;

/** 获取当前月份的天数 */
- (NSUInteger)daysInMonth;

/** 获取当前月份的天数 */
+ (NSUInteger)daysInMonth:(NSDate *)date;

/** 返回x分钟前/x小时前/昨天/x天前/x个月前/x年前 */
- (NSString *)timeInfo;

/** 返回x分钟前/x小时前/昨天/x天前/x个月前/x年前 */
+ (NSString *)timeInfoWithDate:(NSDate *)date;

/** 返回x分钟前/x小时前/昨天/x天前/x个月前/x年前 */
+ (NSString *)timeInfoWithDateString:(NSString *)dateString;

- (NSString *)ymdFormat;
- (NSString *)hmsFormat;
- (NSString *)ymdHmsFormat;
+ (NSString *)ymdFormat;
+ (NSString *)hmsFormat;
+ (NSString *)ymdHmsFormat;

@end
