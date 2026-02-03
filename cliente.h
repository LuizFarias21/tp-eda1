#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int cpf[15];
    char nome[100];
    char email[100];
    char telefone[20];
    char data_nascimento[11];
} Cliente;

typedef struct celulaCliente {
    Cliente dados;
    struct celula_cliente *prox;
} CelulaCliente;

#endif
