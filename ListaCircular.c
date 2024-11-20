#include <stdlib.h>
#include <stdio.h>
#include "circo.h"

//Introdução a filas, inserção no fim e remoção no início.
//Utilizando conceitos de listas circulares, como uma fila de banco.

void inicializar(No **lista){
    (*lista) = NULL;
}

int lista_vazia(No *lista){
    if(lista == NULL)
        return 1;
    return 0;
}

void insere_inicio(No **lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return;
    }
    if(*lista == NULL){
        novo->num = valor;
        novo->prox = novo;
        (*lista) = novo;
    } else {
        novo->num = valor;
        novo->prox = (*lista)->prox;
        (*lista)->prox = novo;
    }
    return;
}

void insere_fim(No **lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
        return;
    if(*lista == NULL){
        insere_inicio(lista,valor);
        return;
    } else {
        novo->num = valor;
        novo->prox = (*lista)->prox;
        (*lista)->prox = novo;
        *lista = novo;
    }
}

void remove_inicio(No **lista){
    if(*lista == NULL)
        return;
    if((*lista)->prox == *lista){
        free(lista);
        *lista = NULL;
        return;
    }
    No *aux = *lista;
    aux = (*lista)->prox;
    (*lista)->prox = aux->prox;
    free(aux);
    return;
}

int main(){
    No *lista;
    inicializar(&lista);
    insere_fim(&lista, 8);
    insere_fim(&lista, 9);
    insere_fim(&lista, 10);
    remove_inicio(&lista);
    
    if(lista == NULL){
        printf("lista nula.\n");
        return 1;
    }

    No *temp = lista->prox;
    printf("\nNumeros:\n");
    int i = 1;
    do {
        printf("%d: %d\n", i, temp->num);
        temp = temp->prox;
        i++;
    } while (temp != lista->prox);
    return 0;
}
