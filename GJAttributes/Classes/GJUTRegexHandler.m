//
//  GJUTRegexHandler.m
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "GJUTRegexHandler.h"
#import "GJUTAttributes.h"

@implementation GJUTRegexHandler
- (instancetype)initWithRegex:(NSString *)regex {
    self = [super init];
    if ( !self ) return nil;
    _recorder = [GJUTRegexRecorder new];
    _recorder.regex = regex;
    return self;
}

- (void (^)(void (^ _Nonnull)(NSMutableAttributedString *attrStr, NSTextCheckingResult * _Nonnull)))handler {
    return ^(void(^block)(NSMutableAttributedString *attrStr, NSTextCheckingResult *result)) {
        self.recorder.handler = block;
    };
}
- (void (^)(void (^ _Nonnull)(id<GJUIKitTextMakerProtocol> _Nonnull)))replaceWithText {
    return ^(void(^block)(id<GJUIKitTextMakerProtocol> make)) {
        self.recorder.replaceWithText = block;
    };
}
- (id<GJUTAttributesProtocol>  _Nonnull (^)(NSString * _Nonnull))replaceWithString {
    return ^id<GJUTAttributesProtocol>(NSString *string) {
        GJUTAttributes *attr = [GJUTAttributes new];
        attr.recorder->string = string;
        self.recorder.utOfReplaceWithString = attr;
        return attr;
    };
}
- (void (^)(void (^ _Nonnull)(id<GJUTAttributesProtocol> _Nonnull)))update {
    return ^(void(^block)(id<GJUTAttributesProtocol> make)) {
        self.recorder.update = block;
    };
}
- (id<GJUTRegexHandlerProtocol>  _Nonnull (^)(NSMatchingOptions))matchingOptions {
    return ^id<GJUTRegexHandlerProtocol>(NSMatchingOptions ops) {
        self.recorder.matchingOptions = ops;
        return self;
    };
}
- (id<GJUTRegexHandlerProtocol>  _Nonnull (^)(NSRegularExpressionOptions))regularExpressionOptions {
    return ^id<GJUTRegexHandlerProtocol>(NSRegularExpressionOptions ops) {
        self.recorder.regularExpressionOptions = ops;
        return self;
    };
}
@end

@implementation GJUTRegexRecorder
- (instancetype)init {
    self = [super init];
    if ( !self ) return nil;
    _matchingOptions = NSMatchingWithoutAnchoringBounds;
    return self;
}
@end
