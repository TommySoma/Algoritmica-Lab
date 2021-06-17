#include <stdio.h>

int main(){

    	int fib,fib1=0,fib2=1,n,i=0;
    	scanf("%d",&n);
	do{
    		if(i==0) //semplicemente f(0)=0
    			fib=0;
    		else if (i==1) // stesso dicasi per f(1)=1
    			fib=1;
    		else{
        		fib=fib1+fib2; //assegno alla variabile di comodo fib la somma dei primi due numeri della sequenza
        		fib1=fib2; //il primo numero diventa il secondo numero
        		fib2=fib; //il secondo numero diventa la somma dei primi due
    		}
    	i++; //incremento i
    	printf("%d\n",fib); //stampa la somma nella variabile di comodo
	}
	while(fib1+fib2<=n); //il tutto cicla finchè il primo e il secondo non restituiscono un valore minimo o uguale ad n
	
}
