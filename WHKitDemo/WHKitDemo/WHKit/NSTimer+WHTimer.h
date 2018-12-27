//
//  NSTimer+WHTimer.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <Foundation/Foundation.h>

typedef void(^TimerCallback)(NSTimer *timer);

@interface NSTimer (WHTimer)

/**
 定时事件，自定义是否重复

 @param interval 时间间隔
 @param repeats 是否重复
 @param callback 回调
 @return timer
 */
+ (NSTimer *)wh_scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                       repeats:(BOOL)repeats
                                      callback:(TimerCallback)callback;

/**
 定时事件，自定义重复次数

 @param interval 时间间隔
 @param count 重复次数
 @param callback 回调
 @return timer
 */
+ (NSTimer *)wh_scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                         count:(NSInteger)count
                                      callback:(TimerCallback)callback;

/** 暂停timer */
- (void)pauseTimer;

/** 开始timer */
- (void)resumeTimer;

/** 延迟开始timer */
- (void)resumeTimerAfterTimeInterval:(NSTimeInterval)interval;

@end
