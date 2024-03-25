#include <stdlib.h>
#include <stdio.h>

typedef struct elementPila {
    int num;
    struct elementPila *seg;
} ElementPila;

ElementPila *top;

void push(int num){
    ElementPila *p=malloc(sizeof(ElementPila));
    p->num=num;
    p->seg=top;
    top=p;
}

int pop(){
    if (top!=NULL){
        int aux=top->num;
        ElementPila *aux_top=top;
        top=top->seg;
        free(aux_top);
        return aux;
    }
}

void main(void){
    top=NULL;
    push(3);
    push(28);
    printf("%d\n", pop());
    printf("%d\n", pop());
}