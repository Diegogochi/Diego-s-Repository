//Homework 4
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100  /*OPTIONS*/
enum opts { NUM = '0', MTH, SIN, COS, TAN, EXP, SQR, POW, DUP, NONE, SWP, CLR, PNT };

void 	push(double); 				//Saves number
double 	pop(void); 					//Takes out the number
int 	getop(char []); 			//Collect the  characters, numbers or operands
int 	getcharf(void); 			//Takes the input
void 	ungetch(int); 				//Gets last unsaved charracter
int 	options(int, char[]); 		//Check if theres any function or command
int 	strinx(char s[], char t[]); //Functions

double 	val[MAX]; 					//stack
int 	sp = 0; 					//val counter
char 	buf[MAX]; 					//last characters
int 	bufp = 0; 					//buf counter
char 	var;						//variable
double 	variables[1000]; 			//assign 1 digit variables
int 	operation1, operation3;		//indicators to variables
double  operation2, operation4; 	//for operations

// Reverse Polish Calculator 
main() {

	int c; 
	char chars[MAX];
											
	printf("#ALLOW OPERATIONS#\n");		//MENU
	printf("\t+ = addition\n");
	printf("\t- = substraction\n");
	printf("\t* = multplication\n"); 
	printf("\t/ = division\n"); 
	printf("\t%% = division residue\n");
	printf("\tsen = sine\n");
	printf("\tcos = cosine\n");
	printf("\ttan = tangent\n");
	printf("\texp = exponential\n");
	printf("\tsqrt = square root\n");
	printf("\tpow = power\n");
	printf("#COMMANDS#\n");
	printf("\tpx = print the top value\n");
	printf("\tdup = duplicate the top value\n");
	printf("\tsw = swap the ");
	printf("\ttop 2 values\n");
	printf("\tcl = clear stack\n");
	printf("\tans = use previous answer\n");
	
	while ((c = getop(chars)) != EOF) {
		switch (c) {
			
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': operation2 = pop(); push(pop() - operation2); break;
			case '/': operation2 = pop(); 
				operation2 != 0.0 ? push(pop() / operation2) : printf("Error: Zero divisor\n"); break;
			case '%': operation2 = pop(); 
				operation2 != 0 ? push(((int) pop()) % ((int) operation2)) : printf("Error: Zero divisor\n"); break;  
			case CLR: sp = 0; break;
			case SIN: push(sin(pop())); break;
			case COS: push(cos(pop())); break;
			case TAN: push(tan(pop())); break;
			case EXP: push(exp(pop())); break;
			case SQR: push(sqrt(pop())); break;
			case NUM: push(atof(chars)); break;
			case DUP: operation2 = pop(); push(operation2); push(operation2); break;
			case POW: operation2 = pop(); push(pow(pop(), operation2)); break;
			case PNT: operation2 = pop(); printf("\t%g\n", operation2); push(operation2); break;
			case SWP: operation2 = pop(); operation4 = pop(); push(operation2); push(operation4); break;
			case '\n': printf("=\t%.8g\n", pop()); operation1 = 0; operation3 = 0; var = 0; break;
			default: if(chars[0] != '=' && strlen(chars) > 1 && variables[var] == 0)
						printf("error: unknown command %s\n", chars); break;
		}
	}
	
	return 0;
} 

void push(double f) {
	
	int ops;
	if (sp < MAX)
		val[sp++] = f;
	else
		printf("Error: Full Stack, can't push %g\n", f);
	
	if(operation1 && var != 0) {
		if(variables[var] == 0 || operation3 == 1)
			variables[var] = f;
		else {
			printf("[Warning] There is already a value in the variable: %c\n", var);
			printf("Are you sure you want to change its value? 0.- NO 1.- YES\n");
			scanf("%i", &ops);
			if(ops)
				 variables[var] = f;
		}
	operation1 = 0;		
	}		
}

double pop(void) {
	
	variables['$'] = val[sp - 1];
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: Empty Stack\n");
		return 0.0;
	}
	
} 

int getop(char chars[]) {

	int i, c;	
	
	while ((chars[0] = c = getcharf()) == ' ' || c == '\t');
	chars[1] = '\0';

	i = 0;
	if (c == '-')                     
		if (!isdigit(chars[++i] = c = getcharf())) {
			ungetch(c);               
			c = chars[0];
		}
	
	if (c == ':') {
		chars[++i] = c = getcharf();
		operation3 = 1;
	}
	
	if (c == '=') {
		chars[++i] = c = getcharf();
		operation1 = 1;
	}
	
	if (isalpha(c))
		return options(c, chars);
		
	if (!isdigit(c) && c != '.')
		return c; 
	
	if (isdigit(c)) {
		while (isdigit(chars[++i] = c = getcharf()));
	}
	if (c == '.') 
		while (isdigit(chars[++i] = c = getcharf()));

	if (c != EOF)
		ungetch(c);
	
	return NUM;
	
}

int getcharf(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();
	
}

void ungetch(int c) {

	if (bufp >= MAX)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

int options(int c, char chars[]) {
	
	int i = 0, o;
	double operation2, n = 0;
	
	chars[i] = c;
	while (isalpha(chars[++i] = c = getcharf()));
	chars[i] = '\0';
	ungetch(c);
	
	if(i == 1)
		var = tolower(chars[0]);
	else 
		var = 0;
	if(variables[var] != 0)
		push(variables[var]);
	if(strinx(chars, "ans")) {
		push(variables['$']);
		var = '$';
	}
	
	if (strinx(chars, "sin"))
		return SIN;
	if (strinx(chars, "cos"))
		return COS;
	if (strinx(chars, "tan"))
		return TAN;
	if (strinx(chars, "exp"))
		return EXP;		
	if (strinx(chars, "sqrt"))
		return SQR;
	if (strinx(chars, "pow"))
		return POW;
	if (strinx(chars, "dup"))
		return DUP;
	if (strinx(chars, "sw"))
		return SWP;
	if (strinx(chars, "cl"))
		return CLR;
	if (strinx(chars, "px"))
		return PNT;
	
	return NONE;
}

int strinx(char s[], char t[]) {
	
	int i, k;
	
	for (i = 0, k = 0; t[k] != '\0' && s[i] == t[k]; i++, k++);
		if (k > 0 && t[k] == '\0' && s[i] == '\0')
			return i + 1;

	return 0;
}
