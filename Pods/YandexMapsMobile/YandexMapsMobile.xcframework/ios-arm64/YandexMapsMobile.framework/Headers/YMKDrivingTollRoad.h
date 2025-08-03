#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKTaxiMoney.h>

/**
 * Undocumented
 */
@interface YMKDrivingTollRoadsPrice : NSObject

/**
 * Null if server returned Null in this field, that, in turn, can be
 * caused by an absence of information about requested toll posts price
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKTaxiMoney *price;


+ (nonnull YMKDrivingTollRoadsPrice *)tollRoadsPriceWithPrice:(nullable YMKTaxiMoney *)price;


@end

/**
 * Undocumented
 */
@interface YMKDrivingTollRoad : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) YMKSubpolyline *position;


+ (nonnull YMKDrivingTollRoad *)tollRoadWithPosition:(nonnull YMKSubpolyline *)position;


@end
