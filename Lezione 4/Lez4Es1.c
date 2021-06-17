#include <stdio.h>

int main(){
    int arr[10];
    int i;
    int n;
    for (i=0; i<10; i++){
        scanf("%d", &n);
        arr[i]=n;
    }
    for (i=9; i>=0; i--){
        if (arr[i]%2==0)
        printf("%d\n", arr[i]/2);
        else printf("%d\n", arr[i]);
    }
    return 0;
   }
