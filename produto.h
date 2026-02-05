#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
    struct Produto *prox;
} Produto;

Produto *criar_lista_produto();
void inserir_produto(Produto *head, Produto *novo);
void cadastrar_produto(Produto *head);
void listar_produtos(Produto *head);
Produto *buscar_produto(Produto *head, int codigo);
void editar_produto(Produto *head);
void remover_produto(Produto *head);
int obter_codigo_produto();
void menu_produtos(Produto *head);

#endif
