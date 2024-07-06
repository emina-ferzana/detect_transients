/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detect_transients_terminate.c
 *
 * Code generation for function 'detect_transients_terminate'
 *
 */

/* Include files */
#include "detect_transients_terminate.h"
#include "detect_transients_data.h"
#include "omp.h"

/* Function Definitions */
void detect_transients_terminate(void)
{
  omp_destroy_nest_lock(&detect_transients_nestLockGlobal);
  isInitialized_detect_transients = false;
}

/* End of code generation (detect_transients_terminate.c) */
