/*.c implementa produto.h*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

/* CRUD */
/*head cell*/
Produto* criarLista() {
    Produto *head = (Produto*) malloc(sizeof(Produto));
    head->prox = NULL;
    return head;
}

/*cadastro*/
void cadastrarProduto(Produto *head) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));

    printf("Codigo: ");
    scanf("%d", &novo->codigo);

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    printf("Preco: ");
    scanf("%f", &novo->preco);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    novo->prox = head->prox;
    head->prox = novo;
}


