//
//  GJUTRangeHandler.m
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "GJUTRangeHandler.h"
#import "GJUTAttributes.h"

@implementation GJUTRangeHandler
- (instancetype)initWithRange:(NSRange)range {
    self = [super init];
    if ( !self ) return nil;
    _recorder = [[GJUTRangeRecorder alloc] init];
    _recorder.range = range;
    return self;
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
@end

@implementation GJUTRangeRecorder
@end
