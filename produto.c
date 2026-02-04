/*.c implementa produto.h*/
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CRUD */
/*head cell*/
Produto *criarLista() {
    Produto *head = (Produto *)malloc(sizeof(Produto));
    head->prox = NULL;
    return head;
}

/*cadastro*/
void cadastrarProduto(Produto *head) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));

    printf("Codigo: ");
    scanf("%d", &novo->codigo);

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    printf("Preco(00.00): ");
    scanf("%f", &novo->preco);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    novo->prox = head->prox;
    head->prox = novo;
}

/* listar produtos */

void listarProdutos(Produto *head) {
    Produto *aux = head->prox;

    if (aux == NULL) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    while (aux != NULL) {
        printf("\nCodigo: %d", aux->codigo);
        printf("\nNome: %s", aux->nome);
        printf("\nPreco: %.2f", aux->preco);
        printf("\nQuantidade: %d", aux->quantidade);
        printf("\n-------------------");
        aux = aux->prox;
    }
}

/* buscar produto */

Produto *buscarProduto(Produto *head) {
    printf(">>> Buscar produto <<<\n");
    int codigo;

    printf("Codigo: ");
    scanf("%d", &codigo);
    getchar();

    Produto *aux = head->prox;

    while (aux != NULL) {
        if (aux->codigo == codigo)
            return aux;
        aux = aux->prox;
    }

    printf("Produto não encontrado!\n");
    return NULL;
}

/* editar produto */

void editarProduto(Produto *head) {
    Produto *p = buscarProduto(head);

    if (p == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", p->nome);

    printf("Novo preco: ");
    scanf("%f", &p->preco);

    printf("Nova quantidade: ");
    scanf("%d", &p->quantidade);

    printf("Produto atualizado!\n");
}

/* remover produto */

void removerProduto(Produto *head, int codigo) {
    Produto *ant = head;
    Produto *atual = head->prox;

    while (atual != NULL && atual->codigo != codigo) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }

    ant->prox = atual->prox;
    free(atual);

    printf("Produto removido!\n");
}

/* Menu */

void menuProdutos(Produto *head) {
    int op, codigo;

    do {
        printf("\n--- MENU PRODUTOS ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Editar\n");
        printf("5 - Remover\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {

        case 1:
            cadastrarProduto(head);
            break;

        case 2:
            listarProdutos(head);
            break;

        case 3: {
            Produto *p = buscarProduto(head);
            if (p) {
                printf("\n%s - R$ %.2f - Qtd: %d\n", p->nome, p->preco,
                       p->quantidade);
            }
            break;
        }

        case 4:
            editarProduto(head);
            break;

        case 5:
            printf("Codigo: ");
            scanf("%d", &codigo);
            removerProduto(head, codigo);
            break;
        }

    } while (op != 0);
}
