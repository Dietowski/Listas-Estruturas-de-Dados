#include <stdlib.h>
#include <stdio.h>
#include "circular.h"

//Listas circulares, operações básicas.

void inicializa(No **l){
    (*l) = NULL;
}

int lista_vazia(No *l){
    if(l == NULL)
        return 1;
    return 0;
}

void liberar(No **l){
    free(*l);
    inicializa(l);
}

void insere_inicio(No **l, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return;
    }
    if(*l == NULL){
        novo->num = valor;
        novo->prox = novo;
        *l = novo;
    }else {
        novo->num = valor;
        novo->prox = (*l)->prox;
        (*l)->prox = novo;
    }
}

void insere_fim(No **l, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
        return;
    novo->num = valor;
    if(*l == NULL){
        insere_inicio(l,valor);
    }else{
        novo->prox = (*l)->prox;
        (*l)->prox = novo;
        *l = novo;
    }
}

void remover_inicio(No **l){
    if(*l == NULL)
        return;
    if((*l)->prox == (*l)){
        liberar(l);
        return;
    }
    No *aux = (*l)->prox;
    (*l)->prox = aux->prox;
    free(aux);
}

void remover_fim(No **l){
    if(*l == NULL)
        return;
    if((*l)->prox == (*l)){
        liberar(l);
        return;
    }
    No *aux = *l;
    No *ant = NULL;
    while(aux->prox != *l){
        aux = aux->prox;
    }
    ant = aux->prox;
    *l = aux;
    (*l)->prox = ant->prox;
    free(ant);
}

void buscar(No **l, int valor){
    if(*l == NULL){
        printf("Lista vazia\n");
        return;
    }
    if((*l == (*l)->prox) && (*l)->num != valor) {
        printf("\nNumero %d nao existe\n",valor);
        return;
    } else if((*l)->num == valor){
        printf("\nO numero %d existe\n",(*l)->num);
        return;
    }
    No *aux = *l;
    while(aux->prox != *l && aux->num != valor){
        aux = aux->prox;
    }
    if(aux->num == valor){
        printf("\nO numero %d existe",aux->num);
        return;
    } else {
        printf("\nA busca nao existe\n");
        return;
    }
}

void busca_comeco(No **l, int valor){
    if(*l == NULL)
        return;
    No *aux = *l;
    No *ant = NULL;
    while(aux->prox != *l && aux->num != valor){
        ant = aux;
        aux = aux->prox;
    }
    if(aux->num == valor){
        No *novo;
        printf("\nO numero %d existe\n",aux->num);
        ant->prox = aux->prox;
        insere_inicio(&novo,valor);
        free(aux);
        printf("\nO ant e %d\n",ant->num);
        return;
    } else {
        printf("\nNao foi achado o elemento.\n");
        return;
    }
}

int qtd(No **l){
    if(*l == NULL)
        return 0;
    int qtd = 1;
    No *aux = *l;
    if(aux->prox == *l)
        return qtd;
    while(aux->prox != *l){
        aux = aux->prox;
        qtd++;
    }
    return qtd;
}

int main(){
    No *lista;
    inicializa(&lista);
    insere_inicio(&lista,4);
    insere_inicio(&lista,5);
    insere_inicio(&lista,6);
    remover_inicio(&lista);
    insere_fim(&lista,7);
    remover_fim(&lista);
    
    if(lista == NULL){
        printf("lista nula");
        return 1;
    }
    No *temp = lista->prox;
    printf("\nNumeros:\n");
    int i = 1;
    
    buscar(&lista,4);
    int quant = qtd(&lista);
    printf("\nA lista tem %d elementos!",quant);
    busca_comeco(&lista,4);
    do {
        printf("%d: %d\n", i, temp->num);
        temp = temp->prox;
        i++;
    } while(temp != lista->prox);
    return 0;
}