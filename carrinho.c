#include "carrinho.h"
#include "cliente.h"
#include "produto.h"
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

void inserir_na_lista_carrinho(Carrinho *lista, Carrinho *carrinho) {
    carrinho->prox = lista->prox;
    lista->prox = carrinho;
}

void remover_carrinho(Carrinho *carrinho) {
    Carrinho *lixo = carrinho->prox;
    carrinho->prox = lixo->prox;
    free(lixo);
}

// TODO: refatorar depois
void adicionar_produto(Carrinho *lista, Produto *head) {
    int codigo = obter_codigo_produto();
    Produto *produto = buscar_produto(head, codigo);
    int quantidade;
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    Carrinho *c = lista->prox;

    while (c != NULL) {
        if (c->codigo_produto == produto->codigo) {
            if (quantidade <= (produto->quantidade - c->quantidade_compra)) {
                c->quantidade_compra = c->quantidade_compra + quantidade;
                return;
            }
            printf("Quantidade pedida maior que estoque!\n");
            return;
        }
        c = c->prox;
    }

    Carrinho *carrinho = criar_carrinho();
    carrinho->codigo_produto = produto->codigo;
    if (quantidade > produto->quantidade) {
        printf("Quantidade pedida maior que estoque!\n");
        return;
    }
    carrinho->quantidade_compra = quantidade;
    inserir_na_lista_carrinho(lista, carrinho);
}

// TODO: Refatorar depois
void retirar_produto_carrinho(Carrinho *lista, Produto *head) {

    int codigo = obter_codigo_produto();
    Produto *produto = buscar_produto(head, codigo);

    int quantidade;
    printf("Quantidade a remover: ");
    scanf("%d", &quantidade);

    Carrinho *carrinho_anterior = lista;
    Carrinho *carrinho_atual = lista->prox;

    while (carrinho_atual != NULL) {

        if (carrinho_atual->codigo_produto == produto->codigo) {
            if (quantidade <= carrinho_atual->quantidade_compra) {
                carrinho_atual->quantidade_compra =
                    carrinho_atual->quantidade_compra - quantidade;

                if (carrinho_atual->quantidade_compra <= 0) {
                    remover_carrinho(carrinho_anterior);
                }
                return;
            }
            printf("Por favor, escolha uma quantidade menor que %d.\n",
                   carrinho_atual->quantidade_compra);
            return;
        } else {
            printf("Erro: Voce tentou remover mais do que possui (%d).\n",
                   carrinho_atual->quantidade_compra);
            return;
        }
        carrinho_anterior = carrinho_atual;
        carrinho_atual = carrinho_atual->prox;
    }
}

void listar_carrinho(Carrinho *lista) {
    Carrinho *carrinho = lista->prox;

    if (carrinho == NULL) {
        printf("Nenhum produto no carrinho!\n");
        return;
    }

    while (carrinho != NULL) {

        printf("\nCodigo: %d", carrinho->codigo_produto);
        printf("\nQuantidade: %d", carrinho->quantidade_compra);
        printf("\n-------------------");
        carrinho = carrinho->prox;
    }
}

// baixar estoque
// TODO: refatorar depois
void finalizar_compra(Carrinho *lista, Produto *head) {

    int comprou = 0;
    Produto *produto = head->prox;

    if (produto == NULL) {
        printf("Impossível finalizar, não há produto.\n");
        return;
    }

    while (produto != NULL) {

        Carrinho *carrinho = lista->prox;
        if (carrinho == NULL) {

            printf("Impossível finalizar, não há nada no carrinho.\n");
            return;
        }
        while (carrinho != NULL) {

            if (produto->codigo == carrinho->codigo_produto) {
                produto->quantidade =
                    produto->quantidade - carrinho->quantidade_compra;
            }

            carrinho = carrinho->prox;
        }

        comprou = 1;
        produto = produto->prox;
    }

    if (comprou) {
        printf("Compra realizada com sucesso!\n");
    }
    free(lista);
    lista = criar_lista_carrinho();
}

void menu_compra(Cliente *lista_clientes, Produto *lista_produtos) {

    int cpf = obter_cpf();
    Cliente *cliente_encontrado = buscar_cliente(lista_clientes, cpf);
    if (cliente_encontrado == NULL) {
        return;
    }
    Carrinho *lista_carrinho = criar_lista_carrinho();

    int opcao;

    do {
        printf("--- Gerenciamento do Carrinho ---\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Listar carrinho\n");
        printf("3 - Retirar produto\n");
        printf("4 - Finalizar compra\n");
        printf("0 - Cancelar e voltar\n");
        printf("-----------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1:
            adicionar_produto(lista_carrinho, lista_produtos);
            break;
        case 2:
            listar_carrinho(lista_carrinho);
            break;
        case 3:
            retirar_produto_carrinho(lista_carrinho, lista_produtos);
            break;
        case 4:
            finalizar_compra(lista_carrinho, lista_produtos);
            break;
        }
    } while (opcao != 0);
}
