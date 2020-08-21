//
//  Foundation+Safe.h
//  WHKitDemo
//
//  Created by 吴浩 on 2018/6/12.
//  Copyright © 2018年 remember17. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray<__covariant ObjectType> (Safe)

- (nullable ObjectType)safeObjectAtIndex:(NSUInteger)index;

- (nullable ObjectType)safeObjectAtIndex:(NSUInteger)index defaultValue:(nullable ObjectType)defaultValue;

+ (instancetype _Nullable )safeArrayWithObject:(ObjectType _Nonnull)object;

- (nullable NSArray<ObjectType> *)safeSubarrayWithRange:(NSRange)range;

- (NSUInteger)safeIndexOfObject:(ObjectType _Nonnull)anObject;

- (NSUInteger)safeIndexOfObject:(ObjectType _Nonnull)anObject defaultIndex:(NSUInteger)defaultIndex;

@end

@interface NSMutableArray<ObjectType> (Safe)

- (void)safeAddObject:(ObjectType _Nonnull)object;

- (void)safeInsertObject:(ObjectType _Nonnull)object atIndex:(NSUInteger)index;

- (void)safeInsertObjects:(NSArray<ObjectType> * _Nonnull)objects atIndexes:(NSIndexSet * _Nonnull)indexs;

- (void)safeRemoveObjectAtIndex:(NSUInteger)index;

- (void)safeRemoveObjectsInRange:(NSRange)range;

- (nullable ObjectType)safeObjectAtIndexedSubscript:(NSUInteger)index;

@end

@interface NSDictionary<__covariant KeyType, __covariant ObjectType> (Safe)

+ (instancetype _Nullable )safeDictionaryWithObject:(ObjectType _Nonnull)object forKey:(KeyType _Nonnull)key;

@end

@interface NSMutableDictionary<KeyType, ObjectType> (safe)

- (void)safeSetObject:(ObjectType _Nonnull)aObj forKey:(KeyType _Nonnull)aKey;

@end

@interface NSString (Safe)

- (nullable NSString *)safeSubstringFromIndex:(NSUInteger)from;

- (nullable NSString *)safeSubstringToIndex:(NSUInteger)to;

- (nullable NSString *)safeSubstringWithRange:(NSRange)range;

- (NSRange)safeRangeOfString:(nullable NSString *)aString;

- (NSRange)safeRangeOfString:(nullable NSString *)aString options:(NSStringCompareOptions)mask;

- (NSString *_Nullable)safeStringByAppendingString:(NSString * _Nonnull)aString;

- (instancetype _Nullable )safeInitWithString:(NSString * _Nonnull)aString;

+ (instancetype _Nullable )safeStringWithString:(NSString * _Nonnull)string;

@end

@interface NSMutableString (Safe)

- (void)safeInsertString:(NSString * _Nonnull)aString atIndex:(NSUInteger)loc;

- (void)safeAppendString:(NSString * _Nonnull)aString;

@end
