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

/* CRUD */

Produto* cadastrarProduto(Produto *lista);

void listarProdutos(Produto *lista);

Produto* buscarProduto(Produto *lista, int codigo);

void editarProduto(Produto *lista);

Produto* removerProduto(Produto *lista, int codigo);

/* Menu */

Produto* menuProdutos(Produto *lista);

#endif
