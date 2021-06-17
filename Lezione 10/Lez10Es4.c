#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void RecStampa(ElementoDiLista *lista);
void inserisci_testa(ElementoDiLista **lista, int el);
void cancella_multipli_ric(ElementoDiLista **lista, int el);
int multipli(int x, int y);

void main(){
	

	ElementoDiLista *lista = NULL;
	int fine=0;
	int n;
	int el;
	scanf("%d",&el);
	while(fine==0){
		scanf("%d",&n);
		if(n>=0) inserisci_testa(&lista, n);
		else fine=1;
		}
		cancella_multipli_ric(&lista, el);
		RecStampa(lista);
}

void RecStampa(ElementoDiLista *lista){

	if(lista!=NULL){
		printf("%d -> ", lista->info);
		RecStampa(lista->next);
		}
	else printf("NULL");
}

void inserisci_testa(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	if(*lista==NULL){
		aux = malloc(sizeof(ElementoDiLista));
		aux->info = el;
		aux->next = NULL;
		*lista = aux;
	}
	else{
		aux = malloc(sizeof(ElementoDiLista));
		aux->info = el;
		aux->next = *lista;
		*lista = aux;
		}
}

void cancella_multipli_ric(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	if(*lista!=NULL){
		if(multipli((*lista)->info, el)){
			aux=*lista; //cancella tutti i multipli di el
			*lista=aux->next;
			free(aux);
			cancella_multipli_ric(&(*lista), el);
	}
	else cancella_multipli_ric(&((*lista)->next), el);
	}
}

int multipli(int x,int y){
	int ok=0;
	if ((x%y)==0) ok=1;  //controlla se x è multiplo di y
	else ok=0;
	
	return ok;
}
