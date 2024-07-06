/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include <stdio.h>
#include <string.h>
#include "detect_transients.h"
#include "detect_transients_emxAPI.h"
#include "detect_transients_initialize.h"
#include "detect_transients_terminate.h"
#include <sndfile.h>

/* Function Declarations */
static void argInit_176400x1_real_T(double result[176400]);
static double argInit_real_T(void);

/* Function Definitions */
static void argInit_176400x1_real_T(double result[176400])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 176400; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

void main_detect_transients(const double* audio)
{
  double dv[176400];
  emxArray_real_T *audio_events;
  /* Initialize function 'detect_transients' input arguments. */
  /* Initialize function input argument 'y'. */
  argInit_176400x1_real_T(dv);
  
  /* Initialize the output array */
  audio_events = emxCreate_real_T(100, 4410); // Adjust the size if needed
  printf("Entering the transient detector.\n");
  /* Call the entry-point 'detect_transients'. */
  detect_transients(audio, audio_events);

  /* Print some output to verify (optional) */
  printf("First audio event segment:\n");
  int number_of_audio_event = 0;
  for (int i = number_of_audio_event * audio_events->size[1]; i < number_of_audio_event * audio_events->size[1] + 100; ++i) {
    printf("%f ", audio_events->data[i]);
  }
  printf("\n Size of audio_events array: (%d, %d)\n", audio_events->size[0], audio_events->size[1]);
  printf("Number of elements in the audio_events array: %d\n", audio_events->allocatedSize);

  /* Destroy the emxArray */
  emxDestroyArray_real_T(audio_events);
}

int main(int argc, char **argv)
{
  const char* wav_file;
  if (argc == 2) {
      wav_file = argv[1];
  } else if (argc == 1){
      wav_file = "1000032-3-0-0.wav";
  } else {
      printf("Usage: ./%s <wav_file> or ./%s\n", argv[0], argv[0]);
      return 1;
  }

  SNDFILE *file;
  SF_INFO info;
  int num, num_items;
  double *buf, *leftChannel, *rightChannel;
  int f,sr,c; // f == size (num of bytes in each channel)
  int i;

  /* Open the WAV file. */
  info.format = 0;
  file = sf_open(wav_file, SFM_READ, &info);
  if (file == NULL) {
      printf("Failed to open the file.\n");
      exit(-1);
  }

  /* Print some of the info, and figure out how much data to read. */
  f = info.frames;
  sr = info.samplerate;
  c = info.channels;
  printf("frames=%d\nsamplerate=%d\nchannels=%d\n", f, sr, c);

  num_items = f*c;
  printf("num_items=%d\n",num_items);

  /* Allocate space for the data to be read, then read it. */
  buf = (double *) malloc(num_items*sizeof(double));
  if ( buf == NULL ){
      perror("Memory allocation failed");
      free(buf);
      exit(2);
  }
  num = sf_read_double(file,buf,num_items);
  sf_close(file);
  printf("Read %d items\n",num);
  if( f*sizeof(double) <= 176400){
    printf("The whole file with fit within the allocated  buffer.\n");
  }
  /* Allocate memory for each channel. */
  // matlab contraint
  //f = 176400/sizeof(double);
  //leftChannel = (double *)malloc(f * sizeof(double));
  //rightChannel = (double *)malloc(f * sizeof(double));
  rightChannel = (double *)malloc(176400 * sizeof(double));
  leftChannel = (double *)malloc(176400 * sizeof(double));
  if (leftChannel == NULL || rightChannel == NULL) {
      perror("Memory allocation failed");
      free(leftChannel);
      free(rightChannel);
      exit(3);
  }
  // memset(rightChannel, 0.0, (size_t) 176400);
  // memset(leftChannel, 0.0, (size_t) 176400);
  argInit_176400x1_real_T(leftChannel);
  argInit_176400x1_real_T(rightChannel);
  /* Deinterleave the data into left and right channels. */
  for (i = 0; i < f; i++) {
      leftChannel[i] = buf[2*i];      // Even indices are left channel
      rightChannel[i] = buf[2*i + 1]; // Odd indices are right channel
  }

  /* At this point, leftChannel and rightChannel contain the separated audio data. */
  

  /* Initialize the application.
     You do not need to do this more than one time. */
  //detect_transients_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_detect_transients(rightChannel);

  /* Terminate the application.
     You do not need to do this more than one time. */
  detect_transients_terminate();
  return 0;
}

/* End of code generation (main.c) */

