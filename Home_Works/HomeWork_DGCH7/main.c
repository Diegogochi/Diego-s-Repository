/*
Como compilar?
TENER EN CUENTA QUE AL USAR GDB Y LA LIBRERIA TIME.h nos da un TIEMPO DIFERENTE al de MEXICO
Se recomienda usar el compilador online gdb
Este archivo va en el main.c, se crea el archivo registros.h 
y se pone lo que esta en el repositorio con ese nombre 
Con ctrl m se crea sistema.txt // entradas.txt // salidas.txt // reporte.txt // horario.txt
IMPORTANTE 
En sistema.txt van 10 lineas (9 lineas que estan en mi repositorio y 1 en blanco)
En entradas.txt van 12 lineas (11 lineas que estan en mi repositorio y 1 en blanco)
En salidas.txt van 12 lineas (11 lineas que estan en mi repositorio y 1 en blanco)
En reporte.txt van 16 lineas (15 lineas que estan en mi repositorio y 1 en blanco)
En horario.txt van 27 lineas (26 lineas que estan en mi repositorio y 1 en blanco)
Al decir una en blanco se debe dar un enter
*/


#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "registers.h"

int main()
{
    header();
    int i;
    int j;
    int pintemporal;
    matrix = (int**)malloc(sizeof(int*) * USUARIOS);
    for (i = 0; i < USUARIOS; i ++){
            matrix[i] = (int*)malloc(sizeof(int) * 6);
            for (j=0; j<6; j++){
            matrix[i][j]=-1;
            }
    }
    int salir=0;
    int opcion=0;
    while(salir==0){
        int limite;
        limite=count();
        printf("\nAt this moment, we have %d workers register\n", limite);
		 
        printf("Welcome\n");
		printf("Choose\n1. To register an entry."); //1. To register an entry.
		printf("\n2. To register an exit.");		//
		printf("\n3. To register a worker.");		
		printf("\n4. To close the program.\n");				//
        scanf("%d", &opcion);
        if (opcion==1){//es entrada
            
        printf("Which is your pin?\n"); 
        scanf("%d", &pintemporal);
        
        if (pintemporal<=0){
            printf("Not Valid Entry\n"); 
        }
        
            else if (pintemporal<=limite){
                ///Si se puede registrar
                if (matrix[pintemporal-1][1]==-1){ ///quiere decir que no ha entrado
                    entradaosalida(pintemporal, 0);///estado es es 0 es entrada 1 salida
                }
                else{
                    printf("It was already an entry of you\n"); 
                }
            }
            else{
                printf("At this moment there is %d workers, you can not used that pin\n", limite); 
            }
        }
        else if (opcion==2){
            
        printf("Which is your pin?\n");
        scanf("%d", &pintemporal);
        
        if (pintemporal<=0){
            printf("Not Valid Entry\n");
        }
        
            else if (pintemporal<=limite){
                ///Si se puede registrar
                if (matrix[pintemporal-1][1]!=-1){  //quiere decir que ya entro alguna vez
                    entradaosalida(pintemporal, 1);///estado es es 0 es entrada 1 salida
                }
                else{
                    printf("To register an exit you must register an entry\n"); 
                }
            }
            else{
                printf("At this moment there is %d workers, you can not used that pin\n", limite);
            }
        }
        else if (opcion==3){
            registrar();
        }
        else if (opcion==4){
            int flag=0;
            for (i=0; i<MAX; i++){
                if(matrix[i][0]*matrix[i][1]*matrix[i][2]>0&&matrix[i][3]*matrix[i][4]*matrix[i][5]<0){
                    flag=-1; 
                    printf("Error: The user, with PIN: %d register an entry but not an exit.\n\n", i+1);
                } 
            }
            if (flag==0){
            horario();
            printf("Have a good day:)\n");
            salir=1;
            }
        }
        else{
            printf("Option Not Available.\n\n"); //Option Not Available.
        }
    }
    //void entradaosalida(int pin, int estado){///estado es es 0 es entrada 1 salida
    //registrar();
    //registrar();
    //entradaosalida(2, 0);
    //entradaosalida(2, 1);
    return 0;
}

int count(){
    FILE* sistema = fopen("sistema.txt", "r");
    char c;
    int count=0;
    while ((c = fgetc(sistema)) != EOF) {
    if (c == '\n') {
      count++; // chequemos cuantos estan registrados hasta el momento
    }
    }
    
    return count;
}

void registrar(){
    int pin;
    pin=count()+1;
    char user[MAX];
    int domingo,lunes,martes,miercoles,jueves, viernes,sabado,hora,min,trabajo;
    
    printf("PIN of the User: %d\n", pin);
    registrados++;
    printf("Name of the User:");      
    scanf("%s", user);
    
     do{
        printf("\Write 0 (False) and 1 (True) the days the User will work: \nAn example: 0 1 1 0 1 1 0\nAt least there must be a 1\n");
        printf("Asegurese de escribir 7 numeros\n");
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        scanf("%d %d %d %d %d %d %d", &domingo, &lunes, &martes, &miercoles, &jueves, &viernes, &sabado);
    } while(domingo+lunes+martes+miercoles+jueves+viernes+sabado==0||domingo!=0&&domingo!=1||lunes!=0&&lunes!=1||martes!=0&&martes!=1||miercoles!=0&&miercoles!=1||jueves!=0&&jueves!=1||viernes!=0&&viernes!=1||sabado!=0&&sabado!=1);
    
    do {
        printf("\nWrite the hour and minutes u will work (separated by an space)\n"); 
        printf("An example: 10 : 30\n");
        scanf("%d %d", &hora, &min);
    } while(hora<0||hora>23||min<0||min>60);
        
    do {
        printf("\nHow many seconds will u work? (From 1 to 60)\n"); 
        scanf("%d", &trabajo);
    }while(trabajo<=0||trabajo>60);
    printf("Succesful Entries\n\n");
    
    FILE* escribirsistema = fopen("sistema.txt", "a");
    fprintf(escribirsistema, "%d %s %d %d %d %d %d %d %d %d %d %d\n",pin, user, domingo, lunes,martes,miercoles,jueves,viernes,sabado, hora, min, trabajo);
    fclose(escribirsistema);
}

void entradaosalida(int pin, int estado){///estado es es 0 es entrada 1 salida
    int diferencia=0; ///El trabajador con el pin <X> trabajo diferencia segundos
    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
    int actualsec=mitiempo->tm_sec;
    int actualmin=mitiempo->tm_min;
    int actualhora=mitiempo->tm_hour;
    int actualyear=mitiempo->tm_year+1900;
    int actualmes=mitiempo->tm_mon+1;
    int actualdia=mitiempo->tm_mday;
    int actualwdia=mitiempo->tm_wday;
    if (estado==0){ //es una entrada
    FILE* entrada = fopen("entradas.txt", "a");  //"Entries.txt","a"
    fprintf(entrada, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwdia, actualdia, actualmes, actualyear, actualhora, actualmin, actualsec);
    fclose(entrada);
    matrix[pin-1][0]=actualhora;
    matrix[pin-1][1]=actualmin;
    matrix[pin-1][2]=actualsec;
    printf("Entries registers\n");
    }
    if (estado==1){
    FILE* salida = fopen("salidas.txt", "a");  //"Exits.txt", "a"
    fprintf(salida, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwdia, actualdia, actualmes, actualyear, actualhora, actualmin, actualsec);
    fclose(salida);
    printf("Register EXITS\n");				//Register EXITS
    matrix[pin-1][3]=actualhora;
    matrix[pin-1][4]=actualmin;
    matrix[pin-1][5]=actualsec;
    FILE* reporte = fopen("reporte.txt", "a"); //"Report.txt" , "a"
    if (totaldesalidas==0){
        //se imprime un header en el reporte
        fprintf(reporte, "Report Generate at "); 
            switch(actualwdia){
                case 0:
                fprintf(reporte, "Sunday");
                break;
                case 1:
                fprintf(reporte, "Monday");
                break;
                case 2:
                fprintf(reporte, "Tuesday");
                break;
                case 3:
                fprintf(reporte, "Wednesday");
                break;
                case 4:
                fprintf(reporte, "Thursday");
                break;
                case 5:
                fprintf(reporte, "Friday");
                break;
                case 6:
                fprintf (reporte, "Saturday");
                break;
            }
        fprintf(reporte, " %d/%d/%d\n", actualdia, actualmes, actualyear);
    } ///Se impimio el header
    
    diferencia=(matrix[pin-1][3]*3600+matrix[pin-1][4]*60+matrix[pin-1][5])-(matrix[pin-1][0]*3600+matrix[pin-1][1]*60+matrix[pin-1][2]);
    int horapin=matrix[pin-1][0];
    int minpin=matrix[pin-1][1];
    int segundopin=matrix[pin-1][2];                                                                             //El trabajador con el pin <%d> entro a la hora: <%d:%d:%d> el dia: <%d/%d/%d> trabajo %d segundos
    fprintf(reporte, "The worker, with PIN <%d> enter at: <%d:%d:%d> the day: <%d/%d/%d> work %d seconds\n", pin, horapin, minpin, segundopin, actualdia, actualmes, actualyear, diferencia);
    fclose(reporte);
    matrix[pin-1][0]=-1;
    matrix[pin-1][1]=-1;
    matrix[pin-1][2]=-1;
    matrix[pin-1][3]=-1;
    matrix[pin-1][4]=-1;
    matrix[pin-1][5]=-1;
    
    totaldesalidas=9; //Whatever number instead of the 0 should work.
    }
}

void header(){
    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
    switch(mitiempo->tm_wday){
        case 0:
        printf("Today is Sunday\n");
        break;
        case 1:
        printf("Today is Monday\n");
        break;
        case 2:
        printf("Today is Tuesday\n");
        break;
        case 3:
        printf("Today is Wednesday\n");
        break;
        case 4:
        printf("Today is Thursday\n");
        break;
        case 5:
        printf("Today is Friday\n");
        break;
        case 6:
        printf ("Today is Saturday\n");
        break;
    }
    printf("Day: %d/%d/%d\n", mitiempo->tm_mday, mitiempo->tm_mon+1, mitiempo->tm_year+1900); //tm year desde 1900 en mes 0 es enero)
    printf("Hour: %d:%d\n", mitiempo->tm_hour, mitiempo->tm_min);
    printf("The maximum number the system can register is:  %d\n", USUARIOS);
} 

void horario(){
    time_t tiempoahora;
    time(&tiempoahora);
    int pinleido;
    char usuarioleido[MAX];
    int domingohorario;
    int luneshorario;
    int marteshorario;
    int miercoleshorario;
    int jueveshorario;
    int vierneshorario;
    int sabadohorario;
    int horaleida;
    int minutoleido;
    int trabajo;
    int i;
    struct tm *mitiempo = localtime(&tiempoahora);
    FILE* leersistema = fopen("sistema.txt", "r");
    FILE* escribirhorario = fopen("horario.txt", "w");
    char c;
    int count;
    while (fscanf(leersistema, "%d %s %d %d %d %d %d %d %d %d %d %d\n", &pinleido, usuarioleido, &domingohorario, &luneshorario, &marteshorario, &miercoleshorario, &jueveshorario, &vierneshorario, &sabadohorario, &horaleida, &minutoleido, &trabajo) == 12) {
    fprintf(escribirhorario, "The User: <%s> with PIN <%d> must enter at: %d:%d would work for <%d segundos> the days:\n", usuarioleido, pinleido,horaleida, minutoleido, trabajo);
    if (domingohorario==1)
    fprintf(escribirhorario, "Sunday ");
    if (luneshorario==1)
    fprintf(escribirhorario, "Monday ");
    if (marteshorario==1)
    fprintf(escribirhorario, "Tuesday ");
    if (miercoleshorario==1)
    fprintf(escribirhorario, "Wednesday ");
    if (jueveshorario==1)
    fprintf(escribirhorario, "Thursday ");
    if (vierneshorario==1)
    fprintf(escribirhorario, "Friday ");
    if (sabadohorario==1)
    fprintf(escribirhorario, "Saturday ");
    
    fprintf(escribirhorario, "\n\n");    
    }
    
    
    fclose(leersistema);
    fclose(escribirhorario);
}
//Helped By Rulygamer
