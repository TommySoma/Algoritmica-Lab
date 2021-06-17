#include <stdio.h>
#include <stdlib.h>

int Pot2(int base, int esp){

	if(esp==0) return 1;
	if(esp==1) return base;
	
	return base*Pot2(base, esp-1);
}

int main(){
	
	int b=2;
	int e;
	scanf("%d", &e);
	printf("%d",Pot2(b,e));
	
	return 0;
}
	 
