#include <stdio.h>
#include "buscaminas.h"

int main() {
	
	extern char hash[CONTL][CONTL];
	int pos, lett, c; //numero de casilla y letra de arriba	
	int flag = 1, i, a, b;
	
	bombs(); // Genera bombas y numeros en su posicion
	forloop(i, CONTL*CONTL) //Poner numero a las minas cercanas
		neighbours(i); 
	forloop(i, CONTL*CONTL) //Crea los arrays
		hash[i/10][i%10] = '#';
	/*RULES*/
	printf("\tComo jugar\n:");
	printf("Ponga el numero y la fila de la columna para abrirla.\n");
	printf("Ejemplo: \"c3\" or \"3c\"Para poner una banderita digite la localizacion + \"m\"\n");
	printf("Example: \"8dm\" \"md8\" \"8md\"\nY para removerlo hazlo de nuevo.\n\n");
	do { //prints board
		for(lett = 'A', i = 0; i != CONTL; i++, lett++)
			printf("\t %c", lett), flag = 1;
		for(pos = 0; pos != 100; pos++) {
			flag ? printf("\n      ") : printf("\n     |");
			for(lett = 0; lett != CONTL; lett++)
				flag ? printf("_______ ") : printf("_______|");
			flag = 0;
			printf("\n     |");
			forloop(i, CONTL)
				printf("       |");	
			printf("\n%2i   |", (pos/CONTL)+1);
			do {
				a = pos/10, b = pos%10;
				hash[a][b] == '-' ? printf("  -1   |") : printf("   %c   |", hash[a][b]); //VALUE
				pos++;
			} while((pos%CONTL) != 0);
			pos--;
		}
		printf("\n     |");
		forloop(i, CONTL)
			printf("_______|");
		printf("\n");
		if(c == PERD) {
			printf("\nHaz Perdido. F\n");
			break;
		}	
	} while((c = open()) != EOF && c != GANA);
		
	return 0;
} //Helped by Rogelio Salinas
