#include <stdio.h>
int main(){

	int n;
	scanf("%d", &n);
	int linea;
	while(n>=1){
    		linea=1;
    		while(linea<=n){
        		printf("*");
        		linea++;
        
    		}
    		n=n-2;
    		printf("\n");
	}	
	
	return 0;
	
}
