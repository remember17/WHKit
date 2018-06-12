//
//  ViewController.m
//  WHKitDemo
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/15.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import "ViewController.h"
#import "WHKit.h"

@interface ViewController () <UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, weak) UIButton *downButton;

@property (nonatomic, weak) UIButton *topButton;

@property (nonatomic, strong) UITableView *tableview;

@end

static NSString *cellID=@"CellID";

@implementation ViewController {
    UITableView *tableV;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    /*******************更多Category请查看WHKit文件*******************/
    
    [self setupTableView];
    
    [self setupDownButton];
    
    // 本月的第一天距离现在多久
    NSLog(@"%@",[[NSDate begindayOfMonth:[NSDate new]] timeInfo]);
}

#pragma mark - Example
- (void)setupDownButton {
    
    //快速创建button
    UIButton *downButton = [UIButton wh_buttonWithTitle:@"Down" backColor:kBlackColor backImageName:nil titleColor:kWhiteColor fontSize:14 frame:CGRectMake(self.view.width-65, self.view.height-65, 50, 50) cornerRadius:25];
    
    [self.view addSubview:downButton];
    self.downButton = downButton;
    
    //按钮点击
    @weakify(self); // 处理循环引用
    [downButton wh_addActionHandler:^{
        @strongify(self);
        [self.topButton removeFromSuperview];
        [self setupTopButton];
        //滑到底部
        [self.tableview scrollToBottom];
    }];
}

- (void)setupTopButton {
    
    UIButton *topButton = [UIButton wh_buttonWithTitle:@"Top" backColor:kBlackColor backImageName:nil titleColor:kWhiteColor fontSize:14 frame:CGRectMake(self.view.width-65, self.view.height-65, 50, 50) cornerRadius:25];
    
    [self.view addSubview:topButton];
    self.topButton = topButton;
    
    @weakify(self); // 处理循环引用
    [topButton wh_addActionHandler:^{
        @strongify(self);
        [self.downButton removeFromSuperview];
        [self setupDownButton];
        [self.tableview scrollToTop];
    }];
}

#pragma mark - TableView
- (void)setupTableView{
    _tableview=[[UITableView alloc] initWithFrame:CGRectMake(0, 10, self.view.frame.size.width, self.view.frame.size.height) style:UITableViewStylePlain];
    [self.view addSubview:_tableview];
    _tableview.dataSource = self;
    _tableview.delegate = self;
    [_tableview registerClass:[UITableViewCell class] forCellReuseIdentifier:cellID];
    UIView *emptyView = [UIView new];
    _tableview.tableFooterView = emptyView;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 5000;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID forIndexPath:indexPath];
    cell.textLabel.text = [NSString stringWithFormat:@"%ld",indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

@end
