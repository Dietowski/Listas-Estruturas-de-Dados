#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

void cria_lista(Lista **l){
    *l = NULL;
}

void liberar(Lista **lista){
	if(*lista == NULL)
		return;
	Lista *aux = *lista;
    while(aux != NULL){
        (*lista) = aux->prox;
        free(aux);
        aux = aux->prox;
    }
    free(lista);
}

void inserir_inicio(Lista **l, struct palavras p){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL){
        return;
    }
    novo->dados = p;
    novo->prox = *l;
    *l = novo;
}

void inserir_final(Lista **l, struct palavras p){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL)
        return;
    Lista *aux = *l;
    novo->dados = p;
    novo->prox = NULL;
    if(*l == NULL){
        inserir_inicio(l,p);
        return;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}

int tamanho_lista(Lista *l){
    if(l == NULL)
        return 0;
    Lista *aux = l;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void remover_final(Lista **l){
    if(*l == NULL)
        return;
    Lista *aux = *l;
    Lista *ant = NULL;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    if(ant == NULL)
    {
        remover_inicio(l);
        return;
    }
    ant->prox = NULL;
    free(aux);
}


void remover_inicio(Lista **l){
    if(*l == NULL)
        return;
    Lista *aux = *l;
    *l = aux->prox;
    free(aux);
}

void buscar_palavras(Lista **l, char pal[]){
    Lista *atual = *l;

    while(atual != NULL){
        int comparaPT = strcmp(atual->dados.PT, pal);
        int comparaEN = strcmp(atual->dados.EN, pal);
        if(comparaPT == 0){
            printf("\nPalavra pesquisada: %s\n", pal);
            printf("Em portugues: %s, traducao em ingles: %s\n", atual->dados.PT, atual->dados.EN);
            return;
        }
        else if(comparaEN == 0){
            printf("\nPalavra pesquisada: %s\n",pal);
            printf("Em ingles: %s, traducao em portugues: %s\n",atual->dados.EN, atual->dados.PT);
            return;
        }
        if(comparaEN != 0 || comparaPT != 0)
        atual = atual->prox;
    }
    printf("Palavra nao encontrada\n");
}

int main()
{
    Lista *lista;
    cria_lista(&lista);
    struct palavras P1 = {"oi","hello"};
    struct palavras P2 = {"meu","my"};
    struct palavras P3 = {"nome","name"};
    struct palavras P4 = {"eh","is"};
    inserir_inicio(&lista,P1);
    inserir_inicio(&lista,P2);
    inserir_inicio(&lista,P3);
    inserir_inicio(&lista,P4);
    struct palavras word;
    int menu;

    do{
        printf("\nBem vindo ao dicionario, digite sua opcao:\n");
        printf("1-Inserir no inicio:\n2-Inserir no final:\n3-Limpa dicionario:\n4-Buscar palavras:\n5-Conferir dicionario:\n6-Remove inicio:\n7-Remover final\n8-Sair\n");
        scanf("%d",&menu);
        getchar();

        switch(menu){
        case 1:
            printf("\nDigite uma palavra em portugues: ");
            gets(word.PT);
            printf("Digite a traducao em ingles: ");
            gets(word.EN);
            inserir_inicio(&lista,word);
            break;
        case 2:
            printf("\nDigite uma palavra em portugues: ");
            gets(word.PT);
            printf("Digite a traducao em ingles: ");
            gets(word.EN);
            inserir_final(&lista,word);
            break;
        case 3:
            {
            printf("\nLimpando a lista:\n");
            liberar(&lista);
            //lista = NULL;
            printf("Lista vazia.\n");
            /*
            int tam = tamanho_lista(lista);
            printf("\nO dicionario tem: %d palavras registradas\n",tam);*/
            break;
            }
        case 4:
            {
            char busca[30];
            printf("\nDigite a palavra para pesquisar: ");
            gets(busca);
            buscar_palavras(&lista,busca);
            break;
            }
        case 5:
            {
            Lista *temp = lista;
            printf("\nDicionario:\n");
            while(temp != NULL){
                printf("Portugues: %s, Ingles: %s\n",temp->dados.PT, temp->dados.EN);
                temp = temp->prox;
            }
            break;
            }
        case 6:
            {
            printf("\nRemovendo no inicio:\n");
            remover_inicio(&lista);
            printf("\npronto.\n");
            break;
            }
        case 7:
            {
            printf("\nRemovendo no final:\n");
            remover_final(&lista);
            printf("\npronto.\n");
            break;
            }
        }
    }
    while(menu != 8);
    if(menu == 8)
        liberar(&lista);
    return 0;
}