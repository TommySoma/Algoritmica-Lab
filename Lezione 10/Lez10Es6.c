#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void RecStampaInversa(ElementoDiLista *lista);
void inserisci_testa(ElementoDiLista **lista, int el);

int main(){
	
	int n;
	ElementoDiLista *lista = NULL;
	while(n>=0){
		scanf("%d",&n);
		if(n>=0) inserisci_testa(&lista, n);
		}

	if(n<0)RecStampaInversa(lista);
	printf("NULL");
	return 0;
}

void RecStampaInversa(ElementoDiLista *lista){

	if(lista!=NULL){
		RecStampaInversa(lista->next);
		printf("%d -> ", lista->info);	
	}
	
}

void inserisci_testa(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	aux = malloc(sizeof(ElementoDiLista));
	aux->info = el;
	aux->next = *lista;
	*lista = aux;
}

