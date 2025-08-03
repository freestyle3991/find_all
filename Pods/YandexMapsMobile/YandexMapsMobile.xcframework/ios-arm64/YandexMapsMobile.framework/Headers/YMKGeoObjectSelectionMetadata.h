#import <YandexMapsMobile/YMKBaseMetadata.h>

/**
 * Geo object metadata which is needed to select object.
 */
@interface YMKGeoObjectSelectionMetadata : NSObject<YMKBaseMetadata>

/**
 * Object ID.
 */
@property (nonatomic, readonly, nonnull) NSString *objectId;

/**
 * Data source name.
 */
@property (nonatomic, readonly, nonnull) NSString *dataSourceName;

/**
 * Layer ID.
 */
@property (nonatomic, readonly, nonnull) NSString *layerId;


+ (nonnull YMKGeoObjectSelectionMetadata *)geoObjectSelectionMetadataWithObjectId:(nonnull NSString *)objectId
                                                                   dataSourceName:(nonnull NSString *)dataSourceName
                                                                          layerId:(nonnull NSString *)layerId;


@end
