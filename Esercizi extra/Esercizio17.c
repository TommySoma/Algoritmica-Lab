/*	Leggere in input una sequenza di numeri interi ordinati in ordine crescente.
	Dopo aver memorizzato la sequenza in una lista, inserire nella posizione corretta all’interno della lista, 
	tutti i numeri mancanti.
	Stampare in output la lista. Non devono essere usate altre liste o array di appoggio.
	
	input:	4		output: 4
		7			5
		8			6
		9			7
		15			8	
		17			9
		-1			10
					11
					12
					13
					14
					15
					16
					17
*/

					
#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserisci_primo(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);
void CompletaLista(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int trovato=0;
	int n;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_primo(&lista, n);
		else trovato=1;
	}
	stampa(lista);
	CompletaLista(lista);
	stampa(lista);

	return 0;
	
}

//inserzione in testa

void inserisci_primo(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=*lista;
	*lista=aux;
}

//stampa lista generica

void stampa(ElementoDiLista *lista){
	
	ElementoDiLista *aux;
	aux=lista;
	while(aux!=NULL){
		printf("%d -> ",aux->info);
		aux=aux->next;
	}
	printf("NULL\n");
	
}

void CompletaLista(ElementoDiLista *lista){

	ElementoDiLista *aux;
	while(lista->next!=NULL){
		if(lista->info > lista->next->info + 1){
			aux=malloc(sizeof(ElementoDiLista));
			aux->info=lista->next->info + 1;
			aux->next=lista->next;
			lista->next=aux;
		}
		else lista=lista->next;
	}
	
	return;
	
}






