/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.h
 *
 * Code generation for function 'diff'
 *
 */

#ifndef DIFF_H
#define DIFF_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_diff(const double x_data[], const int x_size[2], double y_data[],
            int y_size[2]);

void diff(const double x[698368], double y[696320]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (diff.h) */
