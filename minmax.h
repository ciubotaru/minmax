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

#define count(...) (int) (sizeof((int[]){__VA_ARGS__})/sizeof(int))

#if SHRT_MAX == INT16_MAX
#define maxs(...) (short) _max_int16(count(__VA_ARGS__), __VA_ARGS__)
#define mins(...) (short) _min_int16(count(__VA_ARGS__), __VA_ARGS__)
#elif SHRT_MAX == INT32_MAX
#define maxs(...) (short) _max_int32(count(__VA_ARGS__), __VA_ARGS__)
#define mins(...) (short) _min_int32(count(__VA_ARGS__), __VA_ARGS__)
#endif

#if INT_MAX == INT16_MAX
#define maxi(...) (int) _max_int16(count(__VA_ARGS__), __VA_ARGS__)
#define mini(...) (int) _min_int16(count(__VA_ARGS__), __VA_ARGS__)
#elif INT_MAX == INT32_MAX
#define maxi(...) (int) _max_int32(count(__VA_ARGS__), __VA_ARGS__)
#define mini(...) (int) _min_int32(count(__VA_ARGS__), __VA_ARGS__)
#endif

#if LONG_MAX == INT32_MAX
#define maxl(...) (long) _max_int32(count(__VA_ARGS__), __VA_ARGS__)
#define minl(...) (long) _min_int32(count(__VA_ARGS__), __VA_ARGS__)
#elif LONG_MAX == INT64_MAX
#define maxl(...) (long) _max_int64(count(__VA_ARGS__), __VA_ARGS__)
#define minl(...) (long) _min_int64(count(__VA_ARGS__), __VA_ARGS__)
#endif

#if LLONG_MAX == INT64_MAX
#define maxll (long long) max_int64
#define minll (long long) min_int64
#endif

#define max_int8(...) (int8_t) _max_int8(count(__VA_ARGS__), __VA_ARGS__)
#define min_int8(...) (int8_t) _min_int8(count(__VA_ARGS__), __VA_ARGS__)
#define max_int16(...) (int16_t) _max_int16(count(__VA_ARGS__), __VA_ARGS__)
#define min_int16(...) (int16_t) _min_int16(count(__VA_ARGS__), __VA_ARGS__)
#define max_int32(...) (int32_t) _max_int32(count(__VA_ARGS__), __VA_ARGS__)
#define min_int32(...) (int32_t) _min_int32(count(__VA_ARGS__), __VA_ARGS__)
#define max_int64(...) (int64_t) _max_int64(count(__VA_ARGS__), __VA_ARGS__)
#define min_int64(...) (int64_t) _min_int64(count(__VA_ARGS__), __VA_ARGS__)

inline static int8_t _max_int8(int count, ...)
{
	int i;
	int8_t tmp;
	va_list args;
	va_start(args, count);
	int8_t output = va_arg(args, int); /** int8_t is promoted to int */
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int);
		if (tmp > output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int8_t _min_int8(int count, ...)
{
	int i;
	int8_t tmp;
	va_list args;
	va_start(args, count);
	int8_t output = va_arg(args, int);
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int);
		if (tmp < output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int16_t _max_int16(int count, ...)
{
	int i;
	int16_t tmp;
	va_list args;
	va_start(args, count);
	int16_t output = va_arg(args, int); /** int16_t is promoted to int */
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int);
		if (tmp > output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int16_t _min_int16(int count, ...)
{
	int i;
	int16_t tmp;
	va_list args;
	va_start(args, count);
	int16_t output = va_arg(args, int);
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int);
		if (tmp < output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int32_t _max_int32(int count, ...)
{
	int i;
	int32_t tmp;
	va_list args;
	va_start(args, count);
	int32_t output = va_arg(args, int32_t);
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int32_t);
		if (tmp > output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int32_t _min_int32(int count, ...)
{
	int i;
	int32_t tmp;
	va_list args;
	va_start(args, count);
	int32_t output = va_arg(args, int32_t);
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int32_t);
		if (tmp < output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int64_t _max_int64(int count, ...)
{
	int i;
	int64_t tmp;
	va_list args;
	va_start(args, count);
	int64_t output = va_arg(args, int64_t);
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int64_t);
		if (tmp > output)
			output = tmp;
	}
	va_end(args);
	return output;
}

inline static int64_t _min_int64(int count, ...)
{
	int i;
	int64_t tmp;
	va_list args;
	va_start(args, count);
	int64_t output = va_arg(args, int64_t);
	for (i = 1; i < count; i++) {
		tmp = va_arg(args, int64_t);
		if (tmp < output)
			output = tmp;
	}
	va_end(args);
	return output;
}

#endif
