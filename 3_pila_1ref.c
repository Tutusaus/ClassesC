#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /*això és per INT_MAX*/

#define N 50

typedef struct pila{
    int v[N];
    int top;
} Pila ;

int pilaPlena(Pila *p){
    if (p->top == N-1) return 1;
    else return 0;
}

int pilaBuida(Pila *p){
    if (p->top == -1) return 1;
    else return 0;
}

void push(Pila *p, int n){
    if (!pilaPlena(p)){
        p->top++;
        p->v[p->top] = n;
    }
}

int pop(Pila *p){
    if (!pilaBuida(p)){
        (p->top)--;
        return p->v[p->top + 1];
    }
    return INT_MAX;
}

void inicialitzacio(Pila *p){
    (*p).top=-1; // EQUIVALENT A p->top=-1; (millor fer aquest últim)
}

int main(void){

    Pila p1, p2;
    inicialitzacio(&p1);
    inicialitzacio(&p2);
    push(&p1,3);
    push(&p2,8);
    push(&p1,-2);
    printf("Valor extret: %d\n", pop(&p2));
    printf("Valor extret: %d\n", pop(&p1));
    printf("Valor extret: %d\n", pop(&p1));

    /*int res;
    Pila p1, p2;
    inicialitzacio(p1);
    inicialitzacio(p2);
    push(p1,3);
    push(p2,8);
    push(p1,-2);
    printf("Valor extret: %d\n", pop());
    printf("Valor extret: %d\n", pop());
    printf("Valor extret: %d\n", pop());
    int res = pop();
    if (res == INT_MAX) printf("Error, pila buida.");
    else printf("Valor extret: %d\n", res);
    */

    return 0;    
}

/*
void f(int *n){
    *n=*n+2;
    printf("%d\n",*n);
}

void main2(void){
    int i=3;
    f(&i);
    printf("%d\n",i);
}
*/