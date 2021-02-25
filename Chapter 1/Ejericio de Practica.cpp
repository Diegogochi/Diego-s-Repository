//crear un programa que haga una sucesion de 0 a 100 con el valor inicial siempre al cuadrado

#include<iostream>
#include<math.h>

int main(){
	int izq, der;
	int inicial, salto, tope;
	
	inicial = 0;
	salto = 10;
	tope = 100; 
	
	izq = inicial;
	while(izq <= tope ){
		der = (pow (izq,2));
		printf("%d\t%d\n",izq, der);
		izq = izq + salto;
	}
	
}
