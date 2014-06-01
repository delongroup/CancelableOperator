//
//  ViewController.m
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import "ViewController.h"
#import "TaskManager.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    TaskManager *taskManager = [[TaskManager alloc] init];
    TaskOperation *operation = [taskManager executeWithCompletion:^(BOOL finished, NSError *error) {
        NSLog(@"finished");
    }];
    
    operation.progressBlock = ^(NSString *title, CGFloat progress, NSDictionary *params){
        NSLog(@"%@",title);
        [operation cancel];
    };
    
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
