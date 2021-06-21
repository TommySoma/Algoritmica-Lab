/*	Leggere in input una sequenza di n numeri floating point e inserirli in una lista.
	Definire poi una funzione OverMedia che stampi la media e riporti in un'altra lista solo gli elementi maggiori della media.
*/

#include <stdlib.h>
#include <stdio.h>

struct elemento{

	float info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

//inserzione in coda

void inserisci_ultimo(ElementoDiLista **lista, float el){

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

void stampa_lista(ElementoDiLista *lista){

	while(lista!=NULL){
		printf("%3.2f --> ", lista->info);
		lista=lista->next;
	}
	printf("NULL\n");
	return;
}

float media(ElementoDiLista *lista){

	float s=0.0;
	int n=0;
	while(lista!=NULL){
		s=s+lista->info;
		n=n+1;
		lista=lista->next;
	}
	return(s/n);
}

int main(){

	ElementoDiLista *lista1=NULL;
	ElementoDiLista *lista2=NULL;
	int n, i;
	float x;
	printf("inserisci il numero di elementi:\n");
	scanf("%d",&n);
	printf("inserisci i %d elementi:\n", n);
	for(i=0; i<n; i++){
		scanf("%f", &x);
		inserisci_ultimo(&lista1, x);
	}
	stampa_lista(lista1);
	float m=media(lista1);
	printf("%f\n", m);
	while(lista1!=NULL){
		if(lista1->info > m){
			inserisci_ultimo(&lista2, lista1->info);
		}
		lista1=lista1->next;
	}
	stampa_lista(lista2);
	
}








