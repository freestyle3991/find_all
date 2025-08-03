#import <Foundation/Foundation.h>
#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKPoint.h>

#import <YandexMapsMobile/YRTExtern.h>

YRT_EXTERN YMKBoundingBox* YMKGetPointBounds(YMKPoint* point);
YRT_EXTERN YMKBoundingBox* YMKGetPolylineBounds(YMKPolyline* polyline);
YRT_EXTERN YMKBoundingBox* YMKGetLinearRingBounds(YMKLinearRing* ring);
YRT_EXTERN YMKBoundingBox* YMKGetPolygonBounds(YMKPolygon* polygon);
YRT_EXTERN YMKBoundingBox* YMKMergeBounds(YMKBoundingBox* first, YMKBoundingBox* second);
