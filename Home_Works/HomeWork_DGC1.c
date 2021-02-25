#include <stdio.h>
#include <string.h> 

#define MAX 100
void parentless(char line[MAX], char maxline[MAX]); // Eliminates the < >
void spaceless(char line [MAX], char maxline[MAX]); // Change the '\t' and ' '  for '_'   
void strong(char line [MAX], char maxlinewith[MAX]); //Looks <strong> and <\strong> to change the '\t' and ' '  for '_' 
char line[MAX], maxline[MAX];
int saca(); // Here the line is gave to us

int main() {
  extern char line[];
  char maxline[MAX];
  char maxlinewith[MAX];
  char liness[MAX];
  char linessstrong[MAX];
  int ign = 0,ignable = 0, ignimg = 0, ignforms =0, spa = 0;
  int l = 0;


  while ((l = saca()) == 0) {
    if (strstr(line, "<form") != NULL) { // if we found  "<Form" we do not read it
      ignforms = 1;
    }
    if (strstr(line, "<table") != NULL) {
      ignable = 1;
    }
    if (strstr(line, "<script") != NULL) {
      ign = 1;
    }
    if (strstr(line, "<img") != NULL) {
      ignimg = 1;
    }

    if (strstr(line, "<div") != NULL) {
      ign = 1;
    }
    if (!ignable&&!ignforms&&!ignimg && !ign && strstr(line, "<html>") == NULL && strstr(line, "<body>") == NULL && strstr(line, "</html>") == NULL && strstr(line, "</body>") == NULL) {

    if (strstr(line, "<h1") != NULL || strstr(line, "<h2") != NULL || strstr(line, "<h3") != NULL ||  strstr(line, "<h4") != NULL || strstr(line, "<h5") != NULL  || strstr(line, "<h6") != NULL  ) {
      spaceless(line,maxline);
      parentless(maxline, maxlinewith);
      printf("%s\n", maxlinewith);

    }
    else if (strstr(line, "<strong>") != NULL) {
      strong(line, linessstrong);
      parentless(linessstrong, maxlinewith);
      printf("%s\n", maxlinewith);
    }


      else{
      parentless(line,maxlinewith);
      printf("%s\n", maxlinewith);
    }
    }

    if (strstr(line, "</script>") != NULL) { // if we found  "</script>" stop ignoring
      ign = 0;
    }
    if (strstr(line, "</div>") != NULL) {
      ign = 0;
    }
    if (strstr(line, ">") != NULL) {
      ignimg = 0;
    }
    if (strstr(line, "</form>") != NULL) {
      ignforms = 0;
    }
    if (strstr(line, "</table>") != NULL) {
      ignable = 0;
    }

  }
  return 0;
}

int saca() { // Here the line is gave to us
  extern char line[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {

        line[i++] = c;

  }
  line[i] = '\0'; // caracter end of string
  return c == EOF;
}

// Change the '\t' and ' '  for '_' 
void spaceless(char chain [MAX], char chainless[MAX])
{
int a;
for (a=0;a<MAX;a++){ /*Read  the string, one by one */
   if (chain[a] != ' '&& chain[a] != '\t'){
    chainless [a] = chain[a];
   }
   else{
    chainless[a]= '_';
   }
}

}
// Eliminates the < >
void parentless(char chain[MAX], char chainless[MAX]){
int a;
int b = 0, c = 0;

for (a = 0; a < MAX; a++) {
    if (chain[a]=='<'){
        c++;
    }
    if (chain[a]=='>'){
        c--;
    }
    if (chain[a]!='>'&&chain[a] != '<' &&c!=1){
        chainless[b] = chain[a];
        b++;
    }

}
}

//Looks <strong> and <\strong> to change the '\t' and ' '  for '_' void strong(char chain[MAX], char chainless[MAX]){
void strong(char chain[MAX], char chainless[MAX]){
int a;
int c=0;

for ( a = 0;a < MAX; a++){
   if (chain[a]== '<' && chain [a+1] == 's' && chain [a+2] == 't' && chain[a+3] == 'r' && chain[a+4] == 'o' && chain[a+5] == 'n' && chain[a+6] == 'g' && chain[a+7] == '>'){
    c = 1;
   }
    if (chain[a] == '<' && chain[a+1] == '\\' && chain[a+2] == 's' && chain [a+3] == 't' && chain[a+4] == 'r' && chain[a+5] == 'o' && chain[a+6] == 'n' && chain[a+7] == 'g' && chain[a+7] == '>'){
    c = 0;
   }
   if (c==1){
    if (chain[a] != ' ' && chain[a] != '\t'){
    chainless[a] = chain[a];
   }
   else{
    chainless[a]= '_';
   		}
	}
   if (c==0){
    chainless[a] = chain[a];
   		}
	}
}
