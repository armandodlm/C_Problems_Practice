#include <stdio.h>

typedef struct bitVector{
	unsigned a : 1;
	unsigned b : 1;
	unsigned c : 1;
	unsigned d : 1;
}bitVector;

int main(){
	bitVector bv;
	bv.a |= 1;
	bv.b = 0;
	bv.c |= 1;
	bv.d = 0;

	printf("%01u %01u %01u %01u \n",bv.a,bv.b,bv.c,bv.d);
}