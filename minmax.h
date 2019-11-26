/**
 * File name: minmax.h
 * Project name: minmax, a header-only library that implements min and max
 * functions for a variable number of arguments
 * URL: https://github.com/ciubotaru/minmax
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tokyo>
 * License: General Public License, version 3 or later
 * Copyright 2017
**/

#ifndef MINMAX_H
#define MINMAX_H

#include <limits.h>		/* for max size of each data type */
#include <stdint.h>		/* for intXX_t */
#include <stdarg.h>		/* for variable arguments */
#include <assert.h>

#define minmax(count, sign, output, input) \
do{\
assert(count > 0);\
int i;\
output = input[0];\
for (i = 1; i < count; i++) {\
if ((sign == 1 && output < input[i]) || (sign == 0 && output > input[i]))\
output = input[i];\
}\
}while(0)

//#define minmax_count(...) (size_t) (sizeof((int[]){__VA_ARGS__})/sizeof(int))

#define minmax_count(...) minmax_count_(__VA_ARGS__,minmax_rseq_n())
#define minmax_count_(...) \
	minmax_arg_n(__VA_ARGS__)
#define minmax_arg_n( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
         _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
         _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
         _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
         _101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
         _111,_112,_113,_114,_115,_116,_117,_118,_119,_120, \
         _121,_122,_123,_124,_125,_126,_127,N,...) N
#define minmax_rseq_n() \
         127,126,125,124,123,122,121,120, \
         119,118,117,116,115,114,113,112,111,110, \
         109,108,107,106,105,104,103,102,101,100, \
         99,98,97,96,95,94,93,92,91,90, \
         89,88,87,86,85,84,83,82,81,80, \
         79,78,77,76,75,74,73,72,71,70, \
         69,68,67,66,65,64,63,62,61,60, \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

#ifdef INT8_MAX
inline static int8_t minmax_int8_(unsigned char sign, size_t count, int8_t *arr)
{
	int8_t output;
	minmax(count, sign, output, arr);
	return output;
}
#define max_int8(...) minmax_int8_(1, minmax_count(__VA_ARGS__), (int8_t[]) {__VA_ARGS__})
#define min_int8(...) minmax_int8_(0, minmax_count(__VA_ARGS__), (int8_t[]) {__VA_ARGS__})
#endif

#ifdef INT16_MAX
inline static int16_t minmax_int16_(unsigned char sign, size_t count, int16_t *arr)
{
	int16_t output;
	minmax(count, sign, output, arr);
	return output;
}
#define max_int16(...) minmax_int16_(1, minmax_count(__VA_ARGS__), (int16_t[]) {__VA_ARGS__})
#define min_int16(...) minmax_int16_(0, minmax_count(__VA_ARGS__), (int16_t[]) {__VA_ARGS__})
#endif

#ifdef INT32_MAX
inline static int32_t minmax_int32_(unsigned char sign, size_t count, int32_t *arr)
{
	int32_t output;
	minmax(count, sign, output, arr);
	return output;
}
#define max_int32(...) minmax_int32_(1, minmax_count(__VA_ARGS__), (int32_t[]) {__VA_ARGS__})
#define min_int32(...) minmax_int32_(0, minmax_count(__VA_ARGS__), (int32_t[]) {__VA_ARGS__})
#endif

#ifdef INT64_MAX
inline static int64_t minmax_int64_(unsigned char sign, size_t count, int64_t *arr)
{
	int64_t output;
	minmax(count, sign, output, arr);
	return output;
}

inline static int64_t max_int64(int64_t arg1, ...);

#define max_int64(...) minmax_int64_(1, minmax_count(__VA_ARGS__), (int64_t[]) {__VA_ARGS__})
#define min_int64(...) minmax_int64_(0, minmax_count(__VA_ARGS__), (int64_t[]) {__VA_ARGS__})
#endif

#define maxs(...) minmax_short_(1, minmax_count(__VA_ARGS__), (short[]) {__VA_ARGS__})
#define mins(...) minmax_short_(0, minmax_count(__VA_ARGS__), (short[]) {__VA_ARGS__})
#define maxi(...) minmax_int_(1, minmax_count(__VA_ARGS__), (int[]) {__VA_ARGS__})
#define mini(...) minmax_int_(0, minmax_count(__VA_ARGS__), (int[]) {__VA_ARGS__})
#define maxl(...) minmax_long_(1, minmax_count(__VA_ARGS__), (long[]) {__VA_ARGS__})
#define minl(...) minmax_long_(0, minmax_count(__VA_ARGS__), (long[]) {__VA_ARGS__})
#define maxll(...) minmax_ll_(1, minmax_count(__VA_ARGS__), (long long[]){__VA_ARGS__})
#define minll(...) minmax_ll_(0, minmax_count(__VA_ARGS__), (long long[]){__VA_ARGS__})

inline static short minmax_short_(unsigned char sign, size_t count, short *arr)
{
	short output;
	minmax(count, sign, output, arr);
	return output;
}

inline static int minmax_int_(unsigned char sign, size_t count, int *arr)
{
	int output;
	minmax(count, sign, output, arr);
	return output;
}

inline static long minmax_long_(unsigned char sign, size_t count, long *arr)
{
	long output;
	minmax(count, sign, output, arr);
	return output;
}

inline static long long minmax_ll_(unsigned char sign, size_t count, long long *arr)
{
	long long output;
	minmax(count, sign, output, arr);
	return output;
}

#endif
