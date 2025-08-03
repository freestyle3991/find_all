#import <YandexMapsMobile/YMKPoint.h>
#import <YandexMapsMobile/YMKGeometry.h>

#import <YandexMapsMobile/YRTExtern.h>

/**
 * Calculate the great-circle distance between two points on a sphere with
 * a radius equal to the Earth's radius using the haversine formula described here:
 * http://en.wikipedia.org/wiki/Haversine_formula
 *
 * This formula is numerically better-conditioned for small distances, according
 * to http://en.wikipedia.org/wiki/Great-circle_distance
 */
YRT_EXTERN double YMKDistance(YMKPoint *firstPoint, YMKPoint *secondPoint);

/**
 * Find the point on a given segment (great-circle arc or shorter arc)
 * that is closest to a given point.
 */
YRT_EXTERN YMKPoint* YMKClosestPoint(YMKPoint *point, YMKSegment *segment);

/**
 * Find a point X on a given segment AB such that d(AX)/d(AB) = lambda,
 * where lambda is a given number in [0, 1].
 */
YRT_EXTERN YMKPoint* YMKPointOnSegmentByFactor(YMKSegment *segment, double lambda);

/**
 * Calculate the course (bearing) between two points in degrees in the range [0, 360].
 */
YRT_EXTERN double YMKCourse(YMKPoint *firstPoint, YMKPoint *secondPoint);
