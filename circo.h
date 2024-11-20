#ifndef CIRCO_H
#define CIRCO_H

typedef struct circulo{
    int num;
    struct circulo *prox;
}No;

void inicializar(No **lista);
int lista_vazia(No *lista);
void insere_inicio(No **lista, int valor);
void insere_fim(No **lista, int valor);
void remove_inicio(No **lista);
#endif