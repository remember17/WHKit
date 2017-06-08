//
//  NSFileManager+WHFileManager.h
//  WHCategory
//  https://github.com/remember17/WHCategory
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (WHFileManager)

+ (NSURL *)documentsURL;

+ (NSString *)documentsPath;

+ (NSURL *)libraryURL;

+ (NSString *)libraryPath;

+ (NSURL *)cachesURL;

+ (NSString *)cachesPath;

@end
