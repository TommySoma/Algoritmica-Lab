#include <stdio.h>
#define DIM 3

struct persona 
{	char nome[10];
	struct persona * mamma;
	struct persona * babbo;
};
typedef struct persona Persona;

void readFamily(Persona * a)
{	scanf("%10s",(a[0].nome));
	scanf("%10s",(a[1].nome));
	scanf("%10s",(a[2].nome));
	a[0].mamma = &a[1];
	a[0].babbo = &a[2];
	a[1].mamma = NULL;
	a[1].babbo = NULL;
	a[2].mamma = NULL;
	a[2].babbo = NULL;
	
}


void printFamily(Persona * a,int dim)
{	for(int i=0;i<dim;i++)
{		printf("%s\n",a[i].nome);
		if(a[i].mamma == NULL)printf("Sconosciuto");
		else printf("%s",a[i].mamma->nome);
		if(a[i].mamma == NULL)printf("Sconosciuto");
		else printf("%s",a[i].babbo->nome);
		printf("\n");
	}
}

int main(void)
{	Persona famiglia[DIM];	
	readFamily(famiglia);
	printFamily(famiglia, DIM);
	printf("\n");
    
    
    return 0;
    
}
