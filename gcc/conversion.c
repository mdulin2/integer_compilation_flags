
/*
Going from unsigned to signed value and vice versa
Both the flags at the end will catch this POTENTIAL bug.

gcc conversion.c -o conversion -O0 -Wsign-conversion -Wconversion
*/
int a = 0;

int c = 1;

int main(){

	unsigned int b = a;
	unsigned int d = c; 
	a += 1; 
}
