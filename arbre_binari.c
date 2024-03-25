#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Crearem un arbre que n nivells, cada node guardarà un valor
i tindrà dos fills que els valors d'aquests seran més gran al 
del node pare (node de l'esquerra) i més petit (node de la dreta) */

typedef struct node
{
    struct node **fills;
    int n_fills;
    int valor;
    int nivell;
} Node;

void imprimirNode(Node *node){
    printf("Nivell: %d\n Valor: %d\n Numero de fills: %d\n Fills:\n",node->nivell,node->valor,node->n_fills);
    for(int i=0;i<node->n_fills;i++){
        printf("  %d: %x\n",i,node->fills[i]);
    }
}

void recorrerArbre(Node *pare){
    for(int fill=0;fill<pare->n_fills;fill++){
        recorrerArbre(pare->fills[fill]);
    }
    imprimirNode(pare);
}

Node *crearNode(Node *pare, int fill_index) {
    Node *p = malloc(sizeof(Node));
    p->n_fills = 2;
    p->nivell = (pare->nivell)+1;
    p->fills=malloc(p->n_fills * sizeof(Node *));
    if(fill_index == 0) {
        p->valor = (pare->valor) - 1;
    }
    else {
        p->valor = (pare->valor) + 1;
    }
    return p;
}

void crearNivell(Node *pare) {
    for(int fill=0;fill<pare->n_fills;fill++) {
        pare->fills[fill] = crearNode(pare,fill);
    }
}

void crearArbre(Node *pare, int profunditat) {
    if(pare->nivell<profunditat) {
        crearNivell(pare);
        for(int fill=0;fill<pare->n_fills;fill++) {
            crearArbre(pare->fills[fill],profunditat);
        }
    }
    else {
        pare->n_fills = 0;
        pare->fills = NULL;
    }
}

void esborrarArbre(Node *pare){
    for(int fill=0;fill<pare->n_fills;fill++){
        if((pare->fills[fill])->n_fills!=0){
            esborrarArbre(pare->fills[fill]);
        }
        else{
            free(pare->fills[fill]);
        }
    }
}

void mod_Node(Node *node, int nivell, int fill_index, int valor) {
    if(node->nivell != (nivell - 1)) {
        for(int fill=0;fill<node->n_fills;fill++) {
            mod_Node(node->fills[fill],nivell,fill_index, valor);
        }
    }
    else {
        node->fills[fill_index]->valor = valor;
    }
}

int main() {
    srand(time(NULL));

    Node *arrel = malloc(sizeof(Node));
    arrel->n_fills = 2;
    arrel->fills = malloc(arrel->n_fills * sizeof(Node *));
    arrel->nivell = 0;
    arrel->valor = 0;

    crearArbre(arrel, 6);

    recorrerArbre(arrel);

    mod_Node(arrel, 2, 1, 43);

    recorrerArbre(arrel);

    esborrarArbre(arrel);

    return 0;
}