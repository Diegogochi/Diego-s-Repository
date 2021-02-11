// print Fahreinheit-Celsius table for fahr = 0, 20, ..., 300 

#include<stdio.h>

int main(){
	int fahr, cel;
	int lower, upper, step;
	
	lower = 0; //Lower limit of temperature scale
	upper = 300; //Upper limit
	step= 20; //Step size
	
	fahr = lower;
	while (fahr <= upper){
		cel = 5 * (fahr-32) / 9;
		printf("%3d %6d\n", fahr, cel);
		fahr = fahr + step;
	}
	
	
}
