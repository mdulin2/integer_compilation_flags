
/*
Going from unsigned to signed value and vice versa
Both the flags at the end will catch this POTENTIAL bug.

gcc conversion.c -o conversion -O0 -Wsign-conversion -Wconversion
*/
int a = -1;

unsigned int c = 0xFFFFFFFF;

int main(){

        unsigned int b = a;
        int d = c;
        a += 1;
}

