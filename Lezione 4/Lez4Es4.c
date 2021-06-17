#include <stdio.h>
int main(){
int a[10];
int i;
for(i=0;i<10;i++)
    scanf("%d",&a[i]);
for(i=0;i<9;i++){
    if(a[i]>=0 && a[i]%2==0)
        printf("%d\n",a[i]);
    if(a[i]<0 && a[i+1]>=0)
            printf("%d\n",a[i]);
                }
if(a[9]>=0 && a[9]%2==0)
    printf("%d\n",a[i]);
return 0;
}
        
    
    
    
