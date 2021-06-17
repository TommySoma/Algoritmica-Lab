#include <stdio.h>

void count_larger(int a, int b[5], int c);

int main(){

	int a, i;
	int b[5];
	int c=5;
	scanf("%d",&a);
	for(i=0;i<5;i++){
		scanf("%d",&b[i]);}
	count_larger(a,b,c);

	return 0;

}

void count_larger(int a, int b[5], int c){

	int i;
	int conta=0;
	for(i=0;i<5;i++){
		if(b[i]>a) conta++;}
	printf("%d\n",conta);

}
