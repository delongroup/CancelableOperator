//
//  TaskOperation.m
//  OperatorDemo
//
//  Created by chendailong2014@126.com on 14-5-8.
//  Copyright (c) 2014年 com.derlongroup. All rights reserved.
//

#import "TaskOperationExecutor.h"

@interface TaskOperationExecutor ()
@property(nonatomic,copy) TaskBlock block;
@property(nonatomic,copy) TaskCancelBlock cancelBlock;

- (void)invokeCompletionBlock;
- (void)invokeCancelBlock;

@end

@implementation TaskOperationExecutor

- (void)dealloc
{
    self.cancelBlock = nil;
    self.block = nil;
    self.completion = nil;
    self.progressBlock = nil;

    [super dealloc];
}

- (void)invokeCompletionBlock
{
    dispatch_async(dispatch_get_main_queue(), ^{
        @autoreleasepool {
            if (self.completion)
            {
                self.completion(self.running,self.error);
                
                self.cancelBlock = nil;
                self.block = nil;
                self.completion = nil;
                self.progressBlock = nil;
            }
        }
    });
}

- (void)invokeCancelBlock
{
    dispatch_async(dispatch_get_main_queue(), ^{
        @autoreleasepool {
            if (self.cancelBlock)
            {
                [self cancelBlock];
            }
        }
    });
}

- (void)invokeProgressBlock:(NSString *)title progress:(CGFloat)progress params:(NSDictionary *)params
{
    dispatch_async(dispatch_get_main_queue(), ^{
        @autoreleasepool {
            if (self.progressBlock)
            {
                self.progressBlock(title,progress,params);
            }
        }
    });
}

- (void)executeTask:(TaskBlock)block withCancel:(TaskCancelBlock)cancel
{
    self.running = YES;
    self.block = block;
    self.cancelBlock = cancel;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        @autoreleasepool {
            if (self.block)
            {
                self.block(self);
            }
            [self invokeCompletionBlock];
        }
    });
}

- (void)beginTaskWithCancel:(TaskCancelBlock)cancel
{
    self.running = YES;
    self.cancelBlock = cancel;
}

- (void)endTask
{
    [self invokeCompletionBlock];
}

- (void)cancel
{
    self.running = NO;
    
    [self invokeCancelBlock];
    [self invokeCompletionBlock];
}

@end
