# WHKit
分类,开发小工具

### 使用方法 
```objc
pod 'WHKit', '~>1.7'
如果没找到, 请先pod setup

也可以直接在本网页下载，然后把WHKit文件加入到工程中使用

在使用的地方：#import "WHKit.h"
推荐直接在pch文件中：#import "WHKit.h"
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
//点击按钮
[button wh_addActionHandler:^{
  NSLog(@"我被点击了");
}];

//是否为iPhone X的宏，返回BOOL值
if (kIs_iPhoneX ) { ... }

//快速创建单例
WHSingletonH(ClassName)
WHSingletonM(ClassName)

//快速创建一个Button, 其中KBLACK_COLOR是颜色的宏
UIButton *button = [UIButton wh_buttonWithTitle:@"Test" backColor:KBLACK_COLOR backImageName:nil titleColor:KWHITE_COLOR fontSize:14 frame:CGRectMake(100, 100, 50, 50) cornerRadius:7];

//改变手机状态栏的颜色
[WHMethods wh_setStatusBarBackgroundColor:[UIColor lightGrayColor]];

//高效添加圆角图片
- (UIImage*)wh_imageAddCornerWithRadius:(CGFloat)radius andSize:(CGSize)size;

/** mac地址*/
NSString *macAddress = [UIDevice macAddress];

/**反转数组*/
- (NSArray *)wh_reverseArray;

//获得一般模型属性
-(void)wh_createProperty;

/**根据左边和右边的字符串,获得中间特定字符串*/
- (NSString*)wh_substringWithinBoundsLeft:(NSString*)strLeft right:(NSString*)strRight;

/**@brief  渐变颜色*/
+ (UIColor*)wh_gradientFromColor:(UIColor*)fromColor toColor:(UIColor*)toColor withHeight:(CGFloat)height;
```

### MIT LICENSE
