//
//  TaskOperationExecutor.h
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import "TaskOperation.h"

@class TaskOperationExecutor;
typedef void (^TaskBlock)(TaskOperationExecutor *executor);
typedef void (^TaskCancelBlock)();

@interface TaskOperationExecutor : TaskOperation
@property(nonatomic,copy) TaskCompletionBlock completion;
@property(nonatomic,assign) volatile BOOL running;
@property(nonatomic,retain) NSError *error;

- (void)invokeProgressBlock:(NSString *)title progress:(CGFloat)progress params:(NSDictionary *)params;

- (void)executeTask:(TaskBlock)block withCancel:(TaskCancelBlock)cancel;

- (void)beginTaskWithCancel:(TaskCancelBlock)cancel;
- (void)endTask;

@end

