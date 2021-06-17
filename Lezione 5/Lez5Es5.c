#include <stdio.h>

float approx_pi(int);

int main()

{	int cifre;
	scanf("%d",&cifre);
	approx_pi(cifre);
	return 0;

}

float approx_pi(int x){
    
	int i;
	int divisore=1;
	float ris=0;
	float num=0;
	for(i=1;i<=x;i++){
    		if(i%2==0){
    			ris = (float) -4 / divisore;
        		num += ris;}
        	else{
        		ris = (float) 4 / divisore;
        		num += ris;}
        divisore += 2;}
	printf("%.6f\n",num);
	
	return num;

}
