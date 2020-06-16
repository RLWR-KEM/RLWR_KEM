/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Declaration of the CPA KEM functions (NIST api).
 */

//#ifndef _CPA_KEM_H_
//#define _CPA_KEM_H_

#include "chooseparameters.h"

#define ROUND5_CCA_PKE

/*
 * Conditionally provide the KEM NIST API functions.
 */


#ifdef __cplusplus
extern "C" {
#endif
    
//#define ROUND5_CCA_PKE

#ifndef ROUND5_CCA_PKE

    
    /**
     * Generates a CPA KEM key pair.
     *
     * @param[out] pk public key
     * @param[out] sk secret key
     * @return __0__ in case of success
     */
    int crypto_kem_keypair(unsigned char *pk, unsigned char *sk);

    /**
     * CPA KEM encapsulate.
     *
     * @param[out] ct    key encapsulation message (ciphertext)
     * @param[out] k     shared secret
     * @param[in]  pk    public key with which the message is encapsulated
     * @return __0__ in case of success
     */
    int crypto_kem_enc(unsigned char *ct, unsigned char *k, const unsigned char *pk);

    /**
     * CPA KEM de-capsulate.
     *
     * @param[out] k     shared secret
     * @param[in]  ct    key encapsulation message (ciphertext)
     * @param[in]  sk    secret key with which the message is to be de-capsulated
     * @return __0__ in case of success
     */
    int crypto_kem_dec(unsigned char *k, const unsigned char *ct, const unsigned char *sk);
    
#else /*CCA KEM*/
    

    /**
     * Generates a CCA KEM key pair.
     *
     * @param[out] pk public key
     * @param[out] sk secret key
     * @return __0__ in case of success
     */
    inline int crypto_kem_keypair(unsigned char *pk, unsigned char *sk);
    
    /**
     * CCA KEM encapsulate.
     *
     * @param[out] ct    key encapsulation message (ciphertext)
     * @param[out] k     shared secret
     * @param[in]  pk    public key with which the message is encapsulated
     * @return __0__ in case of success
     */
    inline int crypto_kem_enc(unsigned char *ct, unsigned char *k, const unsigned char *pk);
    
    /**
     * CCA KEM de-capsulate.
     *
     * @param[out] k     shared secret
     * @param[in]  ct    key encapsulation message (ciphertext)
     * @param[in]  sk    secret key with which the message is to be de-capsulated
     * @return __0__ in case of success
     */
    inline int crypto_kem_dec(unsigned char *k, const unsigned char *ct, const unsigned char *sk);
    
#endif
    
#ifdef __cplusplus
}
#endif
