#include "produto.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produto *criar_lista_produto() {
    Produto *head = malloc(sizeof(Produto));

    if (head == NULL) {
        printf("\n[X] Memoria cheia.\n");
        return NULL;
    }

    head->prox = NULL;
    return head;
}

void inserir_produto(Produto *head, Produto *novo) {
    novo->prox = head->prox;
    head->prox = novo;
}

void cadastrar_produto(Produto *head) {

    int codigo = obter_codigo_produto();
    if (buscar_produto(head, codigo) != NULL) {
        printf("\n[!] Ja existe um produto com esse codigo.\n");
        return;
    }

    Produto *novo = malloc(sizeof(Produto));

    if (novo == NULL) {
        printf("\n[X] Memoria cheia.\n");
        return;
    }

    novo->codigo = codigo;

    printf("\n ::: Nome: ");
    scanf(" %99[^\n]", novo->nome);

    printf("\n ::: Preco(00.00): ");
    scanf("%f", &novo->preco);

    printf("\n ::: Quantidade: ");
    scanf("%d", &novo->quantidade);

    printf("\n[*] Produto cadastrado com sucesso.\n");

    inserir_produto(head, novo);
}

void listar_produtos(Produto *head) {

    if (head == NULL) {
        printf("\n[!] Lista nao inicializada.\n");
        return;
    }

    Produto *atual = head->prox;

    if (atual == NULL) {
        printf("\n[!] Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n+=====================================================+\n");
    printf("|                  LISTA DE PRODUTOS                  |\n");
    printf("+=====================================================+\n");
    printf("| COD | NOME                     | PRECO        | QTD |\n");
    printf("+-----+--------------------------+--------------+-----+\n");

    while (atual != NULL) {
        printf("| %03d | %-24s | R$ %9.2f | %3d |\n", atual->codigo,
               atual->nome, atual->preco, atual->quantidade);

        atual = atual->prox;
    }
    printf("+-----+--------------------------+--------------+-----+\n");
}

int obter_codigo_produto() {
    int codigo;

    do {

        printf("\n ::: Codigo: ");
        scanf("%d", &codigo);

        if (codigo <= 0) {
            printf("\n[!] Codigo deve ser maior que 0.\n");
        }
    } while (codigo <= 0);

    return codigo;
}

Produto *buscar_produto(Produto *head, int codigo) {

    Produto *atual = head->prox;

    while (atual != NULL) {
        if (atual->codigo == codigo)
            return atual;
        atual = atual->prox;
    }

    return NULL;
}

void editar_produto(Produto *head) {
    int codigo = obter_codigo_produto();
    Produto *produto = buscar_produto(head, codigo);

    if (produto == NULL) {
        printf("\n[!] Nenhum produto encontrado.\n");
        return;
    }

    printf("\n ::: Novo nome: ");
    scanf(" %99[^\n]", produto->nome);

    printf("\n ::: Novo preco: ");
    scanf("%f", &produto->preco);

    printf("\n ::: Nova quantidade: ");
    scanf("%d", &produto->quantidade);

    printf("\n[*] Informações atualizadas com sucesso.\n");
}

void remover_produto(Produto *head) {
    int codigo = obter_codigo_produto();

    Produto *ant = head;
    Produto *atual = head->prox;

    while (atual != NULL && atual->codigo != codigo) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\n[!] Nenhum produto encontrado.\n");
        return;
    }

    ant->prox = atual->prox;
    free(atual);

    printf("\n[*] Produto removido com sucesso.\n");
}

void menu_produtos(Produto *head) {
    int opcao;

    do {
        limpar_tela();
        exibir_cabecalho("  MENU PRODUTOS");
        printf("|                                      |\n");
        printf("|   [1]  Cadastrar Novo Produto        |\n");
        printf("|   [2]  Listar Todos                  |\n");
        printf("|   [3]  Buscar por Codigo             |\n");
        printf("|   [4]  Editar Informacoes            |\n");
        printf("|   [5]  Remover Produto               |\n");
        printf("|                                      |\n");
        printf("|   [0]  Voltar ao Menu Principal      |\n");
        printf("|                                      |\n");
        printf("+--------------------------------------+\n");
        printf("\n ::: Selecione uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            cadastrar_produto(head);
            pausar();
            break;

        case 2:
            listar_produtos(head);
            pausar();
            break;

        case 3: {
            int codigo = obter_codigo_produto();
            Produto *produto = buscar_produto(head, codigo);

            if (produto) {
                printf("\n");
                printf(" +======================================+\n");
                printf(" | [*]      PRODUTO ENCONTRADO          |\n");
                printf(" +======================================+\n");
                printf(" | CODIGO.....: %03d                     |\n",
                       produto->codigo);
                printf(" +--------------------------------------+\n");
                printf(" | Nome.......: %-22s  |\n", produto->nome);
                printf(" | Preco......: R$ %-19.2f  |\n", produto->preco);
                printf(" | Estoque....: %-22d  |\n", produto->quantidade);
                printf(" +======================================+\n");
            } else {
                printf("\n[!] Nenhum produto encontrado.\n");
            }
            pausar();
            break;
        }

        case 4:
            editar_produto(head);
            pausar();
            break;

        case 5:
            remover_produto(head);
            pausar();
            break;
        case 0:
            break;
        default:
            printf("\n[!] Opcao invalida!\n");
            pausar();
            break;
        }

    } while (opcao != 0);
}
