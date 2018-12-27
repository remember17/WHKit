//
//  NSObject+WHObject.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <Foundation/Foundation.h>

typedef void (^KVOBlock)(NSDictionary *change, void *context);

@interface NSObject (WHObject)

/** 版本号 */
+ (NSString *)version;

/** build号 */
+ (NSInteger)build;

/** Bundle id */
+ (NSString *)identifier;

/** 语言 */
+ (NSString *)currentLanguage;

/** 架构 */
+ (NSString *)deviceModel;

/** 类名 */
- (NSString *)className;

/** 类名 */
+ (NSString *)className;

/** 父类名 */
- (NSString *)superClassName;

/** 父类名 */
+ (NSString *)superClassName;

/** 实例属性字典 */
- (NSDictionary *)propertyDictionary;

/** 属性名称列表 */
- (NSArray *)propertyKeys;

/** 属性名称列表 */
+ (NSArray *)propertyKeys;

/** 方法列表 */
- (NSArray *)methodList;

/** 方法列表 */
+ (NSArray *)methodList;

/** 格式化方法列表 */
- (NSArray *)methodListInfo;

/** 创建并返回一个指向所有已注册类的指针列表 */
+ (NSArray *)registedClassList;

/** 实例变量 */
+ (NSArray *)instanceVariable;

/** 是否包含某个属性 */
- (BOOL)hasPropertyForKey:(NSString*)key;

/** 是否包含某个实例变量 */
- (BOOL)hasIvarForKey:(NSString*)key;

- (void)addObserver:(NSObject *)observer
         forKeyPath:(NSString *)keyPath
            options:(NSKeyValueObservingOptions)options
            context:(void *)context
          withBlock:(KVOBlock)block;

-(void)removeBlockObserver:(NSObject *)observer
                forKeyPath:(NSString *)keyPath;

-(void)addObserverForKeyPath:(NSString *)keyPath
                     options:(NSKeyValueObservingOptions)options
                     context:(void *)context
                   withBlock:(KVOBlock)block;

-(void)removeBlockObserverForKeyPath:(NSString *)keyPath;

- (void)modelWithDictionary:(NSDictionary *)dict __attribute__((deprecated(" ")));

@end
