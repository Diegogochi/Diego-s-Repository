#include<stdio.h>
#include<math.h>
#define BASE 13

int main(){
	int a = 3600 ;
	int d = log(a)/log(BASE)+1;
	
	printf("%d needs %d digits in base %d\n", a, d, BASE);
	
	
	
	
	
	
	
	return 0;
}
