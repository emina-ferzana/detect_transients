/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * formatSTFTOutput.c
 *
 * Code generation for function 'formatSTFTOutput'
 *
 */

/* Include files */
#include "formatSTFTOutput.h"
#include <string.h>

/* Function Definitions */
void formatSTFTOutput(creal_T S[698368], double Fout[2048])
{
  creal_T a__1[1023];
  int b_i;
  int i;
  int k;
  for (i = 0; i < 341; i++) {
    int pageroot;
    pageroot = i << 11;
    memcpy(&a__1[0], &S[pageroot + 1025], 1023U * sizeof(creal_T));
    for (k = 1024; k >= 0; k--) {
      b_i = pageroot + k;
      S[b_i + 1023] = S[b_i];
    }
    memcpy(&S[pageroot], &a__1[0], 1023U * sizeof(creal_T));
  }
  for (b_i = 0; b_i < 2048; b_i++) {
    Fout[b_i] = 21.533203125 * (double)b_i - 22028.466796875;
  }
}

/* End of code generation (formatSTFTOutput.c) */
