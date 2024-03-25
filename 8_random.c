#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void){
    double r;
    long t=time(NULL);
    printf("%li\n",t);
    srand(t);       //S'EXECUTA NOMÉS 1 VEGADA AL PROGRAMA
    for(int i=0;i<10;i++){
        r=(double)rand()/RAND_MAX;          //rand() --> (0,RAND_MAX (32767))
        printf("%f ",r);
    }
}