#include <stdio.h>
#include <stdlib.h>

//versió retornant un pointer
void zeros(int **v, int tamany){
    int i;
    *v=malloc(tamany*sizeof(int));   //v[5];
    for(i=0;i<tamany;i++){
        (*v)[i]=0;
    }
}

void main(void){
    int *v;
    zeros(&v,5);
    for(int i=0;i<5;i++){
        printf("%d ", v[i]);
    }
    free(v);
}