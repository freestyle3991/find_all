#import <YandexMapsMobile/YMKBaseMetadata.h>
#import <YandexMapsMobile/YMKConstruction.h>
#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKJamSegment.h>
#import <YandexMapsMobile/YMKMasstransitAnnotation.h>
#import <YandexMapsMobile/YMKMasstransitCommon.h>
#import <YandexMapsMobile/YMKMasstransitFlags.h>
#import <YandexMapsMobile/YMKMasstransitTransport.h>
#import <YandexMapsMobile/YMKMasstransitTravelEstimation.h>
#import <YandexMapsMobile/YMKMasstransitWayPoint.h>
#import <YandexMapsMobile/YMKMasstransitWeight.h>
#import <YandexMapsMobile/YMKPoint.h>
#import <YandexMapsMobile/YMKRestrictedEntry.h>
#import <YandexMapsMobile/YMKUriObjectMetadata.h>

@class YMKMasstransitRoute;
@class YMKMasstransitRouteMetadata;
@class YMKMasstransitSection;
@class YMKMasstransitSectionMetadataSectionData;

/**
 * TrafficTypeID describes who the road is designed for.
 */
typedef NS_ENUM(NSUInteger, YMKMasstransitTrafficTypeID) {
    /**
     * Road that is not one of the following types.
     */
    YMKMasstransitTrafficTypeIDOther,
    /**
     * Footpath, designed only for pedestrian travel.
     */
    YMKMasstransitTrafficTypeIDPedestrian,
    /**
     * Bikepath, designed only for bicycle travel.
     */
    YMKMasstransitTrafficTypeIDBicycle,
    /**
     * Road designed for motorized vehicles that might be dangerous for
     * cyclists.
     */
    YMKMasstransitTrafficTypeIDAuto
};

/**
 * Undocumented
 */
typedef NS_ENUM(NSUInteger, YMKMasstransitFitnessType) {
    /**
     * User moves on feet.
     */
    YMKMasstransitFitnessTypePedestrian,
    /**
     * User moves on wheels (bicycle, scooter).
     */
    YMKMasstransitFitnessTypeBicycle
};

/**
 * A listener to monitor changes to traffic jams on the route.
 */
@protocol YMKMasstransitRouteJamsListener <NSObject>

/**
 * Triggered when traffic jams are updated.
 */
- (void)onJamsUpdatedWithRoute:(nonnull YMKMasstransitRoute *)route;

/**
 * Triggered when traffic jams are outdated.
 */
- (void)onJamsOutdatedWithRoute:(nonnull YMKMasstransitRoute *)route;

@end

/**
 * Represents a 'wait until suitable tranport arrives' section of a
 * route.
 */
@interface YMKMasstransitWait : NSObject

/**
 * Dummy object.
 */
@property (nonatomic, readonly) NSUInteger dummy;


+ (nonnull YMKMasstransitWait *)waitWithDummy:( NSUInteger)dummy;


@end

/**
 * Describes part of pedestrian or bicycle path with the same
 * construction.
 */
@interface YMKMasstransitConstructionSegment : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly) YMKConstructionID construction;

/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) YMKSubpolyline *subpolyline;


+ (nonnull YMKMasstransitConstructionSegment *)constructionSegmentWithConstruction:( YMKConstructionID)construction
                                                                       subpolyline:(nonnull YMKSubpolyline *)subpolyline;


@end

/**
 * Describes part of bicycle or scooter path with the same traffic type.
 */
@interface YMKMasstransitTrafficTypeSegment : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly) YMKMasstransitTrafficTypeID trafficType;

/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) YMKSubpolyline *subpolyline;


+ (nonnull YMKMasstransitTrafficTypeSegment *)trafficTypeSegmentWithTrafficType:( YMKMasstransitTrafficTypeID)trafficType
                                                                    subpolyline:(nonnull YMKSubpolyline *)subpolyline;


@end

/**
 * Represent a section where we have to move by ourself (like
 * pedestrian, or by bicycle and scooter)
 */
@interface YMKMasstransitFitness : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly) YMKMasstransitFitnessType type;

/**
 * Compressed information about constructions along the path.
 * YMKMasstransitConstructionSegment::subpolyline fields of all segments
 * cover the entire geometry of corresponding section".
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitConstructionSegment *> *constructions;

/**
 * List of restricted entries with their coordinates along the path.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKRestrictedEntry *> *restrictedEntries;

/**
 * List of via points on the path. A via point is described by the index
 * of the point in the route geometry polyline.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKPolylinePosition *> *viaPoints;

/**
 * List of annotations on the path.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitAnnotation *> *annotations;

/**
 * List of traffic types on path
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitTrafficTypeSegment *> *trafficTypes;


+ (nonnull YMKMasstransitFitness *)fitnessWithType:( YMKMasstransitFitnessType)type
                                     constructions:(nonnull NSArray<YMKMasstransitConstructionSegment *> *)constructions
                                 restrictedEntries:(nonnull NSArray<YMKRestrictedEntry *> *)restrictedEntries
                                         viaPoints:(nonnull NSArray<YMKPolylinePosition *> *)viaPoints
                                       annotations:(nonnull NSArray<YMKMasstransitAnnotation *> *)annotations
                                      trafficTypes:(nonnull NSArray<YMKMasstransitTrafficTypeSegment *> *)trafficTypes;


@end

/**
 * The metadata about the mass transit stop.
 */
@interface YMKMasstransitRouteStopMetadata : NSObject<YMKBaseMetadata>

/**
 * Route stop information.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitStop *stop;

/**
 * Underground station exit
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKMasstransitStop *stopExit;

/**
 * Coordinates of underground station exit
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKPoint *exitPoint;


+ (nonnull YMKMasstransitRouteStopMetadata *)routeStopMetadataWithStop:(nonnull YMKMasstransitStop *)stop
                                                              stopExit:(nullable YMKMasstransitStop *)stopExit
                                                             exitPoint:(nullable YMKPoint *)exitPoint;


@end

/**
 * Describes a YMKMasstransitStop on a YMKMasstransitRoute.
 */
@interface YMKMasstransitRouteStop : NSObject

/**
 * General information about a stop on a route and optionally about its
 * exit
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitRouteStopMetadata *metadata;

/**
 * Coordinates of the stop.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *position;


+ (nonnull YMKMasstransitRouteStop *)routeStopWithMetadata:(nonnull YMKMasstransitRouteStopMetadata *)metadata
                                                  position:(nonnull YMKPoint *)position;


@end

/**
 * Represents a stop in path which is not a part of any transport trip
 * but must be visited according travelling. For example, exit from
 * subway may require transfer on other stop.
 */
@interface YMKMasstransitTransferStop : NSObject

/**
 * Stop information.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitRouteStop *routeStop;

/**
 * Transports at the stops
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitTransport *> *transports;


+ (nonnull YMKMasstransitTransferStop *)transferStopWithRouteStop:(nonnull YMKMasstransitRouteStop *)routeStop
                                                       transports:(nonnull NSArray<YMKMasstransitTransport *> *)transports;


@end

/**
 * Represents a transfer to another mass transit line or to another
 * stop. For example, transfer from one underground line to another.
 */
@interface YMKMasstransitTransfer : NSObject

/**
 * Compressed information about pedestrian constructions along the
 * transfer path. YMKMasstransitConstructionSegment::subpolyline fields
 * of all segments cover the entire geometry of corresponding section".
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitConstructionSegment *> *constructions;

/**
 * The stop you need to transfer to
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitTransferStop *transferStop;


+ (nonnull YMKMasstransitTransfer *)transferWithConstructions:(nonnull NSArray<YMKMasstransitConstructionSegment *> *)constructions
                                                 transferStop:(nonnull YMKMasstransitTransferStop *)transferStop;


@end

/**
 * Represents a taxi part of route.
 */
@interface YMKMasstransitTaxi : NSObject

/**
 * Traffic conditions on the given part of route.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKJamSegment *> *jamSegments;


+ (nonnull YMKMasstransitTaxi *)taxiWithJamSegments:(nonnull NSArray<YMKJamSegment *> *)jamSegments;


@end

/**
 * General information about a section of a route. The
 * YMKMasstransitSectionMetadata::data field describes the type of
 * section: wait, walk, transfer, or transport, and related data.
 * Related data can be set for walk and transfer sections. This data is
 * a vector of construction types of corresponding geometry segments.
 */
@interface YMKMasstransitSectionMetadata : NSObject

/**
 * Contains the route traveling time, distance of the walking part, and
 * the number of transfers.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitWeight *weight;

/**
 * Contains information that is specific to a section type: wait, walk,
 * transfer, or ride transport.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitSectionMetadataSectionData *data;

/**
 * Arrival and departure time estimations. This field is set only for
 * time-dependent routes.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKMasstransitTravelEstimation *estimation;

/**
 * Part of the route polyline for the route leg. A leg is a part of the
 * route between two consecutive waypoints.
 */
@property (nonatomic, readonly) NSUInteger legIndex;


+ (nonnull YMKMasstransitSectionMetadata *)sectionMetadataWithWeight:(nonnull YMKMasstransitWeight *)weight
                                                                data:(nonnull YMKMasstransitSectionMetadataSectionData *)data
                                                          estimation:(nullable YMKMasstransitTravelEstimation *)estimation
                                                            legIndex:( NSUInteger)legIndex;


@end

/**
 * A choice of information specific to the section type.
 */
@interface YMKMasstransitSectionMetadataSectionData : NSObject

@property (nonatomic, readonly, nullable) YMKMasstransitWait *wait;

@property (nonatomic, readonly, nullable) YMKMasstransitFitness *fitness;

@property (nonatomic, readonly, nullable) YMKMasstransitTransfer *transfer;

@property (nonatomic, readonly, nullable) YMKMasstransitTaxi *taxi;

@property (nonatomic, readonly, nullable) NSArray<YMKMasstransitTransport *> *transports;

+ (nonnull YMKMasstransitSectionMetadataSectionData *)sectionDataWithWait:(nonnull YMKMasstransitWait *)wait;

+ (nonnull YMKMasstransitSectionMetadataSectionData *)sectionDataWithFitness:(nonnull YMKMasstransitFitness *)fitness;

+ (nonnull YMKMasstransitSectionMetadataSectionData *)sectionDataWithTransfer:(nonnull YMKMasstransitTransfer *)transfer;

+ (nonnull YMKMasstransitSectionMetadataSectionData *)sectionDataWithTaxi:(nonnull YMKMasstransitTaxi *)taxi;

+ (nonnull YMKMasstransitSectionMetadataSectionData *)sectionDataWithTransports:(nonnull NSArray<YMKMasstransitTransport *> *)transports;

@end


/**
 * Route settings that were used by the mass transit router for a
 * specific route.
 */
@interface YMKMasstransitRouteSettings : NSObject

/**
 * Transport types that the router avoided.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *avoidTypes;

/**
 * Transport types that were allowed even if they are in the list of
 * avoided types.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *acceptTypes;


+ (nonnull YMKMasstransitRouteSettings *)routeSettingsWithAvoidTypes:(nonnull NSArray<NSString *> *)avoidTypes
                                                         acceptTypes:(nonnull NSArray<NSString *> *)acceptTypes;


@end

/**
 * Contains information associated with a route constructed by the mass
 * transit router.
 */
@interface YMKMasstransitRouteMetadata : NSObject<YMKBaseMetadata>

/**
 * Contains the route time, distance of the walking part, and the number
 * of transfers.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitWeight *weight;

/**
 * Route settings that were used by the mass transit router.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKMasstransitRouteSettings *settings;

/**
 * Arrival and departure time estimations for time-dependent routes.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKMasstransitTravelEstimation *estimation;

/**
 * List of route waypoints. See YMKMasstransitWayPoint for details
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitWayPoint *> *wayPoints;

/**
 * Unique route id.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *routeId;

/**
 * Flags which contains route properties
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKMasstransitFlags *flags;


+ (nonnull YMKMasstransitRouteMetadata *)routeMetadataWithWeight:(nonnull YMKMasstransitWeight *)weight
                                                        settings:(nullable YMKMasstransitRouteSettings *)settings
                                                      estimation:(nullable YMKMasstransitTravelEstimation *)estimation
                                                       wayPoints:(nonnull NSArray<YMKMasstransitWayPoint *> *)wayPoints
                                                         routeId:(nullable NSString *)routeId
                                                           flags:(nullable YMKMasstransitFlags *)flags;


@end

/**
 * Contains information about an individual section of a mass transit
 * YMKMasstransitRoute. The only fields that are always set are
 * YMKMasstransitSection::metadata.YMKMasstransitSectionMetadata::weight,
 * YMKMasstransitSection::geometry and
 * YMKMasstransitSection::metadata.YMKMasstransitSectionMetadata::data.
 */
@interface YMKMasstransitSection : NSObject

/**
 * General information about a section of a route.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitSectionMetadata *metadata;

/**
 * Geometry of the section as a fragment of a YMKMasstransitRoute
 * polyline.
 */
@property (nonatomic, readonly, nonnull) YMKSubpolyline *geometry;

/**
 * Vector of stops along the route. The first stop in the vector is the
 * stop for boarding the transport, and the last stop in the vector is
 * the stop for exiting the transport.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitRouteStop *> *stops;

/**
 * Vector of polylines each connecting two consecutive stops. This
 * vector is only filled for mass transit ride sections, so this
 * geometry represents a part of the mass transit thread geometry
 * between two stops.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKSubpolyline *> *rideLegs;


+ (nonnull YMKMasstransitSection *)sectionWithMetadata:(nonnull YMKMasstransitSectionMetadata *)metadata
                                              geometry:(nonnull YMKSubpolyline *)geometry
                                                 stops:(nonnull NSArray<YMKMasstransitRouteStop *> *)stops
                                              rideLegs:(nonnull NSArray<YMKSubpolyline *> *)rideLegs;


@end

/**
 * Contains information about a route constructed by the mass transit
 * router.
 */
@interface YMKMasstransitRoute : NSObject
/**
 * General route information.
 */
@property (nonatomic, readonly, nonnull) YMKMasstransitRouteMetadata *metadata;
/**
 * List of route waypoints. See YMKMasstransitWayPoint for details
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitWayPoint *> *wayPoints;
/**
 * Vector of sections of the route.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMasstransitSection *> *sections;
/**
 * Polyline of the entire route.
 */
@property (nonatomic, readonly, nonnull) YMKPolyline *geometry;
/**
 * Route URI, which can be used with YMKMasstransitRouter to fetch
 * additional information about the route or can be bookmarked for
 * future reference.
 */
@property (nonatomic, readonly, nonnull) YMKUriObjectMetadata *uriMetadata;

/**
 * Return distance between two polyline positions.
 */
- (double)distanceBetweenPolylinePositionsWithFrom:(nonnull YMKPolylinePosition *)from
                                                to:(nonnull YMKPolylinePosition *)to;

@end
