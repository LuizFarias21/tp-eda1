#include "carrinho.h"
#include "cliente.h"
#include "produto.h"
#include "utils.h"
#include <stdio.h>

int main() {

    Cliente *lista_cliente = criar_lista_cliente();
    Produto *lista_produto = criar_lista_produto();

    if (lista_cliente == NULL || lista_produto == NULL) {
        printf("\n[X] Falha ao alocar memoria para o sistema.\n");
        return 1;
    }

    int opcao;

    do {
        limpar_tela();

        printf("+======================================+\n");
        printf("|       SISTEMA DE GERENCIAMENTO       |\n");
        printf("+======================================+\n");
        printf("|                                      |\n");
        printf("|   [1]  Gerenciamento de Clientes     |\n");
        printf("|   [2]  Gerenciamento de Produtos     |\n");
        printf("|   [3]  Modo Compra (Carrinho)        |\n");
        printf("|                                      |\n");
        printf("|   [0]  Sair do Sistema               |\n");
        printf("|                                      |\n");
        printf("+--------------------------------------+\n");

        printf("\n ::: Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            menu_cliente(lista_cliente);
            break;

        case 2:
            menu_produtos(lista_produto);
            break;

        case 3:
            menu_compra(lista_cliente, lista_produto);
            break;

        case 0:
            printf("\n[*] Encerrando o sistema... Ate logo!\n");
            break;

        default:
            printf("\n[!] Opcao invalida!\n");
            pausar();
            break;
        }

    } while (opcao != 0);

    liberar_lista_cliente(lista_cliente);
    liberar_lista_produto(lista_produto);

    return 0;
}
