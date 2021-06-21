/*	Si crei una funzione  RICORSIVA int EquipotentiREC(ElementoDiLista *lista1, ElementoDiLista *lista2) che restituisca 1 se le liste sono
	equipotenti, 0 altrimenti.
	Due liste di interi si dicono equipotenti se sono di uguale lunghezza e, confrontando i valori in posizioni corrispondenti,
	risulta che i valori della prima lista maggiori dei corrispondenti valori nella seconda sono esattamente in numero uguale ai
	valori della seconda lista maggiori dei corrispondenti valori nella prima.
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
int EquipotentiREC(ElementoDiLista *lista1, ElementoDiLista *lista2);

int main(){

	ElementoDiLista *lista1=NULL;
	ElementoDiLista *lista2=NULL;
	int trovato=0;
	int n;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista1, n);
		else trovato=1;
	}
	trovato=0;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista2, n);
		else trovato=1;
	}
	stampa(lista1);
	stampa(lista2);
	printf("%d\n", EquipotentiREC(lista1, lista2));
	
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

//funzione che controlla

int controlla(ElementoDiLista *lista1, ElementoDiLista *lista2, int bilancio){

	if(lista1==NULL || lista2==NULL)
		return (lista1==lista2 && bilancio==0);
	if(lista1->info > lista2->info) 
		bilancio++;
	else if(lista1->info < lista2->info)
		bilancio--;
		
	return controlla(lista1->next, lista2->next, bilancio);

}

//funzione Equipotenti

int EquipotentiREC(ElementoDiLista *lista1, ElementoDiLista *lista2){

	return controlla(lista1, lista2, 0);
	
}



