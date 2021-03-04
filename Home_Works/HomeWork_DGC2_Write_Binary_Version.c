#include<stdio.h>
#define k 29

int one (int by);

int main(){
	
	int i, count = 0;
	int d ,deci;
	int bin[8];
	//'i' will be used  the for, 'num' will be the number saved, 'count' will count by how many numbers is it divided the 'num'
	
	
	for (i = 1;i <= k; ++i){
		if (k%i == 0){	//Here the num will be divided by all numbers in the loop
			count++;
		}
	}
	
	if(count>2){ //The num can be divided by more than 2 numbers
		printf("The number is a compound\n");
	}
	else{ 		//The number can´t be divided by more than 2 numbers
		printf("The number is a prime\n");	
	}
	
	
	
	
	printf("Type a number to be convert it to binary: ");
	scanf("%d", &deci);	
	
	for(d = 0; d < 8; d++)
	{
		bin[d] = deci % 2;
		deci /= 2;
		
	}
	printf("The binary number is: %h", &bin);
	
	for(d = 7; d >= 0; d--)
	{
		printf("%d",bin[d]);

	} 
	
	
	
	
}

