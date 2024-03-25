#include <stdio.h>
#include <stdlib.h>

typedef struct llibre {
    int referencia;
    float preu;
    struct llibre *seguent;
} Llibre;

typedef struct client {
    int codi_client;
    Llibre *llibres_comprats;
    struct client *seguent;
} Client;

int main() {
    Client *inici_llista_clients = NULL;
    Llibre *llibres_comprats = NULL;

    llibres_comprats = malloc(sizeof(Llibre *));
    llibres_comprats->referencia = 21;
    llibres_comprats->preu = 3.42;
    llibres_comprats->seguent = NULL;

    inici_llista_clients = malloc(sizeof(Client *));
    inici_llista_clients->codi_client = 1;
    inici_llista_clients->llibres_comprats = llibres_comprats;
    inici_llista_clients->seguent = NULL;

    printf("%d", inici_llista_clients->codi_client);    

    return 0;
}