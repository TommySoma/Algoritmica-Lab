#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void RecStampa(ElementoDiLista *lista);
void inserisci_testa(ElementoDiLista **lista, int el);
void aggiungi_menoUno_PrimaDipari(ElementoDiLista **lista);
int pari(int x);

int main(){
	
	ElementoDiLista *lista = NULL;
	int n;
	int trovato=0;
	while(trovato==0){
		scanf("%d",&n);
		if(n>=0) inserisci_testa(&lista, n);
		else trovato=1;
		}
	aggiungi_menoUno_PrimaDipari(&lista);
	RecStampa(lista);
		
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

int pari(int x){

	int p;
	if(x%2==0) p=1; //ritorna vero se il valore è pari
	else p=0;
	
	return p;
}

void aggiungi_menoUno_PrimaDipari(ElementoDiLista **lista){
	
	ElementoDiLista *corr;
	corr=*lista;
	if(corr!=NULL){
		if(pari(corr->info)){
			ElementoDiLista *aux;
			aux = malloc(sizeof(ElementoDiLista));
			aux->info=-1;                 //aggiungo -1 prima dei valori pari
			aux->next=corr;
			*lista=aux;
			aggiungi_menoUno_PrimaDipari(&(*lista)->next->next);
		}
		else aggiungi_menoUno_PrimaDipari(&(*lista)->next);
	}
}
		
		
