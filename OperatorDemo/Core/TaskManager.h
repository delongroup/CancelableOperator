//
//  TaskManager.h
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TaskOperation.h"

/**
 *  任务管理
 */
@interface TaskManager : NSObject
/**
 *  执行任务
 *
 *  @param completion 任务完成时执行
 *
 *  @return 任务对象
 */
- (TaskOperation *)executeWithCompletion:(TaskCompletionBlock)completion;
@end
