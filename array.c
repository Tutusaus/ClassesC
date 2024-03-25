#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int v[10];

    for(int i=0;i<10;i++){
        v[i]=0;
    }

    for(int i=0;i<10;i++)
    {
        printf("L'adreca de l'element %i del vector v es: %x\n",i,&v[i]);
    }

    //-------------------------------------------------------------------
    //-------------------------------------------------------------------

    int m[4][3];

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            m[i][j]=0;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("L'adreca de l'element [%i][%i] de la matriu m es: %x\n",i,j,&m[i][j]);
        }
    }

    return 0;
}