#include <stdio.h>
int main(){

    	int sec,min,ore;
    	scanf("%d",&sec);
    	ore=sec/3600;
    	min=(sec-ore*3600)/60;
    	sec=sec%60;
    	printf("%d h %d min %d s\n",ore,min,sec);
    	
    	return 0;
    	
}
