#import <YandexMapsMobile/YMKRawTile.h>
#import <YandexMapsMobile/YMKTileId.h>
#import <YandexMapsMobile/YMKVersion.h>

/**
 * Generates empty tiles.
 */
@protocol YMKTileProvider <NSObject>

/**
 * Generates an empty tile.
 *
 * This method will be called on a background thread.
 */
- (nonnull YMKRawTile *)loadWithTileId:(nonnull YMKTileId *)tileId
                               version:(nonnull YMKVersion *)version
                                  etag:(nonnull NSString *)etag;

@end
