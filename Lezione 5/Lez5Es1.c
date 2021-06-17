#include <stdio.h>
//media di 10 numeri in un array
float media(int a[]);

int main(){

	int a[10];
	int i;
	for(i=0; i<10; i++)
		scanf("%d", &a[i]);
		printf("%.2f\n",media(a));
return 0;
}
float media(int a[]){
	int i;
	float somma=0;
	float conta=0;
	if(a[9]>0){
		for(i=0;i<10;i++)
	if(a[i]>0){
		somma=somma+a[i];
		conta++;
		}
	}
	else{
		for(i=0;i<10;i++)
			if(a[i]<0){
				somma=somma+a[i];
				conta++;
		}
	}
	somma=somma/conta;

return somma;
}
