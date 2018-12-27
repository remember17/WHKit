//
//  ViewController.m
//  WHKitDemo
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/15.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import "ViewController.h"
#import "WHKit.h"

/***********************************************************/
/******************* 更多Category查看WHKit *******************/
/***********************************************************/

@interface ViewController () <UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, weak) UIButton *button;

@property (nonatomic, assign) BOOL isBottom;

@property (nonatomic, strong) UITableView *tableview;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"TEST";
    
    [self.view addSubview:self.tableview];
    [self.view addSubview:self.button];
    
    // 本月的第一天距离现在多久
    NSLog(@"%@",[[NSDate begindayOfMonth:[NSDate new]] timeInfo]);

    // 定时器
    __block NSInteger test = 1;
    NSTimer *timer = [NSTimer wh_scheduledTimerWithTimeInterval:1 repeats:YES callback:^(NSTimer *timer) {
        NSLog(@"%ld",(test += 1));
    }];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [timer pauseTimer]; // 暂停
        [timer resumeTimerAfterTimeInterval:5]; // 5秒后重新开启
    });
}

#pragma mark - delegate & datasource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 5000;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CellID" forIndexPath:indexPath];
    cell.textLabel.text = [NSString stringWithFormat:@"%ld",indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

#pragma mark - property

- (UITableView *)tableview {
    if (!_tableview) {
        _tableview=[[UITableView alloc] initWithFrame:CGRectMake(0, kTopHeight, kScreenWidth, kScreenHeight) style:UITableViewStylePlain];
        _tableview.dataSource = self;
        _tableview.delegate = self;
        [_tableview registerClass:[UITableViewCell class] forCellReuseIdentifier:@"CellID"];
    }
    return _tableview;
}

- (UIButton *)button {
    if (!_button) {
        //快速创建button
        _button = [UIButton wh_buttonWithTitle:@"Down" backColor:kBlackColor backImageName:@"" titleColor:kWhiteColor fontSize:14 frame:CGRectMake(self.view.width-65, self.view.height-65, 50, 50) cornerRadius:25];
        @weakify(self); // 处理循环引用
        [_button wh_addActionHandler:^{ //按钮点击
            @strongify(self);
            [self.button setTitle:(self.isBottom ? @"Down" : @"Top") forState:UIControlStateNormal];
            if (self.isBottom) {
                [self.tableview scrollToTop];
            } else {
                [self.tableview scrollToBottom];
            }
            self.isBottom = !self.isBottom;
        }];
    }
    return _button;
}

@end
