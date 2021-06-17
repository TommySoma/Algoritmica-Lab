#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void inserisci_primo(ElementoDiLista **lista, int el);
void inserisci_ultimo(ElementoDiLista **lista,int el);
void rimuovi_prima_occ(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);

//inserzione in testa

void inserisci_primo(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=*lista;
	*lista=aux;
}

//inserzione in coda

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

//rimozione prima occorrenza, se non c'è el non fare niente

void rimuovi_prima_occ(ElementoDiLista **lista, int el){
	
	el=el*(-1);	
	ElementoDiLista *aux;
	ElementoDiLista *prec=NULL; //inizializzo
	aux=*lista; //puntatore ausiliaro alla testa della lista
	if(aux!=NULL){
		while(aux!=NULL && aux->info!=el){
			prec=aux;
			aux=aux->next;
		}
		if(aux!=NULL){
			if(prec==NULL){
				*lista=aux->next;
				free(aux);
			} else {
				if(aux->next==NULL){
					prec->next=NULL;
					free(aux);
				} else {
					prec->next=aux->next;
					free(aux);
				}
			}
		}
	}

}


void stampa(ElementoDiLista *lista){
	
	ElementoDiLista *aux;
	aux=lista;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->next;
	}
}

//main

int main(){

	int n;
	int trovato=0;
	ElementoDiLista *lista=NULL;
	while(!trovato){
		scanf("%d",&n);
		if(n<0) rimuovi_prima_occ(&lista,n);
		if(n==0) trovato=1;
		if(n>0){  
			if(n%2==0) inserisci_primo(&lista,n);
			else inserisci_ultimo(&lista,n);
		 }
	}
	stampa(lista);

	return 0;

}
