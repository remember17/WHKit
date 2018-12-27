//
//  UIImage+WHImage.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <UIKit/UIKit.h>

typedef void (^UIImageSizeRequestCompleted) (NSURL* imgURL, CGSize size);

@interface UIImage (WHImage)

/** 截屏 */
+(instancetype)wh_snapshotCurrentScreen;

/** 图片模糊效果 */
- (UIImage *)blur;

/** 圆角图片 */
- (UIImage *)imageWithCornerRadius:(CGFloat)radius;

/** 圆角图片 */
- (UIImage*)wh_imageAddCornerWithRadius:(CGFloat)radius andSize:(CGSize)size;

/** 圆形图片 */
+ (UIImage *)wh_GetRoundImagewithImage:(UIImage *)image;

/** 在图片上加居中的文字 */
- (UIImage *)wh_imageWithTitle:(NSString *)title fontSize:(CGFloat)fontSize titleColor:(UIColor *)titleColor;

/**
 取图片某一像素点的颜色
 
 @param point 图片上的某一点
 @return 图片上这一点的颜色
 */
- (UIColor *)wh_colorAtPixel:(CGPoint)point;

/**
 生成一个纯色的图片
 
 @param color 图片颜色
 @return 返回的纯色图片
 */
- (UIImage *)wh_imageWithColor:(UIColor *)color;

/** 获得灰度图 */
- (UIImage *)wh_convertToGrayImage;

/** 合并两个图片为一个图片 */
+ (UIImage*)mergeImage:(UIImage*)firstImage withImage:(UIImage*)secondImage;

/** 压缩图片 最大字节大小为maxLength */
- (NSData *)compressWithMaxLength:(NSInteger)maxLength;

/** 纠正图片的方向 */
- (UIImage *)fixOrientation;

/** 按给定的方向旋转图片 */
- (UIImage*)rotate:(UIImageOrientation)orient;

/** 垂直翻转 */
- (UIImage *)flipVertical;

/** 水平翻转 */
- (UIImage *)flipHorizontal;

/** 将图片旋转degrees角度 */
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/** 将图片旋转radians弧度 */
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;

/** 截取当前image对象rect区域内的图像 */
- (UIImage *)subImageWithRect:(CGRect)rect;

/** 压缩图片至指定尺寸 */
- (UIImage *)rescaleImageToSize:(CGSize)size;

/** 压缩图片至指定像素 */
- (UIImage *)rescaleImageToPX:(CGFloat )toPX;

/** 在指定的size里面生成一个平铺的图片 */
- (UIImage *)getTiledImageWithSize:(CGSize)size;

/** UIView转化为UIImage */
+ (UIImage *)imageFromView:(UIView *)view;

/** 返回截取得到图片的某一块rect */
- (UIImage *)imageCroppedToRect:(CGRect)rect;

/** 倒影 */
- (UIImage *)reflectedImageWithScale:(CGFloat)scale;

/** 倒影 */
- (UIImage *)imageWithReflectionWithScale:(CGFloat)scale gap:(CGFloat)gap alpha:(CGFloat)alpha;

/**
 带有阴影的图片

 @param color 颜色
 @param offset offset
 @param blur 模糊度，可以先设置个20试试
 @return 带有阴影的图片
 */
- (UIImage *)imageWithShadowColor:(UIColor *)color offset:(CGSize)offset blur:(CGFloat)blur;

/**
 透明图片

 @param alpha 透明度
 @return 透明图片
 */
- (UIImage *)imageWithAlpha:(CGFloat)alpha;

+ (UIImage *)animatedImageWithAnimatedGIFData:(NSData *)theData;
+ (UIImage *)animatedImageWithAnimatedGIFURL:(NSURL *)theURL;
- (UIImage *)imageScaledToSize:(CGSize)size;
- (UIImage *)imageScaledToFitSize:(CGSize)size;
- (UIImage *)imageScaledToFillSize:(CGSize)size;
- (UIImage *)imageCroppedAndScaledToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode padToFit:(BOOL)padToFit;
- (UIImage *)imageWithMask:(UIImage *)maskImage;
- (UIImage *)maskImageFromImageAlpha;

@end
