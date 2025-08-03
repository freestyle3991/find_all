#import <Foundation/Foundation.h>

/**
 * Provides resource URLs for other classes.
 */
@protocol YMKResourceUrlProvider <NSObject>

/**
 * Generates a URL that is used to load a resource based on its ID.
 *
 * This method may be called on any thread. Its implementation must be thread-safe.
 */
- (nonnull NSString *)formatUrlWithResourceId:(nonnull NSString *)resourceId;

@end
