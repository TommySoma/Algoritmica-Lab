//Trovare con una funzione ricorsiva l’elemento massimo in una lista

/*	input:	1		output: 12
		5
		2
		9
		4
		7
		12
		3
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
int massimo(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int trovato=0;
	int n;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista,n);
		else trovato=1;
	}
	stampa(lista);
	printf("%d\n", massimo(lista));

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

int massimo(ElementoDiLista *lista){

	int max;
	if(lista==NULL) exit(1); //caso lista vuota
	if((lista->next)==NULL){ //caso lista con un elemento
		return lista->info;
	}
	max=massimo(lista->next);
	if(max<(lista->info)) return(lista->info);
	else return max;
			
}
	
	
	
	
	
	
	
	
	
	
	
