//
//  GJUTAttributes.m
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "GJUTAttributes.h"

@implementation GJUTAttributes
@synthesize recorder = _recorder;
- (GJUTRecorder *)recorder {
    if ( !_recorder ) {
        _recorder = [[GJUTRecorder alloc] init];
    }
    return _recorder;
}

- (GJUTFontAttribute)font {
    return ^id<GJUTAttributesProtocol>(UIFont *font) {
        self.recorder->font = font;
        return self;
    };
}

- (GJUTColorAttribute)textColor {
    return ^id<GJUTAttributesProtocol>(UIColor *color) {
        self.recorder->textColor = color;
        return self;
    };
}

- (GJUTAlignmentAttribute)alignment {
    return ^id<GJUTAttributesProtocol>(NSTextAlignment alignment) {
        self.recorder->alignment = @(alignment);
        return self;
    };
}

- (GJUTLineSpacingAttribute)lineSpacing {
    return ^id<GJUTAttributesProtocol>(CGFloat lineSpacing) {
        self.recorder->lineSpacing = @(lineSpacing);
        return self;
    };
}

- (GJUTKernAttribute)kern {
    return ^id<GJUTAttributesProtocol>(CGFloat kern) {
        self.recorder->kern = @(kern);
        return self;
    };
}

- (GJUTShadowAttribute)shadow {
    return ^id<GJUTAttributesProtocol>(void(^block)(NSShadow *make)) {
        NSShadow *_Nullable shadow = self.recorder->shadow;
        if ( !shadow ) {
            self.recorder->shadow = shadow = [NSShadow new];
        }
        block(shadow);
        return self;
    };
}

- (GJUTColorAttribute)backgroundColor {
    return ^id<GJUTAttributesProtocol>(UIColor *color) {
        self.recorder->backgroundColor = color;
        return self;
    };
}

- (GJUTStrokeAttribute)stroke {
    return ^id<GJUTAttributesProtocol>(void(^block)(id<GJUTStroke> stroke)) {
        GJUTStroke *_Nullable stroke = self.recorder->stroke;
        if ( !stroke ) {
            self.recorder->stroke = stroke = [GJUTStroke new];
        }
        block(stroke);
        return self;
    };
}

- (GJUTParagraphStyleAttribute)paragraphStyle {
    return ^id<GJUTAttributesProtocol>(void(^block)(NSMutableParagraphStyle *style)) {
        NSMutableParagraphStyle *_Nullable style = self.recorder->style;
        if ( !style ) {
            self.recorder->style = style = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
        }
        block(style);
        return self;
    };
}

- (GJUTLineBreakModeAttribute)lineBreakMode {
    return ^id<GJUTAttributesProtocol>(NSLineBreakMode lineBreakMode) {
        self.recorder->lineBreakMode = @(lineBreakMode);
        return self;
    };
}

- (GJUTDecorationAttribute)underLine {
    return ^id<GJUTAttributesProtocol>(void(^block)(id<GJUTDecoration> decoration)) {
        GJUTDecoration *_Nullable decoration = self.recorder->underLine;
        if ( !decoration ) {
            self.recorder->underLine = decoration = [GJUTDecoration new];
        }
        block(decoration);
        return self;
    };
}

- (GJUTDecorationAttribute)strikethrough {
    return ^id<GJUTAttributesProtocol>(void(^block)(id<GJUTDecoration> decoration)) {
        GJUTDecoration *_Nullable decoration = self.recorder->strikethrough;
        if ( !decoration ) {
            self.recorder->strikethrough = decoration = [GJUTDecoration new];
        }
        block(decoration);
        return self;
    };
}

- (GJUTBaseLineOffsetAttribute)baseLineOffset {
    return ^id<GJUTAttributesProtocol>(double offset) {
        self.recorder->baseLineOffset = @(offset);
        return self;
    };
}
@end
