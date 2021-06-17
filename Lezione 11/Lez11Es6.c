#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void Lettura(ElementoDiLista **lista, int el);
void Stampa(ElementoDiLista *lista);


int main(){

	ElementoDiLista *lista=NULL;
	int n;
	int trovato=0;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) Lettura(&lista,n);
		else trovato=1;
	}
	Stampa(lista);


	return 0;

}

//inserzione in lista ordinata(con duplicati)

void Lettura(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;
	ElementoDiLista *prec=NULL;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=NULL;
	while(corr!=NULL && corr->info<el){
		prec=corr;
		corr=corr->next;
	}
	if(prec==NULL){
		*lista=aux;
		aux->next=corr;
	} else {
		if(corr==NULL){
			prec->next=aux;
			aux->next=corr;
		} else {
			prec->next=aux;
			aux->next=corr;
		}
	}

}

void Stampa(ElementoDiLista *lista){

	while(lista!=NULL){
		printf("%d -> ",lista->info);
		lista=lista->next;
	}
	printf("NULL\n");

}
