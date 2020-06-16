/*
 * Copyright (c) 2018, PQShield and Koninklijke Philips N.V.
 * Markku-Juhani O. Saarinen, Koninklijke Philips N.V.
 */

// Fast ring arithmetic (without cache attack countermeasures)

#include "ringmul.h"
#include "r5_parameter_sets.h"

#if PARAMS_K == 1 && !defined(CM_CACHE) && !defined(CM_CT)  

#include "drbg.h"
#include "little_endian.h"

#include <string.h>

// multiplication mod q, result length n


void ringmul_q(modq_t d[PARAMS_N], modq_t a[PARAMS_N], tern_secret idx) {
    size_t i, j;
    //modq_t *p_add, *p_sub ,*p_sub_, *p_add_;
    modq_t p[2 * (PARAMS_N)]={0,};
    int PARAMS_3N=PARAMS_N+(PARAMS_N/2);

    // Initialize result
    memset(d, 0, PARAMS_N * sizeof (modq_t));

   for (i = 0; i < PARAMS_H / 2; i++) {

        for(j=0;j<PARAMS_N;j++){
          p[j+idx[i][0]]=(modq_t)(p[j+idx[i][0]]+a[j]);
          p[j+idx[i][1]]=(modq_t)(p[j+idx[i][1]]-a[j]);
        }
    }

    for(i=0; i < PARAMS_N/2; i++){
      int j=i+PARAMS_N/2;

      d[i]=p[i]-p[i+PARAMS_3N]-p[i+PARAMS_N];
      d[j]=p[j]+p[i+PARAMS_N];

      d[i]=((d[i] + (1 << (PARAMS_Q_BITS - PARAMS_P_BITS - 1))) >> (PARAMS_Q_BITS - PARAMS_P_BITS));
      d[j]=((d[j] + (1 << (PARAMS_Q_BITS - PARAMS_P_BITS - 1))) >> (PARAMS_Q_BITS - PARAMS_P_BITS));

      d[i]=(modq_t)d[i];
    }

  
}


// multiplication mod p, result length mu

void ringmul_p(modp_t d[PARAMS_MU], modp_t a[PARAMS_N], tern_secret idx) {
    size_t i, j;
    //modp_t *p_add, *p_sub, *p_add_, *p_sub_;
    modp_t p[(PARAMS_N)*2]={0,};
    int PARAMS_3N=PARAMS_N+(PARAMS_N/2);

    //memset(p, 0, 2*PARAMS_N * sizeof (modp_t));

    // Initialize result
    memset(d, 0, (PARAMS_MU) * sizeof (modp_t));

   for (i = 0; i < PARAMS_H / 2; i++) {

        for(j=0;j<PARAMS_N;j++){
          p[j+idx[i][0]]=(modp_t)(p[j+idx[i][0]]+a[j]);
          p[j+idx[i][1]]=(modp_t)(p[j+idx[i][1]]-a[j]);
        }
    }


    for(int i=PARAMS_N/2-PARAMS_MU;i<PARAMS_N/2;i++){

      d[i]=p[i]-p[i + PARAMS_3N]-p[PARAMS_N + i];

      d[i]=((d[i] + (1 << (PARAMS_Q_BITS - PARAMS_P_BITS - 1))) >> (PARAMS_Q_BITS - PARAMS_P_BITS));

      d[i]=(modp_t)d[i];

    }

}

#endif /* PARAMS_K == 1 && !defined(CM_CACHE) */
