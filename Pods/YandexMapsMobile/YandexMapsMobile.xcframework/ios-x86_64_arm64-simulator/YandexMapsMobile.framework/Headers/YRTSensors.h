#import <Foundation/Foundation.h>

/**
 * Undocumented
 */
typedef NS_ENUM(NSUInteger, YRTLocationActivityType) {
    /**
     * Auto activity type detect
     */
    YRTLocationActivityTypeAutoDetect,
    /**
     * Activity type for car navigation
     */
    YRTLocationActivityTypeCar,
    /**
     * Activity type for pedestrian navigation
     */
    YRTLocationActivityTypePedestrian,
    /**
     * Activity type without any hint
     */
    YRTLocationActivityTypeOther
};
