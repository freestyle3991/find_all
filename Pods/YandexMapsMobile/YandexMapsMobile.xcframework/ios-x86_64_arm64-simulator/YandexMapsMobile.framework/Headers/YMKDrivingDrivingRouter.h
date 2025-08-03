#import <YandexMapsMobile/YMKAnnotationLang.h>
#import <YandexMapsMobile/YMKDrivingSession.h>
#import <YandexMapsMobile/YMKRequestPoint.h>

@class YMKDrivingDrivingOptions;
@class YMKDrivingRoute;
@class YMKDrivingVehicleOptions;

/**
 * Driving options.
 */
@interface YMKDrivingDrivingOptions : NSObject

/**
 * Starting location azimuth.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSNumber *initialAzimuth;

/**
 * The number of alternatives.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSNumber *routesCount;

/**
 * The 'avoidTolls' option instructs the router to return routes that
 * avoid tolls when possible.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSNumber *avoidTolls;

/**
 * The 'avoidUnpaved' option instructs the router to return routes that
 * avoid unpaved roads when possible.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSNumber *avoidUnpaved;

/**
 * The 'avoidPoorConditions' option instructs the router to return
 * routes that avoid roads in poor conditions when possible.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSNumber *avoidPoorConditions;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSDate *departureTime;

/**
 * A method to set the annotation language. lang The annotation
 * language.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, copy, nullable) NSNumber *annotationLanguage;

+ (nonnull YMKDrivingDrivingOptions *)drivingOptionsWithInitialAzimuth:(nullable NSNumber *)initialAzimuth
                                                           routesCount:(nullable NSNumber *)routesCount
                                                            avoidTolls:(nullable NSNumber *)avoidTolls
                                                          avoidUnpaved:(nullable NSNumber *)avoidUnpaved
                                                   avoidPoorConditions:(nullable NSNumber *)avoidPoorConditions
                                                         departureTime:(nullable NSDate *)departureTime
                                                    annotationLanguage:(nullable NSNumber *)annotationLanguage;


@end

/**
 * Route serializer interface.
 */
@interface YMKDrivingRouteSerializer : NSObject

/**
 * This method saves the route.
 */
- (nonnull NSData *)saveWithRoute:(nonnull YMKDrivingRoute *)route;

/**
 * This method returns null if given a saved route from an incompatible
 * version of MapKit.
 */
- (nonnull YMKDrivingRoute *)loadWithData:(nonnull NSData *)data;

@end

/**
 * Interface for the driving router.
 */
@interface YMKDrivingRouter : NSObject

/**
 * Builds a route.
 *
 * @param points Route points.
 * @param drivingOptions Driving options.
 * @param vehicleOptions Vehicle options.
 * @param routeListener Route listener object.
 */
- (nonnull YMKDrivingSession *)requestRoutesWithPoints:(nonnull NSArray<YMKRequestPoint *> *)points
                                        drivingOptions:(nonnull YMKDrivingDrivingOptions *)drivingOptions
                                        vehicleOptions:(nonnull YMKDrivingVehicleOptions *)vehicleOptions
                                          routeHandler:(nonnull YMKDrivingSessionRouteHandler)routeHandler;

/**
 * Creates a route summary.
 *
 * @param points Route points.
 * @param drivingOptions Driving options.
 * @param vehicleOptions Vehicle options.
 * @param summaryListener Summary listener object.
 */
- (nonnull YMKDrivingSummarySession *)requestRoutesSummaryWithPoints:(nonnull NSArray<YMKRequestPoint *> *)points
                                                      drivingOptions:(nonnull YMKDrivingDrivingOptions *)drivingOptions
                                                      vehicleOptions:(nonnull YMKDrivingVehicleOptions *)vehicleOptions
                                                      summaryHandler:(nonnull YMKDrivingSummarySessionSummaryHandler)summaryHandler;

@end
