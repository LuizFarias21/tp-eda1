#include "cliente.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente *criar_lista_cliente() {
    Cliente *head = malloc(sizeof(Cliente));

    if (head == NULL) {
        printf("\n[X] Memoria cheia.\n");
        return NULL;
    }

    head->prox = NULL;
    return head;
}

void inserir_cliente(Cliente *head, Cliente *novo) {
    novo->prox = head->prox;
    head->prox = novo;
}

int obter_cpf() {
    int cpf;
    do {
        printf("\n ::: CPF: ");
        scanf("%d", &cpf);

        if (cpf <= 0) {
            printf("\n[!] CPF invalido. Digite apenas numeros positivos.\n");
        }
    } while (cpf <= 0);

    return cpf;
}

void cadastrar_cliente(Cliente *head) {

    int cpf = obter_cpf();

    if (buscar_cliente(head, cpf) != NULL) {
        printf("\n[!] Ja existe um cliente com este CPF.\n");
        return;
    }

    Cliente *novo = malloc(sizeof(Cliente));

    if (novo == NULL) {
        printf("\n[X] Memoria cheia.\n");
        return;
    }

    novo->cpf = cpf;

    printf("\n ::: Nome: ");
    scanf(" %99[^\n]", novo->nome);

    printf("\n ::: Email: ");
    scanf(" %99[^\n]", novo->email);

    printf("\n ::: Telefone: ");
    scanf(" %19[^\n]", novo->telefone);

    printf("\n ::: Data de nascimento (DD/MM/AAAA): ");
    scanf(" %11[^\n]", novo->data_nascimento);

    printf("\n[*] Cliente cadastrado com sucesso.\n");
    inserir_cliente(head, novo);
}

void listar_clientes(Cliente *head) {

    if (head == NULL) {
        printf("\n[!] Lista nao inicializada.\n");
        return;
    }

    Cliente *atual = head->prox;

    if (atual == NULL) {
        printf("\n[!] Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n+================================================================"
           "===================================+\n");
    printf("|                                       LISTA DE CLIENTES          "
           "                                 |\n");
    printf("+=============+======================+===========================+="
           "================+================+\n");
    printf("| CPF         | NOME                 | EMAIL                     | "
           "TELEFONE        | NASCIMENTO     |\n");
    printf("+-------------+----------------------+---------------------------+-"
           "----------------+----------------+\n");

    while (atual != NULL) {
        printf("| %-11d | %-20.20s | %-25.25s | %-15.15s | %-14.14s |\n",
               atual->cpf, atual->nome, atual->email, atual->telefone,
               atual->data_nascimento);

        atual = atual->prox;
    }

    printf("+-------------+----------------------+---------------------------+-"
           "----------------+----------------+\n");
}

Cliente *buscar_cliente(Cliente *head, int cpf) {

    Cliente *atual = head->prox;

    while (atual != NULL) {
        if (atual->cpf == cpf)
            return atual;
        atual = atual->prox;
    }

    return NULL;
}

void editar_cliente(Cliente *head) {

    int cpf = obter_cpf();
    Cliente *cliente = buscar_cliente(head, cpf);

    if (cliente == NULL) {
        printf("\n[!] Nenhum cliente encontrado.\n");
        return;
    }

    printf("\n ::: Novo nome: ");
    scanf(" %99[^\n]", cliente->nome);

    printf("\n ::: Novo email: ");
    scanf(" %99[^\n]", cliente->email);

    printf("\n ::: Novo telefone: ");
    scanf(" %19[^\n]", cliente->telefone);

    printf("\n ::: Nova data de nascimento: ");
    scanf(" %11[^\n]", cliente->data_nascimento);

    printf("\n[*] Informações atualizadas com sucesso.\n");
}

void remover_cliente(Cliente *head) {

    int cpf = obter_cpf();

    Cliente *ant = head;
    Cliente *atual = head->prox;

    while (atual != NULL && atual->cpf != cpf) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\n[!] Nenhum cliente encontrado.\n");
        return;
    }

    ant->prox = atual->prox;
    free(atual);

    printf("\n[*] Cliente removido com sucesso.\n");
}

void menu_cliente(Cliente *head) {
    int opcao;

    do {
        limpar_tela();
        exibir_cabecalho("  MENU CLIENTES");
        printf("|                                      |\n");
        printf("|   [1]  Cadastrar Novo Cliente        |\n");
        printf("|   [2]  Listar Todos                  |\n");
        printf("|   [3]  Buscar por CPF                |\n");
        printf("|   [4]  Editar Informacoes            |\n");
        printf("|   [5]  Remover Cliente               |\n");
        printf("|                                      |\n");
        printf("|   [0]  Voltar ao Menu Principal      |\n");
        printf("|                                      |\n");
        printf("+--------------------------------------+\n");
        printf("\n ::: Selecione uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            cadastrar_cliente(head);
            pausar();
            break;

        case 2:
            listar_clientes(head);
            pausar();
            break;

        case 3: {
            int cpf = obter_cpf();
            Cliente *cliente = buscar_cliente(head, cpf);

            if (cliente) {
                printf("\n");
                printf(
                    " +==================================================+\n");
                printf(
                    " | [*]           CLIENTE ENCONTRADO                 |\n");
                printf(
                    " +==================================================+\n");
                printf(" | CPF.........: %-34d |\n", cliente->cpf);
                printf(
                    " +--------------------------------------------------+\n");
                printf(" | Nome........: %-34.34s |\n", cliente->nome);
                printf(" | Email.......: %-34.34s |\n", cliente->email);
                printf(" | Telefone....: %-34.14s |\n", cliente->telefone);
                printf(" | Nascimento..: %-34.14s |\n",
                       cliente->data_nascimento);
                printf(
                    " +==================================================+\n");
            } else {
                printf("\n[!] Cliente com CPF %d nao encontrado.\n", cpf);
            }

            pausar();
            break;
        }

        case 4:
            editar_cliente(head);
            pausar();
            break;

        case 5:
            remover_cliente(head);
            pausar();
            break;

        case 0:
            break;

        default:
            printf("\n[!] Opcao invalida.\n");
            pausar();
            break;
        }

    } while (opcao != 0);
}
