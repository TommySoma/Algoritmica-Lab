/*	Si crei una funzione chiamata Picchi che restituisca il numero di picchi che la lista contiene.
	Definiamo picchi della lista quei valori che sono preceduti e seguiti nella lista da valori più piccoli della loro metà.
	Il primo e l’ultimo elemento della lista non possono essere picchi.
	
	input:	4		output:  2 (36 e 87 sono picchi)	
		9
		12
		36
		16
		23
		87
		34
		18
		64
		33

	36 e 87 sono picchi (perché 36/2=18, 18>12 e 18>16 e 87/2=43.5, 43.5>23 e 43.5>34)	
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
int Picchi(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int n;
	int trovato=0;
	while(!trovato){
		scanf("%d", &n);
		if(n>0) inserisci_ultimo(&lista, n);
		else trovato=1;
	}
	stampa(lista);
	printf("%d\n", Picchi(lista));
	
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

//funzione che conta i picchi

int Picchi(ElementoDiLista *lista){

	int conta=0;
	while(lista!=NULL && lista->next!=NULL && lista->next->next!=NULL){
		if(((float)(lista->info) < (float)(lista->next->info)/2) && ((float)(lista->next->next->info) < (float)(lista->next->info)/2))
			conta++;
		lista=lista->next;
	}
	
	return conta;

}






