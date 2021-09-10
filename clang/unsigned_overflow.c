
/*
The overflow should work on addition, multiplication and subtraction operations.- UBSAN: https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html

NOTE: This does NOT exist in gcc. Only signed works in gcc while clang supports both. 

clang unsigned_overflow.c -o unsigned_overflow -fsanitize=unsigned-integer-overflow -O0 -ggdb

 -ftrapv works in both clang and GCC
*/
#include <stdio.h>
#include <float.h>

int main(){
	unsigned int a = 0xFFFFFFFF; //Unisgned int
	//double a = DBL_MAX - 1; // Float does not work
	a = a + 1; 
	printf("Value: %d\n", a);
}
