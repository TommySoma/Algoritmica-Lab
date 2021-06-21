/* 	Si codifichi in C la funzione somma avente il seguente prototipo:
	int somma(ElementoDiLista *lista, int M)
	Tale funzione riceve come parametro la testa della lista e un intero M. 
	Quindi, restituisce la somma dei soli valori della lista che sono multipli di M. 
	Se la lista è vuota, la funzione restituisce il valore -1. 
	
	input:	2 (valore M)		output: 20
		1
		2
		3
		4
		5
		6
		7
		8
		9
		-1
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
int somma(ElementoDiLista *lista, int M);

int main(){

	ElementoDiLista *lista=NULL;
	int trovato=0;
	int n, x;
	scanf("%d", &x);
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista,n);
		else trovato=1;
	}
	stampa(lista);
	printf("%d\n", somma(lista, x));
	

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

//funzione somma

int somma(ElementoDiLista *lista, int M){

	int sommatoria=0;
	if(lista==NULL) return -1;
	else{
		while(lista!=NULL){
			if(((lista->info)%M)==0){
				sommatoria=sommatoria+(lista->info);
				lista=lista->next;
			}
			else{
				lista=lista->next;
			}
		}
	}
	
	return sommatoria;
}

