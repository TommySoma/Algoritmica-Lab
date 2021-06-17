/*Le funzioni da implementare devono rispettare le seguenti specifiche:

readbinary: legge dallo standard input una sequenza di 0 e 1 e termina l’acquisizione quando viene digitato un numero diverso da 0 o 1.
	I numeri devono essere memorizzati nell’ordine di acquisizione in un array: l’ultimo numero letto (che fa terminare l’acquisizione)
	non va inserito nell’array, ma va memorizzato all’indirizzo puntato da reps. La funzione scrive, nell’indirizzo puntato da len, il
	numero di elementi inseriti nell’array. Si puo' assumere che la sequenza possa prevedere un massimo di 30 elementi.

sum1rec: La funzione calcola il numero di 1 presenti all’interno dell’array passato come argomento, la cui lunghezza e' passata
	attraverso il parametro formale len, e lo restituisce come valore di ritorno. La funzione DEVE essere implementata in maniera
	RICORSIVA. L’utilizzo di approcci non ricorsivi all’interno della funzione, o in sue eventuali funzioni ausiliarie, costituisce 		una violazione della specifica dell’esercizio e porta al non superamento della prova.

existSubseq: La funzione valuta se all’interno dell’array arr e' presente almeno una sottosequenza di ESATTAMENTE reps 1 in posizioni 
	contigue dell’array. Per chiarezza, con esattamente si intende che la presenza di quattro 1 contigui nell’array soddisfa la
	condizione richiesta quando reps e' pari a 4 ma non quando reps e' pari, ad esempio, a 2 o 3. La funzione restituisce 1 nel caso
	in cui la condizione sia verificata e 0 nel caso in cui sia violata.*/
	
#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 30 

//Functions to be implemented:
void readbinary(char arr[], int *len, int *reps);
int sum1rec(char arr[], int len);
int existSubseq(char arr[], int len, int reps);


int main() {

	char arr[ARR_LEN];
	int len, reps, i;

	//Read and print the array:
	readbinary(arr, &len, &reps);	
	printf("Array:\n");
	for (i = 0; i<len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	//Computes how many 1's are occurring (RECURSIVE)
	printf("Totale occorrenze di 1: %d\n", sum1rec(arr,len));

	//Computes if a subsequence of exactly nreps 1's exists in the array
	if (existSubseq(arr,len,reps)) 
		printf("Condizione per %d uno contigui: VERA\n",reps);
	else
		printf("Condizione per %d uno contigui: FALSA\n",reps);

	return 0;

}

void readbinary(char arr[], int *len, int *reps){

    int n;                                      // elemento da inserire
    int fine=0;                                 // se n e' diverso da 1 e 0, fa uscire dal while
    int i=0;                                    

    while(i<30 && !fine){

        scanf("%d",&n);

        if(n==0 || n==1){

            arr[i]=n;                           // se n e' 1 o 0 assegna al valore corrente dell'array
            i++;                                // e va avanti
        }
        else{

            fine=1;                             // senno' esce
        }
    }

    if(i==30){                                  // se i arriva a 30, allora bisogna assegnare un valore a reps
        scanf("%d",&n);
        *reps=n;
    }
    else{                                       // senno' reps diventa il valore con cui e' uscito il while

        *reps=n;
    }

    *len=i;                                     // len prende il valore di i, cioe' la lunghezza dell'array
}

int sum1rec(char arr[], int len){

    if(len>0){                                  // se len e' maggiore di 0

        if(arr[len-1]==1){                      // se il valore corrente e' uguale ad 1

            return 1 + sum1rec(arr, len-1);     // somma 1 e va avanti
        }
        else{

            sum1rec(arr, len-1);                // senno' va avanti
        }
    }
    else{

        return 0;                               // se len e' minore di 0, somma 0 al risultato
    }
}

int existSubseq(char arr[], int len, int reps){

    int c=0;                                        // conta quanti 1 contigui ci sono
    int i=0;
    int trovato=0;                                  // mi dice se li ha trovati

    while (i<len && !trovato)
    {
        if(arr[i]==1){                              // se il valore corrente e' uguale a 1

            c++;                                    // incrementa c e va avanti
            i++;
        }
        else{

            if(c==reps){                            // quando incontra 0, mi controlla se c e' uguale a reps

                trovato=1;                          // in quel caso esce
            }
            else{

                c=0;                                // senno' azzera c (bisogna contare da capo)
                i++;                                // va avanti
            }
        }
    }

    if(!trovato && c==reps){                        // se il while e' uscito per via di i<len

        trovato=1;                                  // mi controlla se c e' uguale a reps, in quel caso trovato=1
    }

    return trovato;                                 // mi restituisce il valore di trovato, cioe' 1 o 0
}
