//
//  AppDelegate.m
//  WHKitDemo
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/15.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import "AppDelegate.h"
#import "WHKit.h"
#import "ViewController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[ViewController new]];
    
    self.window.backgroundColor = kWhiteColor;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}


@end
