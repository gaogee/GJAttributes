//
//  GJUTRegexHandler.h
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "GJUIKitAttributesDefines.h"
@class GJUTRegexRecorder;

NS_ASSUME_NONNULL_BEGIN
@interface GJUTRegexHandler : NSObject<GJUTRegexHandlerProtocol>
- (instancetype)initWithRegex:(NSString *)regex;
@property (nonatomic, strong, readonly) GJUTRegexRecorder *recorder;
@end

@interface GJUTRegexRecorder : NSObject
@property (nonatomic) NSRegularExpressionOptions regularExpressionOptions;
@property (nonatomic) NSMatchingOptions matchingOptions;
@property (nonatomic, strong, nullable) id<GJUTAttributesProtocol> utOfReplaceWithString;
@property (nonatomic, copy, nullable) NSString *regex;
@property (nonatomic, copy, nullable) void(^replaceWithText)(id<GJUIKitTextMakerProtocol> make);
@property (nonatomic, copy, nullable) void(^update)(id<GJUTAttributesProtocol> make);
@property (nonatomic, copy, nullable) void(^handler)(NSMutableAttributedString *attrStr, NSTextCheckingResult *result);
@end
NS_ASSUME_NONNULL_END
