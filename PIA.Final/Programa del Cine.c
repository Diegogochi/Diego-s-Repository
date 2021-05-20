//PROGRAMA: SISTEMA DE UN CINE 

//By Diego Gómez Chirinos

#include <stdio.h>
#include <string.h>
#include <unistd.h> 
#include <ctype.h>
#include <assert.h>
#include <stdlib.h> 
#include "funciones.h"


//VARIABLES GLOBALES 
int peliculas[10][6] = {
{100, 2, 30, 7, 15, 1},
{85, 2, 7, 8, 10, 1},
{90, 1, 50, 7, 45, 2},
{105, 2, 46, 9, 5, 3},
{70, 1, 25, 8, 25, 2}
};
char pelis[10][15] = {
{"Los vengadores"},
{"Godzila & Kong"},
{"Avatar"},
{"Shrek"},
{"Spiderman"}
};

char candy[25][12];
int comida[25];
int ag[25];
int pagos[25];
char fila[10];
int columna[10];

//funcion principal 
int main(){ //inicio main 
	int op, repetir, con = 0;
	
	do { //incio do 
		system("cls"); //limpiar consola 
		con++;
		printf("\t###Welcome To FIMEPOLIS###\n\n");
	
		printf("Type 1. If you are an Employee.\n");
	    printf("Type 2. If you are a Client.\n");
		printf("Type 3. To finish the program\n");
		scanf("%i", &op);	
	
		switch(op) { //inicio switch 
			case 1:
			system("cls");
			printf("\t###Welcome, Employee###\n\n");
			cine_trabajo(); 
			break;
		
			case 2:
			system("cls");
			printf("\t###Welcome, Client###\n\n");
			cine_cliente();
			break;
				
			default: printf("ERROR\n"); break;
		} //fin switch 
	   	if(op >= 3)
	   		break;
		
		printf("\nType 1 if you want to go back to the main screen. \nType 0 if you do not:\n");
		scanf("%i", &repetir);
	
	} while (repetir == 1); //fin do
	
	printf("\n\n\tEl numero de operaciones realizadas en el sistema es de: %i\n", con);
	printf("\n\tThe Total number of operations was: %i\n", con);
	printf("\n\nThank you for your visit!\n");

}//fin main 

//función creada para todo lo que pueda hacer el empleado del cine	
void cine_trabajo (){ //inicio trabajador 
 
	int emp, op, rep, puesto, horas = 0, x[100], i, n, mayor,  sum;
	int posmayor, menor, posmenor, preg[4], a, otra = 1, o = 0;
	float sueldo;
	char nom[50];
 
	printf("Write your name: \n");
	scanf(" %[^\n]", &nom); //almacena cadena de caracteres con espacio en blanco
	printf("\nWrite your ID number: \n");
	scanf("%i", &emp);
 
	do { //inicio de do 
 	system("cls"); 
	printf("----------------------------------------------\n");
	printf("\t****MENU DE EMPLEADO****\n");
	printf("----------------------------------------------\n");
	printf("Selecciona la opcion que desees realizar: \n");
	printf("1. Consultar tu sueldo de la semana\n");
	printf("2. Autoevaluacion para obtener preferencias \n");
	printf("3. Agregar una pelicula a la cartelera \n");
	printf("4. Regresar a pantalla principal \n");
	printf("----------------------------------------------\n");
	scanf("%i", &op);
 
	switch (op) { //inicio switch
	
		case 1:
		system("cls");
		printf("----------------------------------------------\n");
		printf("Ingresa tu puesto de trabajo: \n");
		printf("1. Gerente \n");
		printf("2. Taquillero \n");
		printf("3. Staff \n");
		printf("4. Limpieza \n");
		printf("----------------------------------------------\n");
		scanf("%i", &puesto);
		
		if(puesto < 5) {
		printf("\nA continuacion ingresaras las horas trabajadas cada dia durante");
		printf(" la semana para calcular tu salario semanal: \n\n");
    	//USO DE ARREGLOS UNIDIMENSIONALES  
    	printf("Ingresa el numero de dias que trabajaste durente la semana: ");
    	scanf("%i", &n);
    	horas = 0;
    	if (n>=1 && n<=7) {//crear el arreglo
			for(i=1; i<=n; i++) {
				printf("Ingresa cuantas horas trabajste el dia %i:  ", i);
				scanf("%i", &x[i]);
				if (x[i]<=24) {
					horas += x[i];
				} else {
					printf("ERROR, EL DIA TIENE 24 HORAS \n"); o = 1;
					break;
				}
			}
			if (o) {
				o = 0;
				break;
			}
			//imprimir
			printf("\n\nLas horas trabajadas durate la semana son: \n");
			for(i=1; i<=n; i++)
				printf("\t %i \n", x[i]);
			
			mayor = x[1];
			posmayor = 1;
			menor = x[1];
			posmenor = 1;
			for (i = 2; i <= n; i++) {
				if (x[i] > mayor ){
					mayor = x[i];
					posmayor = i;
				} else if (x[i] < menor) {
					menor = x[i];
					posmenor = i;
				}
     		}
		} else {
			printf("ERROR, LA SEMANA TIENE 7 DIAS\n");
			break;
		}
		
		printf("\nHola, %s \n", nom);
		printf("Tu numero de empleado es: %i\n", emp);
		}
		switch(puesto) { //inicio switch
			case 1:	
			sueldo = 83.33 * horas; //Datos reales de cinemex 	
			printf("Tu puesto es de: Gerente \n");
			printf("Las horas trabajadas en total durante la semana son: %i\n", horas);
			printf("Tu pago por hora es de: 83.33 pesos  \n");
			break; 

			case 2:
     		sueldo = 24.20 * horas; //Datos reales de cinemex  
			printf("Tu puesto es de: Taquillero \n");
			printf("Las horas trabajadas en total durante la semana son: %i\n", horas);
			printf("Tu pago por hora es de: 23.59 pesos  \n");
			break; 
		
			case 3:
			sueldo = 27.11 * horas; //Datos reales de cinemex
			printf("Tu puesto es de: Staff \n");
			printf("Las horas trabajadas en total durante la semana son: %i\n", horas);
			printf("Tu pago por hora es de: 27.11 pesos  \n");
			break;

			case 4:
			sueldo = 22.10 * horas; //Datos reales de cinemex
			printf("Tu puesto es de: Limpieza \n");
			printf("Las horas trabajadas en total durante la semana son: %i\n", horas);
			printf("Tu pago por hora es de: 22.10 pesos  \n");
			break;
		
			default:
			printf("ERROR al elegir su puesto de trabajo\n");
		} //fin switch
		if(puesto < 5) {
		printf("Tu sueldo es de: %.2f \n", sueldo);
		printf("El dia que ha trabajado mas horas es el numero: %i", posmayor);
		printf(", y las horas que ha trabajado son: %i\n", mayor);
		printf("El dia que ha trabajado menos horas es el numero: %i", posmenor);
		printf(", y las horas que ha trabajado son: %i\n", menor); 
		}	
		break;

		case 2:
		system("cls");
		printf("----------------------------------------------\n");
		printf("Ingresa tu puesto de trabajo: \n");
		printf("1. Gerente \n");
		printf("2. Taquillero \n");
		printf("3. Staff \n");
		printf("4. Limpieza \n");
		printf("----------------------------------------------\n");
		scanf("%i", &puesto);
		
		if(puesto < 5) {
		printf("\n---------------------------------------------------------------------\n");
		printf("\t **AUTOEVALUACION** Clificate con un rango de 1 a 4, siendo: \n");
		printf("1. Malo\n");
		printf("2. Regular\n");
		printf("3. Bueno\n");
		printf("4. Excelente\n");
		printf("\n---------------------------------------------------------------------\n");
		}
		switch(puesto) { //inicio switch
			case 1: 
			printf("\t**Tu puesto de trabajo es: Gerente** \n");
			printf("Trato con amabilidad y paciencia a los empleados y clientes: ");
			scanf("%i", &preg[0]);
			printf("Llevo un control organizado del cine: ");
			scanf("%i", &preg[1]);
			printf("Respeto mis horarios laborales y el de los demas empleados: ");
			scanf("%i", &preg[2]);
			printf("Respeto los codigos de vestimenta del cine: ");
			scanf("%i", &preg[3]);
			break;
	 
			case 2: 
			printf("\t**Tu puesto de trabajo es: Taquillero** \n");
			printf("Trato con amabilidad y paciencia a los clientes: ");
			scanf("%i", &preg[0]);
			printf("Llevo un control organizado sobre el dinero de la caja: ");
			scanf("%i", &preg[1]);
			printf("Respeto mis horarios laborales: ");
			scanf("%i", &preg[2]);
			printf("Comunico cualquier error del sistema con mi gerente: ");
			scanf("%i", &preg[3]);
			break;

			case 3: 
			printf("\t**Tu puesto de trabajo es: Staff** \n");
			printf("Trato con amabilidad y paciencia a los clientes: ");
			scanf("%i", &preg[0]);
			printf("Mantengo mi area de trabajo organizada: ");
			scanf("%i", &preg[1]);
			printf("Respeto mis horarios laborales: ");
			scanf("%i", &preg[2]);
			printf("Comunico cualquier daño encontrado en las instalaciones con mi gerente: ");
			scanf("%i", &preg[3]);
			break;

			case 4: 
			printf("\t**Tu puesto de trabajo es: Intendente** \n");
			printf("Trato con amabilidad y paciencia a los clientes: ");
			scanf("%i", &preg[0]);
			printf("Limpio y sanitizo todas las salas de cine utilizadas anteriormente: ");
			scanf("%i", &preg[1]);
			printf("Mantengo areas del cine (como la dulceria y los baños) limpios y presentables para los clientes: ");
			scanf("%i", &preg[2]);
			printf("Respeto mis horarios de trabajo: ");
			scanf("%i", &preg[3]);
			break;
	
			default: printf("ERROR AL SELECCIONAR TU PUESTO DE TRABAJO\n"); break;
		}
 		sum = preg[0] + preg[1] + preg[2] + preg[3];
 		if(puesto < 5) {
 		printf("\n----------------------------------------------\n");
		printf("Hola, %s\n", nom);
		printf("Tu numero de empleado es: %i\n", emp);
		printf("La suma de tus puntos es: %i\n", sum);

		if(sum>=0 && sum<=5) 
			printf("\n\tEl trabajo que realiza es mediocre, se le recomienda mejorar ya que esta en peligro de perder su empleo.\n\tNo tiene derecho a recompensas.\n");
		else if (sum>=6 && sum<=10)
			printf("\n\tSe le recomienda mejorar para poder tener derecho a recompensas.\n");
		else if (sum>=11 && sum<=13)
			printf("\n\tBuen trabajo! Le falta un poco para llegar a la excelencia.\n\tTiene derecho a dos entradas de cine gratis.\n");
		else if (sum>=13 && sum<=16)
			printf("\n\tExcelente trabajo! Tiene derecho a dos entradas al cine gratis y unas palomitas para disfrutar su pelicula");
		else
			printf("\n\tEvaluacion Invalida\n");
		}
		break;

		case 3: //USO DE MATRIZ O ARREGLO BIDIMENSIONAL
		while(otra == 1) {
			system("cls");
			for(a = 0; peliculas[a][0] != 0; a++);
	
			printf("--------------------------------------------\n");
			printf("Ingresa el nombre de la pelicula\n");
			scanf(" %[^\n]", &pelis[a]);
			printf("\nIngresa el costo del boleto de entrada\n");
			scanf("%d", &peliculas[a][0]);
			printf("Ingresa la duracion de la pelicula\nHoras: ");
			scanf("%d", &peliculas[a][1]);
			printf("Minutos: ");
			scanf("%d", &peliculas[a][2]);
			printf("\n\nIngresa la hora de la funcion\nHora: ");
			scanf("%d", &peliculas[a][3]);
			printf("Minuto: ");
			scanf("%d", &peliculas[a][4]);
			printf("\n\nIngresa la clasificacion de la pelicula segun (Ingresar un numero): \n1 = A\n2 = B\n3 = B15\n4 = C\n");
			scanf("%d", &peliculas[a][5]);
		
			printf("\n\tPelicula agregada exitosamente\n");
			printf("***IMPORTANTE: LA PELICULA AGREGADA SE PODRA VER EN LA OPCION 'CARTELERA' EN LA SECCION DE CLIENTE***\n\n");

			printf("QUIERE AGREGAR OTRA PELICULA? \n 1. SI, 2.NO\n");
			scanf("%i", &otra);
		}
		break;

		case 4: return;
			
		default: printf("\n\n \tERROR AL SELECIONAR LA OPERACION \n"); break; 
	}

	printf("\n\n \tQUIERE VOLVER AL MENU DE EMPLEADO? 1. SI, 0. NO\n");
	scanf("%i", &rep);

	} while (rep==1); //fin do
	
	return; //regresa el control a main
} //fin trabajaador 

//función creada para todo lo que pueda hacer el cliente del cine 
void cine_cliente (){ //inicio cliente 
	int op = 0, du = 1, hecho = 0;
	
	while(du == 1) {
		if(op == 1) {
			cartelera();
			hecho = 1;
		}
		else if (op == 2) {
			dulceria();
			hecho = 1;
		}
		else if(op == 3){
			asientos();
		hecho = 1;
		}
		else if (op == 4)
			break; 
		
			
		system("cls");
		printf("Bienvenido, cliente de FIMEPOLIS\n");
		printf("----------------------------------------------\n");
		printf("Hola, Que desea seleccionar?\n");
		printf("1. Billboard \n");
		printf("2. Candy Store \n");
		printf("3. Sits \n");
		printf("4. Finish \n");
		printf("----------------------------------------------\n");
		if(!hecho) scanf("%i", &op);
		
		if(hecho) {
			printf("\nDesea agregar algo mas? 1. Si, 0. No\n");
			scanf("%i", &du);
			hecho = 0;
			op = 0;
		}
	}//fin while
	 
	ticket();
		
	return; //regresa el control a main
} //fin cliente 
	
void cartelera() {
	
	int i, j = 0, op = 0, col, pago = 0, cant, k = 0, m = 0;
	char row;

	while(1) {
	system("cls");
	printf("Bienvenido, cliente de FIMEPOLIS\n");
	printf("----------------------------------------\n");
	printf("\t*CARTELERA* (Matriz)\n");
	printf("------------------------------------------------------------------------------\n");
	printf("    Pelicula    \t  Costo      Duracion        Horario     Clasificacion\n\n");
	for(i = 0; peliculas[i][j] != 0; i++) {
		printf("%i. %s\t", i+1, pelis[i]);
		if(strlen(pelis[i]) < 13)
			printf("\t");
		if(strlen(pelis[i]) < 5)
			printf("\t");
		for(j = 0; j < 6; j++) {
			if(j%2)
				printf("\t      ");
			if(j == 0)
				printf("  $");
			if((j == 2 || j == 4) && peliculas[i][j] < 10)
				printf("0");
			printf("%i", peliculas[i][j]);
			if(j == 1)
				printf("h");
			if(j == 3)
				printf(":");
		}
		printf("\n");
		j = 0;
	}
	printf("------------------------------------------------------------------------------\n");
	
	switch (op) { //Inicio switch
		case 0:
		printf("\nQue desea hacer?\n");
		printf("1. Ver info clasificaciones\n");
		printf("2. Comprar boletos\n");
		printf("3. Opciones de matriz\n");
		printf("4. Regresar a Menu de cliente\nOpcion: ");
		scanf("%i", &op);
		break;	
		
		case 1: 
		printf("\nClasificaciones\n-----------------------------\n");
		printf("1 = A\n2 = B\n3 = B15\n4 = C\n-----------------------------\n");
		printf("Ingrese 0 para regresar a Cartelera\n");
		scanf("%i", &op);
		break;
		
		case 2:
		printf("\nPara que numero de funcion desea comprar?\n");
		scanf("%i", &ag[k]);
		printf("Cuantos boletos desea comprar?\n");
		scanf("%i", &cant);
		pago += peliculas[ag[k]-1][0]*cant;
		
		for(i = 0; i < cant; i++) {
			pagos[m] = peliculas[ag[k]-1][0];
			ag[++m] = ag[k];
			k = m;
		}	
		printf("Total: $%i\n\n", pago);
		printf("Desea hacer algo mas? 0. Seguir en Cartelera 4. Regresar a Menu de cliente \n");
		scanf("%i", &op);	
		break;
		
		case 3: matrices(); 
		printf("\nDesea hacer algo mas? 0. Seguir en Cartelera 4. Regresar a Menu de cliente \n");
		scanf("%i", &op); break;
		
		case 4: return;	
		default: op = 0; break;
		
	}//fin switch
	}//fin while
	
}
//Quitar	
void matrices() {
	int i, j;
	printf("Diagonal principal\n");
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			if(i == j)
				printf("\t%i", peliculas[i][j]);
			else 
				printf("\t0");
		}
		printf("\n");
	}
	printf("Diagonal secundaria\n");
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			if((i + j) == 5)
				printf("\t%i", peliculas[i][j]);
			else 
				printf("\t0");
		}
		printf("\n");
	}
	printf("Triangular superior\n");
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			if(i < j)
				printf("\t%i", peliculas[i][j]);
			else 
				printf("\t0");
		}
		printf("\n");
	}
	printf("Triangular inferior\n");
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			if(i > j)
				printf("\t%i", peliculas[i][j]);
			else 
				printf("\t0");
		}
		printf("\n");
	}	
	return;
}


void dulceria() {
	
	int opc, dulce, cantidad = 0,total_dulces = 0, repetir, si = 1, i = 0, x = 0;
	float pago = 0, palomitas, chocolates, bebidas, hotdogs, nachos, helado;
	
	palomitas = 55.50;
	chocolates = 24.40;
	bebidas = 45.75;
	hotdogs = 35.80;
	nachos = 40.90;
	helado = 30.40;
	
	do { //Inicio del Do
	  
	system("cls");
	printf("\t***Bienvenido al sistema de dulceria de FIMEPOLIS***\n");
	printf("-----------------------------------------------------------------------\n");
	printf("Digite la opcion que desea: \n");
	printf("\t1. Comprar un dulce.\n");
	printf("\t2. Ver cuantos dulces ha comprado.\n");
	printf("\t3. Regresar a Menu de cliente.\n");
	printf("-----------------------------------------------------------------------\n");
	scanf("%i", &opc);
	si = 1;
	
	switch(opc) {
		case 1: 
			while(si == 1) {
			system("cls");
			printf("Menu de dulces.\n");
			printf("-------------------------------------------------------\n");
			printf("Que desea seleccionar?\n");
			printf("\t1. Palomitas  =  $55.50\n");
			printf("\t2. Chocolates =  $24.40\n");
			printf("\t3. Bebidas    =  $45.75\n");
			printf("\t4. Hotdogs    =  $35.80\n");
			printf("\t5. Nachos     =  $40.90\n");
			printf("\t6. Helado     =  $30.40\n");
			printf("-------------------------------------------------------\nOpcion: ");
			scanf("%i", &dulce); 
			printf("Elija cuantos va a desear: ");
			scanf("%i", &cantidad);
			if(dulce<7)
				total_dulces += cantidad;
			
			switch(dulce) {		
				case 1: pago += palomitas * cantidad; 
					for(; i < (cantidad+x); i++) {
						candy[i][0] = 'P', candy[i][1] = 'a', candy[i][2] = 'l', candy[i][3] = 'o', candy[i][4] = 'm';
						candy[i][5] = 'i', candy[i][6] = 't', candy[i][7] = 'a', candy[i][8] = 's', candy[i][9] = '\0'; 
						comida[i] = palomitas;
					} break;
				case 2: pago += chocolates* cantidad; 
					for(; i < (cantidad+x); i++) {
						candy[i][0] = 'C', candy[i][1] = 'h', candy[i][2] = 'o', candy[i][3] = 'c', candy[i][4] = 'o';
						candy[i][5] = 'l', candy[i][6] = 'a', candy[i][7] = 't', candy[i][8] = 'e', candy[i][9] = 's';
						comida[i] = chocolates;
					} break;
				case 3: pago += bebidas   * cantidad;
					for(; i < (cantidad+x); i++) {
						candy[i][0] = 'B', candy[i][1] = 'e', candy[i][2] = 'b', candy[i][3] = 'i';
						candy[i][4] = 'd', candy[i][5] = 'a', candy[i][6] = 's', candy[i][7] = '\0';;
						comida[i] = bebidas;
					} break;
				case 4: pago += hotdogs   * cantidad; 
					for(; i < (cantidad+x); i++) {
						candy[i][0] = 'H', candy[i][1] = 'o', candy[i][2] = 't', candy[i][3] = 'd';
						candy[i][4] = 'o', candy[i][5] = 'g', candy[i][6] = 's', candy[i][7] = '\0';;
						comida[i] = hotdogs;
					} break;
				case 5: pago += nachos    * cantidad;
					for(; i < (cantidad+x); i++) {
						candy[i][0] = 'N', candy[i][1] = 'a', candy[i][2] = 'c';
						candy[i][3] = 'h', candy[i][4] = 'o', candy[i][5] = 's', candy[i][6] = '\0';;
						comida[i] = nachos;
					} break;
				case 6:	pago += helado    * cantidad;	
					for(; i < (cantidad+x); i++) {
						candy[i][0] = 'H', candy[i][1] = 'e', candy[i][2] = 'l';
						candy[i][3] = 'a', candy[i][4] = 'd', candy[i][5] = 'o', candy[i][6] = '\0';;
						comida[i] = helado;
					} break;
				default: printf("Error. Usted no ha seleccionado ningun dulce.\n"); break;
			} 
			x = i;
			if(pago) 
				printf("\nVan $%1.f\n", pago);
			printf("\nSeguir comprando? 1. Si. | 0. No.\n");
			scanf("%i", &si);
			} break;
			
		case 2: system("cls");
			printf("------------------------------------------------------------\n");
			printf("Usted Esta en el apartado para ver cuantos dulces ha comprado.\n");
			printf("Hasta el momento a comprado %i dulces.\n", total_dulces);
			printf("Subtotal: $%1.f\n", pago);
			printf("------------------------------------------------------------\n");
			break;
		
		case 3:	return;
			
		default: printf("Usted no ha elegido ninguna de las opciones anteriores.\n");break;	
		}
		
	printf("\n\tVolver a la pantalla de Menu de dulces. 1. Si | 0. No\n");
	scanf("%i", &repetir); 
	
	} while(repetir == 1); //Fin del Do
	
	return;
	
}	

int asientos(){
#define ASIENTO_OCUPADO 2
#define ERROR_NINGUNO 3

// Cosas que puedes modificar ;)
#define COLUMNAS 9
#define FILAS 9   
#define ASIENTO_LIBRE 'D'			//Con este se muestran los asientos disponibles
#define ESPACIO_DESCUBIERTO ' ' 	//Con este se muestran los asietnos ocupados


#define DEBUG 1  // Si lo pones en 1, se van a desocultar las minas


//int obtainSits
// obtenerMinasCercanas
int obtainSits(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= FILAS) {
    filaFin = FILAS - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= COLUMNAS) {
    columnaFin = COLUMNAS - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
  }
  return conteo;
}


// Rellena el tablero de espacios sin descubrir
void beginSITS(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      tablero[l][m] =  ASIENTO_LIBRE;
    }
  }
}

//void printSeparateHeaders
void printSeparateHeaders() {
  int m;
  for (m = 0; m <= COLUMNAS; m++) {
    printf("----");
    if (m + 2 == COLUMNAS) {
      printf("-");
    }
  }
  printf("\n");
}

//void printSeparateRows
void printSeparateRows() {
  int m;
  for (m = 0; m <= COLUMNAS; m++) {
    printf("+---");
    if (m == COLUMNAS) {
      printf("+");
    }
  }
  printf("\n");
}

//void printHeader
void printHeader() {
  printSeparateHeaders();
  printf("|   ");
  int l;
  for (l = 0; l < COLUMNAS; l++) {
    printf("| %d ", l + 1);
    if (l + 1 == COLUMNAS) {
      printf("|");
    }
  }
  printf("\n");
}

// Convierte un int a un char. Por ejemplo 0 a '0'
char enteroACaracter(int numero) {
  return numero + 'O';
}

//void printRoom
void printRoom(char tablero[FILAS][COLUMNAS], int deberiaMostrarMinas) {
  printHeader();
  printSeparateHeaders();
  char letra = 'A';
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    // Imprimir la letra de la fila
    printf("| %c ", letra);
    letra++;
    
    for (m = 0; m < COLUMNAS; m++) {
    	//Cambiar esto...
      
      char verdaderaLetra =  ASIENTO_LIBRE;
      char letraActual = tablero[l][m];
      
      //Con Esto Cambia de Disponible a Ocupado
	  if (letraActual == ESPACIO_DESCUBIERTO) {
      	//Modificar para tener siempre visibles los asientos ocupados y disponibles
        // Si ya lo abrió, entonces mostramos las minas cercanas
        int minasCercanas = obtainSits(l, m, tablero);
        verdaderaLetra = enteroACaracter(minasCercanas);
      }
      // Si DEBUG está en 1, o debería mostrar las minas (porque perdió o ganó)
      // mostramos la mina original
 
      printf("| %c ", verdaderaLetra);
      if (m + 1 == COLUMNAS) {
        printf("|");
      }
    }
    printf("\n");
    printSeparateRows();
  }
}

// Recibe la fila, columna y tablero. La fila y columna deben ser tal y como las
// proporciona el usuario. Es decir, la columna debe comenzar en 1 (no en cero
// como si fuera un índice) y la fila debe ser una letra

int openCase(char filaLetra, int columna, char tablero[FILAS][COLUMNAS]) {
  // Convertir a mayúscula
  filaLetra = toupper(filaLetra);
  // Restamos 1 porque usamos la columna como índice
  columna--;
  // Convertimos la letra a índice
  int fila = filaLetra - 'A';
  assert(columna < COLUMNAS && columna >= 0);
  assert(fila < FILAS && fila >= 0);

  if (tablero[fila][columna] == ESPACIO_DESCUBIERTO) {
    return ASIENTO_OCUPADO;
  }		//Cambiar a espacio ocupado
  // Si no hay error, colocamos el espacio descubierto
  tablero[fila][columna] = ESPACIO_DESCUBIERTO;
  return ERROR_NINGUNO;
}



//Modificar
void finalroom() {
 
  char fila,tablero[FILAS][COLUMNAS];
  int columna,asiento = 0, repetir;
  
  srand(getpid());
  beginSITS(tablero);
  
  do{
  	system("cls");
  	printf("\t###Here you can reserve your sit###\n");
    printRoom(tablero, asiento);
    if (asiento) {
      break;
    }
    
    printf("Ingresa la fila: "); 
    scanf(" %c", &fila);
    printf("Ingresa la columna: ");
    scanf("%d", &columna);
   
    int status = openCase(fila, columna, tablero);
     if (status == ASIENTO_OCUPADO) {
      printf("Este asiento esta ocupado.\n");
      asiento = 1;
    } 
     printf("\nRegistrar otro asiento:\n");
     printf("1. Yes\n");
     printf("0. No\n");
	 scanf("%i", &repetir);   
    
  } while  (repetir == 1);
  
  printf("Su asiento es: %c%d",fila,columna);


  return ;
}

}
void ticket(){
		
		
		int i, k, total = 0;
			
		system("cls");
		printf("\t***Ticket de compra cine FIMEPOLIS.***\n");
		printf("------------------------------------------------------\n");
		
		printf("Artiulos comprados\t\tPrecio");
		for(i = 0; pagos[i] != 0; i++) {
			printf("\nBoleto %s", pelis[ag[i]-1]);
			for(k = strlen(pelis[ag[i]-1]); k != 26; k++)
				printf(".");
			printf("$%d", pagos[i]);
			total += pagos[i];
		}
		for(i = 0; comida[i] != 0; i++) {
			printf("\n%s", candy[i]);
			for(k = strlen(candy[i]); k != 33; k++)
				printf(".");
			printf("$%d", comida[i]);
			total += comida[i];
		}
		printf("\n------------------------------------------------------\n");
		printf("Total:\t\t\t\t $%d", total);
		
		printf("\n\n\n\t***Tickets***\n");
		for(i = 0; pagos[i] != 0; i++) {
			printf("-----------------------------------\n");
			printf("\nMovie theater FIMEPOLIS\nFuncion: %s\n", pelis[ag[i]-1]);
			printf("Horario: %i:%02i\n", peliculas[ag[i]-1][3], peliculas[ag[i]-1][4]);
			printf("Sits: a1\n");
			printf("Enjoy Your Movie!\nThank You for Your Visit\n");
			printf("-----------------------------------\n\n");
		}
			
	return;
}
