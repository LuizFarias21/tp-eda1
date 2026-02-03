#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

Cliente *criarLista() {
    Cliente *head = malloc(sizeof(Cliente));
    head->prox = NULL;

    return head;
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
