#include <stdio.h>
#include <stdlib.h>

//tipo lista

struct elemento{
	int info;
	struct elemento *next;
} ;

typedef struct elemento ElementoDiLista;

void inserisci_ultimo(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *ListaDiElementi);
void cancella_primo(ElementoDiLista **lista, int el);

int main(){

	int el;
	int n;
	ElementoDiLista *lista = NULL;
	while(n>=0){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista, n);
		if(n<0){
			scanf("%d", &el);
			cancella_primo(&lista, el);
			stampa(lista);	
		}
	}
	printf("NULL");	
	return 0;
}

//inserzione in fondo

void inserisci_ultimo(ElementoDiLista **lista, int el){

	ElementoDiLista *ultimo; //puntatore per la scansione
	ElementoDiLista *new_el;
	new_el=malloc(sizeof(ElementoDiLista)); //creazione nuovo elemento
	new_el->info=el;
	new_el->next=NULL;
	if(*lista==NULL)
		*lista=new_el;
	else{
		ultimo=*lista;
		while(ultimo->next!=NULL)
			ultimo=ultimo->next; //concatenazione nuovo elemento in fondo alla lista
		ultimo->next=new_el;
	}
}
	
//stampa lista generica

void stampa(ElementoDiLista *ListaDiElementi){

	ElementoDiLista *aux=ListaDiElementi;
	while(aux != NULL){
		printf("%d -> " , aux->info);
		aux=aux->next;
		}
}

//cancellare primi n elementi

void cancella_primo(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;  //puntatore ausiliario che serve per scorrere
	int conta=1;
	int trovato=0;
	aux=*lista;    //faccio puntare il puntatore ausiliario alla testa della lista
	while(*lista!=NULL && !trovato){
		if(lista!=NULL) *lista=(*lista)->next;    //faccio scorrere la lista
		if(conta==el){
			free(aux);   //elimino l elemento che è rimasto puntato dal puntatore ausiliario
			trovato=1;
			}
		else{
			aux=aux->next;
			conta++;
			}
		
	}
}
