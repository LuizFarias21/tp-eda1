#include "carrinho.h"
#include "cliente.h"
#include "produto.h"
#include <stdio.h>

int main() {

    Cliente *lista_cliente = criar_lista();
    Produto *lista_produto = criarLista();

    int opcao;

    do {

        printf("--- SISTEMA DE GERENCIAMENTO ---\n");
        printf("1. Gerenciamento de Clientes\n");
        printf("2. Gerenciamento de Produtos\n");
        printf("3. Modo Compra\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            menu_cliente(lista_cliente);
            break;
        case 2:
            menuProdutos(lista_produto);
            break;
        case 3:
            menu_compra(lista_cliente, lista_produto);
            break;
        }
    } while (opcao != 0);

    return 0;
}
