/*	definire una funzione foo che, data una lista ed un intero el inserisce el dopo l’ultimo elemento della lista maggiore di el.
	Se la lista non contiene alcun elemento maggiore di el, la procedura lascia la lista inalterata.
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
void foo(ElementoDiLista **lista, int el);

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
	printf("inserisci l'elemento da aggiungere dopo l'ultimo elemento maggiore della lista\n");
	scanf("%d", &x);
	foo(&lista, x);
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

//funzione

void foo(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;
	ElementoDiLista *tmp;
	while(corr!=NULL){
		if((corr->info) > el)
			tmp=corr;
		corr=corr->next;
	}
	ElementoDiLista *aux;
	if(tmp!=NULL){
		aux=malloc(sizeof(ElementoDiLista));
		aux->info=el;
		aux->next=tmp->next;
		tmp->next=aux;
	}
}


	
