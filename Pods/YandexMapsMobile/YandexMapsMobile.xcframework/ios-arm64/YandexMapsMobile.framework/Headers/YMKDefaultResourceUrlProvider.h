#import <YandexMapsMobile/YMKResourceUrlProvider.h>

/// :nodoc:
@interface YMKDefaultResourceUrlProvider : NSObject<YMKResourceUrlProvider>

- (NSString *)formatUrlWithResourceId:(NSString *)resId;

- (void)setUrlBase:(NSString *)urlBase;

@end
