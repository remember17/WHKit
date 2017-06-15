//
//  AppDelegate.m
//  WHKitDemo
//
//  Created by 吴浩 on 2017/6/15.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import "AppDelegate.h"
#import "WHKit.h"
#import "ViewController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    self.window.rootViewController=[ViewController new];
    
    self.window.backgroundColor=KWHITE_COLOR;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}


@end
