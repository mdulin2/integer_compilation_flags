#include <limits.h>
#include <float.h>
/*
Float truncation is NOT caught by the compile time checks of Clang. The flag '-fsanitize=float-cast-overflow' only catches conversions from floats to integers that may cause issues but NOT double to float issues. 

Only the line 'float d = c;' is considered to be a potential bug because of a truncation though. The line 'double b = a' is considered to be safe. 
gcc truncation.c -o truncation -Wconversion -Wsign-conversion 

clang-11 float_truncation.c -o float_truncation -fsanitize=integer -ggdb -O0 -Wconversion
*/
float a = 0x0;

//long long c = LONG_MAX;
double c = DBL_MAX;

int main(){

	double b = a;
	float d = c; // Truncation bug that goes to infinity
	a += 1; 
}
