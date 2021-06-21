/* 	si crei una funzione Ordinato che verifichi se l’andamento della lista è monotono crescente, cioè se ogni elemento è strettamente 	superiore al suo predecessore. si ritorni 1 se è verificata, 0 altrimenti.
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
int Ordinato(ElementoDiLista *lista);

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
	printf("%d", Ordinato(lista));
	
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

//funzione monotona

int Ordinato(ElementoDiLista *lista){

	ElementoDiLista *corr=lista;
	ElementoDiLista *prec=lista;
	if(corr->next==NULL) return 1;
	else{
		corr=corr->next;
		while(corr->next!=NULL){
			if(prec->info < corr->info){
				corr=corr->next;
				prec=prec->next;
			}
			else return 0;
		}
	}
	return 1;

}




