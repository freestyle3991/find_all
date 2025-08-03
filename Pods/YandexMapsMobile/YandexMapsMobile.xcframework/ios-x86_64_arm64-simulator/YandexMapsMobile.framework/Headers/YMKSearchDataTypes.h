#import <Foundation/Foundation.h>

/**
 * Bitmask for requested search types.
 */
typedef NS_OPTIONS(NSUInteger, YMKSearchType) {
    /**
     * Default value: all types requested.
     */
    YMKSearchTypeNone = 0,
    /**
     * Toponyms.
     */
    YMKSearchTypeGeo = 1,
    /**
     * Companies.
     */
    YMKSearchTypeBiz = 1 << 1
};
