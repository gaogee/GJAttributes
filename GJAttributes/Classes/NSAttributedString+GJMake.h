//
//  NSAttributedString+GJMake.h
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GJUIKitAttributesDefines.h"

NS_ASSUME_NONNULL_BEGIN
@interface NSAttributedString (GJMake)

+ (instancetype)gj_UIKitText:(void(^)(id<GJUIKitTextMakerProtocol> make))block;

- (CGSize)gj_textSize;
- (CGSize)gj_textSizeForRange:(NSRange)range;
- (CGSize)gj_textSizeForPreferredMaxLayoutWidth:(CGFloat)width;
- (CGSize)gj_textSizeForPreferredMaxLayoutHeight:(CGFloat)height;
@end
NS_ASSUME_NONNULL_END
