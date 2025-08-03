#import <Foundation/Foundation.h>
#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKPoint.h>

/** Undocumented */
@interface YMKPolylineBuilder : NSObject

- (YMKPolylineBuilder *)init;
- (void) appendPolyline:(YMKPolyline *)polyline;
- (void) appendPoint:(YMKPoint *)point;
- (YMKPolyline *)build;

@end
