#include "carrinho.h"
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

Carrinho *criar_carrinho() {
    Carrinho *carrinho = malloc(sizeof(Carrinho));

    if (carrinho == NULL) {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    carrinho->prox = NULL;
    return carrinho;
}

// Função que só chama outra, é redundante mas pode ser útil
// se for colocar algo específico na dummy cell.
Carrinho *criar_lista_carrinho() { return criar_carrinho(); }

void menu_compra(Cliente *lista_clientes, Produto *lista_produtos) {

    Cliente *p = buscar_cliente(lista_clientes);

    if (p == NULL) {
        return;
    }

    int opcao;

    do {
        printf("--- Gerenciamento do Carrinho ---\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Listar carrinho\n");
        printf("3 - Remover produto\n");
        printf("4 - Finalizar compra\n");
        printf("0 - Voltar\n");
        printf("-----------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    } while (opcao != 0);
}
