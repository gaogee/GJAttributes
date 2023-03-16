//
//  GJUIKitAttributesDefines.h
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#ifndef GJUIKitAttributesDefines_h
#define GJUIKitAttributesDefines_h
#import <UIKit/UIKit.h>
@protocol   GJUIKitTextMakerProtocol,
            GJUTAttributesProtocol,
            GJUTImageAttributesProtocol,
            GJUTRegexHandlerProtocol,
            GJUTRangeHandlerProtocol,
            GJUTStroke,
            GJUTDecoration,
            GJUTImageAttachment;

@protocol GJUIKitTextMakerProtocol <GJUTAttributesProtocol>
/**
 * - Append a `string` to the text.
 *
 * \code
 *    NSAttributedString *text = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.append(@"String 1").font([UIFont boldSystemFontOfSize:14]);
 *   }];
 *
 *   // It's equivalent to below code.
 *
 *   NSDictionary *attributes = @{NSFontAttributeName:[UIFont boldSystemFontOfSize:20]};
 *   NSAttributedString *text1 = [[NSAttributedString alloc] initWithString:@"String 1" attributes:attributes];
 *
 * \endcode
 */
@property (nonatomic, copy, readonly) id<GJUTAttributesProtocol>_Nullable(^ _Nullable append)(NSString * _Nullable str);

typedef void(^GJUTAppendImageHandler)(id<GJUTImageAttachment> _Nullable make);
/**
 * - Append an `image attachment` to the text.
 *
 * \code
 *    NSAttributedString *text = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.appendImage(^(id<GJUTImageAttachment>  _Nonnull make) {
 *           make.image = [UIImage imageNamed:@"image"];
 *           make.bounds = CGRectMake(0, 0, 50, 50);
 *       });
 *   }];
 *
 *   // It's equivalent to below code.
 *
 *   NSTextAttachment *attachment = [[NSTextAttachment alloc] init];
 *   attachment.image = [UIImage imageNamed:@"image"];
 *   attachment.bounds = CGRectMake(0, 0, 50, 50);
 *   NSAttributedString *text1 = [NSAttributedString attributedStringWithAttachment:attachment];
 *
 * \endcode
 */
@property (nonatomic, copy, readonly) id<GJUTAttributesProtocol>_Nullable(^ _Nullable appendImage)(GJUTAppendImageHandler _Nullable block);

/**
 * - Append a `subtext` to the text.
 *
 * \code
 *   NSAttributedString *subtext = _label.attributedText;
 *
 *   NSAttributedString *text = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.appendText(subtext);
 *   }];
 *
 * \endcode
 */
@property (nonatomic, copy, readonly) id<GJUTAttributesProtocol>_Nullable(^ _Nullable appendText)(NSAttributedString * _Nullable subtext);

/**
 * - Update the attributes for the specified range of `text`.
 *
 * \code
 *    NSAttributedString *text = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.append(@"String 1");
 *       make.update(NSMakeRange(0, 1)).font([UIFont boldSystemFontOfSize:20]);
 *   }];
 * \endcode
 */
@property (nonatomic, copy, readonly) id<GJUTAttributesProtocol>_Nullable(^ _Nullable update)(NSRange range);

/**
 * - Use regular to process `text`.
 *
 * \code
 *    NSAttributedString *text1 = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.append(@"123 123 4 123 123");
 *       // Replace `123` with `oOo`.
 *       make.regex(@"123").replaceWithString(@"oOo").font([UIFont boldSystemFontOfSize:20]);
 *   }];
 *
 *    NSAttributedString *text2 = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.append(@"123 123 4 123 123");
 *       // Replace `123` with `oOo`.
 *       make.regex(@"123").replaceWithText(^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *           make.append(@"oOo").font([UIFont boldSystemFontOfSize:20]);
 *       });
 *   }];
 *
 *    NSAttributedString *text3 = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.append(@"123 123 4 123 123");
 *       // Update the attributes of the matched text.
 *       make.regex(@"123").update(^(id<GJUTAttributesProtocol>  _Nonnull make) {
 *           make.font([UIFont boldSystemFontOfSize:20]).textColor([UIColor redColor]);
 *       });
 *   }];
 * \endcode
 */
@property (nonatomic, copy, readonly) id<GJUTRegexHandlerProtocol>_Nullable(^ _Nullable regex)(NSString * _Nullable regularExpression);

/**
 * - Edit the subtext for the specified range of `text`.
 *
 * \code
 *    NSAttributedString *text = [NSAttributedString gj_UIKitText:^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *       make.append(@"123 123 M 123 123").font([UIFont boldSystemFontOfSize:20]);
 *       // Update the attributes for the specified range of `text`.
 *       make.range(NSMakeRange(0, 1)).update(^(id<GJUTAttributesProtocol>  _Nonnull make) {
 *           make.font([UIFont boldSystemFontOfSize:20]).textColor([UIColor orangeColor]);
 *       });
 *
 *       // Replace the subtext for the specified range of `text`.
 *       make.range(NSMakeRange(1, 1)).replaceWithString(@"O").textColor([UIColor purpleColor]);
 *
 *       // Replace the subtext for the specified range of `text`.
 *       make.range(NSMakeRange(2, 1)).replaceWithText(^(id<GJUIKitTextMakerProtocol>  _Nonnull make) {
 *           make.append(@"S").font([UIFont boldSystemFontOfSize:24]).textColor([UIColor greenColor]);
 *       });
 *   }];
 * \endcode
 */
@property (nonatomic, copy, readonly) id<GJUTRangeHandlerProtocol>_Nullable(^ _Nullable range)(NSRange range);
@end

typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTFontAttribute)(UIFont * _Nullable font);
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTColorAttribute)(UIColor * _Nullable color);
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTAlignmentAttribute)(NSTextAlignment alignment);
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTLineSpacingAttribute)(CGFloat lineSpacing);
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTKernAttribute)(CGFloat kern);
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTShadowAttribute)(void(^_Nullable)(NSShadow * _Nullable make));
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTStrokeAttribute)(void(^ _Nullable block)(id<GJUTStroke> _Nullable make));
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTParagraphStyleAttribute)(void(^ _Nullable block)(NSMutableParagraphStyle * _Nullable make));
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTLineBreakModeAttribute)(NSLineBreakMode lineBreakMode);
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTDecorationAttribute)(void(^_Nullable)(id<GJUTDecoration> _Nullable make));
typedef id<GJUTAttributesProtocol>_Nonnull(^GJUTBaseLineOffsetAttribute)(double offset);

@protocol GJUTAttributesProtocol
@property (nonatomic, copy, readonly) GJUTFontAttribute _Nullable font;
@property (nonatomic, copy, readonly) GJUTColorAttribute _Nullable textColor;
@property (nonatomic, copy, readonly) GJUTColorAttribute _Nullable backgroundColor;
@property (nonatomic, copy, readonly) GJUTAlignmentAttribute _Nullable alignment;
@property (nonatomic, copy, readonly) GJUTLineSpacingAttribute _Nullable lineSpacing;
@property (nonatomic, copy, readonly) GJUTKernAttribute _Nullable kern;
@property (nonatomic, copy, readonly) GJUTShadowAttribute _Nullable shadow;
@property (nonatomic, copy, readonly) GJUTStrokeAttribute _Nullable stroke;
@property (nonatomic, copy, readonly) GJUTParagraphStyleAttribute _Nullable paragraphStyle;
@property (nonatomic, copy, readonly) GJUTLineBreakModeAttribute _Nullable lineBreakMode;
@property (nonatomic, copy, readonly) GJUTDecorationAttribute _Nullable underLine;
@property (nonatomic, copy, readonly) GJUTDecorationAttribute _Nullable strikethrough;
@property (nonatomic, copy, readonly) GJUTBaseLineOffsetAttribute _Nullable baseLineOffset;
@end

@protocol GJUTRangeHandlerProtocol
@property (nonatomic, copy, readonly) void(^ _Nullable update)(void(^_Nullable)(id<GJUTAttributesProtocol> _Nullable make));
@property (nonatomic, copy, readonly) void(^ _Nullable replaceWithText)(void(^_Nullable)(id<GJUIKitTextMakerProtocol> _Nullable make));
@property (nonatomic, copy, readonly) id<GJUTAttributesProtocol>_Nullable(^ _Nullable replaceWithString)(NSString * _Nullable string);
@end

@protocol GJUTRegexHandlerProtocol <GJUTRangeHandlerProtocol>
@property (nonatomic, copy, readonly) void(^ _Nullable handler)(void(^_Nullable)(NSMutableAttributedString * _Nullable attrStr, NSTextCheckingResult * _Nullable result));

@property (nonatomic, copy, readonly) id<GJUTRegexHandlerProtocol>_Nullable(^ _Nullable regularExpressionOptions)(NSRegularExpressionOptions ops);
@property (nonatomic, copy, readonly) id<GJUTRegexHandlerProtocol>_Nullable(^ _Nullable matchingOptions)(NSMatchingOptions ops);
@end

@protocol GJUTStroke
@property (nonatomic, strong, nullable) UIColor *color;
@property (nonatomic) float width;
@end

@protocol GJUTDecoration
@property (nonatomic, strong, nullable) UIColor *color;
@property (nonatomic) NSUnderlineStyle style;
@end

typedef enum : NSUInteger {
    GJUTVerticalAlignmentBottom = 0,
    GJUTVerticalAlignmentCenter = 1,
    GJUTVerticalAlignmentTop = 2,
} GJUTVerticalAlignment;

@protocol GJUTImageAttachment <NSObject>
@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic) GJUTVerticalAlignment alignment; ///< Text为统一的字体时生效
@property (nonatomic) CGRect bounds;
@end
#endif /* GJUIKitAttributesDefines_h */
