/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_detect_transients_info.c
 *
 * Code generation for function 'detect_transients'
 *
 */

/* Include files */
#include "_coder_detect_transients_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced564d4fd440189ed5c57851ba31cac9bf405920211e51c0dd44d98dbb6ac098a1b4"
      "6f6997ce4ce94c770b5712aefe0d8f7af1e4aff0ea9f91d28fdd1d32"
      "29a158d8e87b79fbced3f679e69dce3345b5f6db1a42e8314ac26f24f9515a6b69be87a6"
      "43c66b69be2fd559cca1fad47319fe25cd26a302229114d420903f69",
      "31e252838afeb10f2800cebc21581788ed7ad07709f4268bedb8225b13505ec4507cfdca"
      "01f3b0171214387cacd09b2cf27e7c53ccb77ec57eb415fdd024fcd3"
      "e667dd61047488676bebc4109eb18f8dd07219f603360053e826b3001f00c51019c4f740"
      "b7409c8f63111894bb40055f2492fea8a4fe8502fd199e4bc0892616",
      "603ba466ae63afa48e074a1d0962b170df839b5bb78e926f1abfdeba29ba75be7a45fd9a"
      "bfa27e398fef7f7891bfff38b3e35c15dfd269a35e255f16b7c55776"
      "df3d53f06912de8e3658683bcbdd9396b3f6a2b57df4e67d78f07aaca35bc053a40329ea"
      "aade3febfbb8ec77d028d09fe1a6c73870d16523083a767fc4d2f159",
      "f5dfbf7b6e5eead6a573734fa1efa6fce277e379a5fe9bc5bfc25795ffd29591371cf065"
      "1e0cd7a3a50f8cb53ebefbefbf77e7ffd72fa95fd52f4dca662852b1"
      "f10180f96df9eed7927c2d25df347e4ddf95bab448aaf2875f15ffefe2273fe7abe4cb62"
      "56fdf6a9824f93f09d669bbeb4569afd0dbade1b74e9ee6aa73940b3",
      "efb77f00f867311a",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4488U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("detect_transients"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString("/home/eminaf/matlab_audio_project/"
                                    "code_gen_example/detect_transients.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739437.66372685181));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2599560 (R2023b) Update 8"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("WcKOE0A8MiWyw8xYNvquWD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_detect_transients_info.c) */
