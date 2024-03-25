#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /*això és per INT_MAX*/

#define N 50

typedef struct pila{
    int v[N];
    int top;
} Pila ;

Pila p;

int pilaPlena(void){
    if (p.top == N-1) return 1;
    return 0;
}

int pilaBuida(void){
    if (p.top == -1) return 1;
    return 0;
}

void push(int n){
    if (!pilaPlena()){
        p.top++;
        p.v[p.top] = n;
    }
}

int pop(){
    if (!pilaBuida()){
        p.top--;
        return p.v[p.top + 1];
    }
    return INT_MAX;
}

void inicialitzacio(){
    p.top=-1;
}

int main(void){
    inicialitzacio();
    push(3);
    push(8);
    push(-2);
    printf("Valor extret: %d\n", pop());
    printf("Valor extret: %d\n", pop());
    printf("Valor extret: %d\n", pop());
    int res = pop();
    if (res == INT_MAX) printf("Error, pila buida.");
    else printf("Valor extret: %d\n", res);

    return 0;    
}