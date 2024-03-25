#include <stdio.h>
#include <stdlib.h>

void f(int n){
    n=n+2;
    printf("%d\n",n);
}

void zeros(int v[50]){
    int i;
    for(i=0; i<50; i++){
        v[i]=0; // EQUIVALENT A *(v+i)=0
    }
}

void main(void){
    int v[50];
    zeros(v);
    for(int i=0; i<50; i++){
        printf("%i ", v[i]);
    }
}