//
//  GJUTRangeHandler.h
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "GJUIKitAttributesDefines.h"
@class GJUTRangeRecorder;

NS_ASSUME_NONNULL_BEGIN
@interface GJUTRangeHandler : NSObject<GJUTRangeHandlerProtocol>
- (instancetype)initWithRange:(NSRange)range;
@property (nonatomic, strong, readonly) GJUTRangeRecorder *recorder;
@end

@interface GJUTRangeRecorder : NSObject
@property (nonatomic) NSRange range;
@property (nonatomic, strong, nullable) id<GJUTAttributesProtocol> utOfReplaceWithString;
@property (nonatomic, copy, nullable) void(^replaceWithText)(id<GJUIKitTextMakerProtocol> make);
@property (nonatomic, copy, nullable) void(^update)(id<GJUTAttributesProtocol> make);
@end
NS_ASSUME_NONNULL_END
