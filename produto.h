/* .h= define tudo o que ocorre no programa */
#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
    struct Produto *prox;
} Produto;

/* Lista */

Produto *criarLista();

/* CRUD */

void cadastrarProduto(Produto *head);

void listarProdutos(Produto *head);

Produto *buscarProduto(Produto *head);

void editarProduto(Produto *head);

void removerProduto(Produto *head, int codigo);

/* Menu */

void menuProdutos(Produto *head);

#endif
