//
//  TaskManager.h
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TaskOperation.h"

@interface TaskManager : NSObject
- (TaskOperation *)executeWithCompletion:(TaskCompletionBlock)completion;
@end
