//
//  UIImageView+WHImageView.h
//  WHCategory
//  https://github.com/remember17/WHCategory
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (WHImageView)

//快速创建imageView
+(instancetype)wh_imageViewWithPNGImage:(NSString *)imageName frame:(CGRect)frame;

@end
