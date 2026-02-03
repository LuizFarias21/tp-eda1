#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    int cpf;
    char *nome;
    char *email;
    char *telefone;
    char *data_nascimento;
    struct cliente *prox;
} Cliente;

// Cliente *criarLista();
// Cliente *buscarCliente(int cpf, Cliente *lista);
// void listarClientes(Cliente *lista);

#endif
