#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
@interface YMKGlyphsGlyphIdRange : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly) NSUInteger firstGlyphId;

/**
 * Undocumented
 */
@property (nonatomic, readonly) NSUInteger lastGlyphId;


+ (nonnull YMKGlyphsGlyphIdRange *)glyphIdRangeWithFirstGlyphId:( NSUInteger)firstGlyphId
                                                    lastGlyphId:( NSUInteger)lastGlyphId;


@end
