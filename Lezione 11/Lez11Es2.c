#include <stdio.h>
#include <stdlib.h>

//tipo lista

struct elemento{
	int info;
	struct elemento *next;
} ;

typedef struct elemento ElementoDiLista;

void inserisci_ultimo(ElementoDiLista **lista, int el);
int pari(ElementoDiLista *lista);
int dispari(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int n;
	int trovato=0;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista,n);
		else trovato=1;
	}
	printf("%d\n",dispari(lista));	
	printf("%d\n",pari(lista));

	
	return 0;

}

//inserzione in fondo (lettura)

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

//ricerca del primo elemento pari
	
int pari(ElementoDiLista *lista){

	ElementoDiLista *aux;
	aux=lista;
	int trovato=0;
	while(aux!=NULL){
		if(aux->info%2==0) return aux->info;
		else aux=aux->next;
	}
	if(!trovato) return -1;
}

//ricerca del primo elemento dispari

int dispari(ElementoDiLista *lista){

	ElementoDiLista *aux;
	aux=lista;
	int trovato=0;
	while(aux!=NULL){
		if(aux->info%2==1) return aux->info;
		else aux=aux->next;
	}
	if(!trovato) return -1;
}
