#include <stdio.h>
#include <stdlib.h>

//tipo lista

struct elemento{
	int info;
	struct elemento *next;
} ;

typedef struct elemento ElementoDiLista;

// inserzione

void inserisci_testa (ElementoDiLista **lista, int v){

	ElementoDiLista *aux;
	aux = malloc(sizeof(ElementoDiLista));
	aux->info = v;
	aux->next = *lista;
	*lista = aux;
	}
	
// rimozione

void rimuovi_testa (ElementoDiLista **lista){

	ElementoDiLista *aux;
	if (*lista != NULL){
		aux = *lista;
		*lista = (*lista)->next;
		free(aux);
		}
	}

//stampa lista generica

void stampa(ElementoDiLista *ListaDiElementi){

	ElementoDiLista *aux=ListaDiElementi;
	while(aux != NULL){
		printf("%d\n", aux->info);
		aux=aux->next;
		}
	}

int main(){

	int n;
	ElementoDiLista *lista = NULL;
	while(n>=0){
		scanf("%d",&n);
		if(n>0) inserisci_testa(&lista, n);
		else if(n==0) rimuovi_testa(&lista);
		}
	if(n<0)
	stampa(lista);
		
	return 0;
	}
	
