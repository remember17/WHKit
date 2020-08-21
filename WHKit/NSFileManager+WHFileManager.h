//
//  NSFileManager+WHFileManager.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  

#import <Foundation/Foundation.h>

@interface NSFileManager (WHFileManager)

/** document URL */
+ (NSURL *)documentsURL;

/** document 路径 */
+ (NSString *)documentsPath;

/** library URL */
+ (NSURL *)libraryURL;

/** library 路径 */
+ (NSString *)libraryPath;

/** cache URL */
+ (NSURL *)cachesURL;

/** cache 路径 */
+ (NSString *)cachesPath;

@end
