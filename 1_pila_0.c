#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //això és per INT_MAX

int v[50];
int top;

int pilaPlena(void){
    if (top == 49) return 1;
    return 0;
}

int pilaBuida(void){
    if (top == -1) return 1;
    return 0;
}

void push(int n){
    if (!pilaPlena()){
        top++;
        v[top] = n;
    }
}

int pop(){
    if (!pilaBuida()){
        top--;
        return v[top + 1];
    }
    return INT_MAX;
}

void inicialitzacio(){
    top=-1;
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