#define MAX 80
typedef struct treenode {
  char* usuario; //usuario 
  char* contraseña; //contraseña 

  struct treenode* niñoizquierdo;
  struct treenode* niñoderecho;
  unsigned int depth;
} node;

char linea[MAX], contraseña[MAX], usuario[MAX];
int saca(); // Function that give us the line
void get (char l[MAX],char p[MAX],char u[MAX]);                       //Funcion que nos da el usuario y la contraseña y nos permite agregar gente
node* insert(char* u, char* p, node* pos, int d);                     // Funcion añade usuario
void alpha(node* position);                                           // Funcion que ordena alfabeticamente
  void delete(node* position, char* u, char* p, int* n);              // Funcion elimina usuario
/* */
