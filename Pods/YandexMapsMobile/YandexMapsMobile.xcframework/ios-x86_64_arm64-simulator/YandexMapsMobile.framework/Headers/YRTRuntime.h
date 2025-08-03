#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
@interface YRTRuntime : NSObject

/**
 * Undocumented
 */
+ (nonnull NSString *)version;

/**
 * Undocumented
 */
+ (void)setPreinitializationOptions:(nonnull NSDictionary<NSString *, NSString *> *)runtimeOptions;

@end
