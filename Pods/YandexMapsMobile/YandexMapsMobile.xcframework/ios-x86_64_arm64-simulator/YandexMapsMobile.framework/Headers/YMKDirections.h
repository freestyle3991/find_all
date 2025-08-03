#import <YandexMapsMobile/YMKDrivingDrivingRouter.h>

/**
 * Undocumented
 */
@interface YMKDirections : NSObject

/**
 * Creates a manager that builds driving routes.
 */
- (nonnull YMKDrivingRouter *)createDrivingRouter;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
