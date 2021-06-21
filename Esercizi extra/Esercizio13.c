/*	Definire una funzione InserisciOrd che, data una Lista ordinata, ed un elemento el, inserisce quest’ultimo al posto giusto. */

#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserisci_ultimo(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);
void InserisciOrd(ElementoDiLista **lista, int el);

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
	printf("inserisci l'elemento da aggiungere\n");
	scanf("%d", &x);
	InserisciOrd(&lista, x);
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

//funzione che inserisce l'elemento in posizione corretta

void InserisciOrd(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	ElementoDiLista *corr;
	ElementoDiLista *prec;
	//la lista non contiene elementi
	if((*lista)==NULL){
		(*lista)=malloc(sizeof(ElementoDiLista));
		(*lista)->info=el;
		(*lista)->next=NULL;
		return;
	}
	//l'elemento va inserito in prima posizione
	if((*lista)->info >= el){
		aux=malloc(sizeof(ElementoDiLista));
		aux->info=el;
		aux->next=*lista;
		*lista=aux;
		return;
	}
	//la lista ha più di un elemento
	corr=*lista;
	while(corr->next!=NULL){
		if(corr->next->info >= el){
			prec=corr;
			corr=corr->next;
			aux=malloc(sizeof(ElementoDiLista));
			prec->next=aux;
			aux->info=el;
			aux->next=corr;
			return;
		}
		corr=corr->next;
	}
	//se arrivo qui, l'elemento va inserito in fondo
	aux=malloc(sizeof(ElementoDiLista));
	corr->next=aux;
	aux->info=el;
	aux->next=NULL;

	return;

}




