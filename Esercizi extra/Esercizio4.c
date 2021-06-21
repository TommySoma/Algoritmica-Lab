/* definire una funzione MinEven che, data una ListaDiInteri restituisce la posizione (puntatore) del minimo elemento pari nella lista 		(restituisce NULL se la lista non contiene elementi pari).
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
int MinEven(ElementoDiLista *lista);
int FirstEven(ElementoDiLista *lista);

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
	printf("%d\n", MinEven(lista));
	

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

int FirstEven(ElementoDiLista *lista){

	while(lista!=NULL){
		if(((lista->info)%2)==0) return lista->info;
		else lista=lista->next;
	}
		return NULL;
		
}

int MinEven(ElementoDiLista *lista){

	int min_pari=FirstEven(lista);
	int pari;
	while(lista!=NULL){
		if(((lista->info)%2)==0){ 
			pari=lista->info;
			if(pari < min_pari){
				min_pari=pari;
			}
			lista=lista->next;
		}
		else{
			lista=lista->next;
		}
	}
	
	return min_pari;
	
}





