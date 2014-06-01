//
//  TaskOperation.h
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^TaskProgressBlock)(NSString *title, CGFloat progress, NSDictionary *params);
typedef void (^TaskCompletionBlock)(BOOL finished, NSError *error);

@interface TaskOperation : NSObject
@property(nonatomic,copy) TaskProgressBlock progressBlock;

- (void)cancel;

@end
