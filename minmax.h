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

#define minmax_count(...) (size_t) (sizeof((int[]){__VA_ARGS__})/sizeof(int))

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
