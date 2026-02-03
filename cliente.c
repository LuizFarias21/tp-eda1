#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente *criar_cliente() {
    Cliente *cliente = malloc(sizeof(Cliente));

    if (cliente == NULL) {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    cliente->cpf = 0;
    cliente->nome = malloc(100 * sizeof(char));
    cliente->email = malloc(100 * sizeof(char));
    cliente->telefone = malloc(20 * sizeof(char));
    cliente->data_nascimento = malloc(11 * sizeof(char));

    return cliente;
}

Cliente *criar_lista() {
    Cliente *head = malloc(sizeof(Cliente));
    head->prox = NULL;

    return head;
}

void inserir_na_lista(int cpf, char *nome, char *email, char *telefone,
                      char *data_nascimento, Cliente *cliente) {
    Cliente *novo_cliente = criar_cliente();

    novo_cliente->cpf = cpf;
    strcpy(novo_cliente->nome, nome);
    strcpy(novo_cliente->email, email);
    strcpy(novo_cliente->telefone, telefone);
    strcpy(novo_cliente->data_nascimento, data_nascimento);

    novo_cliente->prox = cliente->prox;
    cliente->prox = novo_cliente;
}

void listarClientes(Cliente *lista) {

    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Cliente *p = lista->prox;

    while (p != NULL) {
        printf("%s\n", p->nome);
        p = p->prox;
    }
}

Cliente *buscarCliente(int cpf, Cliente *lista) {
    Cliente *p = lista->prox;

    while (p != NULL && p->cpf != cpf) {
        p = p->prox;
    }

    return p;
}

void menu_cliente(Cliente *cliente) {
    int opcao;

    do {
        printf("--- Gerenciamento de Clientes ---\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar todos os clientes \n");
        printf("3 - Buscar cliente\n");
        printf("4 - Editar dados de um cliente\n");
        printf("5 - Remover cliente \n");
        printf("0 - Sair");
        printf("-----------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
    } while (opcao != 0);
}

int main() {

    Cliente lista = *criar_cliente();
    menu_cliente(&lista);
    return 0;
}
