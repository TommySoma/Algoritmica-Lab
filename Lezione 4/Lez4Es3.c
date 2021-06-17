#include <stdio.h>

int main(){
    int a[10];
    int i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    int trovato=0;
    i=1;
    while(i<9 && !trovato){
        if(a[i]==a[i+1]-a[i-1]) trovato=1;
        if(trovato) printf("%d\n",i);
        i++;
        
    }
    if(!trovato) printf("-1\n");
    return 0;
}
