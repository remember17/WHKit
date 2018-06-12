//
//  Foundation+Safe.m
//  WHKitDemo
//
//  Created by 吴浩 on 2018/6/12.
//  Copyright © 2018年 remember17. All rights reserved.
//

#import "Foundation+Safe.h"
#import <objc/runtime.h>

@implementation NSArray (Safe)

+ (void)load {
    method_setImplementation(class_getInstanceMethod(self, @selector(objectAtIndexedSubscript:)), class_getMethodImplementation(self, @selector(safeObjectAtIndexedSubscript:)));
}

- (id)safeObjectAtIndexedSubscript:(NSUInteger)index {
    if (index >= self.count) {
        NSAssert(FALSE, @"数组越界了，请解决。。。");
        return nil;
    } else {
        return [self objectAtIndex:index];
    }
}

- (id)safeObjectAtIndex:(NSUInteger)index {
    if (index >= self.count) {
        NSAssert(FALSE, @"数组越界了，请解决。。。");
        return nil;
    } else {
        return [self objectAtIndex:index];
    }
}

- (id)safeObjectAtIndex:(NSUInteger)index defaultValue:(id)defaultValue {
    if (index >= self.count) {
        return defaultValue;
    } else {
        return [self objectAtIndex:index];
    }
}

+ (instancetype)safeArrayWithObject:(id)object {
    if (object == nil) {
        return [self array];
    } else {
        return [self arrayWithObject:object];
    }
}

- (NSArray *)safeSubarrayWithRange:(NSRange)range {
    NSUInteger location = range.location;
    NSUInteger length = range.length;
    if (location + length > self.count) {
        //超过了边界,就获取从loction开始所有的item
        if ((location + length) > self.count) {
            length = (self.count - location);
            return [self safeSubarrayWithRange:NSMakeRange(location, length)];
        }
        
        return nil;
    } else {
        return [self subarrayWithRange:range];
    }
}

- (NSUInteger)safeIndexOfObject:(id)anObject {
    if (anObject == nil) {
        return NSNotFound;
    } else {
        return [self indexOfObject:anObject];
    }
}

- (NSUInteger)safeIndexOfObject:(id)anObject defaultIndex:(NSUInteger)defaultIndex {
    if (anObject == nil) {
        return defaultIndex;
    } else {
        return [self indexOfObject:anObject];
    }
}

@end

@implementation NSMutableArray (Safe)

+ (void)load {
    method_setImplementation(class_getInstanceMethod(self, @selector(setObject:atIndexedSubscript:)), class_getMethodImplementation(self, @selector(safeSetObject:atIndexedSubscript:)));
    
    method_setImplementation(class_getInstanceMethod(NSClassFromString(@"__NSArrayM"), @selector(objectAtIndexedSubscript:)), class_getMethodImplementation(self, @selector(safeObjectAtIndexedSubscript:)));
}

- (void)safeSetObject:(id)obj atIndexedSubscript:(NSUInteger)idx {
    NSAssert(obj, @"setObject:atIndexedSubscript: 异常，obj为空，请修复，有问题联系liuwei7@yhd.com");
    if (obj == nil) {
        return;
    }
    
    if (self.count < idx) {
        NSAssert(obj, @"setObject:atIndexedSubscript: 异常，index越界，请修复，有问题联系liuwei7@yhd.com");
        return;
    }
    
    if (idx == self.count) {
        [self addObject:obj];
    } else {
        [self replaceObjectAtIndex:idx withObject:obj];
    }
}

- (void)safeAddObject:(id)object {
    if (object == nil) {
        return;
    } else {
        [self addObject:object];
    }
}

- (void)safeInsertObject:(id)object atIndex:(NSUInteger)index {
    if (object == nil) {
        return;
    } else if (index > self.count) {
        return;
    } else {
        [self insertObject:object atIndex:index];
    }
}

- (void)safeInsertObjects:(NSArray *)objects atIndexes:(NSIndexSet *)indexs {
    NSUInteger firstIndex = indexs.firstIndex;
    if (indexs == nil) {
        return;
    } else if (indexs.count != objects.count || firstIndex > objects.count) {
        return;
    } else {
        [self insertObjects:objects atIndexes:indexs];
    }
}

- (void)safeRemoveObjectAtIndex:(NSUInteger)index {
    if (index >= self.count) {
        return;
    } else {
        [self removeObjectAtIndex:index];
    }
}

- (void)safeRemoveObjectsInRange:(NSRange)range {
    NSUInteger location = range.location;
    NSUInteger length = range.length;
    if (location + length > self.count) {
        return;
    } else {
        [self removeObjectsInRange:range];
    }
}

- (id)safeObjectAtIndexedSubscript:(NSUInteger)index {
    if (index >= self.count) {
        NSAssert(FALSE, @"数组越界了，请解决。。。");
        return nil;
    } else {
        return [self objectAtIndex:index];
    }
}

@end

@implementation NSDictionary (Safe)

+ (instancetype)safeDictionaryWithObject:(id)object forKey:(id <NSCopying>)key {
    if (!object || !key) {
        return [self dictionary];
    } else {
        return [self dictionaryWithObject:object forKey:key];
    }
}

@end

@implementation NSMutableDictionary (safe)

+ (void)load {
    method_setImplementation(class_getInstanceMethod(self, @selector(setObject:forKeyedSubscript:)), class_getMethodImplementation(self, @selector(safeSetObject:forKeyedSubscript:)));
}

- (void)safeSetObject:(id)obj forKeyedSubscript:(id <NSCopying>)key {
    NSAssert(key, @"setObject:forKeyedSubscript: 异常，请修复，有问题联系liuwei7@yhd.com");
    if (!key) {
        return;
    }
    
    if (!obj) {
        [self removeObjectForKey:key];
    } else {
        [self setObject:obj forKey:key];
    }
}

- (void)safeSetObject:(id)aObj forKey:(id <NSCopying>)aKey {
    if (aObj && aKey) {
        [self setObject:aObj forKey:aKey];
    } else {
        return;
    }
}

@end

@implementation NSString (Safe)

- (NSString *)safeSubstringFromIndex:(NSUInteger)from {
    if (from > self.length) {
        return nil;
    } else {
        return [self substringFromIndex:from];
    }
}

- (NSString *)safeSubstringToIndex:(NSUInteger)to {
    if (to > self.length) {
        return nil;
    } else {
        return [self substringToIndex:to];
    }
}

- (NSString *)safeSubstringWithRange:(NSRange)range {
    NSUInteger location = range.location;
    NSUInteger length = range.length;
    if (location + length > self.length) {
        return nil;
    } else {
        return [self substringWithRange:range];
    }
}

- (NSRange)safeRangeOfString:(NSString *)aString {
    if (aString == nil) {
        return NSMakeRange(NSNotFound, 0);
    } else {
        return [self rangeOfString:aString];
    }
}

- (NSRange)safeRangeOfString:(NSString *)aString options:(NSStringCompareOptions)mask {
    if (aString == nil) {
        return NSMakeRange(NSNotFound, 0);
    } else {
        return [self rangeOfString:aString options:mask];
    }
}

- (NSString *)safeStringByAppendingString:(NSString *)aString {
    if (aString == nil) {
        return [self stringByAppendingString:@""];
    } else {
        return [self stringByAppendingString:aString];
    }
}

- (instancetype)safeInitWithString:(NSString *)aString {
    if (aString == nil) {
        return [self initWithString:@""];
    } else {
        return [self initWithString:aString];
    }
}

+ (instancetype)safeStringWithString:(NSString *)string {
    if (string == nil) {
        return [self stringWithString:@""];
    } else {
        return [self stringWithString:string];
    }
}

@end

@implementation NSMutableString (Safe)

- (void)safeInsertString:(NSString *)aString atIndex:(NSUInteger)loc {
    if (aString == nil) {
        return;
    } else if (loc > self.length) {
        return;
    } else {
        [self insertString:aString atIndex:loc];
    }
}

- (void)safeAppendString:(NSString *)aString {
    if (aString == nil) {
        return;
    } else {
        [self appendString:aString];
    }
}

@end

