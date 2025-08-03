#import <YandexMapsMobile/YMKCallback.h>
#import <YandexMapsMobile/YRTAnimatedImageProvider.h>

@class YMKIconStyle;

/**
 * Provides an interface to load and control animation of placemark.
 */
@interface YMKPlacemarkAnimation : NSObject

/**
 * Sets the animated image and icon style. The new animation will be in
 * the paused state.
 */
- (void)setIconWithImage:(nonnull id<YRTAnimatedImageProvider>)image
                   style:(nonnull YMKIconStyle *)style;

/**
 * Sets the animated image and icon style. The new animation will be in
 * the paused state.
 *
 * @param onFinished is called when the icon is loaded.
 */
- (void)setIconWithImage:(nonnull id<YRTAnimatedImageProvider>)image
                   style:(nonnull YMKIconStyle *)style
                callback:(nonnull YMKCallback)callback;

/**
 * Changes the icon style.
 */
- (void)setIconStyleWithStyle:(nonnull YMKIconStyle *)style;

/**
 * Starts animation. Removes the current play callback. Same as
 * play(null).
 */
- (void)play;

/**
 * Starts animation and handles the callback.
 *
 * @param onFinished is called when animation finishes and replaces the
 * previous callback.
 */
- (void)playWithCallback:(nonnull YMKCallback)callback;

/**
 * Resumes paused animation. Callback (if any) is NOT removed.
 */
- (void)resume;

/**
 * Stops animation. Animation returns to the initial paused state.
 */
- (void)stop;

/**
 * Pauses animation.
 */
- (void)pause;
/**
 * If true, animation will be played in the reverse direction. Default
 * value is false.
 */
@property (nonatomic, getter=isReversed) BOOL reversed;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
