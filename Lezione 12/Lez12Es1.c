/*Le funzioni da implementare devono rispettare le seguenti specifiche:

readList: Chiamiamo distanza tra due interi n1 e n2 il valore assoluto della loro differenza (|n1−n2|).
	Dato un limite per la distanza passato alla funzione nel parametro formale boundis(che sara’ un intero positivo), readList legge
	una sequenza di numeri interi positivi e termina l’acquisizione quando la distanza tra il numero letto e il successivo e’
	strettamente maggiore del limite. I numeri letti devono essere memorizzati nell’ordine di acquisizione in una lista: l’ultimo
	numero letto (che fa terminare l’acquisizione) non va inserito nella lista. Se il valore limite della distanza(boundis) passato
	a readList`e 3, la sequenza in input 1 4 7 2 deve creare una lista contenente nell’ordine (1,4,7).

maxDistance: Questa funzione prende una lista e deve restituire la massima distanza tra due elementi consecutivi della lista. Per esempio,
	supponendo che la lista sia (5,8,15,10,12), la funzione maxDistance dovra’ restituire 7.

CancellaMax: dato il valore della distanza massima di una lista, CancellaMax deve cancellare il primo elemento di tutte le coppie della
	lista di partenza che sono a distanza massima. Per esempio, se la lista e'(5,8,15,10,12), dato che in questo caso CancellaMax
	verra' chiamata con maxdis=7, la lista risultante dovra' essere (5,15,10,12).*/
	
#include <stdio.h>
#include <stdlib.h>

//List structure:

struct El{
	int info;
	struct El *next;
};
typedef struct El ElementoLista;
typedef ElementoLista* ListEl;

//functions/procedure to be implemented:

void add_tail(ListEl *lista, int el){

	ListEl ultimo; 
	ListEl new_el;
	new_el=malloc(sizeof(ElementoLista)); 
	new_el->info=el;
	new_el->next=NULL;
	if(*lista==NULL)
		*lista=new_el;
	else{
		ultimo=*lista;
		while(ultimo->next!=NULL)
			ultimo=ultimo->next; 
		ultimo->next=new_el;
	}
}


void readList(ElementoLista **Lista, int dis);
int maxDistance(ElementoLista *Lista);
void CancellaMax(ElementoLista **Lista, int maxdis);

//function to print all the elements of the list:
void printList(ElementoLista *list){
	
	printf("(");
	while(list!=NULL){
		printf("%d ", list->info);
		list=list->next;
	}
	printf(")\n");
}

int main(){
	
	ElementoLista *list=NULL;
	int boundis, maxdis;
	
	//read the bounded distance:
	scanf("%d", &boundis);
	
	//read and print the list:
	readList(&list, boundis);
	printf("La lista bounded-%d e':\n", boundis);
	printList(list);
	
	//compute and print the maxdistance of the list
	maxdis=maxDistance(list);
	printf("La distanza massima e':\n%d\n", maxdis);
	
	//removes the elements at distance maxdistance
	CancellaMax(&list, maxdis);
	printf("La lista modificata e':\n");
	printList(list);
	
	return 0;
}

int absolute_value(int n){
	
	if(n>=0) return n;
	else return -n;
}

void delete_head(ListEl *lista){

	ListEl *aux;
	if (*lista != NULL){
		aux = *lista;
		*lista = (*lista)->next;
		free(aux);
		}
	}
	
void readList(ListEl *lista, int dis){

	int n;
	int out=0;
	int check=0;
	while(!out){
		scanf("%d", &n);
		if(*lista==NULL){
			add_tail(lista, n);
			check=n;
		}
		else if(absolute_value(n-check)<=dis){
			add_tail(lista, n);
			check=n;
			}
			else out=1;
	}
}

int maxDistance (ListEl lista){
	int dist=0;
	int maxdis=0;
	ListEl cur=lista;
    	if (lista != NULL){
		while ((cur)->next != NULL){
            		dist=absolute_value((cur)->next->info - (cur)->info);
            		if (dist > maxdis)
                		maxdis=dist;
            		cur=(cur)->next;
        	}
    	}	    
    	return maxdis;
}

void CancellaMax(ListEl *lista, int maxdis){
	maxdis=maxDistance(*lista);
	ListEl cur=*lista;
	ListEl tmp=NULL;
	ListEl prev=NULL;
	while (cur->next != NULL){
       	if (absolute_value(cur->next->info - cur->info) != maxdis){
               	prev=cur;
           		cur=cur->next;}
        	else{
            		if (prev==NULL){
               		delete_head(lista);
               		cur=cur->next;}

            		else{
               		tmp=cur;
               		prev->next=cur->next;
                		cur=cur->next;
                		free(tmp);
                	}
                }
	}
}	
	
	
