//
//  GJViewController.m
//  GJAttributes
//
//  Created by gaogee on 03/16/2023.
//  Copyright (c) 2023 gaogee. All rights reserved.
//

#import "GJViewController.h"
#import "GJAttributes.h"
@interface GJViewController ()

@end

@implementation GJViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    NSAttributedString *att = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
        make.append(@"第一段文字，红色").textColor([UIColor redColor]);
        make.append(@" ");
        make.append(@"第二段文字，蓝色").textColor([UIColor blueColor]);
    }];
    UILabel *lab = [[UILabel alloc]initWithFrame:CGRectMake(100, 100, 240, 30)];
    lab.attributedText = att;
    [self.view addSubview:lab];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
