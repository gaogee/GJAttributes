//
//  GJUTAttributes.h
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GJUIKitAttributesDefines.h"
#import "GJUTRecorder.h"

NS_ASSUME_NONNULL_BEGIN
@interface GJUTAttributes : NSObject<GJUTAttributesProtocol>
@property (nonatomic, strong, readonly) GJUTRecorder *recorder;
@end
NS_ASSUME_NONNULL_END

