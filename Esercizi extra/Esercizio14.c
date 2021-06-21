/* 	Definire una funzione foo che, data una lista ed un intero el, inserisce quest’ultimo tra i primi due
	elementi consecutivi che siano, rispettivamente, strettamente minore e strettamente maggiore di el. 
	Se la lista non contiene due elementi consecutivi siffatti, la procedura inserisce el in testa.
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
void inserisci_primo(ElementoDiLista **lista, int el);

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
	printf("inserisci l'elemento da aggiungere\n");
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

void foo(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;
	ElementoDiLista *prec=*lista;
	ElementoDiLista *aux;
	int trovato=0;
	//guardo se ci sono almeno due elementi che rispettano la condizione
	if(corr->next!=NULL){ 
		corr=corr->next;
		while(corr!=NULL){		
			if(el > prec->info && el < corr->info){
				trovato=1;
				aux=malloc(sizeof(ElementoDiLista));
				aux->info=el;
				prec->next=aux;
				aux->next=corr;
				return;
			}
			else{
				prec=corr;
				corr=corr->next;
			}
		}

	}
	//altrimenti lo metto in testa
	if(!trovato) inserisci_primo(lista, el);
	

}

void inserisci_primo(ElementoDiLista **lista, int el){

	ElementoDiLista *aux;
	aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=*lista;
	*lista=aux;

}






