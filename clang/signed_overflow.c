
/*
The overflow should work on addition, multiplication and subtraction operations.- UBSAN: https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html

clang signed_overflow.c -o signed_overflow -fsanitize=signed-integer-overflow -O0 -ggdb
*/
#include <stdio.h>
#include <float.h>

int main(){
	int a = 0x7FFFFFFF; 
	a = a + 1; 
	printf("Value: %d\n", a);
}
