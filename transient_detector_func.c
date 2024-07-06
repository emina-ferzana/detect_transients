/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * transient_detector_func.c
 *
 * Code generation for function 'transient_detector_func'
 *
 */

/* Include files */
#include "transient_detector_func.h"
#include "detect_transients_emxutil.h"
#include "detect_transients_types.h"
#include "diff.h"
#include "stft.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_hypotd(double u0, double u1);

/* Function Definitions */
static double rt_hypotd(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

void transient_detector_func(const double y[176400],
                             double c_filtered_times_of_transients_[],
                             int d_filtered_times_of_transients_[2])
{
  static creal_T s_1[698368];
  static const double t_1[341] = {
      0.023219954648526078, 0.034829931972789115, 0.046439909297052155,
      0.058049886621315196, 0.069659863945578229, 0.08126984126984127,
      0.09287981859410431,  0.10448979591836735,  0.11609977324263039,
      0.12770975056689343,  0.13931972789115646,  0.15092970521541951,
      0.16253968253968254,  0.17414965986394557,  0.18575963718820862,
      0.19736961451247165,  0.2089795918367347,   0.22058956916099773,
      0.23219954648526078,  0.24380952380952381,  0.25541950113378686,
      0.26702947845804986,  0.27863945578231292,  0.29024943310657597,
      0.301859410430839,    0.313469387755102,    0.32507936507936508,
      0.33668934240362813,  0.34829931972789113,  0.35990929705215419,
      0.37151927437641724,  0.3831292517006803,   0.39473922902494329,
      0.40634920634920635,  0.4179591836734694,   0.4295691609977324,
      0.44117913832199546,  0.45278911564625851,  0.46439909297052157,
      0.47600907029478456,  0.48761904761904762,  0.49922902494331067,
      0.51083900226757373,  0.52244897959183678,  0.53405895691609973,
      0.54566893424036278,  0.55727891156462583,  0.56888888888888889,
      0.58049886621315194,  0.592108843537415,    0.603718820861678,
      0.615328798185941,    0.626938775510204,    0.6385487528344671,
      0.65015873015873016,  0.66176870748299321,  0.67337868480725627,
      0.68498866213151932,  0.69659863945578226,  0.70820861678004532,
      0.71981859410430837,  0.73142857142857143,  0.74303854875283448,
      0.75464852607709754,  0.76625850340136059,  0.77786848072562353,
      0.78947845804988659,  0.80108843537414964,  0.8126984126984127,
      0.82430839002267575,  0.83591836734693881,  0.84752834467120186,
      0.8591383219954648,   0.87074829931972786,  0.88235827664399091,
      0.893968253968254,    0.905578231292517,    0.91718820861678008,
      0.92879818594104313,  0.94040816326530607,  0.95201814058956913,
      0.96362811791383218,  0.97523809523809524,  0.98684807256235829,
      0.99845804988662135,  1.0100680272108844,   1.0216780045351475,
      1.0332879818594105,   1.0448979591836736,   1.0565079365079366,
      1.0681179138321995,   1.0797278911564625,   1.0913378684807256,
      1.1029478458049886,   1.1145578231292517,   1.1261678004535147,
      1.1377777777777778,   1.1493877551020408,   1.1609977324263039,
      1.1726077097505669,   1.18421768707483,     1.195827664399093,
      1.2074376417233561,   1.2190476190476192,   1.230657596371882,
      1.242267573696145,    1.2538775510204081,   1.2654875283446712,
      1.2770975056689342,   1.2887074829931973,   1.3003174603174603,
      1.3119274376417234,   1.3235374149659864,   1.3351473922902495,
      1.3467573696145125,   1.3583673469387756,   1.3699773242630386,
      1.3815873015873017,   1.3931972789115645,   1.4048072562358276,
      1.4164172335600906,   1.4280272108843537,   1.4396371882086167,
      1.4512471655328798,   1.4628571428571429,   1.4744671201814059,
      1.486077097505669,    1.497687074829932,    1.5092970521541951,
      1.5209070294784581,   1.5325170068027212,   1.5441269841269842,
      1.5557369614512471,   1.5673469387755101,   1.5789569160997732,
      1.5905668934240362,   1.6021768707482993,   1.6137868480725623,
      1.6253968253968254,   1.6370068027210884,   1.6486167800453515,
      1.6602267573696146,   1.6718367346938776,   1.6834467120181407,
      1.6950566893424037,   1.7066666666666668,   1.7182766439909296,
      1.7298866213151927,   1.7414965986394557,   1.7531065759637188,
      1.7647165532879818,   1.7763265306122449,   1.7879365079365079,
      1.799546485260771,    1.811156462585034,    1.8227664399092971,
      1.8343764172335602,   1.8459863945578232,   1.8575963718820863,
      1.8692063492063493,   1.8808163265306121,   1.8924263038548752,
      1.9040362811791383,   1.9156462585034013,   1.9272562358276644,
      1.9388662131519274,   1.9504761904761905,   1.9620861678004535,
      1.9736961451247166,   1.9853061224489796,   1.9969160997732427,
      2.0085260770975055,   2.0201360544217688,   2.0317460317460316,
      2.0433560090702949,   2.0549659863945577,   2.066575963718821,
      2.0781859410430839,   2.0897959183673471,   2.10140589569161,
      2.1130158730158732,   2.1246258503401361,   2.1362358276643989,
      2.1478458049886622,   2.159455782312925,    2.1710657596371883,
      2.1826757369614511,   2.1942857142857144,   2.2058956916099772,
      2.2175056689342405,   2.2291156462585033,   2.2407256235827666,
      2.2523356009070294,   2.2639455782312927,   2.2755555555555556,
      2.2871655328798184,   2.2987755102040817,   2.3103854875283445,
      2.3219954648526078,   2.3336054421768706,   2.3452154195011339,
      2.3568253968253967,   2.36843537414966,     2.3800453514739228,
      2.3916553287981861,   2.4032653061224489,   2.4148752834467122,
      2.426485260770975,    2.4380952380952383,   2.4497052154195011,
      2.461315192743764,    2.4729251700680273,   2.48453514739229,
      2.4961451247165534,   2.5077551020408162,   2.5193650793650795,
      2.5309750566893423,   2.5425850340136056,   2.5541950113378684,
      2.5658049886621317,   2.5774149659863945,   2.5890249433106578,
      2.6006349206349206,   2.6122448979591835,   2.6238548752834467,
      2.6354648526077096,   2.6470748299319729,   2.6586848072562357,
      2.670294784580499,    2.6819047619047618,   2.6935147392290251,
      2.7051247165532879,   2.7167346938775512,   2.728344671201814,
      2.7399546485260773,   2.75156462585034,     2.7631746031746034,
      2.7747845804988662,   2.7863945578231291,   2.7980045351473923,
      2.8096145124716552,   2.8212244897959184,   2.8328344671201813,
      2.8444444444444446,   2.8560544217687074,   2.8676643990929707,
      2.8792743764172335,   2.8908843537414968,   2.9024943310657596,
      2.9141043083900229,   2.9257142857142857,   2.9373242630385485,
      2.9489342403628118,   2.9605442176870747,   2.9721541950113379,
      2.9837641723356008,   2.995374149659864,    3.0069841269841269,
      3.01859410430839,     3.030204081632653,    3.0418140589569163,
      3.0534240362811791,   3.0650340136054424,   3.0766439909297052,
      3.0882539682539685,   3.0998639455782313,   3.1114739229024941,
      3.1230839002267574,   3.1346938775510202,   3.1463038548752835,
      3.1579138321995464,   3.1695238095238096,   3.1811337868480725,
      3.1927437641723357,   3.2043537414965986,   3.2159637188208618,
      3.2275736961451247,   3.239183673469388,    3.2507936507936508,
      3.2624036281179136,   3.2740136054421769,   3.2856235827664397,
      3.297233560090703,    3.3088435374149658,   3.3204535147392291,
      3.3320634920634919,   3.3436734693877552,   3.3552834467120181,
      3.3668934240362813,   3.3785034013605442,   3.3901133786848074,
      3.4017233560090703,   3.4133333333333336,   3.4249433106575964,
      3.4365532879818592,   3.4481632653061225,   3.4597732426303853,
      3.4713832199546486,   3.4829931972789114,   3.4946031746031747,
      3.5062131519274375,   3.5178231292517008,   3.5294331065759637,
      3.5410430839002269,   3.5526530612244898,   3.564263038548753,
      3.5758730158730159,   3.5874829931972787,   3.599092970521542,
      3.6107029478458048,   3.6223129251700681,   3.6339229024943309,
      3.6455328798185942,   3.657142857142857,    3.6687528344671203,
      3.6803628117913831,   3.6919727891156464,   3.7035827664399092,
      3.7151927437641725,   3.7268027210884354,   3.7384126984126986,
      3.7500226757369615,   3.7616326530612243,   3.7732426303854876,
      3.7848526077097504,   3.7964625850340137,   3.8080725623582765,
      3.81968253968254,     3.8312925170068026,   3.8429024943310659,
      3.8545124716553287,   3.866122448979592,    3.8777324263038548,
      3.8893424036281181,   3.9009523809523809,   3.9125623582766438,
      3.9241723356009071,   3.93578231292517,     3.9473922902494332,
      3.959002267573696,    3.9706122448979593};
  static double magnitude_1[698368];
  static double thresholds[698368];
  static double dv[696320];
  static double b_y[176400];
  static signed char gama_flags[698368];
  emxArray_real_T *T_minus_1;
  emxArray_real_T *T_plus_1;
  double f_1[2048];
  double gama_sum[341];
  double steps_data[341];
  double bsum;
  double ex;
  double x_tmp;
  double *T_minus_1_data;
  double *T_plus_1_data;
  int steps_size[2];
  int times_of_transients_size[2];
  int i;
  int ib;
  int j;
  int k;
  int kEnd;
  int kStart;
  int lastBlockLength;
  int nblocks;
  short tmp_data[2048];
  short ii_data[341];
  boolean_T exitg1;
  /*  adjustable parameters */
  /*  40 ms */
  /*  or time_interval/dt */
  /*  prej je bilo 5 */
  /*  over how many spectogram bins we will smooth the functions */
  /* 5 najde vse dogodke */
  /*  how many time frames are considered for the threshold calculation */
  /* 3.2-pleski, tloski, snaps; 1.8-urbansound8k;2.55-profesorjev file */
  /*  controls the strength of transients to be detected */
  /*  /4 prej  */
  /*  normalize the input signal */
  ex = y[0];
  for (k = 0; k < 176399; k++) {
    x_tmp = y[k + 1];
    if (ex < x_tmp) {
      ex = x_tmp;
    }
  }
  /*  Preallocate for STFT */
  for (ib = 0; ib < 176400; ib++) {
    b_y[ib] = y[ib] / ex;
  }
  stft(b_y, s_1, f_1);
  /*  Preallocate indices_1 array */
  /*  Filter out small frequencies ( 0 - 25 Hz)  */
  lastBlockLength = 0;
  kStart = 0;
  for (i = 0; i < 2048; i++) {
    x_tmp = f_1[i];
    if ((x_tmp >= -25.0) && (x_tmp <= 25.0)) {
      lastBlockLength++;
      tmp_data[kStart] = (short)i;
      kStart++;
    }
  }
  for (ib = 0; ib < 341; ib++) {
    for (nblocks = 0; nblocks < lastBlockLength; nblocks++) {
      kStart = tmp_data[nblocks] + (ib << 11);
      s_1[kStart].re = 0.0;
      s_1[kStart].im = 0.0;
    }
  }
  for (k = 0; k < 698368; k++) {
    magnitude_1[k] = rt_hypotd(s_1[k].re, s_1[k].im);
  }
  /*  Preallocate T_minus_1 and T_plus_1 */
  /*  T- and T+ functions - razlike med amplitudami skozi čas */
  /*  For channel 1 */
  /*  Padding  */
  for (ib = 0; ib < 341; ib++) {
    memcpy(&thresholds[ib * 2048], &magnitude_1[ib * -2048 + 696320],
           2048U * sizeof(double));
  }
  diff(thresholds, dv);
  emxInit_real_T(&T_plus_1, 2);
  ib = T_plus_1->size[0] * T_plus_1->size[1];
  T_plus_1->size[0] = 2048;
  T_plus_1->size[1] = 341;
  emxEnsureCapacity_real_T(T_plus_1, ib);
  T_plus_1_data = T_plus_1->data;
  for (ib = 0; ib < 340; ib++) {
    for (nblocks = 0; nblocks < 2048; nblocks++) {
      T_plus_1_data[nblocks + 2048 * ib] = -dv[nblocks + ((339 - ib) << 11)];
    }
  }
  diff(magnitude_1, dv);
  emxInit_real_T(&T_minus_1, 2);
  ib = T_minus_1->size[0] * T_minus_1->size[1];
  T_minus_1->size[0] = 2048;
  T_minus_1->size[1] = 341;
  emxEnsureCapacity_real_T(T_minus_1, ib);
  T_minus_1_data = T_minus_1->data;
  for (ib = 0; ib < 2048; ib++) {
    T_plus_1_data[ib + 696320] = 0.0;
    T_minus_1_data[ib] = 0.0;
  }
  for (ib = 0; ib < 696320; ib++) {
    T_minus_1_data[ib + 2048] = dv[ib];
  }
  /*  sign funkcija glede na clanek ( razlika v 0 z MATLABom ! ) */
  /* [numBins, numFrames] = size(magnitude_1); */
  /*  smoothed half wave rectified T functions -> F_function */
  for (i = 0; i < 341; i++) {
    for (j = 0; j < 2048; j++) {
      kStart = (int)fmax(1.0, ((double)j + 1.0) - 7.0);
      kEnd = (int)fmin(2048.0, ((double)j + 1.0) + 7.0);
      if (kStart > kEnd) {
        ib = -1;
        nblocks = -1;
      } else {
        ib = kStart - 2;
        nblocks = kEnd - 1;
      }
      kEnd = nblocks - ib;
      for (nblocks = 0; nblocks < kEnd; nblocks++) {
        kStart = ((ib + nblocks) + 2048 * i) + 1;
        ex = T_minus_1_data[kStart];
        x_tmp = T_plus_1_data[kStart];
        f_1[nblocks] = ((double)((ex >= 0.0) - (ex < 0.0)) + 1.0) * ex +
                       ((double)((x_tmp >= 0.0) - (x_tmp < 0.0)) + 1.0) * x_tmp;
      }
      if (kEnd == 0) {
        ex = 0.0;
      } else {
        if (kEnd <= 1024) {
          kStart = kEnd;
          lastBlockLength = 0;
          nblocks = 1;
        } else {
          kStart = 1024;
          nblocks = (int)((unsigned int)kEnd >> 10);
          lastBlockLength = kEnd - (nblocks << 10);
          if (lastBlockLength > 0) {
            nblocks++;
          } else {
            lastBlockLength = 1024;
          }
        }
        ex = f_1[0];
        for (k = 2; k <= kStart; k++) {
          ex += f_1[k - 1];
        }
        for (ib = 2; ib <= nblocks; ib++) {
          kStart = (ib - 1) << 10;
          bsum = f_1[kStart];
          if (ib == nblocks) {
            kEnd = lastBlockLength;
          } else {
            kEnd = 1024;
          }
          for (k = 2; k <= kEnd; k++) {
            bsum += f_1[(kStart + k) - 1];
          }
          ex += bsum;
        }
      }
      magnitude_1[j + (i << 11)] = 0.5 * ex;
    }
  }
  emxFree_real_T(&T_plus_1);
  emxFree_real_T(&T_minus_1);
  /*  adaptive threshold calculation;  */
  for (i = 0; i < 341; i++) {
    kStart = (int)fmax(1.0, ((double)i + 1.0) - 5.0);
    kEnd = (int)fmin(341.0, ((double)i + 1.0) + 5.0);
    if (kStart > kEnd) {
      ib = 0;
      kEnd = 0;
    } else {
      ib = kStart - 1;
    }
    kStart = kEnd - ib;
    for (j = 0; j < 2048; j++) {
      if (kStart == 0) {
        ex = 0.0;
      } else {
        ex = magnitude_1[j + (ib << 11)];
        for (k = 2; k <= kStart; k++) {
          ex += magnitude_1[j + (((ib + k) - 1) << 11)];
        }
      }
      thresholds[j + (i << 11)] = 0.16363636363636364 * ex;
    }
  }
  for (ib = 0; ib < 698368; ib++) {
    gama_flags[ib] = 0;
    if (magnitude_1[ib] > thresholds[ib]) {
      gama_flags[ib] = 1;
    }
  }
  for (kEnd = 0; kEnd < 341; kEnd++) {
    kStart = kEnd << 11;
    bsum = gama_flags[kStart + 1024];
    x_tmp = gama_flags[kStart];
    for (k = 0; k < 1023; k++) {
      ib = kStart + k;
      x_tmp += (double)gama_flags[ib + 1];
      bsum += (double)gama_flags[ib + 1025];
    }
    gama_sum[kEnd] = x_tmp + bsum;
  }
  nblocks = 0;
  kStart = 0;
  exitg1 = false;
  while ((!exitg1) && (kStart < 341)) {
    if (gama_sum[kStart] > 341.33333333333331) {
      nblocks++;
      ii_data[nblocks - 1] = (short)(kStart + 1);
      if (nblocks >= 341) {
        exitg1 = true;
      } else {
        kStart++;
      }
    } else {
      kStart++;
    }
  }
  if (nblocks < 1) {
    kEnd = 0;
  } else {
    kEnd = nblocks;
  }
  times_of_transients_size[0] = kEnd;
  times_of_transients_size[1] = 1;
  for (ib = 0; ib < kEnd; ib++) {
    gama_sum[ib] = t_1[ii_data[ib] - 1];
  }
  b_diff(gama_sum, times_of_transients_size, steps_data, steps_size);
  /*  now filter out the detected transient times, that are too close to */
  /*  each other and belong to the same event. These moments are not more */
  /*  than 0.1 ms apart. */
  if (kEnd >= 1) {
    kStart = kEnd;
  } else {
    kStart = 1;
  }
  if (kEnd == 0) {
    kStart = 0;
  }
  if (kStart - 1 >= 0) {
    memset(&c_filtered_times_of_transients_[0], 0,
           (unsigned int)kStart * sizeof(double));
  }
  c_filtered_times_of_transients_[0] = gama_sum[0];
  kEnd = 0;
  if (steps_size[0] == 0) {
    lastBlockLength = -2;
  } else if (steps_size[0] > 1) {
    lastBlockLength = steps_size[0] - 2;
  } else {
    lastBlockLength = -1;
  }
  for (nblocks = 0; nblocks <= lastBlockLength; nblocks++) {
    if (steps_data[nblocks + 1] >= 0.1) {
      kEnd++;
      c_filtered_times_of_transients_[kEnd] = gama_sum[nblocks + 2];
    }
  }
  kEnd = kStart - 1;
  lastBlockLength = 0;
  for (i = 0; i <= kEnd; i++) {
    if (c_filtered_times_of_transients_[i] != 0.0) {
      lastBlockLength++;
    }
  }
  kStart = 0;
  for (i = 0; i <= kEnd; i++) {
    if (c_filtered_times_of_transients_[i] != 0.0) {
      c_filtered_times_of_transients_[kStart] =
          c_filtered_times_of_transients_[i];
      kStart++;
    }
  }
  d_filtered_times_of_transients_[0] = 1;
  d_filtered_times_of_transients_[1] = lastBlockLength;
  /*  Remove unused preallocated space */
}

/* End of code generation (transient_detector_func.c) */
