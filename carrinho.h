#ifndef CARRINHO_H
#define CARRINHO_H

#include "cliente.h"
#include "produto.h"

typedef struct carrinho {
    int codigo_produto;
    int quantidade_compra;
    struct carrinho *prox;
} Carrinho;

void menu_compra(Cliente *lista_clientes, Produto *lista_produtos);

Carrinho *criar_lista_carrinho();

#endif
