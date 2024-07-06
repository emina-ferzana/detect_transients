/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detect_transients.c
 *
 * Code generation for function 'detect_transients'
 *
 */

/* Include files */
#include "detect_transients.h"
#include "detect_transients_data.h"
#include "detect_transients_emxutil.h"
#include "detect_transients_initialize.h"
#include "detect_transients_types.h"
#include "transient_detector_func.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_roundd(double u);

/* Function Definitions */
static double rt_roundd(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void detect_transients(const double y[176400], emxArray_real_T *audio_events)
{
  double cut_audio_segment[4410];
  double transients_data[341];
  double *audio_events_data;
  int transients_size[2];
  int end;
  int i;
  int idx;
  int partialTrueCount;
  int trueCount;
  if (!isInitialized_detect_transients) {
    detect_transients_initialize();
  }
  /*  0.1ms */
  /*  Ensure the audio data is single-channel */
  /*  y must be monochannel */
  transient_detector_func(y, transients_data, transients_size);
  end = transients_size[1] - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (transients_data[i] != 0.0) {
      trueCount++;
    }
  }
  partialTrueCount = 0;
  for (i = 0; i <= end; i++) {
    if (transients_data[i] != 0.0) {
      transients_data[partialTrueCount] = transients_data[i];
      partialTrueCount++;
    }
  }
  transients_size[1] = trueCount;
  /*  Remove unused preallocated space */
  /*  file length in seconds        */
  if (trueCount == 0) {
    audio_events->size[0] = 0;
    audio_events->size[1] = 4410;
    /* return value is empty */
  } else {
    boolean_T exitg1;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= trueCount - 1)) {
      if (transients_data[idx] > 3.9) {
        transients_data[idx] = 3.9;
        transients_size[1] = idx + 1;
        printf("Start time: %f\n", transients_data[idx]);
        exitg1 = true;
      } else {
        printf("Start time: %f\n", transients_data[idx]);
        idx++;
      }
    }
    partialTrueCount = audio_events->size[0] * audio_events->size[1];
    audio_events->size[0] = transients_size[1];
    audio_events->size[1] = 4410;
    emxEnsureCapacity_real_T(audio_events, partialTrueCount);
    audio_events_data = audio_events->data;
    end = transients_size[1] * 4410;
    for (partialTrueCount = 0; partialTrueCount < end; partialTrueCount++) {
      audio_events_data[partialTrueCount] = 0.0;
    }
    partialTrueCount = transients_size[1];
    for (idx = 0; idx < partialTrueCount; idx++) {
      double b_y;
      double end_point;
      b_y = rt_roundd(transients_data[idx] * 44100.0);
      memset(&cut_audio_segment[0], 0, 4410U * sizeof(double));
      end_point = fmin(176400.0, ((b_y + 1.0) + 4410.0) - 1.0);
      if (b_y + 1.0 > end_point) {
        trueCount = 0;
        i = 0;
      } else {
        trueCount = (int)(b_y + 1.0) - 1;
        i = (int)end_point;
      }
      end = i - trueCount;
      for (i = 0; i < end; i++) {
        cut_audio_segment[i] = y[trueCount + i];
      }
      for (trueCount = 0; trueCount < 4410; trueCount++) {
        //audio_events_data[idx + audio_events->size[0] * trueCount] =
        audio_events_data[idx * audio_events->size[1] + trueCount] =
            cut_audio_segment[trueCount];
      }
      /* return value is a matrix, a vector of vectors */
    }
  }
}

/* End of code generation (detect_transients.c) */
