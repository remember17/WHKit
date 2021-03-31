# WHKit

### 使用方法 
```objc
pod 'WHKit', '~>1.8.0'

也可以直接把WHKit文件添加进工程中
在pch文件中：#import "WHKit.h"
```

### 这个文件中包含了如下内容
```objc
#import <WHKit/NSArray+WHArray.h>
#import <WHKit/NSDate+WHDate.h>
#import <WHKit/NSDictionary+WHDictionary.h>
#import <WHKit/NSFileManager+WHFileManager.h>
#import <WHKit/NSNumber+WHNumber.h>
#import <WHKit/NSObject+WHObject.h>
#import <WHKit/NSObject+WHRuntime.h>
#import <WHKit/NSString+WHString.h>
#import <WHKit/NSTimer+WHTimer.h>
#import <WHKit/UIBarButtonItem+WHBarButtonItem.h>
#import <WHKit/UIButton+WHButton.h>
#import <WHKit/UIColor+WHColor.h>
#import <WHKit/UIDevice+WHDevice.h>
#import <WHKit/UIImage+WHImage.h>
#import <WHKit/UILabel+WHLabel.h>
#import <WHKit/UINavigationController+WHNavigationController.h>
#import <WHKit/UIScrollView+WHScrollView.h>
#import <WHKit/UITableView+WHTableView.h>
#import <WHKit/UIView+WHView.h>
#import <WHKit/UIViewController+WHVC.h>
#import <WHKit/CALayer+WHLayer.h>
#import <WHKit/UIAlertController+WHAlert.h>
#import <WHKit/Foundation+Safe.h>

#import <WHKit/WHMethods.h>

#import <WHKit/WHMacro.h>
#import <WHKit/SerializeKit.h>
#import <WHKit/WHSingleton.h>
```

### 例子 Example
```objc
/** 点击按钮 */
[button wh_addActionHandler:^{
  NSLog(@"我被点击了");
}];

/** UIView分类， 触发view点击事件 */
[view wh_addTapActionWithBlock:^(UITapGestureRecognizer *gestureRecoginzer) {
  NSLog(@"点击了view");
}];

/** 是否为iPhone X的宏，返回BOOL值 */
if (kIs_iPhoneX ) { ... }

/** 快速创建单例 */
WHSingletonH(ClassName)
WHSingletonM(ClassName)

/** 高效添加圆角 */
- (UIImage*)wh_imageAddCornerWithRadius:(CGFloat)radius andSize:(CGSize)size;

/** 反转数组 */
- (NSArray *)wh_reverseArray;

/** 根据左边和右边的字符串,获得中间特定字符串 */
- (NSString*)wh_substringWithinBoundsLeft:(NSString*)strLeft right:(NSString*)strRight;

/** 渐变颜色*/
+ (UIColor*)wh_gradientFromColor:(UIColor*)fromColor toColor:(UIColor*)toColor withHeight:(CGFloat)height;

/** 十六进制字符串颜色 */
+ (UIColor *)wh_colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

/** 根据Date返回日期字符串 */
+ (NSString *)stringWithDate:(NSDate *)date format:(NSString *)format;

/** 是否润年 */
- (BOOL)isLeapYear;

/** 是否是今天 */
- (BOOL)isToday;
```

### MIT LICENSE
