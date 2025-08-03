#import <YandexMapsMobile/YRTRsaPublicKey.h>

@class YRTAttestationListener;

/**
 * :nodoc:
 */
@protocol YRTPlatformKeystore <NSObject>

/**
 * Returns true if there is a generated platform key.
 *
 * This method will be called on a background thread.
 */
- (BOOL)hasKey;

/**
 * Generates platform key.
 *
 * This method will be called on a background thread.
 */
- (void)generateKeyWithChallenge:(nonnull NSData *)challenge;

/**
 * Removes platform key.
 *
 * This method will be called on a background thread.
 */
- (void)removeKey;

/**
 * Returns platform keystore key proof. On Android it is a certificate
 * chain, on iOS it is KeyId.
 *
 * This method will be called on a background thread.
 */
- (nonnull NSData *)getKeystoreProof;

/**
 * Returns public key information for stored key.
 *
 * This method will be called on a background thread.
 */
- (nonnull YRTRsaPublicKey *)getRsaPublicKey;

/**
 * Requests key attestation from service used in implementation of this
 * interface.
 *
 * This method will be called on a background thread.
 */
- (void)requestAttestKeyWithChallenge:(nonnull NSData *)challenge
                   cloudProjectNumber:(long long)cloudProjectNumber
                  attestationListener:(nonnull YRTAttestationListener *)attestationListener;

/**
 * Signs data with private key that is in the platform keystore.
 *
 * This method will be called on a background thread.
 */
- (nonnull NSData *)rsaSignWithData:(nonnull NSData *)data;

/**
 * This method will be called on a background thread.
 */
- (nonnull NSData *)rsaEncryptWithData:(nonnull NSData *)data
                          pkcs1Padding:(BOOL)pkcs1Padding;

@end
