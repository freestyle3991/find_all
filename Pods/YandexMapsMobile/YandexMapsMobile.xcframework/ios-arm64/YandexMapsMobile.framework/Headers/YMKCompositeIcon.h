#import <YandexMapsMobile/YMKCallback.h>

#import <UIKit/UIKit.h>

@class YMKIconStyle;

/**
 * Combines multiple icons into one.
 */
@interface YMKCompositeIcon : NSObject

/**
 * Creates or resets a named layer with an icon and its style.
 */
- (void)setIconWithName:(nonnull NSString *)name
                  image:(nonnull UIImage *)image
                  style:(nonnull YMKIconStyle *)style;

/**
 * Creates or resets a named layer that contains an icon and its style.
 *
 * @param onFinished Called when an icon is loaded.
 */
- (void)setIconWithName:(nonnull NSString *)name
                  image:(nonnull UIImage *)image
                  style:(nonnull YMKIconStyle *)style
               callback:(nonnull YMKCallback)callback;

/**
 * Changes the icon style for a specific layer.
 */
- (void)setIconStyleWithName:(nonnull NSString *)name
                       style:(nonnull YMKIconStyle *)style;

/**
 * Removes the named layer.
 */
- (void)removeIconWithName:(nonnull NSString *)name;

/**
 * Removes all layers.
 */
- (void)removeAll;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
