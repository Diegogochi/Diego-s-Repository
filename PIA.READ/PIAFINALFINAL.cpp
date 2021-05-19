/*PIA - V1
1947576 - Angela Gabriela Pesina de los Santos
1965850 - Rogelio Adrián Salinas Rosette 
1969800 - Diego Gómez Chirinos 

PROGRAMA: SISTEMA DE UN CINE */

#include <stdio.h>
#include <windows.h>
#include <string.h>

//decalarar funciones 
void cine_cliente();
void cine_trabajo();
void cine_cliente();
void cine_trabajo();
void cartelera();
void dulceria();
void matrices();
void ticket();

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

float pagar_dulces = 0;

//funcion principal 
int main(){ //inicio main 
	int op, repetir, con;
	con=0;
	do { //incio do 
		system("cls"); //limpiar consola 
		con ++;
	printf("Bienvendio a FIMEPOLIS! \n");
	printf("------------------------------------\n");
	printf("Selecciona si eres un cliente o un trabajador del cine: \n");
	printf("1. Empleado \n");
	printf("2. Cliente \n");
	printf("------------------------------------\n");
	scanf("%i", &op);	
	
	switch(op) { //inicio switch 
		case 1:
		system("cls");
		printf("Bienvenido, empleado de FIMEPOLIS!\n");
		printf("----------------------------------------------\n");
		cine_trabajo();
    	printf("\n\n \tQUIERE VOLVER A LA PANTALLA PRINCIPAL? 1. SI, 2. NO\n");
		scanf("%i", &repetir);
		break;
		
		case 2:
		system("cls");
		printf("Bienvenido, cliente de FIMEPOLIS!\n");
		printf("----------------------------------------------\n");
		cine_cliente();
		printf("\n\n \tQUIERE VOLVER A LA PANTALLA PRINCIPAL? 1. SI, 2. NO\n");
		scanf("%i", &repetir);
		break;
				
		default:
		printf("ERROR\n");
		printf("\n\n \tQUIERE VOLVER A LA PANTALLA PRINCIPAL? 1. SI, 2. NO\n");
		scanf("%i", &repetir);
		break;
	
	 } //fin switch 
 } //fin do
while (repetir == 1); 
printf("\n\n\tEl numero de operaciones realizadas en el sistema es de: %i\n", con);
  
  printf("\n\n\tGracias por visitarnos!\n");
	} //fin main 
	
	
	
void cine_trabajo (){ //inicio trabajador 
 
 int emp, opc, rep, puesto, horas, con, x[100], i, n, mayor, posmayor, menor, posmenor, preg1, preg2, preg3, preg4, sum, i2, otra;
 con = 0;
 horas= 0;
 float sueldo;
 char nom[50];
 

 	
 printf("Ingresa tu nombre: \n");
scanf(" %[^\n]", &nom); //almacena cadena de caracteres con espacio en blanco
 
 printf("Ingresa tu numero de empleado: \n");
 scanf("%i", &emp);
 
  do { //inicio de do 
 	system("cls"); 
  

printf("----------------------------------------------\n");
printf("\t****MENU DE EMPLEADO****\n");
printf("Selecciona la opcion que desees realizar: \n");
printf("1. Consultar tu sueldo del mes\n");
printf("2. Autoevaluacion para obtener preferencias \n");
printf("3. Agregar una pelicula a la cartelera \n");
printf("----------------------------------------------\n");
scanf("%i", &opc);

 
switch (opc) { //inicio switch

 case 1:
	printf("----------------------------------------------\n");
	printf("Ingresa tu puesto de trabajo: \n");
	printf("1. Gerente \n");
	printf("2. Taquillero \n");
	printf("3. Staff \n");
	printf("4. Limpieza \n");
	printf("----------------------------------------------\n");
	scanf("%i", &puesto);
	
	printf("\tA continuacion ingresaras las horas trabajadas cada dia durante la semana para calcular tu salario semanal: \n\n");
	
     //USO DE ARREGLOS UNIDIMENSIONALES  
     
     printf("Ingresa el numero de dias que trabajaste durente la semana: ");
     scanf("%i", &n);
     if (n>=1 && n<=7) {
     
	//crear el arreglo
	for(i=1; i<=n; i++){
		printf("Ingresa cuantas horas trabajste el dia %i:  ", i);
		scanf("%i", &x[i]);
		if (x[i]<=24) {
		horas = horas + x[i];
	} else {
		printf("ERROR, EL DIA TIENE 24 HORAS \n");
		return ;
	}
	}
	//imprimir
	printf("\n\nLas horas trabajadas durate la semana son: \n");
	for(i=1; i<=n; i++){
		printf("\t %i \n", x[i]);
	}
	mayor = x[1];
	posmayor = 1;
	menor = x[1];
	posmenor = 1;	
	for (i=2; i<n; i++) {
		if (x[i] > mayor ){
			mayor = x[i];
			posmayor = i;
		} else{
			if (x[i] < menor) {
				menor = x[i];
				posmenor = i;
			}
     	}		
	}
} else {
	printf("ERROR, LA SEMANA TIENE 7 DIAS\n");
	return;
}
	
switch(puesto) { //inicio switch
	case 1:	
	//Datos reales de cinemex 
		sueldo = 83.33 * horas;
		
		printf("\n\n\n\n\n\nHola, %s \n", nom);
		printf("Tu numero de empleado es: %i\n", emp);
		printf("Tu puesto es de: Gerente \n");
		printf("Las horas trabajadas en total durante el mes son: %i\n", horas);
		printf("Tu pago por hora es de: 83.33 pesos  \n");
		printf("Tu sueldo es de: %.2f \n", sueldo);
		break; 
		
		
		
	case 2:
		//Datos reales de cinemex  
     	sueldo = 24.20 * horas;
		
		printf("Hola, %s \n", nom);
		printf("Tu numero de empleado es: %i\n", emp);
		printf("Tu puesto es de: Taquillero \n");
		printf("Las horas trabajadas en total durante el mes son: %i\n", horas);
		printf("Tu pago por hora es de: 23.59 pesos  \n");
		printf("Tu sueldo es de: %.2f \n", sueldo);
		break; 
		
		
		
	case 3:
		printf("Hola, %s \n", nom);
		printf("Tu numero de empleado es: %i\n", emp);
		printf("Tu puesto es de: Staff \n");
		printf("Las horas trabajadas en total durante el mes son: %i\n", horas);
		printf("Tu pago por hora es de: 27.11 pesos  \n");
		printf("Tu sueldo es de: %.2f \n", sueldo);
		break;
		
		
		
	case 4:
		//datos reales de cinemex
		sueldo = 22.10 * horas;
	
		printf("Hola, %s \n", nom);
		printf("Tu numero de empleado es: %i\n", emp);
		printf("Tu puesto es de: Limpieza \n");
		printf("Las horas trabajadas en total durante el mes son: %i\n", horas);
		printf("Tu pago por hora es de: 22.10 pesos  \n");
		printf("Tu sueldo es de: %.2f \n", sueldo);
		break;
		
	default:
		printf("ERROR al elegir su puesto de trabajo\n");
	printf("\n\n \tQUIERE VOLVER A INTENTARLO? 1. SI, 2. NO\n");
		
		
	
} //fin switch

printf("El dia que ha trabajado mas horas es el numero: %i", posmayor);
printf(" , y las horas que ha trabajado son: %i\n", mayor);
printf("El dia que ha trabajado menos horas es el numero: %i", posmenor);
printf(" , y las horas que ha trabajado son: %i\n", menor);

break;


case 2:
 	printf("----------------------------------------------\n");
	printf("Ingresa tu puesto de trabajo: \n");
	printf("1. Gerente \n");
	printf("2. Taquillero \n");
	printf("3. Staff \n");
	printf("4. Limpieza \n");
	printf("----------------------------------------------\n");
	scanf("%i", &puesto);
	
		printf("----------------------------------------------\n");
	printf("\t **AUTOEVALUACION**");
	printf("Clificate con un rango de 1 a 4, siendo: \n");
	printf("1. Malo\n");
	printf("2. Regular\n");
	printf("3. Bueno\n");
	printf("4. Excelente\n");
		printf("----------------------------------------------\n");
	switch(puesto) { //inicio switch
	
	case 1: 
	printf("\t**Tu puesto de trabajo es: Gerente** \n");
	printf("Trato con amabilidad y paciencia a los empleados y clientes: ");
	scanf("%i", &preg1);
	printf("Llevo un control organizado del cine: ");
	scanf("%i", &preg2);
	printf("Respeto mis horarios laborales y el de los demas empleados: ");
	scanf("%i", &preg3);
	printf("Respeto los codigos de vestimenta del cine: ");
	scanf("%i", &preg4);
	 sum = preg1 + preg2 + preg3 + preg4;
	 break;
	 
	case 2: 
	printf("\t**Tu puesto de trabajo es: Taquillero** \n");
	printf("Trato con amabilidad y paciencia a los clientes: ");
	scanf("%i", &preg1);
	printf("Llevo un control organizado sobre el dinero de la caja: ");
	scanf("%i", &preg2);
	printf("Respeto mis horarios laborales: ");
	scanf("%i", &preg3);
	printf("Comunico cualquier error del sistema con mi gerente: ");
	scanf("%i", &preg4);
	 sum = preg1 + preg2 + preg3 + preg4;
	 break;
	 
	case 3: 
	printf("\t**Tu puesto de trabajo es: Staff** \n");
	printf("Trato con amabilidad y paciencia a los clientes: ");
	scanf("%i", &preg1);
	printf("Mantengo mi area de trabajo organizada: ");
	scanf("%i", &preg2);
	printf("Respeto mis horarios laborales: ");
	scanf("%i", &preg3);
	printf("Comunico cualquier daño encontrado en las instalaciones con mi gerente: ");
	scanf("%i", &preg4);
	 sum = preg1 + preg2 + preg3 + preg4;
	 break;

		case 4: 
	printf("\t**Tu puesto de trabajo es: Intendente** \n");
	printf("Trato con amabilidad y paciencia a los clientes: ");
	scanf("%i", &preg1);
	printf("Limpio y sanitizo todas las salas de cine utilizadas anteriormente: ");
	scanf("%i", &preg2);
	printf("Mantengo areas del cine (como la dulceria y los baños) limpios y presentables para los clientes: ");
	scanf("%i", &preg3);
	printf("Respeto mis horarios de trabajo: ");
	scanf("%i", &preg4);
	 sum = preg1 + preg2 + preg3 + preg4;
	 break;
	
	
	default:
		printf("ERROR AL SELECCIONAR TU PUESTO DE TRABAJO\n");
		return;
	
	}
 	
 	
 	
 	
printf("\n\n\nHola, %s\n", nom);
printf("Tu numero de empleado es: %i\n", emp);
printf("La suma de tus puntos es: %i\n", sum);

if(sum>=0 && sum<=5) {
	printf("\n\t El trabajo que realiza es mediocre, se le recomienda mejorar ya que esta en peligro de perder su empleo.\n No tiene derecho a recompensas. \n");
} else {
	if (sum>=6 && sum<=10){
		printf("\n\t Se le recomienda mejorar para poder tener derecho a recompensas. \n");
	}
else {
	if (sum>=11 && sum<=13){
		printf("\n\tBuen trabajo! Le falta un poco para llegar a la excelencia. \n Tiene derecho a dos entradas de cine gratis.\n ");
	}
else {
	printf("\n\tExcelente trabajo! Tiene derecho a dos entradas al cine gratis y unas palomitas para disfrutar su pelicula");
}
}
}
break;

case 3:
//USO DE MATRIZ O ARREGLO BIDIMENSIONAL
do {
	system("cls"); 

		for(i2 = 0; peliculas[i2][0] != 0; i2++);
		

		printf("--------------------------------------------\n");
		printf("Ingresa el nombre de la pelicula (Max 15 caracteres)\n");
		scanf(" %[^\n]", &pelis[i2]);
		printf("\nIngresa el costo del boleto de entrada\n");
		scanf("%d", &peliculas[i2][0]);
		printf("Ingresa la duracion de la pelicula\nHoras: ");
		scanf("%d", &peliculas[i2][1]);
		printf("Minutos: ");
		scanf("%d", &peliculas[i2][2]);
		printf("\n\nIngresa la hora de la funcion\nHora: ");
		scanf("%d", &peliculas[i2][3]);
		printf("Minuto: ");
		scanf("%d", &peliculas[i2][4]);
		printf("\n\nIngresa la clasificacion de la pelicula segun (Ingresar un numero): \n1 = A\n2 = B\n3 = B15\n4 = C\n");
		scanf("%d", &peliculas[i2][5]);
		
		
		printf("\n\tPelicula agregada exitosamente\n");
		printf("\t***IMPORTANTE: LA PELICULA AGREGADA SE PODRA VER EN LA OPCION 'CARTELERA' EN LA SECCION DE CLIENTE***\n\n");
	
	printf("QUIERE AGREGAR OTRA PELICULA? \n 1. SI, 2.NO\n");
	scanf("%i", &otra);
}
while(otra == 1);
	
         break;

default:
printf("\n\n \tERROR AL SELECIONAR LA OPERACION \n");
break; 
} //FIN SWITCH

		printf("\n\n \tQUIERE VOLVER AL MENU DE EMPLEADO? 1. SI, 2. NO\n");
		scanf("%i", &rep);

} //fin do 
while (rep==1);


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
		else if (op == 3){
			 ticket();
			 hecho = 1;
		}
			
		system("cls");
			printf("Bienvenido, cliente de FIMEPOLIS\n");
		printf("----------------------------------------------\n");
		printf("Hola, Que desea seleccionar?\n");
		printf("1. Cartelera \n");
		printf("2. Dulceria \n");
		printf("3. Ver su ticket. \n");
		printf("----------------------------------------------\n");
		if(!hecho) scanf("%i", &op);
		
		if((op == 1 || op == 2) && hecho) {
			printf("\nDesea agregar algo mas? 1. Si, 2. No\n");
			scanf("%i", &du);
			hecho = 0;
			op = 0;
		}
	} 
	 
//	ticket();
		
	return; //regresa el control a main
	} //fin cliente 
	
	void cartelera() {
	
	int i, j = 0, op = 0, pago = 0, a, cant;

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
	
	switch (op) {
		case 0:
		printf("\nQue desea hacer?\n");
		printf("1. Ver info clasificaciones\n");
		printf("2. Comprar boletos\n");
		printf("3. Opciones de matriz\n");
		printf("4. regresar\nOpcion: ");
		scanf("%i", &op);
		break;	
		
		case 1: 
		printf("\nClasificaciones\n-----------------------------\n");
		printf("1 = A\n2 = B\n3 = B15\n4 = C\n-----------------------------\n");
		printf("Ingrese 0 para regresar\n");
		scanf("%i", &op);
		break;
		
		case 2:
		printf("\nPara que numero de funcion desea comprar?\n");
		scanf("%i", &a);
		printf("Cuantos boletos desea comprar?\n");
		scanf("%i", &cant);
		pago += peliculas[a-1][0]*cant;
		printf("%i\n", pago);
		printf("Desea hacer algo mas? 0. Si 4. Regresar \n");
		scanf("%i", &op);	
		break;
		
		case 3: matrices(); 
		printf("Desea hacer algo mas? 0. Si 4. Regresar \n");
		scanf("%i", &op); break;
		case 4: return;	
	}
	} 
	
}
	
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
	int opc,dulce, cantidad = 0,total_de_dulces = 0, repetir;
	float pago = 0, palomitas, chocolates, bebidas, hotdogs, nachos, helado;
	
	palomitas = 55.50;
	chocolates = 24.40;
	bebidas = 45.75;
	hotdogs = 35.80;
	nachos = 40.90;
	helado = 30.40;
	
	do
	{  //Inicio del Do
	 system("cls");
	
	printf("\t***Bienvenido al sistema de dulceria de FIMEPOLIS***\n");
	printf("Digite la opcion que desea: \n");
	printf("\t1. Comprar un dulce.\n");
	printf("\t2. Ver cuantos dulces ha comprado.\n");
	printf("\t0. Salir de este apartado.\n");
	scanf("%i", &opc);



	switch(opc){
				case 1: system("cls");
						printf("Esta en el menu de dulces.\n");
						printf("Seleccione algun producto por favor.\n");
						printf("\t1. Palomitas  =  $55.50\n");
						printf("\t2. Chocolates =  $24.40\n");
						printf("\t3. Bebidas    =  $45.75\n");
						printf("\t4. Hotdogs    =  $35.80\n");
						printf("\t5. Nachos     =  $40.90\n");
						printf("\t6. Helado     =  $30.40\n");
						scanf("%i", &dulce); //Todavia no esta terminado
						printf("Elija cuantos va a desear.\n");
						scanf("%i", &cantidad);
				
						switch(dulce)
						{		
							case 1: pago = palomitas * cantidad;
							printf("Van $%1.f\n", pago);
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
							case 2: pago = chocolates* cantidad;
							printf("Van $%1.f\n", pago);
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
							case 3: pago = bebidas   * cantidad;
							printf("Van $%1.f\n", pago);
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
							case 4: pago = hotdogs   * cantidad;
							printf("Van $%1.f\n", pago);
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
							case 5: pago = nachos    * cantidad;
							printf("Van $%1.f\n", pago);
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
							case 6:	pago = helado    * cantidad;
							printf("Van $%1.f\n", pago);
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
							default: printf("Usted no ha seleccionado ningun dulce.\n");
							printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
							scanf("%i", &repetir);break;
						} break;
				case 2: system("cls");
						printf("Esta en el apartado para ver cuantos dulces ha comprado.\n");
						total_de_dulces = total_de_dulces + cantidad;
						printf("Hasta el momento a comprado %i dulces.\n", total_de_dulces);
						printf("Volver a la pantalla de seleccion de dulces. 1.Si | 0. No\n");
						scanf("%i", &repetir);break;
					
				default: printf("Usted no ha elegido ninguna de las opciones anteriores.\n");break;				
		}	
	//suma de los productos, CHECAR ESTE APARTADO	
	pagar_dulces = pago + pagar_dulces;	
	total_de_dulces = total_de_dulces;
	}  //Fin del Do
	while(repetir == 1);

	
	//Muestra los resultados del menu de dulceria.
	
	printf("Usted va a pagar: $%2.f\n", pagar_dulces);
	printf("Usted a comprado %i dulces", total_de_dulces);
	
	return;
	
}	

void ticket(int i2){
		int opc, dulceria,ticket_total;
		
		dulceria = pagar_dulces ; 
		ticket_total = dulceria + peliculas[i2][0];
		
			
		printf("Bienvenido, se encuentra en el apartado para obtener su ticket del cine FIMEPOLIS.\n");
		printf("Digite 1 para poder ver su ticket.");
		scanf("%i", &opc);
		
		if(opc == 1){
		
		printf("La pelicula que usted vera sera:  %s\n", pelis[i2]);
		printf("Lo que usted pago por su boleto fue de: %i", peliculas[i2][0]);
		printf("Lo que usted pago en dulceria fue: $%2.f\n",pagar_dulces );
		printf("Lo que usted pago en total fue de: $%2.f",ticket_total);
		}
		else{
			printf("Usted no presiono el 1 para poder mostrar su ticket:).");
		}
	
		
	return;
}



	

	
	
	
	
	

