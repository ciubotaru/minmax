/**
 * File name: tests/test2.c
 * Project name: minmax, a header-only library that implements min and max
 * functions for a variable number of arguments
 * URL: https://github.com/ciubotaru/minmax
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tokyo>
 * License: General Public License, version 3 or later
 * Copyright 2017
**/

#include <limits.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <minmax.h>
#include <time.h>

/* Testing mini() and maxi() */

int main()
{
	srand((unsigned)time(NULL));
	unsigned int i;		//counter
	unsigned int len = 80;
	char *msg = "Testing mini() and maxi()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	unsigned int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");

	int limit = 5;
	int j;

	int numbers[limit];
	for (i = 0; i < limit; i++) {
		for (j = 0; j < (sizeof(int) * 8); j++) {
			if (rand() % 2)
				numbers[i] |= (1U << j);
			else
				numbers[i] &= ~(1U << j);
		}
	}

	int max =
	    maxi(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	int max_check = numbers[0];
	for (i = 1; i < limit; i++)
		if (max_check < numbers[i])
			max_check = numbers[i];
	if (max != max_check) {
		printf("%s\n", failed);
		return 1;
	}

	int min =
	    mini(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	int min_check = numbers[0];
	for (i = 1; i < limit; i++)
		if (min_check > numbers[i])
			min_check = numbers[i];
	if (min != min_check) {
		printf("%s\n", failed);
		return 1;
	}
	printf("%s\n", passed);
	return 0;
}
