/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * transient_detector_func.h
 *
 * Code generation for function 'transient_detector_func'
 *
 */

#ifndef TRANSIENT_DETECTOR_FUNC_H
#define TRANSIENT_DETECTOR_FUNC_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void transient_detector_func(const double y[176400],
                             double c_filtered_times_of_transients_[],
                             int d_filtered_times_of_transients_[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (transient_detector_func.h) */
