#include <stdio.h>

void min_azzera(int a[]);

int main(){

	int x[10];
	int i;
	int min;
	for(i=0;i<10;i++)
		scanf("%d",(x+i));
	min_azzera(x);

	return 0;

}


void min_azzera(int a[]){

	int i;
	int b;
	b=*a;
	for(i=0;i<10;i++){
		if(*(a+i)<b) b=*(a+i);
		if(i%2!=0) *(a+i)=0;
		printf("%d\n",*(a+i));
		if(i==9)  printf("%d\n",b);
	}
}


