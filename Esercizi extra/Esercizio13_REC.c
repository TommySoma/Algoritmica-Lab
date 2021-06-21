/*	Definire una funzione (RICORSIVA) InserisciOrd_REC che, data una Lista ordinata, ed un elemento el, 
	inserisce quest’ultimo al posto giusto. 
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
void InserisciOrd_REC(ElementoDiLista **lista, int el);

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
	InserisciOrd_REC(&lista, x);
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

void InserisciOrd_REC(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
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
	//l'elemento va aggiunto al resto della lista
	InserisciOrd_REC(&(*lista)->next, el);

}




