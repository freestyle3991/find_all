#import <YandexMapsMobile/YMKTileId.h>
#import <YandexMapsMobile/YMKVersion.h>

/**
 * Provides a formatted URL.
 */
@protocol YMKTilesUrlProvider <NSObject>

/**
 * Creates a URL based on the tile ID and version.
 *
 * This method may be called on any thread. Its implementation must be thread-safe.
 */
- (nonnull NSString *)formatUrlWithTileId:(nonnull YMKTileId *)tileId
                                  version:(nonnull YMKVersion *)version;

@end
