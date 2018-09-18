//
//  WHMacro.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e


//NSLog
#ifdef DEBUG
#define NSLog(...) NSLog(@"%s 第%d行: %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define NSLog(...)
#endif

//APP版本号
#define KAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//系统版本号
#define kSystemVersion [[UIDevice currentDevice] systemVersion]

//黑色和白色
#define kWhiteColor [UIColor whiteColor]
#define kBlackColor [UIColor blackColor]

// View 圆角和加边框
#define kViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define kViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

//字符串是否为空
#define kIsStringEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
//数组是否为空
#define kIsArrayEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define kIsDictEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
//是否是空对象
#define kIsObjectEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//屏幕宽度
#define kScreenWidth \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)
//屏幕高度
#define kScreenHeight \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
//屏幕Size
#define kScreenSize \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)
//状态栏加导航栏高度
#define kTopHeight (kIs_iPhoneX ? 88 : 64)
//TabBar高度
#define kTabBarHeight (kIs_iPhoneX ? 83 : 49)

//Aplication
#define kApplication [UIApplication sharedApplication]
//keyWindow
#define kKeyWindow [UIApplication sharedApplication].keyWindow
//AppDelegate
#define kAppdelegate [UIApplication sharedApplication].delegate
//UserDefaults
#define kUserDefault [NSUserDefaults standardUserDefaults]
//NSNotificationCenter
#define kNotificationCenter [NSNotificationCenter defaultCenter]

//获取当前语言
#define kCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
//判断是否为iPhone
#define kIs_iPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define kIs_iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//获取沙盒Document路径
#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒temp路径
#define kTempPath NSTemporaryDirectory()
//获取沙盒Cache路径
#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//真机
#endif

#if TARGET_IPHONE_SIMULATOR
//模拟器
#endif

//颜色
#define kRGB(r, g, b)     [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define kRandomColor           KRGB_COLOR(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))


/**
 十六进制表示颜色

 @param hexValue 十六进制值，不是字符串
 @param alphaValue 透明度
 @return 颜色
 */
#define kHexColor(hexValue, alphaValue) \
[UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 \
green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 \
blue:((float)(hexValue & 0xFF)) / 255.0 alpha:alphaValue]

//弱引用/强引用
#define kWeakSelf(type)   __weak typeof(type) weak##type = type;
#define kStrongSelf(type) __strong typeof(type) type = weak##type;

// 必须成对使用，使用该宏前必须加@，如@weakify(self);  @strongify(self);
#define weakify( x ) autoreleasepool{} __weak typeof(x) weak##x = x
#define strongify( x ) autoreleasepool{} __strong typeof(weak##x) x = weak##x
#define onExit(deferBlock) \
autoreleasepool{} __strong nob_defer_block_t nob_macro_concat(__nob_stack_defer_block_, __LINE__) __attribute__((cleanup(nob_deferFunc), unused)) = deferBlock

//由角度转换弧度
#define kDegreesToRadian(x) (M_PI * (x) / 180.0)
//由弧度转换角度
#define kRadianToDegrees(radian) (radian * 180.0) / (M_PI)

//获取一段时间间隔
#define kStart CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define KEnd NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

// 图片
#define kImageOfFile(NAME,EXT) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]
#define kImageNamed(NAME) [UIImage imageNamed:NAME]

// 多行文本获取高度
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_7_0
#define kMultiLineTextSize(text, font, maxSize) [text length] > 0 ? [text \
boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin) \
attributes:@{NSFontAttributeName:font} context:nil].size : CGSizeZero;
#else
#define kMultiLineTextSize(text, font, maxSize) [text length] > 0 ? [text \
sizeWithFont:font constrainedToSize:maxSize] : CGSizeZero;
#endif

// 字体大小（常规/粗体）
#define kBoldFont(FONTSIZE)      [UIFont boldSystemFontOfSize:FONTSIZE]
#define kSystemFont(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define kFont(NAME,FONTSIZE)     [UIFont fontWithName:(NAME) size:(FONTSIZE)]

static inline BOOL isIphoneX() {
    BOOL result = NO;
    if (UIDevice.currentDevice.userInterfaceIdiom != UIUserInterfaceIdiomPhone) {
        return result;
    }
    if (@available(iOS 11.0, *)) {
        UIWindow *mainWindow = [[[UIApplication sharedApplication] delegate] window];
        if (mainWindow.safeAreaInsets.bottom > 0.0) {
            result = YES;
        }
    }
    return result;
}
// 是否为iPhone X
#define kIs_iPhoneX (isIphoneX())
