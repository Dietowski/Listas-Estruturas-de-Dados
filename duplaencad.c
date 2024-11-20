#include <stdio.h>
#include <stdlib.h>
#include "dupla.h"

//Lista dinâmica duplamente encadeada, operações básicas.

void inicializa(No **lista){
    *lista = NULL;
}

int vazia(No **lista){
    if(*lista == NULL)
        return 0;
    return 1;
}

void insere_inicio(No **lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
        printf("erro");
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = (*lista);
    if((*lista) != NULL){
        (*lista)->ant = novo;}
    (*lista) = novo;
}

void insere_final(No **lista, int valor){
    if((*lista) == NULL)
        insere_inicio(lista,valor);
    No *aux = (*lista);
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    No *novo = (No*)malloc(sizeof(No));
    novo->ant = aux;
    novo->prox = NULL;
    aux->prox = novo;
    novo->dado = valor;
}

No *buscar_no(No *lista,int valor){
    No *aux = lista;
    while(aux != NULL && aux->dado != valor){
        aux = aux->prox;
    }
    return aux;
}

void remover_valor(No **lista,int valor){
    No *aux = buscar_no(*lista,valor);
    if(aux == NULL)
        return;
    if(aux->ant == NULL)
        printf("\nCaso 2.");
    else if(aux->prox == NULL)
        printf("\nCaso 3.");
    else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
    }
}

int main(){
    No *novo;
    int x = 3;
    int y = 4;
    int z = 5;
    inicializa(&novo);
    insere_inicio(&novo,x);
    insere_final(&novo,y);
    insere_inicio(&novo,z);
    novo = buscar_no(novo,y);
    remover_valor(&novo,x);
    getchar();
    No *temp = novo;
    while(temp != NULL){
        printf("Dados: %d", &temp->dado);
        temp = temp->prox;
    }
return 0;
}
