#include <stdio.h>
#define DIM 7

void primoultimopari(int arr[], int dim, int* primaocc, int* ultimaocc);

int main(){

	int a[DIM];
	int i;
	for(i=0;i<7;i++){
		scanf("%d",&a[i]);}
	primoultimopari(a,DIM,&a[0],&a[6]);

	return 0;

}


void primoultimopari(int arr[], int dim, int* primaocc, int* ultimaocc){

	int i=0;
	int j=6;
	int trovato=0;
	while(!trovato && i<7){
		if(arr[i]%2==0){
			printf("%d ",i);
			trovato=1;
		}
	i++;
	}
	if(!trovato) printf("-1 ");
	trovato=0;
	while(!trovato && j>=0){
		if(arr[j]%2==0){
			printf("%d\n",j);
			trovato=1;
		}
	j--;
	}
	if(!trovato) printf("-1\n");
}
