#include <stdlib.h>
#include <stdio.h>

typedef struct elementPila {
    int num;
    struct elementPila *seg;
} ElementPila;

void push(int num, ElementPila **top){
    ElementPila *p=malloc(sizeof(ElementPila));
    p->num=num;
    p->seg=*top;
    *top=p;
}

int pop(ElementPila **top){
    if (*top!=NULL){
        int aux=(*top)->num;
        ElementPila *aux_top=*top;
        *top=(*top)->seg;
        free(aux_top);
        return aux;
    }
}

void main(void){
    ElementPila *top=NULL;
    push(3, &top);
    push(28, &top);
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
}