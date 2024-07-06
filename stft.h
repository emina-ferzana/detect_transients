/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stft.h
 *
 * Code generation for function 'stft'
 *
 */

#ifndef STFT_H
#define STFT_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void stft(const double x[176400], creal_T varargout_1[698368],
          double varargout_2[2048]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (stft.h) */
