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
void adicionar_produto(Carrinho *head_carrinho, Produto *head_produto);
void retirar_produto_carrinho(Carrinho *head_carrinho, Produto *head_produto);
void listar_carrinho(Carrinho *head_carrinho, Produto *head_produto);
void finalizar_compra(Carrinho *head_carrinho, Produto *head_produto);
void menu_compra(Cliente *lista_clientes, Produto *lista_produtos);
void liberar_carrinho(Carrinho *head);
#endif
