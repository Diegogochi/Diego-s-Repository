// Exercise 1.8 Write a program to count blanks, tabs, and newlines.

#include<stdio.h>

 main(){
	int c,bl,tl,nl;
	
	bl = 0;
	tl = 0;
	nl = 0;
	
	printf("Input some characters, the press CTRL+D.\n");
	while((c = getchar ()) != EOF)
		if (c == ' ') ++bl;
			else if (c == '\t') ++tl; 
				else if (c == '\n') ++nl;
				
	printf("The numbers of blanks is %d, the numbers of tabs is %d, the  numbers of newlines is %d.\n", bl, tl, nl);


}
