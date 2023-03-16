//
//  NSAttributedString+GJMake.m
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "NSAttributedString+GJMake.h"
#import "GJUIKitTextMaker.h"

@implementation NSAttributedString (GJMake)
+ (instancetype)gj_UIKitText:(void(^)(id<GJUIKitTextMakerProtocol> make))block {
    GJUIKitTextMaker *maker = [GJUIKitTextMaker new];
    block(maker);
    return maker.install;
}

- (CGSize)gj_textSize {
    return [self gj_textSizeForPreferredMaxLayoutWidth:CGFLOAT_MAX];
}
- (CGSize)gj_textSizeForRange:(NSRange)range {
    if ( range.length < 1 || range.length > self.length )
        return CGSizeZero;
    return gj_textSize([self attributedSubstringFromRange:range], CGFLOAT_MAX, CGFLOAT_MAX);
}
- (CGSize)gj_textSizeForPreferredMaxLayoutWidth:(CGFloat)width {
    return gj_textSize(self, width, CGFLOAT_MAX);
}
- (CGSize)gj_textSizeForPreferredMaxLayoutHeight:(CGFloat)height {
    return gj_textSize(self, CGFLOAT_MAX, height);
}

static CGSize gj_textSize(NSAttributedString *attrStr, CGFloat width, CGFloat height) {
    if ( attrStr.length < 1 )
        return CGSizeZero;
    CGRect bounds = [attrStr boundingRectWithSize:CGSizeMake(width, height) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading context:nil];
    bounds.size.width = ceil(bounds.size.width);
    bounds.size.height = ceil(bounds.size.height);
    return bounds.size;
}
@end
