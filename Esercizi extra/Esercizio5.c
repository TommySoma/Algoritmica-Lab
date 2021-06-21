/*	Sia data una struttura dati dinamica di tipo lista semplicemente concatenata. Ogni nodo della lista contiene un numero intero 		come valore.
	Si scriva la funzione che, dato un vettore di N numeri interi, restituisce la lista contenente gli N elementi del vettore;
	l’elemento di indice 0 va in testa alla lista, ecc.
	Si scriva la funzione che stampa a terminale i valori contenuti nella lista in ordine inverso rispetto a quello della lista stessa 	(leggendoli dalla lista, non dal vettore).
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
void RecStampaInversa(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int i, N, x;
	printf("inserisci la linghezza del vettore\n");
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d",&x);
		inserisci_ultimo(&lista,x);
	}
	stampa(lista);
	RecStampaInversa(lista);
	printf("NULL");
	

	return 0;

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

//stampa lista inversa(RICORSIVA)

void RecStampaInversa(ElementoDiLista *lista){

	if(lista!=NULL){
		RecStampaInversa(lista->next);
		printf("%d -> ", lista->info);	
	}

}




