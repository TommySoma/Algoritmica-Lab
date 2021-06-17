#include <stdio.h>

typedef struct{

	int codice;
	int mese;
	int anno;
	int stipendio;

} dipendenti;

void aumento(int* a, int b);


int main(){

	dipendenti dipendente1, dipendente2;
	int percentuale;
	scanf("%d %d %d %d",&dipendente1.codice,&dipendente1.mese,&dipendente1.anno,&dipendente1.stipendio);
	scanf("%d %d %d %d",&dipendente2.codice,&dipendente2.mese,&dipendente2.anno,&dipendente2.stipendio);
	scanf("%d",&percentuale);
	if(dipendente1.anno<2000 || (dipendente1.anno==2000 && dipendente1.mese<5))
		aumento(&dipendente1.stipendio,percentuale);
	if(dipendente1.stipendio>1200) printf("%d %d\n",dipendente1.codice,dipendente1.stipendio);
	if(dipendente2.anno<2000 || (dipendente2.anno==2000 && dipendente2.mese<5))
		aumento(&dipendente2.stipendio,percentuale);
	if(dipendente2.stipendio>1200) printf("%d %d\n",dipendente2.codice,dipendente2.stipendio);

	return 0;

}


void aumento(int* a,int b){

	*a=*a+((*a*b)/100);
}
