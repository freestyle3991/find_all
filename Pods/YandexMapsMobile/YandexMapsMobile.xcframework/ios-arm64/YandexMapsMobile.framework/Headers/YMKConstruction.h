#import <Foundation/Foundation.h>

/**
 * Constructions that can be found on pedestrian, bicycle paths or on
 * mass transit transfers.
 */
typedef NS_ENUM(NSUInteger, YMKConstructionID) {
    /**
     * Regular path segment or a segment without any additional information
     * known.
     */
    YMKConstructionIDUnknown,
    /**
     * Stairway with stairs going up along a pedestrian path.
     */
    YMKConstructionIDStairsUp,
    /**
     * Stairway with stairs going down along a pedestrian path.
     */
    YMKConstructionIDStairsDown,
    /**
     * Stairway with no information whether stairs go up or down along a
     * pedestrian path.
     */
    YMKConstructionIDStairsUnknown,
    /**
     * Underground crossing.
     */
    YMKConstructionIDUnderpass,
    /**
     * Overground crossing, such as a bridge.
     */
    YMKConstructionIDOverpass,
    /**
     * crossing that is not an underground tunnel or a bridge.
     */
    YMKConstructionIDCrosswalk,
    /**
     * Edge connecting the route endpoint to the route network.
     */
    YMKConstructionIDBinding,
    /**
     * Transfer. For example, transfer from one underground line to another
     * or transfer from an underground station to an exit from it.
     */
    YMKConstructionIDTransition,
    /**
     * Tunnel that is not a crossing.
     */
    YMKConstructionIDTunnel
};
