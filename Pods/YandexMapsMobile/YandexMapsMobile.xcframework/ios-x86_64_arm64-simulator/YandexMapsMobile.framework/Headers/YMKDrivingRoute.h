#import <YandexMapsMobile/YMKAnnotationLang.h>
#import <YandexMapsMobile/YMKBaseMetadata.h>
#import <YandexMapsMobile/YMKDrivingAnnotation.h>
#import <YandexMapsMobile/YMKDrivingDescription.h>
#import <YandexMapsMobile/YMKDrivingFlags.h>
#import <YandexMapsMobile/YMKDrivingWeight.h>
#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKJamSegment.h>
#import <YandexMapsMobile/YMKPoint.h>
#import <YandexMapsMobile/YMKRequestPoint.h>
#import <YandexMapsMobile/YMKRoadEventsEventTag.h>
#import <YandexMapsMobile/YMKRoutePosition.h>

@class YMKDrivingCheckpoint;
@class YMKDrivingDirectionSign;
@class YMKDrivingEvent;
@class YMKDrivingFerry;
@class YMKDrivingFordCrossing;
@class YMKDrivingLaneSign;
@class YMKDrivingManoeuvreVehicleRestriction;
@class YMKDrivingPedestrianCrossing;
@class YMKDrivingRailwayCrossing;
@class YMKDrivingRestrictedEntry;
@class YMKDrivingRestrictedTurn;
@class YMKDrivingRoadVehicleRestriction;
@class YMKDrivingRouteMetadata;
@class YMKDrivingRuggedRoad;
@class YMKDrivingSection;
@class YMKDrivingSpeedBump;
@class YMKDrivingStandingSegment;
@class YMKDrivingTollRoad;
@class YMKDrivingTollRoadsPrice;
@class YMKDrivingTrafficLight;
@class YMKDrivingVehicleOptions;

/**
 * A listener to monitor route condition changes.
 */
@protocol YMKDrivingConditionsListener <NSObject>

/**
 * Triggers when the conditions are updated.
 */
- (void)onConditionsUpdated;

/**
 * Triggers when the conditions are outdated.
 */
- (void)onConditionsOutdated;

@end

/**
 * A listener to monitor toll roads price changes. (toll roads price
 * info update starts by Route.requestTollRoadsPriceUpdate call)
 */
@protocol YMKDrivingTollRoadsPriceListener <NSObject>

/**
 * Triggers when toll roads price info is updated.
 */
- (void)onTollRoadsPriceUpdated;

/**
 * Triggers in case of toll roads price update error.
 */
- (void)onTollRoadsPriceUpdateErrorWithError:(nonnull NSError *)error;

@end

/**
 * Route summary.
 */
@interface YMKDrivingSummary : NSObject

/**
 * Route "weight".
 */
@property (nonatomic, readonly, nonnull) YMKDrivingWeight *weight;

/**
 * Overall route characteristics.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingFlags *flags;

/**
 * Route driving arrival point id
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *drivingArrivalPointId;


+ (nonnull YMKDrivingSummary *)summaryWithWeight:(nonnull YMKDrivingWeight *)weight
                                           flags:(nonnull YMKDrivingFlags *)flags
                           drivingArrivalPointId:(nullable NSString *)drivingArrivalPointId;


@end

/**
 * Information about section metadata.
 */
@interface YMKDrivingSectionMetadata : NSObject

/**
 * A leg is a section of the route between two consecutive waypoints.
 */
@property (nonatomic, readonly) NSUInteger legIndex;

/**
 * The "weight" of the section.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingWeight *weight;

/**
 * Section annotation.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingAnnotation *annotation;

/**
 * The ID of the annotation scheme.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *schemeId;

/**
 * Via points (throughpoints) can appear only at nodes of the section's
 * geometry. The vector contains the positions of all corresponding
 * nodes. These positions should be listed in ascending order.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *viaPointPositions;


+ (nonnull YMKDrivingSectionMetadata *)sectionMetadataWithLegIndex:( NSUInteger)legIndex
                                                            weight:(nonnull YMKDrivingWeight *)weight
                                                        annotation:(nonnull YMKDrivingAnnotation *)annotation
                                                          schemeId:(nullable NSNumber *)schemeId
                                                 viaPointPositions:(nonnull NSArray<NSNumber *> *)viaPointPositions;


@end

/**
 * Route point metadata (exists for both waypoints and via points).
 */
@interface YMKDrivingRoutePoint : NSObject

/**
 * Position of original route point.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *position;

/**
 * Arrival point selected for routing.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKPoint *selectedArrivalPoint;

/**
 * ID of driving arrival point selected for routing.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *drivingArrivalPointId;


+ (nonnull YMKDrivingRoutePoint *)routePointWithPosition:(nonnull YMKPoint *)position
                                    selectedArrivalPoint:(nullable YMKPoint *)selectedArrivalPoint
                                   drivingArrivalPointId:(nullable NSString *)drivingArrivalPointId;


@end

/**
 * Information about driving route metadata.
 */
@interface YMKDrivingRouteMetadata : NSObject<YMKBaseMetadata>

/**
 * Route "weight".
 */
@property (nonatomic, readonly, nonnull) YMKDrivingWeight *weight;

/**
 * Overall route characteristics.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingFlags *flags;

/**
 * Route descriptor.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSData *descriptor;

/**
 * Route traits.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSData *traits;

/**
 * Route description.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKDrivingDescription *description;

/**
 * Route points. In addition to point coordinates each route point may
 * have a selected arrival point
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingRoutePoint *> *routePoints;

/**
 * Route tags.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *tags;

/**
 * Route URI
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *uri;


+ (nonnull YMKDrivingRouteMetadata *)routeMetadataWithWeight:(nonnull YMKDrivingWeight *)weight
                                                       flags:(nonnull YMKDrivingFlags *)flags
                                                  descriptor:(nullable NSData *)descriptor
                                                      traits:(nullable NSData *)traits
                                                 description:(nullable YMKDrivingDescription *)description
                                                 routePoints:(nonnull NSArray<YMKDrivingRoutePoint *> *)routePoints
                                                        tags:(nonnull NSArray<NSString *> *)tags
                                                         uri:(nullable NSString *)uri;


@end

/**
 * Route section.
 */
@interface YMKDrivingSection : NSObject

/**
 * Metadata information for the route section.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingSectionMetadata *metadata;

/**
 * A polyline of the route section.
 */
@property (nonatomic, readonly, nonnull) YMKSubpolyline *geometry;


+ (nonnull YMKDrivingSection *)sectionWithMetadata:(nonnull YMKDrivingSectionMetadata *)metadata
                                          geometry:(nonnull YMKSubpolyline *)geometry;


@end

/**
 * Road event.
 */
@interface YMKDrivingEvent : NSObject

/**
 * The position of the polyline.
 */
@property (nonatomic, readonly, nonnull) YMKPolylinePosition *polylinePosition;

/**
 * The unique ID of the event.
 */
@property (nonatomic, readonly, nonnull) NSString *eventId;

/**
 * The description of the event.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *descriptionText;

/**
 * The types of the road event.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *tags;

/**
 * The location of the road event.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *location;

/**
 * The speed limit on the road.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *speedLimit;

/**
 * valid only for cameras The SchemeId of the annotation.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *annotationSchemeId;


+ (nonnull YMKDrivingEvent *)eventWithPolylinePosition:(nonnull YMKPolylinePosition *)polylinePosition
                                               eventId:(nonnull NSString *)eventId
                                       descriptionText:(nullable NSString *)descriptionText
                                                  tags:(nonnull NSArray<NSNumber *> *)tags
                                              location:(nonnull YMKPoint *)location
                                            speedLimit:(nullable NSNumber *)speedLimit
                                    annotationSchemeId:(nullable NSNumber *)annotationSchemeId;


@end

/**
 * Driving route. A route consists of multiple sections. Each section
 * has a corresponding annotation that describes the action at the
 * beginning of the section.
 */
@interface YMKDrivingRoute : NSObject
/**
 * The ID of the route.
 */
@property (nonatomic, readonly, nonnull) NSString *routeId;
/**
 * The route metadata.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingRouteMetadata *metadata;
/**
 * Manoeuvre-to-Manoeuvre route sections.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingSection *> *sections;
/**
 * Route geometry.
 */
@property (nonatomic, readonly, nonnull) YMKPolyline *geometry;
/**
 * Traffic conditions on the given route.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKJamSegment *> *jamSegments;
/**
 * Events on the given route.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingEvent *> *events;
/**
 * Speed limits for segments in the geometry.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *speedLimits;
/**
 * Annotation schemes for segments in the geometry.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *annotationSchemes;
/**
 * Vehicle options.
 */
@property (nonatomic, readonly, nonnull) YMKDrivingVehicleOptions *vehicleOptions;
/**
 * Lane signs.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingLaneSign *> *laneSigns;
/**
 * Direction signs.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingDirectionSign *> *directionSigns;
/**
 * Route restricted entries.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingRestrictedEntry *> *restrictedEntries;
/**
 * Route traffic lights.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingTrafficLight *> *trafficLights;
/**
 * Route points with time-dependent restrictions.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingRestrictedTurn *> *restrictedTurns;
/**
 * Railway crossings
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingRailwayCrossing *> *railwayCrossings;
/**
 * Pedestrian crossings
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingPedestrianCrossing *> *pedestrianCrossings;
/**
 * Speed bumps
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingSpeedBump *> *speedBumps;
/**
 * Checkpoints
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingCheckpoint *> *checkpoints;
/**
 * Z-levels
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *zlevels;
/**
 * Intermediate Z-level breakpoints (excluding begin and end of
 * polyline)
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKPolylinePosition *> *zlevelBreakpoints;
/**
 * Route roads.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingRuggedRoad *> *ruggedRoads;
/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingTollRoad *> *tollRoads;
/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingFordCrossing *> *fordCrossings;
/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingFerry *> *ferries;
/**
 * Route vehicle restrictions.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingRoadVehicleRestriction *> *roadVehicleRestrictions;
/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingManoeuvreVehicleRestriction *> *manoeuvreVehicleRestrictions;
/**
 * Segments for which we calc standing status
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKDrivingStandingSegment *> *standingSegments;
/**
 * Language of string annotations (for example street names) in this
 * route object.
 *
 * Optional property, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *annotationLanguage;
/**
 * Request points that were specified in the router request that this
 * route originated from.
 *
 * Optional property, can be nil.
 */
@property (nonatomic, readonly, nullable) NSArray<YMKRequestPoint *> *requestPoints;
/**
 * The reached position on the given route. The 'RouteMetadata::weight'
 * field contains data for the part of the route beyond this position.
 */
@property (nonatomic, nonnull) YMKPolylinePosition *position;
/**
 * The reached position on the given route. The 'RouteMetadata::weight'
 * field contains data for the part of the route beyond this position.
 */
@property (nonatomic, readonly, readonly, nonnull) YMKRoutePosition *routePosition;
/**
 * A leg is a section of the route between two consecutive waypoints.
 */
@property (nonatomic) NSUInteger legIndex;
/**
 * Indicates whether driving conditions (jamSegments and events) have
 * become outdated when we are not able to fetch updates for some
 * predefined time.
 */
@property (nonatomic, readonly, getter=isAreConditionsOutdated) BOOL areConditionsOutdated;

/**
 * Adds a listener for route condition changes.
 *
 * The class does not retain the object in the 'conditionsListener' parameter.
 * It is your responsibility to maintain a strong reference to
 * the target object while it is attached to a class.
 */
- (void)addConditionsListenerWithConditionsListener:(nonnull id<YMKDrivingConditionsListener>)conditionsListener;

/**
 * Removes the listener for route condition changes.
 *
 * The class does not retain the object in the 'conditionsListener' parameter.
 * It is your responsibility to maintain a strong reference to
 * the target object while it is attached to a class.
 */
- (void)removeConditionsListenerWithConditionsListener:(nonnull id<YMKDrivingConditionsListener>)conditionsListener;

/**
 * Adds a listener for route toll roads price changes.
 *
 * The class does not retain the object in the 'tollRoadsPriceListener' parameter.
 * It is your responsibility to maintain a strong reference to
 * the target object while it is attached to a class.
 */
- (void)addTollRoadsPriceListenerWithTollRoadsPriceListener:(nonnull id<YMKDrivingTollRoadsPriceListener>)tollRoadsPriceListener;

/**
 * Removes the listener for toll roads price changes.
 */
- (void)removeTollRoadsPriceListenerWithTollRoadsPriceListener:(nonnull id<YMKDrivingTollRoadsPriceListener>)tollRoadsPriceListener;

/**
 * Section index.
 */
- (NSUInteger)sectionIndexWithSegmentIndex:(NSUInteger)segmentIndex;

/**
 * Metadata location.
 */
- (nonnull YMKDrivingRouteMetadata *)metadataAtWithPosition:(nonnull YMKPolylinePosition *)position;
/**
 * Polyline positions of waypoints including start and finish point.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKPolylinePosition *> *wayPoints;
/**
 * This field contains a price of the toll route. The field is invalid
 * until the callback `onTollRoadsPriceUpdated` is called. After calling
 * the callback, this field will be empty if there are no paid posts,
 * and filled otherwise.
 *
 * Optional property, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKDrivingTollRoadsPrice *tollRoadsPrice;

/**
 * Undocumented
 */
- (void)requestConditionsUpdate;

/**
 * Initiate request to server to get toll roads price info. Results in
 * TollRoadsPriceListener async call.
 */
- (void)requestTollRoadsPriceUpdate;

@end
