#include <float.h>
#include <stdio.h>

/*
Like integers, floats and doubles can overflow as well! However, there is no intramention that will dynamically catch this when it overflows to INF. 

clang float_overflow.c -o float_overflow -ggdb -O0 -fsanitize=integer -ftrapv
*/

int main()
{
	float f = (float) FLT_MAX;

	f *= (1+FLT_EPSILON);
	printf("Overflows value: %f\n",f);

	return 0;
}
