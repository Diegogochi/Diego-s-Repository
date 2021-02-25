/*1.10 Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. 
this makes tabs and backspaces visible in an unambiguous way.*/

#include<stdio.h>

int main(){
	int c, tl, bs, bsh;
	
	tl = 0;
	bs = 0;
	bsh = 0;
	
	printf("Type something please, then use CTRL+D to finish the program\n");
	while((c = getchar()) != EOF)
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else 
			printf("%c", c);	
	
	
	
	
	
	return 0;
}
