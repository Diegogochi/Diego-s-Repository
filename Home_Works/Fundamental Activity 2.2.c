#include <stdio.h>

int main(){
	int x = 100 , k = 29;
	int y = (x|(1<<k)) & ~(1 << k/2);
	
	printf("%d -> %d \n", x, y);
	
	
	
}
