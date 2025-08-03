#import <Foundation/Foundation.h>

/**
 * Description to display.
 */
@interface YMKDrivingDescription : NSObject

/**
 * How to get a description.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *via;


+ (nonnull YMKDrivingDescription *)descriptionWithVia:(nullable NSString *)via;


@end
