#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKLocationLocationManager.h>

/**
 * Undocumented
 */
typedef NS_ENUM(NSUInteger, YMKSimulationAccuracy) {
    /**
     * Generate locations strictly the geometry
     */
    YMKSimulationAccuracyFine,
    /**
     * Generate locations with normal distribution
     */
    YMKSimulationAccuracyCoarse
};

/**
 * Listens for updates for location simulation.
 */
@protocol YMKLocationSimulatorListener <NSObject>

/**
 * Simulation is finished.
 */
- (void)onSimulationFinished;

@end

/**
 * Simulates the device location.
 */
@interface YMKLocationSimulator : YMKLocationManager
/**
 * The polyline describing the location.
 *
 * Optional property, can be nil.
 */
@property (nonatomic, nullable) YMKPolyline *geometry;
/**
 * Movement speed.
 */
@property (nonatomic) double speed;

/**
 * Subscribes to simulation events.
 *
 * The class does not retain the object in the 'simulatorListener' parameter.
 * It is your responsibility to maintain a strong reference to
 * the target object while it is attached to a class.
 */
- (void)subscribeForSimulatorEventsWithSimulatorListener:(nonnull id<YMKLocationSimulatorListener>)simulatorListener;

/**
 * Unsubscribes from simulation events.
 *
 * The class does not retain the object in the 'simulatorListener' parameter.
 * It is your responsibility to maintain a strong reference to
 * the target object while it is attached to a class.
 */
- (void)unsubscribeFromSimulatorEventsWithSimulatorListener:(nonnull id<YMKLocationSimulatorListener>)simulatorListener;

/**
 * Start simulation.
 *
 * @param simulationAccuracy Generate locations with given accuracy.
 */
- (void)startSimulationWithSimulationAccuracy:(YMKSimulationAccuracy)simulationAccuracy;

/**
 * Stop simulation.
 */
- (void)stopSimulation;

/**
 * The position of the polyline.
 */
- (nonnull YMKPolylinePosition *)polylinePosition;
/**
 * True if simulator is not suspended.
 */
@property (nonatomic, readonly, getter=isActive) BOOL active;

/**
 * Fill location::Location::speed.
 */
- (void)setLocationSpeedProvidingWithProvide:(BOOL)provide;

@end
