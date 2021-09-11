#include <limits.h>
/*
Going from a bigger integer to a small one and vice versa. For Clang, there are two UBSAN flags that we want to set: 
- implicit-unsigned-integer-truncation
- implicit-signed-integer-truncation

The first one catches unsigned to unsigned truncations. The latter does everything else, at run time.  When you run this program, a runtime error should be thrown because of the truncation issue with actual values. 

Only the line 'int d = c;' is considered to be a potential bug because of a truncation though. The line 'long long b = a' is considered to be safe. 
gcc truncation.c -o truncation -Wconversion -Wsign-conversion 

This happens dynamically though! In gcc, there is only support for a STATIC check. '-Wconversion' is supported for clang as well for checking this statically. 

clang-11 truncation.c -o truncation -fsanitize=implicit-unsigned-integer-truncation,implicit-signed-integer-truncation -Wconversion -O0
*/
int a = 0x0;

//long long c = LONG_MAX;
long long c = 0x7FFFFFFF80000000;

int main(){

	long long b = a;
	int d = c; // Truncation bug
	a += 1; 
}
