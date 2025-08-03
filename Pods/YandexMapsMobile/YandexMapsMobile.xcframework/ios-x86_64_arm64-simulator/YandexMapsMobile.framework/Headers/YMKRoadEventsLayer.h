#import <YandexMapsMobile/YMKRoadEventsEventTag.h>
#import <YandexMapsMobile/YMKRoadEventsLayerStyleProvider.h>

@class YMKRoadEventsLayerRoadEvent;

/**
 * Undocumented
 */
@protocol YMKRoadEventsLayerListener <NSObject>

/**
 * You can select placemark via layer interface in this callback.
 */
- (void)onRoadEventPlacemarkTapWithRoadEvent:(nonnull YMKRoadEventsLayerRoadEvent *)roadEvent;

@end

/**
 * Undocumented
 */
@interface YMKHighlightedRoadEvent : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) NSString *eventId;

/**
 * Undocumented
 */
@property (nonatomic, readonly) YMKRoadEventsLayerHighlightMode mode;


+ (nonnull YMKHighlightedRoadEvent *)highlightedRoadEventWithEventId:(nonnull NSString *)eventId
                                                                mode:( YMKRoadEventsLayerHighlightMode)mode;


@end

/**
 * Undocumented
 */
@interface YMKRoadEventsLayer : NSObject

/**
 * The class does not retain the object in the 'layerListener' parameter.
 * It is your responsibility to maintain a strong reference to
 * the target object while it is attached to a class.
 */
- (void)addListenerWithLayerListener:(nonnull id<YMKRoadEventsLayerListener>)layerListener;

/**
 * Undocumented
 */
- (void)removeListenerWithLayerListener:(nonnull id<YMKRoadEventsLayerListener>)layerListener;

/**
 * Selects a road event with specified id. Only one event can be
 * selected at a time. If some other event is selected already, it will
 * be deselected.
 */
- (void)selectRoadEventWithEventId:(nonnull NSString *)eventId;

/**
 * Deselects selected road event if any.
 */
- (void)deselectRoadEvent;

/**
 * Sets road events on route tag visibility. Setting local chats
 * visibility will also set visibility for ordinary chats and vice
 * versa. None are visible by default.
 */
- (void)setRoadEventVisibleOnRouteWithTag:(YMKRoadEventsEventTag)tag
                                       on:(BOOL)on;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
