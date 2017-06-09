# WHCategory
分类,开发小工具

### 使用方法 
```objc
 a>> 直接在本网页下载使用：#import "WHCategory.h"
 b>> 或者利用CocoaPods安装到项目中：#import <WHCategory.h>
```

### 这个文件中包含了如下内容
```objc
#import "NSArray+WHArray.h"
#import "NSDate+WHDate.h"
#import "NSDictionary+WHDictionary.h"
#import "NSFileManager+WHFileManager.h"
#import "NSNumber+WHNumber.h"
#import "NSObject+WHObject.h"
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

* 还包含一个好用的宏文件
#import "WHMacro.h"
```

### 例子 Example
```objc
//点击按钮
    [button wh_addActionHandler:^{
        //点击按钮之后的事件 do something
        NSLog(@"我被点击了");
    }];

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

### 还有许多好用的方法在分类中。如果觉得好用就给个Star吧,谢谢😁

## MIT LICENSE
