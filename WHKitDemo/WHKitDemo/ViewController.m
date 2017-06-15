//
//  ViewController.m
//  WHKitDemo
//
//  Created by 吴浩 on 2017/6/15.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import "ViewController.h"
#import "WHKit.h"

@interface ViewController () <UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, weak) UIButton *downButton;

@property (nonatomic, weak) UIButton *topButton;

@end

static NSString *cellID=@"CellID";

@implementation ViewController {
    UITableView *tableV;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    /*******************更多Category请查看WHCategories文件*******************/
    
    [self setupTableView];
    
    [self setupDownButton];
}


#pragma mark - Example
- (void)setupDownButton {
    
    //快速创建button
    UIButton *downButton = [UIButton wh_buttonWithTitle:@"Down" backColor:KBLACK_COLOR backImageName:nil titleColor:KWHITE_COLOR fontSize:14 frame:CGRectMake(self.view.width-65, self.view.height-65, 50, 50) cornerRadius:25];
    
    [self.view addSubview:downButton];
    self.downButton = downButton;
    
    //按钮点击
    [downButton wh_addActionHandler:^{
        [self.topButton removeFromSuperview];
        [self setupTopButton];
        //滑动到底部
        [tableV scrollToBottom];
    }];
}

- (void)setupTopButton {
    
    UIButton *topButton = [UIButton wh_buttonWithTitle:@"Top" backColor:KBLACK_COLOR backImageName:nil titleColor:KWHITE_COLOR fontSize:14 frame:CGRectMake(self.view.width-65, self.view.height-65, 50, 50) cornerRadius:25];
    
    [self.view addSubview:topButton];
    self.topButton = topButton;
    
    [topButton wh_addActionHandler:^{
        [self.downButton removeFromSuperview];
        [self setupDownButton];
        [tableV scrollToTop];
    }];
}

#pragma mark - TableView
- (void)setupTableView{
    tableV=[[UITableView alloc] initWithFrame:CGRectMake(0, 10, self.view.frame.size.width, self.view.frame.size.height) style:UITableViewStylePlain];
    [self.view addSubview:tableV];
    tableV.dataSource = self;
    tableV.delegate = self;
    [tableV registerClass:[UITableViewCell class] forCellReuseIdentifier:cellID];
    
    UIView *emptyView = [UIView new];
    tableV.tableFooterView = emptyView;
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
