/*	definire una funzione foo che, data una lista ed un intero el inserisce el dopo il terzo elemento di ℓ.
	Se quest’ultima non contiene almeno tre elementi, viene lasciata inalterata.
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
void foo(ElementoDiLista **lista, int el);

int main(){

	ElementoDiLista *lista=NULL;
	int trovato=0;
	int n, x;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista, n);
		else trovato=1;
	}
	stampa(lista);
	printf("inserisci l'elemento da aggiungere dopo il terzo elemento\n");
	scanf("%d", &x);
	foo(&lista, x);
	stampa(lista);
	
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


//funzione che aggiunge dopo il terzo elemento

void foo(ElementoDiLista **lista, int el){
	
	ElementoDiLista *corr=*lista; //uso corr per scorrere la lista
	ElementoDiLista *prec=NULL;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista)); //creo la nuova struttura
	aux->info=el; 
	aux->next=NULL;
	int conta=1;
	if(corr==NULL) *lista=aux; //se la lista è vuota prendi aux
	else{
		while(conta!=3 && corr!=NULL){
			prec=corr;		//fino a che conta non è uguale a 3 e la lista non è uguale a NULL, sposto i 2 puntatori
			corr=corr->next;       //in maniera che prec rimanga sempre dietro a corr e incrmento conta
			conta++;
		}
		if(corr==NULL) prec->next=aux; //se la lista è finita e non ho trovato quello che mi serve l'elemento dopo sarà aux
		else {                         //aux = elemento che voglio inserire
			prec=corr;		
			corr=corr->next;       //OK, sono arrivato al quarto elemento, adesso inserisco aux(elemento che voglio inserire)
			prec->next=aux;
			aux->next=corr;
		}
	}
}




