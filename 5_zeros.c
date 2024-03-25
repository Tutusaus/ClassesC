#include <stdio.h>
#include <stdlib.h>

//versió retornant un pointer
int* zeros(int tamany){
    int i;
    int *v=malloc(tamany*sizeof(int));   //v[5];
    for(i=0;i<tamany;i++){
        v[i]=0;
    }
    return v;
}

void main(void){
    int *v;
    v=zeros(5);
    for(int i=0;i<5;i++){
        printf("%d ", v[i]);
    }
    free(v);
}