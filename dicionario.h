#ifndef DICIONARIO_H
#define DICIONARIO_H

struct palavras{
    char PT[30];
    char EN[30];
};

typedef struct dicio{
    struct palavras dados;
    struct dicio *prox;
}Lista;

void cria_lista(Lista **l);
void liberar(Lista **lista);
void inserir_inicio(Lista **l, struct palavras p);
void inserir_final(Lista **l, struct palavras p);
int tamanho_lista(Lista *l);
void remover_final(Lista **l);
void remover_inicio(Lista **l);
void buscar_palavras(Lista **l, char pal[]);

#endif // DICIONARIO_H
