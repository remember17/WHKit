//
//  ViewController.m
//  WHKitDemo
//
//  Created by wu, hao on 2020/8/21.
//  Copyright © 2020 wuhao. All rights reserved.
//

#import "ViewController.h"
#import "WHKit.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // 本月的第一天距离现在多久
    NSLog(@"%@",[[NSDate begindayOfMonth:[NSDate new]] timeInfo]);

    // 定时器
    __block NSInteger test = 1;
    NSTimer *timer = [NSTimer wh_scheduledTimerWithTimeInterval:1 repeats:YES callback:^(NSTimer *timer) {
        NSLog(@"%ld",(test += 1));
    }];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [timer pauseTimer]; // 暂停
        [timer resumeTimerAfterTimeInterval:5]; // 5秒后重新开启
    });
}

@end
