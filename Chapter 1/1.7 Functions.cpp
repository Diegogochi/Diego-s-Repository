#include<stdio.h>

int power (int m, int n);

//Test power function 

int main(){
	int i;
	
	printf("These numbers are the power from 0 to 9:\n");
	for (i = 0; i < 10; ++i)
		printf("%d, %d, %d\n", i, power(2,i), power(-3,i));
	return 0;	
	
}

// power: raise base to n-th power; n >=
int power (int base, int n){
	
	int i,p;
	
	p = 1;
	for (i = 1; i<= n; ++i)
			p = p * base;
	return p;
}
