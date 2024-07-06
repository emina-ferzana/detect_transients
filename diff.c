/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"

/* Function Definitions */
void b_diff(const double x_data[], const int x_size[2], double y_data[],
            int y_size[2])
{
  int dimSize;
  int u0;
  dimSize = x_size[0];
  if (x_size[0] == 0) {
    y_size[0] = 0;
    y_size[1] = 1;
  } else {
    u0 = x_size[0] - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y_size[0] = 0;
      y_size[1] = 1;
    } else {
      y_size[0] = x_size[0] - 1;
      y_size[1] = 1;
      if (x_size[0] - 1 != 0) {
        double work_data;
        work_data = x_data[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          double d;
          double tmp1;
          tmp1 = x_data[u0 - 1];
          d = tmp1;
          tmp1 -= work_data;
          work_data = d;
          y_data[u0 - 2] = tmp1;
        }
      }
    }
  }
}

void diff(const double x[698368], double y[696320])
{
  int iy;
  int m;
  int s;
  iy = 0;
  for (s = 0; s < 2048; s++) {
    double work;
    work = x[s];
    for (m = 0; m < 340; m++) {
      double tmp2;
      int i;
      tmp2 = work;
      i = m << 11;
      work = x[(s + i) + 2048];
      y[iy + i] = work - tmp2;
    }
    iy++;
  }
}

/* End of code generation (diff.c) */
