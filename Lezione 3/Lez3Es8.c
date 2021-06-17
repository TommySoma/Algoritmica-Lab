#include <stdio.h>

int main(){

    	float a,b;
    	char c;
    	scanf("%f %f %c",&a,&b,&c);
    	if(c=='+') printf("%.1f\n",a+b);
    	if(c=='-') printf("%.1f\n",a-b);
    	if(c=='/') printf("%.1f\n",a/b);
    	if(c=='%') printf("%d.0\n",(int)a%(int)b);
    	
    	return 0;
    	
}
