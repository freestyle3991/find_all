#import <Foundation/Foundation.h>

@class YMKGlyphsGlyphIdRange;

/**
 * :nodoc:
 */
@protocol YMKGlyphsGlyphUrlProvider <NSObject>

/**
 * This method may be called on any thread. Its implementation must be thread-safe.
 */
- (nonnull NSString *)formatUrlWithFontId:(nonnull NSString *)fontId
                                    range:(nonnull YMKGlyphsGlyphIdRange *)range;

@end
