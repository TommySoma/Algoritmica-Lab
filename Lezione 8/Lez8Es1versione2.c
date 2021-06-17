#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef ElementoDiLista* ListaDiElementi;

ElementoDiLista* inserisci_testa(ElementoDiLista *lista, int el){

	ElementoDiLista *aux;
	aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=lista;
	return aux;
	}

ElementoDiLista* rimuovi_testa(ElementoDiLista *lista){

	ElementoDiLista *aux;
	if (lista != NULL){
		aux=lista;
		lista=lista->next;
		free(aux);
		}
	return lista;
}

void stampa(ElementoDiLista *lista){

	ElementoDiLista* aux=lista;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->next;
		}
}	

int main(){

	int n;
	int trovato=0;
	ElementoDiLista *lista=NULL;
	while(n>=0){
		scanf("%d",&n);
		if(n>0) lista=inserisci_testa(lista,n);
		else if(n==0) lista=rimuovi_testa(lista);
		}
	if(n<0) stampa(lista);

	return 0;
}
