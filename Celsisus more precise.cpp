// print Fahreinheit-Celsius table for fahr = 0, 20, ..., 300 MORE ACURRATE

#include<stdio.h>

 int main(){
	float fahr, cel;
	float lower, upper, step;

	lower = 0; //Lower limit of temperature scale
	upper = 300; //Upper limit
	step= 20; //Step size

	fahr = lower;
	while (fahr <= upper){
		cel = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, cel);
		fahr = fahr + step;
	}


}
