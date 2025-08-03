#import <Foundation/Foundation.h>

@class YMKImageImageSize;

/**
 * Undocumented
 */
@interface YMKImage : NSObject

/**
 * urlTemplate for the image.
 */
@property (nonatomic, readonly, nonnull) NSString *urlTemplate;

/**
 * Image sizes.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKImageImageSize *> *sizes;

/**
 * Image tags.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *tags;


+ (nonnull YMKImage *)imageWithUrlTemplate:(nonnull NSString *)urlTemplate
                                     sizes:(nonnull NSArray<YMKImageImageSize *> *)sizes
                                      tags:(nonnull NSArray<NSString *> *)tags;


@end

/**
 * Undocumented
 */
@interface YMKImageImageSize : NSObject

/**
 * Undocumented
 */
@property (nonatomic, readonly, nonnull) NSString *size;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *width;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *height;


+ (nonnull YMKImageImageSize *)imageSizeWithSize:(nonnull NSString *)size
                                           width:(nullable NSNumber *)width
                                          height:(nullable NSNumber *)height;


@end
