
/*
Cause an integer overflow. Use the '-trapv' flag to catch it and crash.
NOTE: If 'a' is unsigned, this validation does NOT work for some reason? HUH!?!?!
- https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html 

The overflow should work on addition, multiplication and subtraction operations. 

gcc overflow.c -o overflow -O0 -ftrapv -ggdb
*/
#include <stdio.h>
#include <float.h>

int main(){
	int a = 0x7FFFFFFF; 
	a = a + 1; 
	printf("Value: %d\n", a);
}
