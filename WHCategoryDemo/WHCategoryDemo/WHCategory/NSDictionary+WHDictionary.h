//
//  NSDictionary+WHDictionary.h
//  WHCategory
//  https://github.com/remember17/WHCategory
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (WHDictionary)

//获得一般模型属性
-(void)wh_createProperty;

//获得网络模型属性
-(void)wh_createNetProperty;

/** 合并两个NSDictionary */
+ (NSDictionary *)dictionaryByMerging:(NSDictionary *)dict1 with:(NSDictionary *)dict2;

/** 并入一个NSDictionary */
- (NSDictionary *)dictionaryByMergingWith:(NSDictionary *)dict;

#pragma mark - Manipulation
- (NSDictionary *)dictionaryByAddingEntriesFromDictionary:(NSDictionary *)dictionary;

- (NSDictionary *)dictionaryByRemovingEntriesWithKeys:(NSSet *)keys;

@end
