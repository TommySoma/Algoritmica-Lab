/*	Si consideri una lista dinamica di interi (tutti diversi tra loro).
	si definisca la funzione Mediana(ElementoDiLista *lista) che ritorna l'elemento nel mezzo alla lista.
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
void Mediana(ElementoDiLista *lista);

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
	Mediana(lista);
	
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

//funzione mediana

void Mediana(ElementoDiLista *lista){
	
	ElementoDiLista *corr=lista;
	int conta=0;
	if(lista==NULL) return;
	else{
		while(corr!=NULL){
			conta++;
			corr=corr->next;
		}
	}
	if(conta%2==0) printf("l'elemento mediano non c'è\n");
	else{
		corr=lista;
		int numero=0;
		conta=(conta-1)/2;
		printf("%d\n", conta);
		while(corr!=NULL){
			if(numero==conta){
				printf("%d\n", corr->info);
				return;
			}
			else{
				numero++;
				corr=corr->next;
			}
		}
	}
}
		
		
		
