#include <stdio.h>
//mcd e mcm tra due interi con uso di funzioni
int MassimoComuneDivisore(int a, int b){
int r;
r=a%b;
while(r>0){
	a=b;
	b=r;
	r=a%b;
	}
return b;   
}

int MinimoComuneMultiplo(int a, int b){

return a*b/MassimoComuneDivisore(a,b);
}

int main(){

int x;
int y;
scanf("%d%d",&x,&y);
printf("%d\n",MassimoComuneDivisore(x,y));
printf("%d\n",MinimoComuneMultiplo(x,y));
}


