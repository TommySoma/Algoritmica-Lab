#include <stdio.h>

void ordered_swap (int *a, int *b, int *c);

int main(){

	int x;
	int y;
	int z;
	scanf("%d %d %d", &x, &y, &z);
	ordered_swap(&x,&y,&z);
	printf("%d\n", x); //numero minore
	printf("%d\n", y); //numero mediano
	printf("%d\n", z); //numero maggiore
return 0;
}
void swap(int*a, int*b){

int c=*a;
*a=*b;
*b=c;
}

void ordered_swap (int *a, int *b, int *c){

if(*a>*b) swap(a,b);
if(*b>*c) swap(b,c);
if(*a>*b) swap(a,b);

}

		 

	

		
