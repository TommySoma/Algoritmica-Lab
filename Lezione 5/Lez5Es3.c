#include <stdio.h>

float sum_pow(int n,float x);
float pw(float b,float e);

int main(){

	int n;
	float x;
	scanf("%d %f",&n,&x);
	printf("%.2f\n",sum_pow(n,x));

	return 0;
}

float sum_pow(int n,float x){

	int i;
	float tot=0;
	for(i=0;i<=n;i++){
		tot +=pw(x,i);
	 }

	return tot;

}


float pw(float b,float e){

	int i;
	float p=1;
	for(i=0;i<e;i++){
		p*=b;
	 }
	
	return p;

}
