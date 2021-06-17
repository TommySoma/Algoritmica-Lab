#include <stdio.h>
#include <stdlib.h>

//tipo lista

struct elemento{
	int info;
	struct elemento *next;
} ;

typedef struct elemento ElementoDiLista;

void inserisci_testa (ElementoDiLista **lista, int v);
void stampa_calcolo_somma(ElementoDiLista *ListaDiElementi);
void stampa_n_elementi(ElementoDiLista *ListaDiElementi);

//main

int main(){

	int n;
	ElementoDiLista *lista = NULL;
	while(n>=0){
		scanf("%d",&n);
		if(n>0) inserisci_testa(&lista, n);
		}
	if(n<0)
	stampa_calcolo_somma(lista);
	stampa_n_elementi(lista);
		
	return 0;
}

// inserzione

void inserisci_testa (ElementoDiLista **lista, int v){

	ElementoDiLista *aux;
	aux = malloc(sizeof(ElementoDiLista));
	aux->info = v;
	aux->next = *lista;
	*lista = aux;
}
	
//stampa calcolo somma

void stampa_calcolo_somma(ElementoDiLista *ListaDiElementi){

	ElementoDiLista *aux=ListaDiElementi;
	int somma=0;
	while(aux != NULL){
		somma=somma + (aux->info);
		aux=aux->next;
		}
	printf("%d\n", somma);	
}

//stampa calcolo N elementi

void stampa_n_elementi(ElementoDiLista *ListaDiElementi){

	ElementoDiLista *aux=ListaDiElementi;
	int conta=0;
	float s=0;
	while(aux != NULL){
		s=s + (aux->info);
		aux=aux->next;
		}
	s=s/4;
	ElementoDiLista *corr=ListaDiElementi;
	while(corr != NULL){
		if((corr->info)>(s)){
			conta=conta+1;
		}
	corr=corr->next;
	}
	printf("%d\n", conta);	

}
	
