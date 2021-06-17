#include <stdio.h>

float diff_abs (float *a, float *b);

int main(){

	float x;
	float y;
	scanf("%f %f", &x, &y);
	diff_abs(&x,&y);
	printf("%.2f\n",x);
	printf("%.2f\n",y);

return 0;
}

float diff_abs (float *a, float *b){

float z,w;
z=*a;
w=*b;
*a=*a-*b;
*b=w-z;

}
