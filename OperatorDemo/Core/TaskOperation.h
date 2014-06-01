//
//  TaskOperation.h
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  任务进度
 *
 *  @param title    描述
 *  @param progress 完成度
 *  @param params   参数
 */
typedef void (^TaskProgressBlock)(NSString *title, CGFloat progress, NSDictionary *params);

/**
 *  任务完成
 *
 *  @param finished 是否完成,如果任务被取消或者异常则为NO
 *  @param error    错误
 */
typedef void (^TaskCompletionBlock)(BOOL finished, NSError *error);

@interface TaskOperation : NSObject
@property(nonatomic,copy) TaskProgressBlock progressBlock;

/**
 *  结束任务
 */
- (void)cancel;

@end
