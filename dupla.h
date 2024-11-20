#ifndef DUPLA_H
#define DUPLA_H

typedef struct sno{
    int dado;
    struct sno *ant;
    struct sno *prox;
}No;

void inicializa(No **lista);
int vazia(No **lista);
void insere_inicio(No **lista, int valor);
void insere_final(No **lista, int valor);
No *buscar_no(No *lista,int valor);
void remover_valor(No **lista,int valor);

#endif // DUPLA_H
