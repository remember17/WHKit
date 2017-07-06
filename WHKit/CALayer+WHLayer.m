//
//  CALayer+WHLayer.m
//  WHKitDemo
//
//  Created by joymed on 2017/7/6.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import "CALayer+WHLayer.h"

@implementation CALayer (WHLayer)

-(void)shake{
    CAKeyframeAnimation *keyAnimation = [CAKeyframeAnimation animationWithKeyPath:@"transform.translation.x"];
    CGFloat shakeWidth = 16;
    keyAnimation.values = @[@(-shakeWidth),@(0),@(shakeWidth),@(0),@(-shakeWidth),@(0),@(shakeWidth),@(0)];
    //时长
    keyAnimation.duration = .1f;
    //重复
    keyAnimation.repeatCount =2;
    //移除
    keyAnimation.removedOnCompletion = YES;
    [self addAnimation:keyAnimation forKey:@"shake"];
}

@end
