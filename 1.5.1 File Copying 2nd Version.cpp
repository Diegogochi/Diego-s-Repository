#include<stdio.h>

//Copy input to output; 2st version

int main(){
	
	int c;
	
	c = getchar();
	while ((c = getchar())!= EOF){  //!= means "Not equal to"
						// EOF means end of line
		putchar (c);
	
	}
	
}
