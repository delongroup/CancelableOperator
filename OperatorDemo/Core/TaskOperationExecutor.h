//
//  TaskOperationExecutor.h
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import "TaskOperation.h"

@class TaskOperationExecutor;
/**
 *  任务执行
 *
 *  @param executor 任务对象
 */
typedef void (^TaskBlock)(TaskOperationExecutor *executor);

/**
 *  取消任务
 */
typedef void (^TaskCancelBlock)();

/**
 *  任务的实现
 */
@interface TaskOperationExecutor : TaskOperation
@property(nonatomic,copy) TaskCompletionBlock completion;
@property(nonatomic,assign) volatile BOOL running;
@property(nonatomic,retain) NSError *error;

/**
 *  主进程中回调进度
 *
 *  @param title    标题
 *  @param progress 进度
 *  @param params   参数
 */
- (void)invokeProgressBlock:(NSString *)title progress:(CGFloat)progress params:(NSDictionary *)params;

/**
 *  执行任务
 *
 *  @param block  执行任务块
 *  @param cancel 取消任务块
 */
- (void)executeTask:(TaskBlock)block withCancel:(TaskCancelBlock)cancel;

/**
 *  执行异步操作
 *
 *  @param cancel 取消任务块
 */
- (void)beginTaskWithCancel:(TaskCancelBlock)cancel;

/**
 *  完成任务
 */
- (void)endTask;

@end

