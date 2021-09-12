#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// gcc NaN_inf.c -o NaN_inf -ggdb -O0 -lm

/*
Floating point numbers in C are real weird! Unlike integers wrapping around being
the weirdest thing, floats representation with powers makes things go crazy. 
- https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html

Floating point numbers are represented by three parts: 
- Mantissa (frational portion) 
- Base 
- Exponent

This representation can be seen below: 
bit  31 30    23 22                    0
     S  EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM
- S for the 'sign'
- E for the exponent
- M: The fractional portion 

This representation does have a few quirks: 
- 0 can be represented twice with this (both negative and positive zero) 
- inf: 0 11111111 00000000000000000000000
- neg intf: 1 11111111 00000000000000000000000
- nan: 0 11111111 10000000000000000000000
- -nan: 1 11111111 10000000000000000000000

 1.17549435e-38 through 3.40282347e+38 can be represented as floats, for this reason.
Doubles can store 1.7976931348623157e+308 to 2.2250738585072014e-308


Programming with floats in C is VERY challenging: 
- Precision is complicated
- Loss of significance

The '==' operapter is confusing... it will match for a bit by bit representation. However, this MAY not be what we want. Commonly, programmers do '#define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)' to do an 'approximate' check on floating point values. THe take home message is that when you're defining how close is close enough, you need to talk about how many significant digits you want to match. Answering this question might require some experimentation; try out your algorithm and see how close "equal" results can get. 


Having your decimals cut off at some point wreaks a surprising amount of havoc with mathematics. "Loss of significance" refers to a class of situations where you end up inadvertently losing precision (discarding information) and potentially ending up with laughably bad results. often a large number of small terms can make a significant contribution to a sum. 

- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html
- https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)FloatingPoint.html
*/

/*
First, not a number (NaN) is possible! NaN is unordered and does not equal ANYTHING.
NaN does not equal NaN even, which is wild. There are a few ways to produce it: 
- Modify a number directly to get the representation of it
- Log(0) or other bad math operations such as float(0)/float(0)
- Use the GCC NAN macro.
- Math on things that does not make sense
- Math with infinity: 0 * inf, inf - inf

To check if something is NaN, then just use the 'isnan' function from math.h

*/
void NaN(){

	// Sqrt of -1 is not a number (NaN)
	double j = -1;
	double NaN_sqrt = sqrt(j); // Imaginary number
	double zerod = 0.0/0.0; // Crashes as ints but NOT as floats. 

	printf("NaN via sqrt: %f\n", NaN_sqrt); // -nan
	printf("NaN via 0 divisor: %f\n", zerod); // -nan
	printf("NaN via macro: %f\n", NAN); // nan

	printf("NaN == NaN: %d\n", NAN == NAN); // False! All math with NaN is false
}

/*
According to the floating point spec, the number infinity is possible! 
In the world of maths, this is just a VERY large value. There are a few
ways to get it: 
- 'inf' itself as a math literal 
- Overflowing or underflowing into inf
- Divide by 0
- log(0)

*/
void infinity(){
	//Log of 0 is negative infinity
	double neg_inf = log(0);

	// Would be infinity...
	float pos_inf = 1.0/0.0;

	float overflow = ((float) FLT_MAX) * (1 + FLT_EPSILON);
	printf("Log(0): %f\n", neg_inf);
	printf("1f/0f: %f\n", pos_inf);
	printf("Overflow: %f\n", overflow);
}

int main(){

	NaN();
	infinity();

}
