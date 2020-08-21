# WHKit

### 使用方法 
```objc
pod 'WHKit', '~>1.8.0'

也可以直接把WHKit文件添加进工程中
在pch文件中：#import "WHKit.h"
```

### 这个文件中包含了如下内容
```objc
/************* 分类 *************/
#import "NSArray+WHArray.h"
#import "NSDate+WHDate.h"
#import "NSDictionary+WHDictionary.h"
#import "NSFileManager+WHFileManager.h"
#import "NSNumber+WHNumber.h"
#import "NSObject+WHObject.h"
#import "NSObject+WHRuntime.h"
#import "NSString+WHString.h"
#import "NSTimer+WHTimer.h"
#import "UIBarButtonItem+WHBarButtonItem.h"
#import "UIButton+WHButton.h"
#import "UIColor+WHColor.h"
#import "UIDevice+WHDevice.h"
#import "UIImage+WHImage.h"
#import "UIImageView+WHImageView.h"
#import "UILabel+WHLabel.h"
#import "UINavigationController+WHNavigationController.h"
#import "UIScrollView+WHScrollView.h"
#import "UITableView+WHTableView.h"
#import "UIView+WHView.h"
#import "UIViewController+WHVC.h"
#import "WHMethods.h"
#import "SerializeKit.h"
#import "WHSingleton.h"
#import "CALayer+WHLayer.h"
#import "UIAlertController+WHAlert.h"
#import "Foundation+Safe.h"
/******************************/


/************* 宏 *************/
#import "WHMacro.h"
/******************************/
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

/** 改变状态栏的颜色 */
[WHMethods wh_setStatusBarBackgroundColor:[UIColor lightGrayColor]];

/** 高效添加圆角 */
- (UIImage*)wh_imageAddCornerWithRadius:(CGFloat)radius andSize:(CGSize)size;

/** mac地址 */
NSString *macAddress = [UIDevice macAddress];

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
