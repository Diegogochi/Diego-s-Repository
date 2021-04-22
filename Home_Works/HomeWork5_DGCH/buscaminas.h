#define forloop(i, x) for(i = 0; i != x; i++)// Me dijeron que era mas facil usandola:)
#define BOMB -1 		//Poner Bombas
#define AMBOMBS 15		//Cantidad de Bombas
#define CONTL 10 		//Numero de filas y columnas  (counter line)

#define PERD 'l' 
#define GANA 'O'
#define WHAT '?'

void bombs();
void neighbours(int); 
int open();
void kaboom();
void empty(int, int);


