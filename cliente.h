#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    int cpf[15];
    char nome[100];
    char email[100];
    char telefone[20];
    char data_nascimento[11];
    struct celula_cliente *prox;
} Cliente;

Cliente *criarLista();
Cliente buscarCliente(int cpf, Cliente *lista);
void listarCliente(Cliente *lista);

#endif
