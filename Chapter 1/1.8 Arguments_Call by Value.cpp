#include<stdio.h>

//Test power function 

int power (int m, int n);

int main(){
	int i;
	
	printf("These numbers are the power from 0 to 9:\n");
	for (i = 0; i < 10; ++i)
		printf("%d, %d, %d\n", i, power(2,i), power(-3,i));
	return 0;	
	
}

// power: raise base to n-th power; n >= version 2;
int power (int base, int n){
	
	int p;

	for (p = 1; n > 0; --n)
			p = p * base;
	return p;
}
