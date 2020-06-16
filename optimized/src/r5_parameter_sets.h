/*
 * Copyright (c) 2020, PQShield and Koninklijke Philips N.V.
 * Markku-Juhani O. Saarinen, Koninklijke Philips N.V.
 */

#ifndef _R5_PARAMETER_SETS_H_
#define _R5_PARAMETER_SETS_H_

#include <stdint.h>
#include <stddef.h>
#include "misc.h"

// Parameter Set definitions

#if defined(R5ND_1CCA_0d)
#define ROUND5_CCA_PKE
#define PARAMS_KAPPA_BYTES 16
#define PARAMS_D           576
#define PARAMS_N           576
#define PARAMS_H           112
#define PARAMS_HMAX        357
#define PARAMS_Q_BITS      11
#define PARAMS_P_BITS      8
#define PARAMS_T_BITS      4
#define PARAMS_B_BITS      1
#define PARAMS_N_BAR       1
#define PARAMS_M_BAR       1
#define PARAMS_F           0
#define PARAMS_XE          0
#define PARAMS_MAL_BIN_TH  34
#define PARAMS_MAL_C2_TH   267
#define CRYPTO_ALGNAME     "R5ND_1CCA_0d"

#else
#error You must define one of: R5ND_1CPA_0d, R5ND_3CPA_0d, R5ND_5CPA_0d, R5ND_1CCA_0d, R5ND_3CCA_0d, R5ND_5CCA_0d, R5ND_1CPA_5d, R5ND_3CPA_5d, R5ND_5CPA_5d, R5ND_1CCA_5d, R5ND_3CCA_5d, R5ND_5CCA_5d, R5N1_1CPA_0d, R5N1_3CPA_0d, R5N1_5CPA_0d, R5N1_1CCA_0d, R5N1_3CCA_0d, R5N1_5CCA_0d, R5ND_0CPA_2iot, R5ND_1CPA_4longkey, R5N1_3CCA_0smallCT, R5ND_0CPA_0fail_phi_0, R5ND_0CPA_0fail_phi_1, R5ND_0CPA_0fail_phi_2, R5ND_0CPA_0fail_phi_3, R5ND_0CPA_0fail_phi_4, R5ND_0CPA_0fail_phi_5, R5ND_0CPA_0fail_phi_6, R5ND_0CPA_0fail_phi_7, R5ND_0CPA_0fail_phi_8, R5ND_0CPA_0fail_phi_9, R5ND_0CPA_0fail_phi_10, R5ND_0CPA_0fail_phi_11, R5ND_0CPA_0fail_phi_12, R5ND_0CPA_0fail_phi_13, R5ND_0CPA_0fail_phi_14, R5ND_0CPA_0fail_phi_15, R5ND_0CPA_0fail_phi_16, R5ND_0CPA_0fail_phi_17, R5ND_0CPA_0fail_phi_18, R5ND_0CPA_0fail_phi_19, R5ND_0CPA_0fail_phi_20, R5ND_0CPA_0fail_phi_21, R5ND_0CPA_0fail_phi_22, R5ND_0CPA_0fail_phi_23, R5ND_0CPA_0fail_phi_24, R5ND_0CPA_0fail_phi_25, R5ND_0CPA_0fail_phi_26, R5ND_0CPA_0fail_phi_27, R5ND_0CPA_0fail_phi_28, R5ND_0CPA_0fail_phi_29, R5ND_0CPA_xfail_ntru_0, R5ND_0CPA_xfail_ntru_1, R5ND_0CPA_xfail_ntru_2, R5ND_0CPA_xfail_ntru_3, R5ND_0CPA_xfail_ntru_4, R5ND_0CPA_xfail_ntru_5, R5ND_0CPA_xfail_ntru_6, R5ND_0CPA_xfail_ntru_7, R5ND_0CPA_xfail_ntru_8, R5ND_0CPA_xfail_ntru_9, R5ND_0CPA_xfail_ntru_10, R5ND_0CPA_xfail_ntru_11, R5ND_0CPA_xfail_ntru_12, R5ND_0CPA_xfail_ntru_13, R5ND_0CPA_xfail_ntru_14, R5ND_0CPA_xfail_ntru_15, R5ND_0CPA_xfail_ntru_16, R5ND_0CPA_xfail_ntru_17, R5ND_0CPA_xfail_ntru_18, R5ND_0CPA_xfail_ntru_19, R5ND_0CPA_xfail_ntru_20, R5ND_0CPA_xfail_ntru_21, R5ND_0CPA_xfail_ntru_22, R5ND_0CPA_xfail_ntru_23, R5ND_0CPA_xfail_ntru_24, R5ND_0CPA_xfail_ntru_25, R5ND_0CPA_xfail_ntru_26, R5ND_0CPA_xfail_ntru_27, R5ND_0CPA_xfail_ntru_28, R5ND_0CPA_xfail_ntru_29, R5N1_1CCA_0_Challenge_Toy, R5N1_1CCA_0_Challenge_Small, R5N1_1CCA_0_Challenge_Medium, R5ND_1CCA_0_Challenge_Toy, R5ND_1CCA_0_Challenge_Small, R5ND_1CCA_0_Challenge_Medium, R5ND_1CCA_5_Challenge_Medium, R5ND_1CCA_5_Challenge_Medium_HF
//    R5ND_1CCA_5_Challenge_Toy, R5ND_1CCA_5_Challenge_Small, R5ND_1CCA_5_Challenge_Toy_HF, R5ND_1CCA_5_Challenge_Small_HF,
#define PARAMS_KAPPA_BYTES 1
#define PARAMS_D           1
#define PARAMS_N           1
#define PARAMS_H           1
#define PARAMS_Q_BITS      1
#define PARAMS_P_BITS      1
#define PARAMS_T_BITS      1
#define PARAMS_B_BITS      1
#define PARAMS_N_BAR       1
#define PARAMS_M_BAR       1
#define PARAMS_F           0
#define PARAMS_XE          0
#define CRYPTO_ALGNAME     "INVALID"
#endif

// appropriate types
typedef uint16_t modq_t;
#if (PARAMS_P_BITS <= 8)
typedef uint8_t modp_t;
#else
typedef uint16_t modp_t;
#endif
typedef uint8_t modt_t;

// derived parameters
#define PARAMS_K        (PARAMS_D/PARAMS_N)
#define PARAMS_Q        (1 << PARAMS_Q_BITS)
#define PARAMS_Q_MASK   (PARAMS_Q - 1)
#define PARAMS_P        (1 << PARAMS_P_BITS)
#define PARAMS_P_MASK   (PARAMS_P - 1)
#define PARAMS_KAPPA    (8 * PARAMS_KAPPA_BYTES)
#define PARAMS_MU       CEIL_DIV((PARAMS_KAPPA + PARAMS_XE), PARAMS_B_BITS)
#define PARAMS_MUT_SIZE BITS_TO_BYTES(PARAMS_MU * PARAMS_T_BITS)


// parameters required for sampling of secret keys
#define PARAMS_RS_DIV       (0x10000 / PARAMS_D)
#define PARAMS_RS_LIM       (PARAMS_D * PARAMS_RS_DIV)
#define PARAMS_CUSTOM_LEN   8   // lenght of custom_lenght in drbg_init_customization
#define PARAMS_XSIZE        32  // amount of 16 bit numbers sampled at once
#define PARAMS_XMASK        0x1F
#define CTSECRETVECTOR64  (PARAMS_D+63)/64 //# of 64-bit words.

// Disable AVX2 if not supported by platform
#ifndef __AVX2__
#warning AVX2 not supported by platform
#undef AVX2
#endif

// If AVX2, determine CM_CT and CM_CACHE
#ifdef AVX2
#if !defined(CM_CACHE) && !defined(CM_CT)
#define CM_CT
#elif defined(CM_CT)
#undef CM_CACHE
#else
#undef CM_CACHE
#define CM_CACHE
#endif
#endif

#if (defined(STANDALONE) && defined(AVX2) && (PARAMS_N_BAR > 1))
#define PARAMS_N_BAR_4x (4*((PARAMS_N_BAR * 3)/4))
#else
#define PARAMS_N_BAR_4x PARAMS_N_BAR
#endif

#if (defined(STANDALONE) && defined(AVX2) && (PARAMS_M_BAR > 1))
#define PARAMS_M_BAR_4x (4*((PARAMS_M_BAR * 3)/4))
#else
#define PARAMS_M_BAR_4x PARAMS_M_BAR
#endif


// ternary vector type
#if  ((defined(CM_CACHE) || defined(CM_CT) ) && (PARAMS_N == 1)) || ( defined(CM_CT)  && (PARAMS_N != 1))  || (defined(AVX2) && (PARAMS_N == 1))// constant-time type
typedef  int16_t tern_coef_type;
typedef  tern_coef_type tern_secret[PARAMS_D];
typedef  tern_secret tern_secret_s[PARAMS_N_BAR_4x];
typedef  tern_secret tern_secret_r[PARAMS_M_BAR_4x];

#else
//    fast index type
typedef uint16_t tern_coef_type;
typedef tern_coef_type tern_secret[PARAMS_H/2][2];
typedef tern_secret tern_secret_s[PARAMS_N_BAR];
typedef tern_secret tern_secret_r[PARAMS_M_BAR];
#endif


#define PARAMS_DP_SIZE  BITS_TO_BYTES(PARAMS_N_BAR * PARAMS_D * PARAMS_P_BITS)
#define PARAMS_DPU_SIZE BITS_TO_BYTES(PARAMS_M_BAR * PARAMS_D * PARAMS_P_BITS)
#define PARAMS_PK_SIZE  (PARAMS_KAPPA_BYTES + PARAMS_DP_SIZE)
#define PARAMS_CT_SIZE  (PARAMS_DPU_SIZE + PARAMS_MUT_SIZE)


// Definition of TAU parameter
// Default for non-ring is 0
#if !defined(ROUND5_API_TAU) && PARAMS_K != 1
#undef ROUND5_API_TAU
#define ROUND5_API_TAU 2
#endif
// Ring only allows for 0
#if PARAMS_K == 1
#undef ROUND5_API_TAU
#define ROUND5_API_TAU 0
#endif

#define PARAMS_TAU      ROUND5_API_TAU

// Define the length of the random vector when TAU is 2 is used for generating A, defaults to parameter 2^11.
// Important: Must be a power of two and > d
#if !defined(ROUND5_API_TAU2_LEN) || ROUND5_API_TAU2_LEN == 0
#undef ROUND5_API_TAU2_LEN
#define ROUND5_API_TAU2_LEN (1<<11)
#endif
#if ROUND5_API_TAU2_LEN > (1<<31)
#error ROUND5_API_TAU2_LEN must be less than or equal to 2^31
#endif
#if (ROUND5_API_TAU2_LEN & (ROUND5_API_TAU2_LEN - 1)) != 0 || ROUND5_API_TAU2_LEN < PARAMS_D
#error ROUND5_API_TAU2_LEN must be a power of two and greater than or equal to PARAMS_D
#endif
#define PARAMS_TAU2_LEN ROUND5_API_TAU2_LEN

// Rounding constants
#if ((PARAMS_Q_BITS - PARAMS_P_BITS + PARAMS_T_BITS) < PARAMS_P_BITS)
#define PARAMS_Z_BITS   PARAMS_P_BITS
#else
#define PARAMS_Z_BITS   (PARAMS_Q_BITS - PARAMS_P_BITS + PARAMS_T_BITS)
#endif
#define PARAMS_H1       (1 << (PARAMS_Q_BITS - PARAMS_P_BITS - 1))
#define PARAMS_H2       (1 << (PARAMS_Q_BITS - PARAMS_Z_BITS - 1))
#define PARAMS_H3       ((1 << (PARAMS_P_BITS - PARAMS_T_BITS - 1)) + (1 << (PARAMS_P_BITS - PARAMS_B_BITS - 1)) - (1 << (PARAMS_Q_BITS - PARAMS_Z_BITS - 1)))

// Packing shift
//#if PARAMS_K != 1
#if PARAMS_B_BITS == 1
#define PACK_SHIFT 3
#define PACK_AND 7
#endif
#if PARAMS_B_BITS == 2
#define PACK_SHIFT 2
#define PACK_AND 3
#endif
#if PARAMS_B_BITS == 4
#define PACK_SHIFT 1
#define PACK_AND 1
#endif
//#endif

#endif /* _R5_PARAMETER_SETS_H_ */

