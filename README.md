# RLWR_KEM

We implemented our KEM by slightly modifying the source code of Round5(https://round5.org/). Only codes in "optimized" are modified. All codes in "configurable" and "reference" are not changed, sames as in Round5(https://github.com/round5/code)

/optimized/ringmul.c (change the procedure of polynomial multiplication)
/optimized/r5_parameters.h (change the parmaeters as we set for our KEM)
/optimized/cpa_pke_nd.c (change encoding method into EMBLEM encoding)
are modified to fit our KEM.

To build and run the implementaion, follow the instructions in README of https://github.com/round5/code.
