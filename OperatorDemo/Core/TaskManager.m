//
//  TaskManager.m
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import "TaskManager.h"
#import "TaskOperationExecutor.h"

@implementation TaskManager

- (TaskOperation *)executeWithCompletion:(TaskCompletionBlock)completion
{
    TaskOperationExecutor *executor = [[TaskOperationExecutor alloc] init];
    executor.completion = completion;
    [executor executeTask:^(TaskOperationExecutor *executor) {
        NSInteger l = 0;
        while (l++ < 10 && executor.running)
        {
            [NSThread sleepForTimeInterval:1];
            [executor invokeProgressBlock:[NSString stringWithFormat:@"%d",l,nil] progress:0 params:nil];
        }
    } withCancel:^{
        
    }];
    
    [executor release];

    return executor;
}

@end

