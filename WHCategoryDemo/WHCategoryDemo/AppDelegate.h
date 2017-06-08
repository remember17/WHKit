//
//  AppDelegate.h
//  WHCategoryDemo
//
//  Created by 吴浩 on 2017/6/8.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

