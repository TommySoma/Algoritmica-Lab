#include <stdio.h>
#define RIG 4
#define COL 3

void sum_mat(int mat1[][COL],int mat2[][COL]);

int main(){
int mat1[RIG][COL];
int mat2[RIG][COL];

int i,j;

for(i=0;i<RIG;i++){
for(j=0;j<COL;j++){
scanf("%d", &mat1[i][j]);
}
}

for(i=0;i<RIG;i++){
for(j=0;j<COL;j++){
scanf("%d", &mat2[i][j]);
}
}

sum_mat(mat1,mat2);

return 0;
}
void sum_mat(int mat1[][COL],int mat2[][COL]){

int matsom[RIG][COL];
int i,j;

for(i=0;i<RIG;i++){
for(j=0;j<COL;j++)
printf("%d ", matsom[i][j]=mat1[i][j]+mat2[i][j]);
printf("\n");
}
return ;
}
