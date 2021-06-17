#include <stdio.h>

int min (int a[3]);
void verificaminore (int c, int d);

int main(){

	int a[3], b[3], i;
	for(i=0;i<3;i++)
		scanf("%d",&a[i]);
	for(i=0;i<3;i++)
		scanf("%d",&b[i]);

	verificaminore(min(a), min(b));

	return 0;

}


int min(int a[3]){

	int m, i;
	m=a[0];
	for(i=1;i<3;i++)
		if(m>a[i]) m=a[i];

	return m;

}


void verificaminore(int c, int d){

	if(c<d) printf("TRUE\n");
	else printf("FALSE\n");

}
	

         
