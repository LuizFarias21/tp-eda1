#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    int cpf;
    char nome[100];
    char email[100];
    char telefone[20];
    char data_nascimento[12];
    struct cliente *prox;
} Cliente;

// Cliente *criarLista();
// Cliente *buscarCliente(int cpf, Cliente *lista);
// void listarClientes(Cliente *lista);

#endif
