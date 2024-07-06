/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detect_transients_initialize.c
 *
 * Code generation for function 'detect_transients_initialize'
 *
 */

/* Include files */
#include "detect_transients_initialize.h"
#include "detect_transients_data.h"
#include "omp.h"

/* Function Definitions */
void detect_transients_initialize(void)
{
  omp_init_nest_lock(&detect_transients_nestLockGlobal);
  isInitialized_detect_transients = true;
}

/* End of code generation (detect_transients_initialize.c) */
