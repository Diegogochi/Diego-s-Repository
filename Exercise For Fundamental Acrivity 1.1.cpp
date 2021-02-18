// Provide the exact printput of each of the following program, substituting the upper-case by the numeric contrast

#include<stdio.h>

int main(){
	float x;
	int y,z;
	
	x = 2.195;
	y = 16;
	z = 2;
	
	while (x <= y){
		
		x = x/z;
		y = y*x;
	}
		
	printf("%.2f, %d\n", x, y);
}
