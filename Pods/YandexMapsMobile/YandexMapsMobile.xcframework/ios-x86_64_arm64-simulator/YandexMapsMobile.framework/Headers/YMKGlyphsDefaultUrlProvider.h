#import <YandexMapsMobile/YMKGlyphsGlyphUrlProvider.h>

/// :nodoc:
@interface YMKGlyphsDefaultUrlProvider : NSObject<YMKGlyphsGlyphUrlProvider>

- (NSString *)formatUrlWithFontId:(NSString *)fontId
                            range:(YMKGlyphsGlyphIdRange *)range;

- (void)setUrlPattern:(NSString *)urlPattern;

@end
