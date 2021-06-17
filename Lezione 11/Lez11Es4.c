#include <stdio.h>
#include <stdlib.h>

//tipo lista

struct elemento{
	int info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;

void inserisci_ultimo(ElementoDiLista **lista, int el);
void inserisci_in_mezzo(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista=NULL;
	int n, m;
	int trovato=0;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserisci_ultimo(&lista,n);
		else trovato=1;
	}
	scanf("%d", &m);	
	inserisci_in_mezzo(&lista, m);
	stampa(lista);
	
	return 0;

}

//inserzione in fondo (lettura)

void inserisci_ultimo(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=NULL;
	if(corr==NULL) *lista=aux;
	else {
		while(corr->next!=NULL)
			corr=corr->next;
			corr->next=aux;
	}

}

//inserzione in mezzo (inserzione dopo il quarto elemento)

void inserisci_in_mezzo(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista; //uso corr per scorrere la lista
	ElementoDiLista *prec=NULL;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista)); //creo la nuova struttura
	aux->info=el; 
	aux->next=NULL;
	int conta=0;
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

void stampa(ElementoDiLista *lista){

	while(lista!=NULL){
		printf("%d -> ",lista->info);
		lista=lista->next;
	}
	printf("NULL\n");

}	
