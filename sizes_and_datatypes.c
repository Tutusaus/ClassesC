#include <stdio.h>
#include <stdlib.h>

typedef struct estructura{
    int x;
    int vect2[3];
    char carac;
} Estructura;

int main(void){
    char Char='a';
    int Int=1;
    float Float=0.32;
    double Double=0.54;
    long double LongDouble=10.34;
    int vect[3]={2,3,4};
    Estructura struct1={1,2,3,4,'c'};
    Estructura *p=&struct1;

    printf("Contingut de Char: %c\n",Char);
    printf("Adreca de Char: %x\n",&Char);
    printf("Mida de Char: %d\n",sizeof(Char));
    printf("Mida de Char *: %d\n",sizeof(&Char));
    printf("Mida de char: %d\n",sizeof(char));
    printf("Mida de char *: %d\n",sizeof(char *));
    printf("-----------------------------------------------\n");
    printf("Contingut de Int: %d\n",Int);
    printf("Adreca de Int: %x\n",&Int);
    printf("Mida de Int: %d\n",sizeof(Int));
    printf("Mida de Int *: %d\n",sizeof(&Int));
    printf("Mida de int: %d\n",sizeof(int));
    printf("Mida de int *: %d\n",sizeof(int *));
    printf("-----------------------------------------------\n");
    printf("Contingut de Float: %f\n",Float);
    printf("Adreca de Float: %x\n",&Float);
    printf("Mida de Float: %d\n",sizeof(Float));
    printf("Mida de Float *: %d\n",sizeof(&Float));
    printf("Mida de float: %d\n",sizeof(float));
    printf("Mida de float *: %d\n",sizeof(float *));
    printf("-----------------------------------------------\n");
    printf("Contingut de Double: %lf\n",Double);
    printf("Adreca de Double: %x\n",&Double);
    printf("Mida de Double: %d\n",sizeof(Double));
    printf("Mida de Double *: %d\n",sizeof(&Double));
    printf("Mida de double: %d\n",sizeof(double));
    printf("Mida de double *: %d\n",sizeof(double *));
    printf("-----------------------------------------------\n");
    printf("Contingut de LongDouble: %Lf\n",LongDouble);
    printf("Adreca de LongDouble: %x\n",&LongDouble);
    printf("Mida de LongDouble: %d\n",sizeof(LongDouble));
    printf("Mida de LongDouble *: %d\n",sizeof(&LongDouble));
    printf("Mida de long double: %d\n",sizeof(long double));
    printf("Mida de long double *: %d\n",sizeof(long double *));
    printf("-----------------------------------------------\n");
    printf("Contingut de vect: %d,%d,%d\n",vect[0],vect[1],vect[2]);
    printf("Adreca de vect: %x\n",vect);   //equivalent a vect o &vect[0]. vect apunta a la primera adreça de memòria del vector
    printf("Adreca de vect[1]: %x\n",vect+1);
    printf("Adreca de vect[2]: %x\n",&vect[2]);
    printf("Mida de vect: %d\n",sizeof(vect));  //3*sizeof(int)=3*4=12
    printf("Mida de *vect: %d\n",sizeof(&vect));
    printf("Mida de vect[1]: %d\n",sizeof(*(vect+1)));
    printf("Contingut de vect[1]: %d\n",*(vect+1));
    printf("-----------------------------------------------\n");
    printf("Contingut de struct1: %d,%c,%d,%d,%d\n",struct1.x,struct1.carac,struct1.vect2[0],struct1.vect2[1],struct1.vect2[2]);
    printf("Adreca de struct1: %x\n",&struct1);
    printf("Adreca de struct1.x: %x\n",&struct1.x);
    printf("Adreca de struct1.vect2: %x\n",&struct1.vect2);
    printf("Adreca de struct1.carac: %x\n",&struct1.carac);
    printf("Adreca de struct1.vect2[0]: %x\n",&struct1.vect2[0]);
    printf("Adreca de struct1.vect2[1]: %x\n",&struct1.vect2[1]);
    printf("Adreca de struct1.vect2[2]: %x\n",&struct1.vect2[2]);
    printf("Mida de struct1: %d\n",sizeof(struct1));    //surt 20 a causa de "structure padding", mirar a internet o a adreçes d'interès
    printf("Mida de struct1 *: %d\n",sizeof(&struct1));
    printf("Mida de Estructura: %d\n",sizeof(Estructura));
    printf("Mida de Estructura *: %d\n",sizeof(Estructura *));
    printf("-----------------------------------------------\n");
    printf("Contingut de struct1: %d,%c,%d,%d,%d\n",p->x,p->carac,p->vect2[0],p->vect2[1],p->vect2[2]);
    printf("Adreca de struct1: %x\n",p);
    printf("Mida de p: %d\n",sizeof(p));
    printf("Mida de *p: %d\n",sizeof(*p));
    /* printf("Adreca de struct1.carac: %x\n",p+3);
    printf("Adreca de struct1.vect2[0]: %x\n",&struct1.vect2[0]);
    printf("Adreca de struct1.vect2[1]: %x\n",&struct1.vect2[1]);
    printf("Adreca de struct1.vect2[2]: %x\n",&struct1.vect2[2]);
    printf("Mida de struct1: %d\n",sizeof(struct1));    //surt 20 a causa de "structure padding", mirar a internet o a adreçes d'interès
    printf("Mida de struct1 *: %d\n",sizeof(&struct1));
    printf("Mida de Estructura: %d\n",sizeof(Estructura));
    printf("Mida de Estructura *: %d\n",sizeof(Estructura *)); */
    printf("-----------------------------------------------\n");
    printf("Recordem que la funcio sizeof() retorna el tamany en bytes (8 bits) que un cert 'data type' ocupa en memoria.");

    return 0;
}