/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_detect_transients_api.h
 *
 * Code generation for function 'detect_transients'
 *
 */

#ifndef _CODER_DETECT_TRANSIENTS_API_H
#define _CODER_DETECT_TRANSIENTS_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void detect_transients(real_T y[176400], emxArray_real_T *audio_events);

void detect_transients_api(const mxArray *prhs, const mxArray **plhs);

void detect_transients_atexit(void);

void detect_transients_initialize(void);

void detect_transients_terminate(void);

void detect_transients_xil_shutdown(void);

void detect_transients_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_detect_transients_api.h) */
