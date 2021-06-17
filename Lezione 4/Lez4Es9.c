#include <stdio.h>

int main(){

	int a[5];
	int i;
	for(i=0; i<5; i++)
    		scanf("%d", &a[i]);
	int b[5];
	for(i=0;i<5;i++)
    		scanf("%d", &b[i]);
	printf("[");
	for(i=0;i<4;i++)
    		printf("%d,", a[i]);
	printf("%d", a[4]);
	printf("]\n");
	printf("[");
	for(i=0;i<4;i++)
    		printf("%d,",b[i]);
	printf("%d",b[4]);
	printf("]\n");
	printf("[");
	for(i=0;i<4;i++)
    		printf("%d,", a[i]+b[i]);
	printf("%d", a[4]+b[4]);
	printf("]\n");

	return 0;
	
}

