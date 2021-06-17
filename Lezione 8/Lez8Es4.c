#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserzione(ElementoDiLista **lista, int el);
void intersezione_liste(ElementoDiLista **lista1, ElementoDiLista **lista2, ElementoDiLista **lista3);
void stampa(ElementoDiLista *lista);

int main(){

	ElementoDiLista *lista1=NULL;
	ElementoDiLista *lista2=NULL;
	ElementoDiLista *lista3=NULL;
	int trovato=0;
	int n;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserzione(&lista1,n);
		else trovato=1;
	}
	trovato=0;
	while(!trovato){
		scanf("%d",&n);
		if(n>=0) inserzione(&lista2,n);
		else trovato=1;
	}
	intersezione_liste(&lista1,&lista2,&lista3);
	stampa(lista3);

	return 0;

}

void inserzione(ElementoDiLista **lista, int el){

	ElementoDiLista *corr=*lista;
	ElementoDiLista *prec=NULL;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	while(corr!=NULL && corr->info<el){
		prec=corr;
		corr=corr->next;
	}
	if(prec==NULL){
		*lista=aux;
		aux->next=corr;
	}
	else{ 
		if(corr==NULL){
			prec->next=aux;
			aux->next=corr;
			}
		else{
			prec->next=aux;
			aux->next=corr;
			}
		}
}

void intersezione_liste(ElementoDiLista **lista1, ElementoDiLista **lista2, ElementoDiLista **lista3){
	
	ElementoDiLista *corr1;    //3 puntatori per scorrere le 3 liste
	ElementoDiLista *corr2;
	ElementoDiLista *corr3;
	ElementoDiLista *prec=NULL;//inizializzo il puntatore prec
	corr1=*lista1;
	corr2=*lista2;             //inizializzo i 3 puntatori alle teste delle rispettive liste
	corr3=*lista3;
	int trovato=0;
	while(!trovato && corr2!=NULL){ //scorro la lista 2, se non è vuota
		if(corr1->info==corr2->info){ //se trovo 2 elementi uguali
			if(corr3==NULL){ //scorro la lista 3, ma è vuota
				ElementoDiLista *new=malloc(sizeof(ElementoDiLista)); //creo la nuova struttura in lista 3
				new->info=corr1->info; //metto nel campo info della struttura l'elemento trovato
				*lista3=new;           //aggiungo new alla lista 3
				corr3=*lista3;         //rimetto il puntatore corr alla testa della lista
			} 
			else{
				if(corr1->info!=corr3->info){ //elemento della lista 1 diverso da elemento lista 3(controllo duplicati)
					ElementoDiLista *new=malloc(sizeof(ElementoDiLista)); //mi creo una nuova struttura
					new->info=corr1->info;//metto nel campo info della struttura l'elemento trovato
					corr3->next=new;      //attacco al campo next di corr l'elemento trovato
					prec=corr3;           //aggiungo corr3 a prec
					corr3=new;            //aggiungo new a corr3
				}
				
			}	
		trovato=1;           //esco dal ciclo
		}
	corr1=corr1->next;          //vado al prossimo elemento di corr1
	if(corr1==NULL || trovato){ //finisco di scorrere la lista
		corr1=*lista1;      //riporto in cima alla lista il puntatore corr1
		corr2=corr2->next;  //vado al prossimo elemento di corr2
		trovato=0;          //rientro nel ciclo per rieseguirlo
	}

	}

}
	


void stampa(ElementoDiLista *lista){

	ElementoDiLista *aux=lista;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->next;
		}
}		

