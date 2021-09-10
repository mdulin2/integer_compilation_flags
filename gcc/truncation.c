
/*
Going from a bigger integer to a small one and vice versa.
Both the flags at the end will catch this POTENTIAL bug.

Only the line 'int d = c;' is considered to be a potential bug because of a truncation though. The line 'long long b = a' is considered to be safe. 
gcc truncation.c -o truncation -Wconversion -Wsign-conversion 
*/
int a = 0;

long long c = 0;

int main(){

	long long b = a;
	int d = c; 
	a += 1; 
}
