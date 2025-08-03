#import <Foundation/Foundation.h>
#import <YandexMapsMobile/YMKGeometry.h>

#import <YandexMapsMobile/YRTExtern.h>

YRT_EXTERN YMKPolyline* YMKMakeSubpolyline(YMKPolyline* polyline, YMKSubpolyline* subpolyline);
YRT_EXTERN double YMKSubpolylineLength(YMKPolyline* polyline, YMKSubpolyline* subpolyline);
