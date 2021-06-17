#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserisci_ordinato(ElementoDiLista **lista, int el);
int prodotto_interi(ElementoDiLista **lista, int n, int m);

int main(){

	ElementoDiLista *lista=NULL;
	int n;
	int m;	
	scanf("%d %d",&n,&m);
	if(n<m){
		int x;
		int trovato=0;
		while(!trovato){
			scanf("%d",&x);
			if(x>=0) inserisci_ordinato(&lista,x);
			else trovato=1;
		}
		printf("%d\n",prodotto_interi(&lista,n,m));

	}
	
	return 0;

}

void inserisci_ordinato(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;
	ElementoDiLista *prec=NULL;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	while(corr!=NULL && corr->info!=el && corr->info<el){
		prec=corr;
		corr=corr->next;
		}
	if(prec==NULL){
		*lista=aux;
		aux->next=corr;
		}
	else{
		if(corr==NULL){
			prec->next=aux;
			aux->next=corr;
			}
		else{
			prec->next=aux;
			aux->next=corr;
			}
	}
}

int prodotto_interi(ElementoDiLista **lista, int n, int m){

	ElementoDiLista *prec=*lista;
	ElementoDiLista *succ=*lista;
	ElementoDiLista *corr=*lista;
	int prod=0;
	if(corr==NULL) return -1;
	else {
		while(prec->info<n){
			prec=prec->next;
			if(prec==NULL) return 1;
		}
		while(succ->info<m) succ=succ->next;
		corr=prec->next;
		while(corr!=succ){
			if(prod!=0) prod=prod*corr->info;
			else prod=corr->info;
			corr=corr->next;
		}
	
	return prod;

	}

}
