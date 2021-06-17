#include <stdio.h>

void multipli (int a, int b);

int main(){

	int n, m;
	scanf("%d",&n);
	scanf("%d",&m);
	multipli(n,m);

	return 0;

}


void multipli (int a, int b){

	int i=1;
	int som=0;
	while(som<=a){
		som=i*b;
		if(som<=a) printf("%d\n",som);
		i++;
	}

}
