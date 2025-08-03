#import <Foundation/Foundation.h>

/**
 * Undocumented
 */
typedef NS_ENUM(NSUInteger, YMKRoadEventsEventTag) {
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagOther,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagFeedback,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagChat,
    /**
     * Only use this tag in conjuction with RoadEventsLayer. Road events
     * layer embedded into TrafficLayer can't display local chats.
     */
    YMKRoadEventsEventTagLocalChat,
    /**
     * Temporary issues
     */
    YMKRoadEventsEventTagDrawbridge,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagClosed,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagReconstruction,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagAccident,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagTrafficAlert,
    /**
     * Potentially dangerous zones
     */
    YMKRoadEventsEventTagDanger,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagSchool,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagOvertakingDanger,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagPedestrianDanger,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagCrossRoadDanger,
    /**
     * Traffic code control tags
     */
    YMKRoadEventsEventTagPolice,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagLaneControl,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagRoadMarkingControl,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagCrossRoadControl,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagNoStoppingControl,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagMobileControl,
    /**
     * Undocumented
     */
    YMKRoadEventsEventTagSpeedControl
};
