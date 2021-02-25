/* Exercise 1.9 Write a program to cpy its input to its output
, replacing each string of one or more blanks by a single blank */

#include<stdio.h>

int main(){
	int t, br;
	br = 0;
	
	printf("Type something if you want, please; then press CTRL+D to finish the program \n");
	
	while((t = getchar()) != EOF)
		if (t == ' '){
			if (br){
				br = 1;
				putchar(t);
			}
		} else {
			br = 0;
			putchar(t);
		} 
	return 0;	
	
}
