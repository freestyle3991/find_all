#import <YandexMapsMobile/YMKLocalizedValue.h>
#import <YandexMapsMobile/YMKPoint.h>
#import <YandexMapsMobile/YMKSpannableString.h>
#import <YandexMapsMobile/YRTKeyvalue.h>

/**
 * Suggest item type.
 */
typedef NS_ENUM(NSUInteger, YMKSuggestItemType) {
    /**
     * For backward compatibility in future.
     */
    YMKSuggestItemTypeUnknown,
    /**
     * City, street, house etc.
     */
    YMKSuggestItemTypeToponym,
    /**
     * Company with specific location.
     */
    YMKSuggestItemTypeBusiness,
    /**
     * Public transport route number or transit-related keyword.
     */
    YMKSuggestItemTypeTransit
};

/**
 * Action to be performed when user selected suggest item.
 */
typedef NS_ENUM(NSUInteger, YMKSuggestItemAction) {
    /**
     * Immediately search for `text`.
     */
    YMKSuggestItemActionSearch,
    /**
     * Substitute query by `text` for further editing.
     */
    YMKSuggestItemActionSubstitute
};

/**
 * A single suggested item.
 */
@interface YMKSuggestItem : NSObject

/**
 * Suggested object type.
 */
@property (nonatomic, readonly) YMKSuggestItemType type;

/**
 * Short object name.
 */
@property (nonatomic, readonly, nonnull) YMKSpannableString *title;

/**
 * If type is TOPONYM returns reversed toponym hierarchy, if type is
 * BUSINESS returns business address.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKSpannableString *subtitle;

/**
 * Additional free-form data for suggest item. If type is TOPONYM,
 * returns toponym kind (house/street/locality/...). If type is
 * BUSINESS, returns category class (drugstores/restaurants/...).
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *tags;

/**
 * Text to search for.
 */
@property (nonatomic, readonly, nonnull) NSString *searchText;

/**
 * Text to display if searchText is too technical to display.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *displayText;

/**
 * Element uri, if applicable.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *uri;

/**
 * Optional distance localized value.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKLocalizedValue *distance;

/**
 * If the suggested item respects personalization.
 */
@property (nonatomic, readonly) BOOL isPersonal;

/**
 * Action to perform on click/tap/enter.
 */
@property (nonatomic, readonly) YMKSuggestItemAction action;

/**
 * Id for request logging.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *logId;

/**
 * Item is from offline search.
 */
@property (nonatomic, readonly) BOOL isOffline;

/**
 * Item is a word suggest item.
 */
@property (nonatomic, readonly) BOOL isWordItem;

/**
 * Additional item properties.
 */
@property (nonatomic, readonly, nonnull) NSArray<YRTKeyValuePair *> *properties;

/**
 * Position of object.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKPoint *center;


+ (nonnull YMKSuggestItem *)suggestItemWithType:( YMKSuggestItemType)type
                                          title:(nonnull YMKSpannableString *)title
                                       subtitle:(nullable YMKSpannableString *)subtitle
                                           tags:(nonnull NSArray<NSString *> *)tags
                                     searchText:(nonnull NSString *)searchText
                                    displayText:(nullable NSString *)displayText
                                            uri:(nullable NSString *)uri
                                       distance:(nullable YMKLocalizedValue *)distance
                                     isPersonal:( BOOL)isPersonal
                                         action:( YMKSuggestItemAction)action
                                          logId:(nullable NSString *)logId
                                      isOffline:( BOOL)isOffline
                                     isWordItem:( BOOL)isWordItem
                                     properties:(nonnull NSArray<YRTKeyValuePair *> *)properties
                                         center:(nullable YMKPoint *)center;


@end
