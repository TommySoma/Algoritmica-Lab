/*	Letta in input una lista di numeri interi stamparla e poi ordinarla utilizzando l’algoritmo Selection Sort.
	Stampare la lista ordinata.
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserisci_ultimo(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);
void scambia(int *a, int *b);
void SelectionSort(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int trovato=0;
	int n, x;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista, n);
		else trovato=1;
	}
	stampa(lista);
	SelectionSort(lista);
	stampa(lista);
	
}

//inserzione in coda

void inserisci_ultimo(ElementoDiLista **lista, int el){

	ElementoDiLista *ultimo;
	ElementoDiLista *new_el=malloc(sizeof(ElementoDiLista));
	new_el->info=el;
	new_el->next=NULL;
	if(*lista==NULL)
		*lista=new_el;
	else{
		ultimo=*lista;
		while(ultimo->next!=NULL){
			ultimo=ultimo->next;
		}
		ultimo->next=new_el;
	}
}

//stampa lista generica

void stampa(ElementoDiLista *lista){
	
	ElementoDiLista *aux;
	aux=lista;
	while(aux!=NULL){
		printf("%d -> ",aux->info);
		aux=aux->next;
	}
	printf("NULL");
	printf("\n");
}

void scambia(int *a, int *b){

	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	return;

}

void SelectionSort(ElementoDiLista *lista){

	ElementoDiLista *aux;
	while(lista!=NULL){
		aux=lista->next;
		while(aux!=NULL){
			if(lista->info > aux->info)
				scambia(&(lista->info), &(aux->info));
			aux=aux->next;
		}
		lista=lista->next;
	}

	return;

}

