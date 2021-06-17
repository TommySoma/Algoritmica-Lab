#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserzione(ElementoDiLista **lista,int el);
void stampa(ElementoDiLista *lista);


int main(){

	ElementoDiLista *lista=NULL;
	int trovato=0;
	int n;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserzione(&lista,n);
		else trovato=1;
	}
	stampa(lista);

	return 0;
}


void inserzione(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;//puntatore per scorrere la lista
	ElementoDiLista *prec=NULL;//puntatore inizializzato 
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));//nuova struttura che mi serve per aggiungere l'elemento
	aux->info=el;// asegno ad aux l'elemento
	while(corr!=NULL && corr->info<el){ //scorro la lista, elemento per elemento fino a che la guardia del while non diventa falsa
		prec=corr;
		corr=corr->next;
	}
	if(prec==NULL){                //caso in cui sia il primo elemento
		*lista=aux;            //punto la lista alla nuova struttura aux
		aux->next=corr;        //successivamente, ripunto il campo next della struttura all'elemento della lista corrente
	} 
	else{
		if(corr==NULL){        //caso in cui sia l'ultimo elemento
			prec->next=aux;//punto il campo next dell'elemento precedente alla struttura aux
			aux->next=corr;//punto il campo next della struttura aux a corr
			} 	
		else{                  //caso in cui NON sia l'ultimo elemento
			prec->next=aux;//punto il campo next dell'elemento precedente alla struttura aux
			aux->next=corr;//punto il campo next della struttura aux a corr
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

