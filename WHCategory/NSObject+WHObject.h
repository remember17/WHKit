//
//  NSObject+WHObject.h
//  WHCategory
//  https://github.com/remember17/WHCategory
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^KVOBlock)(NSDictionary *change, void *context);

@interface NSObject (WHObject)

+ (NSString *)version;

+ (NSInteger)build;

+ (NSString *)identifier;

+ (NSString *)currentLanguage;

+ (NSString *)deviceModel;


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


//类名
- (NSString *)className;
+ (NSString *)className;
//父类名称
- (NSString *)superClassName;
+ (NSString *)superClassName;

//实例属性字典
-(NSDictionary *)propertyDictionary;

//属性名称列表
- (NSArray*)propertyKeys;
+ (NSArray *)propertyKeys;

//属性详细信息列表
- (NSArray *)propertiesInfo;
+ (NSArray *)propertiesInfo;

//格式化后的属性列表
+ (NSArray *)propertiesWithCodeFormat;

//方法列表
-(NSArray*)methodList;
+(NSArray*)methodList;

-(NSArray*)methodListInfo;

//创建并返回一个指向所有已注册类的指针列表
+ (NSArray *)registedClassList;
//实例变量
+ (NSArray *)instanceVariable;

//协议列表
-(NSDictionary *)protocolList;
+ (NSDictionary *)protocolList;


- (BOOL)hasPropertyForKey:(NSString*)key;
- (BOOL)hasIvarForKey:(NSString*)key;



//获取类中所有属性的名字集合
-(NSArray <NSString *> *)getPropertyNameList;

//如果用字典给一个类里的属性赋值,如有值是类中不存在的,常规情况下程序会崩溃
//根据本类的属性有选择的拿字典中的key value
//如果本类的属性包含字典的key,则把key的value赋值给这个属性
-(void)modelWithDictionary:(NSDictionary *)dict;

@end
