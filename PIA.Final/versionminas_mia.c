#include <assert.h>  // assert
#include <ctype.h>   // toupper
#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // rand
#include <unistd.h>  // getpid
#include <windows.h> //cls


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
//int sit
int main() {
 
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


  return 0;
}


