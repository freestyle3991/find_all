#import <Foundation/Foundation.h>

/**
 * Checks if the arrow was tapped.
 */
@protocol YMKArrowTapListener <NSObject>

/**
 * Index of an arrow in the collection of colored polyline arrows.
 */
- (void)onArrowTapWithIndex:(NSUInteger)index;

@end
