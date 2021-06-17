#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void RecStampa(ElementoDiLista *lista);
void inserisci_testa(ElementoDiLista **lista, int el);

int main(){

	int n;
	ElementoDiLista *lista = NULL;
	while(n>=0){
		scanf("%d",&n);
		if(n>=0) inserisci_testa(&lista, n);
		}
	if(n<0)RecStampa(lista);
		
	return 0;
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
	aux = malloc(sizeof(ElementoDiLista));
	aux->info = el;
	aux->next = *lista;
	*lista = aux;
}
	


