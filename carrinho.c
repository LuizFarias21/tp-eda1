#include "carrinho.h"
#include "cliente.h"
#include "produto.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Carrinho *criar_lista_carrinho() {
    Carrinho *head = malloc(sizeof(Carrinho));

    if (head == NULL) {
        printf("\n[X] Memoria cheia.\n");
        return NULL;
    }

    head->prox = NULL;
    return head;
}

void inserir_na_lista_carrinho(Carrinho *head, Carrinho *novo) {
    novo->prox = head->prox;
    head->prox = novo;
}

void remover_carrinho(Carrinho *anterior) {
    Carrinho *lixo = anterior->prox;
    if (lixo != NULL) {
        anterior->prox = lixo->prox;
        free(lixo);
    }
}

void esvaziar_carrinho(Carrinho *head) {
    if (head == NULL)
        return;

    Carrinho *atual = head->prox;
    Carrinho *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    head->prox = NULL;
}

void liberar_carrinho(Carrinho *head) {
    if (head == NULL) {
        return;
    }

    esvaziar_carrinho(head);
    free(head);
}

int obter_qtd_pedida() {
    int qtd;

    do {

        printf("\n ::: Quantidade desejada: ");
        scanf("%d", &qtd);

        if (qtd <= 0) {
            printf("\n[!] A Quantidade deve ser maior que zero.\n");
        }
    } while (qtd <= 0);

    return qtd;
}

Carrinho *criar_carrinho(int qtd_pedida, Produto *produto) {
    Carrinho *carrinho = malloc(sizeof(Carrinho));
    carrinho->codigo_produto = produto->codigo;
    carrinho->quantidade_compra = qtd_pedida;

    return carrinho;
}

void adicionar_produto(Carrinho *head_carrinho, Produto *head_produto) {
    int codigo = obter_codigo_produto();
    Produto *produto = buscar_produto(head_produto, codigo);

    if (produto == NULL) {
        printf("\n[!] Produto nao encontrado.\n");
        return;
    }

    int qtd_pedida = obter_qtd_pedida();
    if (qtd_pedida > produto->quantidade) {
        printf("\n[!] Estoque insuficiente. Disponivel: %d\n",
               produto->quantidade);
        return;
    }

    Carrinho *carrinho_atual = head_carrinho->prox;

    while (carrinho_atual != NULL) {
        if (carrinho_atual->codigo_produto == produto->codigo) {

            if (qtd_pedida <=
                (produto->quantidade - carrinho_atual->quantidade_compra)) {
                carrinho_atual->quantidade_compra += qtd_pedida;
                return;
            }

            printf("\n[!] Quantidade pedida maior que estoque.\n");
            return;
        }
        carrinho_atual = carrinho_atual->prox;
    }

    Carrinho *novo = criar_carrinho(qtd_pedida, produto);

    if (novo == NULL) {
        printf("\n[X] Erro ao criar item do carrinho.\n");
        return;
    }

    inserir_na_lista_carrinho(head_carrinho, novo);
    printf("\n[*] Produto adicionado ao carrinho.\n");
}

void retirar_produto_carrinho(Carrinho *head_carrinho) {

    if (head_carrinho->prox == NULL) {
        printf("\n[!] O carrinho esta vazio.\n");
        return;
    }

    int codigo = obter_codigo_produto();

    Carrinho *anterior = head_carrinho;
    Carrinho *atual = head_carrinho->prox;

    while (atual != NULL) {

        if (atual->codigo_produto == codigo) {

            printf("\n ::: Produto encontrado. Qtd atual: %d",
                   atual->quantidade_compra);
            printf("\n ::: Quanto deseja remover? ");
            int qtd_remover;
            scanf("%d", &qtd_remover);

            if (qtd_remover >= atual->quantidade_compra) {
                remover_carrinho(anterior);
                printf("\n[*] Item removido totalmente do carrinho.\n");

            } else if (qtd_remover > 0) {
                atual->quantidade_compra -= qtd_remover;
                printf("\n[*] Quantidade atualizada. Restam: %d\n",
                       atual->quantidade_compra);
            } else {
                printf("\n[!] Quantidade invalida. Nada foi alterado.\n");
            }

            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("\n[!] Esse produto nao esta no seu carrinho.\n");
}

void listar_carrinho(Carrinho *head_carrinho, Produto *head_produto) {
    if (head_carrinho == NULL || head_carrinho->prox == NULL) {
        printf("\n[!] O carrinho esta vazio.\n");
        return;
    }

    Carrinho *atual = head_carrinho->prox;
    float total_geral = 0.0;

    printf(
        "\n+=============================================================+\n");
    printf("|                      SEU CARRINHO                           |\n");
    printf("+======+=========================+==========+======+==========+\n");
    printf("| COD  | PRODUTO                 | PRECO UN | QTD  | SUBTOTAL |\n");
    printf("+------+-------------------------+----------+------+----------+\n");

    while (atual != NULL) {
        Produto *p = buscar_produto(head_produto, atual->codigo_produto);

        if (p != NULL) {
            float subtotal = p->preco * atual->quantidade_compra;
            total_geral += subtotal;

            printf("| %04d | %-23.23s | R$ %6.2f | %4d | R$ %6.2f |\n",
                   p->codigo, p->nome, p->preco, atual->quantidade_compra,
                   subtotal);
        } else {
            printf("| %04d | [PRODUTO REMOVIDO]      | R$ --.-- | %4d | R$ "
                   "--.-- |\n",
                   atual->codigo_produto, atual->quantidade_compra);
        }

        atual = atual->prox;
    }

    printf("+------+-------------------------+----------+------+----------+\n");
    printf("|                                     TOTAL GERAL: | R$ %6.2f |\n",
           total_geral);
    printf("+=============================================================+\n");
}

void finalizar_compra(Carrinho *head_carrinho, Produto *head_produto) {
    if (head_carrinho->prox == NULL) {
        printf("\n[!] Carrinho vazio. Adicione itens antes de finalizar.\n");
        return;
    }

    Carrinho *item_carrinho = head_carrinho->prox;
    int houve_sucesso = 0;

    printf("\nProcessando compra...\n");

    while (item_carrinho != NULL) {
        Produto *produto_estoque =
            buscar_produto(head_produto, item_carrinho->codigo_produto);

        if (produto_estoque != NULL) {
            produto_estoque->quantidade -= item_carrinho->quantidade_compra;
            houve_sucesso = 1;
        } else {
            printf("[!] Erro: Produto %d nao existe mais no sistema.\n",
                   item_carrinho->codigo_produto);
        }

        item_carrinho = item_carrinho->prox;
    }

    if (houve_sucesso) {
        printf("\n[*] Compra finalizada com sucesso! Estoque atualizado.\n");
        esvaziar_carrinho(head_carrinho);
    }
}

void menu_compra(Cliente *lista_clientes, Produto *lista_produtos) {

    limpar_tela();
    exibir_cabecalho(" MODO COMPRA ");
    printf("Identifique-se para iniciar.\n");

    int cpf = obter_cpf();
    Cliente *cliente = buscar_cliente(lista_clientes, cpf);

    if (cliente == NULL) {
        printf("\n[!] Cliente nao encontrado. Cadastre-se antes de comprar.\n");
        pausar();
        return;
    }

    printf("\nOla, %s! Vamos as compras.\n", cliente->nome);
    pausar();

    Carrinho *meu_carrinho = criar_lista_carrinho();
    if (meu_carrinho == NULL)
        return;

    int opcao;

    do {
        limpar_tela();
        printf("+======================================+\n");
        printf("| CARRINHO DE: %-23.23s |\n", cliente->nome);
        printf("+======================================+\n");
        printf("|   [1]  Adicionar Produto             |\n");
        printf("|   [2]  Ver Meu Carrinho              |\n");
        printf("|   [3]  Remover/Alterar Qtd           |\n");
        printf("|   [4]  FINALIZAR COMPRA              |\n");
        printf("|                                      |\n");
        printf("|   [0]  Cancelar e Sair               |\n");
        printf("+--------------------------------------+\n");
        printf("\n ::: Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            listar_produtos(lista_produtos);
            adicionar_produto(meu_carrinho, lista_produtos);
            pausar();
            break;

        case 2:
            listar_carrinho(meu_carrinho, lista_produtos);
            pausar();
            break;

        case 3:
            listar_carrinho(meu_carrinho, lista_produtos);
            retirar_produto_carrinho(meu_carrinho);
            pausar();
            break;

        case 4:
            listar_carrinho(meu_carrinho, lista_produtos);
            printf("\nConfirmar compra? (1-Sim / 0-Nao): ");
            int confirm;
            scanf("%d", &confirm);
            if (confirm == 1) {
                finalizar_compra(meu_carrinho, lista_produtos);
            } else {
                printf("\nCompra nao finalizada.\n");
            }
            pausar();
            break;

        case 0:
            printf("\nSaindo do carrinho...\n");
            break;

        default:
            printf("\n[!] Opcao invalida.\n");
            pausar();
            break;
        }
    } while (opcao != 0);

    liberar_carrinho(meu_carrinho);
}
