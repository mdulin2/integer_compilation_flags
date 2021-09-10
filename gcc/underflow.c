
/*
Cause an integer underflow. Use the '-trapv' flag to catch it and crash.

gcc underflow.c -o underflow -O0 -ftrapv -ggdb
*/
#include <stdio.h>
int main(){

	int a = -2147483648; // Smallest signed integer value
	a = a - 1;  // Crash here
	printf("Value: %d\n", a);
}
