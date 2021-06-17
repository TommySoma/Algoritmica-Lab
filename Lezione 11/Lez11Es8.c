#include <stdio.h>
#include <stdlib.h>

struct el {

    int info;
    struct el * next;
};

typedef struct el ElementoDiLista;
typedef ElementoDiLista * ListaDiElementi;

void inSort(ListaDiElementi *l, int v);         // inserisce ordinato
void insMiss(ListaDiElementi *l);               // inserisce elementi mancanti
void print (ListaDiElementi l);                 // stampa

int main(void){

    ListaDiElementi lista=NULL;

    int n;
    int fine=0;

    while (!fine) {

        scanf("%d",&n);

        if(n>=0){

            inSort(&lista, n);           
        }
        else{

            fine=1;
        }
    }  

    insMiss(&lista);

    print(lista);
}

void inSort(ListaDiElementi *l, int v){

    ListaDiElementi nuovo=malloc(sizeof(ElementoDiLista));

    nuovo->info=v;

    ListaDiElementi temp1=NULL;
    ListaDiElementi temp2=*l;

    while (temp2!=NULL && v < temp2->info) {
        
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

void print (ListaDiElementi l){

    if(l==NULL){

        printf("NULL\n");
    }
    else{

        printf("%d --> ", l->info);
        print(l->next);
    }
}

void insMiss(ListaDiElementi *l){

    if(*l!=NULL){

        ListaDiElementi temp1=*l;
        ListaDiElementi temp2=(*l)->next;

        while(temp1->next!=NULL){

            if(temp1->info==temp2->info){           // SE l'elemento corrente e quello successivo sono uguali

                temp1=temp2;                        // scorre
                temp2=temp2->next;
            }
            else if(temp1->info-1!=temp2->info){    // SE l'elemento corrente-1 e' diverso dall'elemento successivo

                inSort(&(*l), temp1->info-1);       // inserisce elemento corrente-1 nella lista
                temp1=temp1->next;                  // quindi temp diventa l'elemento corrente-1
            }
            else{
                
                temp1=temp2;                        // SE nessuno dei due, scorre
                temp2=temp2->next;
            }
        }
    }
}
