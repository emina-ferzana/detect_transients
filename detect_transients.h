/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detect_transients.h
 *
 * Code generation for function 'detect_transients'
 *
 */

#ifndef DETECT_TRANSIENTS_H
#define DETECT_TRANSIENTS_H

/* Include files */
#include "detect_transients_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void detect_transients(const double y[176400],
                              emxArray_real_T *audio_events);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (detect_transients.h) */
