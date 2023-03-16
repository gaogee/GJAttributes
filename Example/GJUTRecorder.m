//
//  GJUTRecorder.m
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import "GJUTRecorder.h"

NS_ASSUME_NONNULL_BEGIN
@implementation GJUTStroke
@end
@implementation GJUTDecoration
@end
@implementation GJUTImageAttachment
@end
@implementation GJUTReplace
@end

@implementation GJUTRecorder
- (NSParagraphStyle *)paragraphStyle {
    if ( !self->style ) {
        NSMutableParagraphStyle *style = [NSParagraphStyle defaultParagraphStyle].mutableCopy;
        style.lineSpacing = [self->lineSpacing doubleValue];
        style.alignment = [self->alignment integerValue];
        style.lineBreakMode = [self->lineBreakMode integerValue];
        return style;
    }
    return self->style;
}
@end
NS_ASSUME_NONNULL_END
