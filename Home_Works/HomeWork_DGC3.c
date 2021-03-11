#include<stdio.h> 
#include<ctype.h>

#define FALSE 0
#define TRUE 1
#define NUM 2
#define DONE 5
#define ONE 12

main () {  
	
	int c, skip, numb, all, quo;
	
	while ((c = getchar()) != EOF) {
		if ((c == '"' || c == '\'') && quo == FALSE) { //start quotes
			all = TRUE;
			quo = ONE;
		} else if ((c == '"' || c == '\'' || c == '\n') && quo == ONE) { //Quotes to finish a line
			all = FALSE; 
			quo = FALSE;
		}	
		if (c == '<') //start parenthesis
			all = 1;
		else if ((c == '>' || c == '\n') && all == 1) //end parenthesis
			all = 2;
		if (c == '(') //start parenthesis
			all = 3;
		else if ((c == ')' || c == '\n') && all == 3) //end parenthesis
			all = 4;
		if (c == '{') //start parenthesis
			all = 5;
		else if ((c == '}' || c == '\n') && all == 5) //end parenthesis
			all = 6;
		if (c == '[') //start parenthesis
			all = 7;
		else if ((c == ']' || c == '\n') && all == 7) //end parenthesis
			all = 8;
	
		if (c == ',' || c == '.' || c == ':' || c == ';' || c == '?' || c == '!' || c == '_') //remove punctuation
			skip = FALSE;
		else 
			skip = TRUE;
			
		if ((all % 2) == FALSE) { //chages the digits to X
			if (isdigit(c))
				skip = NUM;
			if (!isdigit(c) && numb == DONE)
				numb = TRUE;
			
			if (skip == TRUE)
				putchar (c);
			else if (skip == NUM && numb != DONE) {
				putchar ('X');
				numb = DONE;
			}
		}
		
		if ((all % 2) != FALSE && skip == TRUE)//prints everything exept puntuation
			putchar (c);		
	} 
}  //Helped by my friend Rogelio Salinas
