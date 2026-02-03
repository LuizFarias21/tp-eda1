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

    cliente->prox = NULL;
    return cliente;
}

// Função que só chama outra, é redundante mas pode ser útil
// se for colocar algo específico na dummy cell.
Cliente *criar_lista() { return criar_cliente(); }

void inserir_na_lista(Cliente *lista, Cliente *cliente) {
    cliente->prox = lista->prox;
    lista->prox = cliente;
}

void listarClientes(Cliente *lista) {

    if (lista->prox == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Cliente *p = lista->prox;

    while (p != NULL) {
        printf("CPF: %d | Nome: %s\n", p->cpf, p->nome);
        p = p->prox;
    }
    printf("--------------------\n");
}

void buscar_cliente(Cliente *lista) {

    int cpf;
    printf(">>> Buscar cliente <<<\n");

    printf("CPF: ");
    scanf("%d", &cpf);

    Cliente *p = lista->prox;

    while (p != NULL && p->cpf != cpf) {
        p = p->prox;
    }

    if (p == NULL) {
        printf("Nenhum cliente encontrado!\n");
        return;
    }

    printf("%s\n", p->nome);
}

void cadastrar_cliente(Cliente *lista) {

    Cliente *novo_cliente = criar_cliente();

    printf(">>> Cadastrar cliente <<<\n");
    printf("CPF: ");
    scanf("%d", &novo_cliente->cpf);
    getchar();
    printf("Nome: ");
    scanf("%[^\n]", novo_cliente->nome);
    getchar();
    printf("Email: ");
    scanf("%[^\n]", novo_cliente->email);
    getchar();
    printf("Telefone: ");
    scanf("%[^\n]", novo_cliente->telefone);
    getchar();
    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf("%[^\n]", novo_cliente->data_nascimento);
    getchar();
    printf("\n");

    inserir_na_lista(lista, novo_cliente);
    printf(">> Sucesso! Cliente cadastrado. <<\n");
}

void menu_cliente(Cliente *lista) {
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
        getchar();

        switch (opcao) {
        case 1:
            cadastrar_cliente(lista);
            break;
        case 2:
            listarClientes(lista);
            break;
        case 3:
            buscar_cliente(lista);
        case 4:
            break;
        case 5:
            break;
        }
    } while (opcao != 0);
}

int main() {

    Cliente *lista = criar_lista();
    menu_cliente(lista);
    return 0;
}
