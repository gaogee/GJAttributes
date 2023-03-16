//
//  GJUTRecorder.h
//  GJAttributes
//
//  Created by zhanggaoju on 2023/3/16.
//  Copyright © 2023 gaogee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GJUIKitAttributesDefines.h"

NS_ASSUME_NONNULL_BEGIN
@interface GJUTStroke : NSObject<GJUTStroke>
@property (nonatomic, strong, nullable) UIColor *color;
@property (nonatomic) float width;
@end

@interface GJUTDecoration : NSObject<GJUTDecoration>
@property (nonatomic, strong, nullable) UIColor *color;
@property (nonatomic) NSUnderlineStyle style;
@end

@interface GJUTImageAttachment : NSObject<GJUTImageAttachment>
@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic) CGRect bounds;
@property (nonatomic) GJUTVerticalAlignment alignment;
@end

@interface GJUTReplace : NSObject
@property (nonatomic, strong, nullable) NSString *fromString;
@property (nonatomic, copy, nullable) void(^block)(id<GJUIKitTextMakerProtocol> make);
@end

@interface GJUTRecorder : NSObject {
    @package
    UIFont *_Nullable font;
    UIColor *_Nullable textColor;
    UIColor *_Nullable backgroundColor;
    NSNumber *_Nullable alignment;
    NSNumber *_Nullable lineSpacing;
    NSNumber *_Nullable kern;
    NSShadow *_Nullable shadow;
    GJUTStroke *_Nullable stroke;
    NSMutableParagraphStyle *_Nullable style;
    NSNumber *_Nullable lineBreakMode;
    GJUTDecoration *_Nullable underLine;
    GJUTDecoration *_Nullable strikethrough;
    NSNumber *_Nullable baseLineOffset;
    
    // - sources
    NSString *_Nullable string;
    NSRange range;
    GJUTImageAttachment *_Nullable attachment;
    NSMutableAttributedString *_Nullable attrStr;
}

- (NSParagraphStyle *)paragraphStyle;
@end
NS_ASSUME_NONNULL_END
