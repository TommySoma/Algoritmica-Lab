#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    int y= x-1;
    if(x==1) printf("1");
    else {
    while(y>0){
        x=x*y;
        y--;
        if(y==0) printf("%d\n", x);
        }
    }
    return 0;
}
