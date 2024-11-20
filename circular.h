#ifndef CIRCULAR_H
#define CIRCULAR_H

typedef struct lista
{
    int num;
    struct lista *prox;
}No;

void inicializa(No **l);
int lista_vazia(No *l);
void liberar(No **l);
void insere_inicio(No **l, int valor);
void insere_fim(No **l, int valor);
void remover_inicio(No **l);
void remover_fim(No **l);
void buscar(No **l, int valor);
int qtd(No **l);
void busca_comeco(No **l, int valor);
#endif