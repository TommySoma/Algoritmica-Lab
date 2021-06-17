#include <stdio.h>

enum tipo_cibo {
	crocchette,
	scatolette,
	tonno
	};
	
typedef struct {
	int codice;
	int eta;
	float peso;
	int tipo_cibo;
	} gatto;
	
int main(){
	
	gatto gattile[4];
	int i;
	int j;
	float somma=0.0;
	float media=0.0;
	for(i=0; i<4; i++){
		scanf("%d" ,&gattile[i].codice);
		scanf("%d" ,&gattile[i].eta);
		scanf("%f" ,&gattile[i].peso);
		scanf("%d" ,&gattile[i].tipo_cibo);
	}
	
	somma = gattile[0].peso + gattile[1].peso + gattile[2].peso + gattile[3].peso;
	media = somma/4.0;
	
	for (j=0; j<4; j++) {
    		if (gattile[j].eta < 4 && gattile[j].peso > media) {
       		printf("%d" ,gattile[j].codice);
       
       		if (gattile[j].tipo_cibo == 0)
          		printf(" crocchette\n");
       		else if (gattile[j].tipo_cibo == 1)
          		printf(" scatolette\n");
       		else if (gattile[j].tipo_cibo == 2)
          		printf(" tonno\n");
    			}	
	}	
	return 0;
	}
	

	

