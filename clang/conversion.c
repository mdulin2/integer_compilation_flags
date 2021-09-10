
/*
Going from unsigned to signed value and vice versa
Both the flags at the end will catch this POTENTIAL bug within clang. 

The flag '-fsanitize=implicit-integer-truncation' will catch this issue in real time if something bad is going on.

clang conversion.c -o conversion -O0 -Wsign-conversion -Wconversion -fsanitize=implicit-integer-truncation
*/
int a = 0;

unsigned int c = 1;

int main(){

	unsigned int b = a;
	int d = c; 
	a += 1; 
}
