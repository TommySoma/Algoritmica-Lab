#include <stdio.h>
#include <stdlib.h>

struct el {

    int info;
    struct el * next;
};

typedef struct el ElementoDiLista;
typedef ElementoDiLista * ListaDiElementi;

void read(ListaDiElementi *l);                           // carica gli elementi all'interno della lista
void insTail(ListaDiElementi *l, int v);                 // inserisce in coda
void fusion(ListaDiElementi l, ListaDiElementi *l3);     // prende la lista, e la inserisce in ordine in l3
void inSort(ListaDiElementi *l, int v);                  // inserisce un elemento in ordinata
void print(ListaDiElementi l);                           // stampa

int main(void){

    ListaDiElementi lista1=NULL;
    ListaDiElementi lista2=NULL;

    ListaDiElementi lista3=NULL;

    read(&lista1);                          // carica la lista1
    read(&lista2);                          // carica la lista2

    fusion(lista1, &lista3);                // prende gli elementi della lista1 e le inserisce in ordine in lista3
    fusion(lista2, &lista3);                // uguale ma con la lista2

    print(lista3);                          // stampa la lista3
}

void read(ListaDiElementi *l){

    int n;
    int fine=0;

    while(!fine){

        scanf("%d",&n);

        if(n>=0){

            insTail(&(*l), n);              // inserisce in coda
        }
        else{

            fine=1;                         // esce
        } 
    }
}

void insTail(ListaDiElementi *l, int v){

    ListaDiElementi nuovo=malloc(sizeof(ElementoDiLista));

    nuovo->info=v;
    nuovo->next=NULL;

    if(*l==NULL){

        *l=nuovo;
    }
    else{

        ListaDiElementi ultimo=*l;

        while (ultimo->next!=NULL) {
            
            ultimo=ultimo->next;
        }

        ultimo->next=nuovo;
    }
}

void fusion(ListaDiElementi l, ListaDiElementi *l3){

    while(l!=NULL){                         // finche' la lista non e' vuota, usa la funzione inSort

        inSort(&(*l3), l->info);
        l=l->next;
    }
}

void inSort(ListaDiElementi *l, int v){                         // inserisce in maniera ordinata

    ListaDiElementi nuovo=malloc(sizeof(ElementoDiLista));

    nuovo->info=v;

    ListaDiElementi temp1=NULL;
    ListaDiElementi temp2=*l;

    while (temp2!=NULL && v > temp2->info)
    {
        temp1=temp2;
        temp2=temp2->next;
    }

    if(temp1==NULL){

        nuovo->next=*l;
        *l=nuovo;
    }
    else{

        temp1->next=nuovo;
        nuovo->next=temp2;
    }
}

void print(ListaDiElementi l){     // stampa

    if(l==NULL){

        printf("NULL\n");
    }
    else{

        printf("%d --> ", l->info);
        print(l->next);
    }
}

