#include <stdio.h>

int main(){

    	int a,b,a1,b1;
    	scanf("%d",&a);
    	scanf("%d",&b);
    	for (a1=0; a1<a; a1++){
        	for(b1=0; b1<b; b1++)
        		if(a1==0 || a1==(a-1))
        			printf("*");
        		else
        			if(b1==0 || b1==(b-1))
        				printf("*");
        			else
        				printf(" ");

        printf("\n");
        }
        
	return 0;
	
}
