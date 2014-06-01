//
//  TaskOperation.m
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import "TaskOperation.h"

@implementation TaskOperation

- (void)dealloc
{
    self.progressBlock = nil;
    [super dealloc];
}

- (void)cancel
{
    
}

@end
