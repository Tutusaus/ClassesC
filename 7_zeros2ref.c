#include <stdio.h>
#include <stdlib.h>

void freeMatriu(int **m,int files){
    for(int i=0;i<files;i++){
        free(m[i]);
    }
    free(m);
}

//versió retornant un pointer
int **matriu(int files, int columnes){
    int i;
    int **m=malloc(files*sizeof(int *));   //v[5];
    for(i=0;i<files;i++){
        m[i]=malloc(columnes * sizeof(int));
        for(int j=0;j<columnes;j++){
            m[i][j]=0;
        }
    }
    return m;
}

void main(void){
    int **m;
    m=matriu(3,2);
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    freeMatriu(m, 3);
}